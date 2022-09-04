#include "include.h"
#include "gps_log.h"

static const char *TAG = "example";
sdmmc_card_t *card;
const char mount_point[] = MOUNT_POINT;
sdmmc_host_t host = SDSPI_HOST_DEFAULT();
bool init_res = false;
bool rename_flag = false;
FILE *f = NULL;
char filename[32];
char new_filename[64];

bool IsExternsion(char *name, char *ext) {
    while (*name != '.' && *name != '\0') {
        name++;
    }
    if (*name == '.') {
        return !strcmp(name+1, ext);
    } else {
        return false;
    }
}

int GetFileNameCnt(char *name) {
    int cnt = 0;
    if (strstr(name, "TEMP")) {
        sscanf(name, "TEMP_%d", &cnt);
        return cnt;
    } else {
        return 0;
    }
}

int GetCurFileNameCounter(char* path) {
    FRESULT res;
    FF_DIR dir;
    static FILINFO fno;
    int file_cnt = 0;

    res = f_opendir(&dir, path);                       /* Open the directory */
    if (res == FR_OK) {
        for (;;) {
            res = f_readdir(&dir, &fno);                   /* Read a directory item */
            if (res != FR_OK || fno.fname[0] == 0) break;  /* Break on error or end of dir */
            if (fno.fattrib & AM_DIR) {                    /* It is a directory */
                //res = scan_files(path);                    /* Enter the directory */
                //if (res != FR_OK) break;
                //path[i] = 0;
            } else {              
                if (IsExternsion(fno.fname, "GPS")) {
                    int temp = GetFileNameCnt(fno.fname);
                    file_cnt = file_cnt>temp ? file_cnt : temp;
                }
            }
        }
        f_closedir(&dir);
    }

    return file_cnt;
}

bool SdcardInit(void)
{
    esp_err_t ret;

    esp_vfs_fat_sdmmc_mount_config_t mount_config = {
        .format_if_mount_failed = false,
        .max_files = 5,
        .allocation_unit_size = 16 * 1024
    };
    spi_bus_config_t bus_cfg = {
        .mosi_io_num = PIN_NUM_MOSI,
        .miso_io_num = PIN_NUM_MISO,
        .sclk_io_num = PIN_NUM_CLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 4000,
        };
    ret = spi_bus_initialize(host.slot, &bus_cfg, SPI_DMA_CHAN);        //SPI2  SPI_DMA_2
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize bus.");
        return false;
    }

    sdspi_device_config_t slot_config = SDSPI_DEVICE_CONFIG_DEFAULT();
    slot_config.gpio_cs = PIN_NUM_CS;
    slot_config.host_id = host.slot;
    ret = esp_vfs_fat_sdspi_mount(mount_point, &host, &slot_config, &mount_config, &card);
    if (ret != ESP_OK) {
        if (ret == ESP_FAIL) {
            ESP_LOGE(TAG, "Failed to mount filesystem. "
                     "If you want the card to be formatted, set the EXAMPLE_FORMAT_IF_MOUNT_FAILED menuconfig option.");
        } else {
            ESP_LOGE(TAG, "Failed to initialize the card (%s). "
                     "Make sure SD card lines have pull-up resistors in place.", esp_err_to_name(ret));
        }
        return false;
    }
    ESP_LOGI(TAG, "Filesystem mounted");

    // Card has been initialized, print its properties
    sdmmc_card_print_info(stdout, card);

    return true;
}

void SdcardUninit() {
    // All done, unmount partition and disable SPI peripheral
    esp_vfs_fat_sdcard_unmount(mount_point, card);
    ESP_LOGI(TAG, "Card unmounted");

    //deinitialize the bus after all devices are removed
    spi_bus_free(host.slot);
}

void GpsLogInit() {
    if (SdcardInit()) {
        sprintf(filename, "%s/TEMP_%d.GPS", MOUNT_POINT, GetCurFileNameCounter("")+1);
        f = fopen(filename, "a");
        if (f) {
            ESP_LOGI(TAG, "open succeed: %s", filename);
        }
        fwrite("hello, world!\n", 14, 1, f);
    }

    //SdcardUninit();
}

void log_file_rename(gps_t *data) {
    if (rename_flag || data->date.year <= YEAR_BASE) {
       return;
    }
    fclose(f);
    f = NULL;

    sprintf(new_filename, "%s/%u%02u%02u_%u%u%u.GPS", MOUNT_POINT,
        data->date.year, data->date.month, data->date.day,
        data->tim.hour, data->tim.minute, data->tim.second);

    // Check if destination file exists before renaming
    struct stat st;
    if (stat(new_filename, &st) == 0) {
        // Delete it if it exists
        unlink(new_filename);
    }

    // Rename original file
    ESP_LOGI(TAG, "Renaming file %s to %s", filename, new_filename);
    if (rename(filename, new_filename) != 0) {
        ESP_LOGE(TAG, "Rename failed");
        return;
    }

    // Open renamed file for reading
    f = fopen(new_filename, "a");
    if (f == NULL) {
        ESP_LOGE(TAG, "Failed to open file for reading");
        return;
    }
    rename_flag = true;
}

void gps_write_log(char *buf, int len) {
    static int cnt = 0;

    if (f) {
        fputs(buf, f);
        if (!(++cnt%10)) {
            fsync(fileno(f));
        }
    }
}