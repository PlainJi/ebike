// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Screen1;
lv_obj_t * ui_PanelTop;
lv_obj_t * ui_textsatellites;
lv_obj_t * ui_texttimenow;
lv_obj_t * ui_imgbluetooth;
lv_obj_t * ui_imgsdcard;
lv_obj_t * ui_imglocating;
lv_obj_t * ui_imglocated;
lv_obj_t * ui_imgp;
lv_obj_t * ui_Imgrecording;
lv_obj_t * ui_Imgrecordidle;
lv_obj_t * ui_PanelSpeed;
lv_obj_t * ui_textspeed;
lv_obj_t * ui_Labelkmh;
lv_obj_t * ui_PanelDirrection;
lv_obj_t * ui_imgdirection;
lv_obj_t * ui_PanelDetail;
lv_obj_t * ui_texttriptime;
lv_obj_t * ui_LabelTime;
lv_obj_t * ui_texttrip;
lv_obj_t * ui_LabelTrip;
lv_obj_t * ui_texttotal;
lv_obj_t * ui_LabelTotal;
lv_obj_t * ui_textwenshi;
lv_obj_t * ui_LabelWenShi;
lv_obj_t * ui_PanelBattery;
lv_obj_t * ui_BatteryPositive;
lv_obj_t * ui_barbattery;
lv_obj_t * ui_textleft;
lv_obj_t * ui_Screen2;
lv_obj_t * ui_PanelTop1;
lv_obj_t * ui_textsatellites1;
lv_obj_t * ui_texttimenow1;
lv_obj_t * ui_imgbluetooth1;
lv_obj_t * ui_imgsdcard1;
lv_obj_t * ui_imglocating1;
lv_obj_t * ui_imglocated1;
lv_obj_t * ui_imgp1;
lv_obj_t * ui_Imgrecording1;
lv_obj_t * ui_Imgrecordidle1;
lv_obj_t * ui_PanelSpeed1;
lv_obj_t * ui_textspeed1;
lv_obj_t * ui_Labelkmh1;
lv_obj_t * ui_PanelDirrection1;
lv_obj_t * ui_imgdirection1;
lv_obj_t * ui_PanelDetail1;
lv_obj_t * ui_texttriptime1;
lv_obj_t * ui_LabelTime1;
lv_obj_t * ui_texttrip1;
lv_obj_t * ui_LabelTrip1;
lv_obj_t * ui_texttotal1;
lv_obj_t * ui_LabelTotal1;
lv_obj_t * ui_textwenshi1;
lv_obj_t * ui_LabelWenShi1;
lv_obj_t * ui_PanelBattery1;
lv_obj_t * ui_BatteryPositive1;
lv_obj_t * ui_barbattery1;
lv_obj_t * ui_textleft1;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    #error "#error LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{

    // ui_Screen1

    ui_Screen1 = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE |
                      LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM);

    // ui_PanelTop

    ui_PanelTop = lv_obj_create(ui_Screen1);

    lv_obj_set_width(ui_PanelTop, 240);
    lv_obj_set_height(ui_PanelTop, 30);

    lv_obj_set_x(ui_PanelTop, 0);
    lv_obj_set_y(ui_PanelTop, 0);

    lv_obj_set_align(ui_PanelTop, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_PanelTop, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_radius(ui_PanelTop, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelTop, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelTop, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_textsatellites

    ui_textsatellites = lv_textarea_create(ui_PanelTop);

    lv_obj_set_width(ui_textsatellites, 46);
    lv_obj_set_height(ui_textsatellites, 44);

    lv_obj_set_x(ui_textsatellites, 102);
    lv_obj_set_y(ui_textsatellites, 0);

    lv_obj_set_align(ui_textsatellites, LV_ALIGN_CENTER);

    // if("" == "") lv_textarea_set_accepted_chars(ui_textsatellites, NULL);
    //lv_textarea_set_accepted_chars(ui_textsatellites, "");

    lv_textarea_set_max_length(ui_textsatellites, 2);
    lv_textarea_set_text(ui_textsatellites, "12");
    lv_textarea_set_placeholder_text(ui_textsatellites, "Placeholder...");
    lv_textarea_set_one_line(ui_textsatellites, true);

    lv_obj_clear_flag(ui_textsatellites,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_align(ui_textsatellites, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_textsatellites, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_textsatellites, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_textsatellites, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_textsatellites, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_textsatellites, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_textsatellites, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_textsatellites, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_texttimenow

    ui_texttimenow = lv_textarea_create(ui_PanelTop);

    lv_obj_set_width(ui_texttimenow, 90);
    lv_obj_set_height(ui_texttimenow, 43);

    lv_obj_set_x(ui_texttimenow, 0);
    lv_obj_set_y(ui_texttimenow, 0);

    lv_obj_set_align(ui_texttimenow, LV_ALIGN_CENTER);

    // if("" == "") lv_textarea_set_accepted_chars(ui_texttimenow, NULL);
    //lv_textarea_set_accepted_chars(ui_texttimenow, "");

    lv_textarea_set_max_length(ui_texttimenow, 7);
    lv_textarea_set_text(ui_texttimenow, "12 : 34");
    lv_textarea_set_placeholder_text(ui_texttimenow, "Placeholder...");
    lv_textarea_set_one_line(ui_texttimenow, true);

    lv_obj_clear_flag(ui_texttimenow, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_align(ui_texttimenow, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_texttimenow, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_texttimenow, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_texttimenow, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_texttimenow, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_texttimenow, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_texttimenow, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_texttimenow, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_imgbluetooth

    ui_imgbluetooth = lv_img_create(ui_PanelTop);
    lv_img_set_src(ui_imgbluetooth, &ui_img_bt24_png);

    lv_obj_set_width(ui_imgbluetooth, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_imgbluetooth, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_imgbluetooth, 34);
    lv_obj_set_y(ui_imgbluetooth, -12);

    lv_obj_clear_flag(ui_imgbluetooth, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_imgsdcard

    ui_imgsdcard = lv_img_create(ui_PanelTop);
    lv_img_set_src(ui_imgsdcard, &ui_img_sdcard_png);

    lv_obj_set_width(ui_imgsdcard, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_imgsdcard, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_imgsdcard, -108);
    lv_obj_set_y(ui_imgsdcard, 0);

    lv_obj_set_align(ui_imgsdcard, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_imgsdcard, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_imglocating

    ui_imglocating = lv_img_create(ui_PanelTop);
    lv_img_set_src(ui_imglocating, &ui_img_locating_png);

    lv_obj_set_width(ui_imglocating, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_imglocating, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_imglocating, 75);
    lv_obj_set_y(ui_imglocating, 0);

    lv_obj_set_align(ui_imglocating, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_imglocating, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_imglocated

    ui_imglocated = lv_img_create(ui_PanelTop);
    lv_img_set_src(ui_imglocated, &ui_img_located_png);

    lv_obj_set_width(ui_imglocated, 24);
    lv_obj_set_height(ui_imglocated, 24);

    lv_obj_set_x(ui_imglocated, 75);
    lv_obj_set_y(ui_imglocated, 0);

    lv_obj_set_align(ui_imglocated, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_imglocated, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_imgp

    ui_imgp = lv_img_create(ui_PanelTop);
    lv_img_set_src(ui_imgp, &ui_img_p_png);

    lv_obj_set_width(ui_imgp, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_imgp, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_imgp, -84);
    lv_obj_set_y(ui_imgp, 0);

    lv_obj_set_align(ui_imgp, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_imgp, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_Imgrecording

    ui_Imgrecording = lv_img_create(ui_PanelTop);
    lv_img_set_src(ui_Imgrecording, &ui_img_recording_png);

    lv_obj_set_width(ui_Imgrecording, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Imgrecording, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Imgrecording, 52);
    lv_obj_set_y(ui_Imgrecording, 0);

    lv_obj_set_align(ui_Imgrecording, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Imgrecording, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_Imgrecordidle

    ui_Imgrecordidle = lv_img_create(ui_PanelTop);
    lv_img_set_src(ui_Imgrecordidle, &ui_img_record_idle_png);

    lv_obj_set_width(ui_Imgrecordidle, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Imgrecordidle, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Imgrecordidle, 52);
    lv_obj_set_y(ui_Imgrecordidle, 0);

    lv_obj_set_align(ui_Imgrecordidle, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Imgrecordidle, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_PanelSpeed

    ui_PanelSpeed = lv_obj_create(ui_Screen1);

    lv_obj_set_width(ui_PanelSpeed, 100);
    lv_obj_set_height(ui_PanelSpeed, 100);

    lv_obj_set_x(ui_PanelSpeed, -57);
    lv_obj_set_y(ui_PanelSpeed, -73);

    lv_obj_set_align(ui_PanelSpeed, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_PanelSpeed, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_textspeed

    ui_textspeed = lv_textarea_create(ui_PanelSpeed);

    lv_obj_set_width(ui_textspeed, 100);
    lv_obj_set_height(ui_textspeed, 80);

    lv_obj_set_x(ui_textspeed, 0);
    lv_obj_set_y(ui_textspeed, 0);

    lv_obj_set_align(ui_textspeed, LV_ALIGN_CENTER);

    // if("" == "") lv_textarea_set_accepted_chars(ui_textspeed, NULL);
    //lv_textarea_set_accepted_chars(ui_textspeed, "");

    lv_textarea_set_max_length(ui_textspeed, 2);
    lv_textarea_set_text(ui_textspeed, "88");
    lv_textarea_set_placeholder_text(ui_textspeed, "Placeholder...");
    lv_textarea_set_one_line(ui_textspeed, true);

    lv_obj_clear_flag(ui_textspeed, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_align(ui_textspeed, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_textspeed, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_textspeed, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_textspeed, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Labelkmh

    ui_Labelkmh = lv_label_create(ui_PanelSpeed);

    lv_obj_set_width(ui_Labelkmh, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Labelkmh, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Labelkmh, 0);
    lv_obj_set_y(ui_Labelkmh, 33);

    lv_obj_set_align(ui_Labelkmh, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Labelkmh, "km/h");

    lv_obj_clear_flag(ui_Labelkmh, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_font(ui_Labelkmh, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_PanelDirrection

    ui_PanelDirrection = lv_obj_create(ui_Screen1);

    lv_obj_set_width(ui_PanelDirrection, 100);
    lv_obj_set_height(ui_PanelDirrection, 100);

    lv_obj_set_x(ui_PanelDirrection, 57);
    lv_obj_set_y(ui_PanelDirrection, -73);

    lv_obj_set_align(ui_PanelDirrection, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_PanelDirrection,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_imgdirection

    ui_imgdirection = lv_img_create(ui_PanelDirrection);
    lv_img_set_src(ui_imgdirection, &ui_img_direction_png);

    lv_obj_set_width(ui_imgdirection, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_imgdirection, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_imgdirection, 0);
    lv_obj_set_y(ui_imgdirection, 0);

    lv_obj_set_align(ui_imgdirection, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_imgdirection, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_scrollbar_mode(ui_imgdirection, LV_SCROLLBAR_MODE_OFF);

    // ui_PanelDetail

    ui_PanelDetail = lv_obj_create(ui_Screen1);

    lv_obj_set_width(ui_PanelDetail, 216);
    lv_obj_set_height(ui_PanelDetail, 120);

    lv_obj_set_x(ui_PanelDetail, 0);
    lv_obj_set_y(ui_PanelDetail, -56);

    lv_obj_set_align(ui_PanelDetail, LV_ALIGN_BOTTOM_MID);

    lv_obj_clear_flag(ui_PanelDetail, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_texttriptime

    ui_texttriptime = lv_textarea_create(ui_PanelDetail);

    lv_obj_set_width(ui_texttriptime, 90);
    lv_obj_set_height(ui_texttriptime, 47);

    lv_obj_set_x(ui_texttriptime, 59);
    lv_obj_set_y(ui_texttriptime, -11);

    lv_obj_set_align(ui_texttriptime, LV_ALIGN_CENTER);

    // if("" == "") lv_textarea_set_accepted_chars(ui_texttriptime, NULL);
    //lv_textarea_set_accepted_chars(ui_texttriptime, "");

    lv_textarea_set_max_length(ui_texttriptime, 7);
    lv_textarea_set_text(ui_texttriptime, "12 : 34");
    lv_textarea_set_placeholder_text(ui_texttriptime, "Placeholder...");
    lv_textarea_set_one_line(ui_texttriptime, true);

    lv_obj_clear_flag(ui_texttriptime, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_align(ui_texttriptime, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_texttriptime, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_texttriptime, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_texttriptime, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelTime

    ui_LabelTime = lv_label_create(ui_PanelDetail);

    lv_obj_set_width(ui_LabelTime, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelTime, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelTime, 58);
    lv_obj_set_y(ui_LabelTime, -40);

    lv_obj_set_align(ui_LabelTime, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelTime, "TripTime");

    lv_obj_clear_flag(ui_LabelTime, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_font(ui_LabelTime, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_texttrip

    ui_texttrip = lv_textarea_create(ui_PanelDetail);

    lv_obj_set_width(ui_texttrip, 81);
    lv_obj_set_height(ui_texttrip, 47);

    lv_obj_set_x(ui_texttrip, -53);
    lv_obj_set_y(ui_texttrip, -15);

    lv_obj_set_align(ui_texttrip, LV_ALIGN_CENTER);

    // if("" == "") lv_textarea_set_accepted_chars(ui_texttrip, NULL);
    //lv_textarea_set_accepted_chars(ui_texttrip, "");

    lv_textarea_set_max_length(ui_texttrip, 5);
    lv_textarea_set_text(ui_texttrip, "8.12");
    lv_textarea_set_placeholder_text(ui_texttrip, "Placeholder...");
    lv_textarea_set_one_line(ui_texttrip, true);

    lv_obj_clear_flag(ui_texttrip, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_align(ui_texttrip, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_texttrip, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_texttrip, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_texttrip, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelTrip

    ui_LabelTrip = lv_label_create(ui_PanelDetail);

    lv_obj_set_width(ui_LabelTrip, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelTrip, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelTrip, -56);
    lv_obj_set_y(ui_LabelTrip, -40);

    lv_obj_set_align(ui_LabelTrip, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelTrip, "Trip(km)");

    lv_obj_clear_flag(ui_LabelTrip, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_font(ui_LabelTrip, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_texttotal

    ui_texttotal = lv_textarea_create(ui_PanelDetail);

    lv_obj_set_width(ui_texttotal, 81);
    lv_obj_set_height(ui_texttotal, 47);

    lv_obj_set_x(ui_texttotal, -52);
    lv_obj_set_y(ui_texttotal, 35);

    lv_obj_set_align(ui_texttotal, LV_ALIGN_CENTER);

    // if("" == "") lv_textarea_set_accepted_chars(ui_texttotal, NULL);
    //lv_textarea_set_accepted_chars(ui_texttotal, "");

    lv_textarea_set_max_length(ui_texttotal, 5);
    lv_textarea_set_text(ui_texttotal, "123.4");
    lv_textarea_set_placeholder_text(ui_texttotal, "Placeholder...");
    lv_textarea_set_one_line(ui_texttotal, true);

    lv_obj_clear_flag(ui_texttotal, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_align(ui_texttotal, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_texttotal, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_texttotal, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_texttotal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelTotal

    ui_LabelTotal = lv_label_create(ui_PanelDetail);

    lv_obj_set_width(ui_LabelTotal, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelTotal, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelTotal, -56);
    lv_obj_set_y(ui_LabelTotal, 10);

    lv_obj_set_align(ui_LabelTotal, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelTotal, "Total(km)");

    lv_obj_clear_flag(ui_LabelTotal, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_font(ui_LabelTotal, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_textwenshi

    ui_textwenshi = lv_textarea_create(ui_PanelDetail);

    lv_obj_set_width(ui_textwenshi, 115);
    lv_obj_set_height(ui_textwenshi, 47);

    lv_obj_set_x(ui_textwenshi, 58);
    lv_obj_set_y(ui_textwenshi, 36);

    lv_obj_set_align(ui_textwenshi, LV_ALIGN_CENTER);

    // if("" == "") lv_textarea_set_accepted_chars(ui_textwenshi, NULL);
    //lv_textarea_set_accepted_chars(ui_textwenshi, "");

    lv_textarea_set_max_length(ui_textwenshi, 8);
    lv_textarea_set_text(ui_textwenshi, "30C 65%");
    lv_textarea_set_placeholder_text(ui_textwenshi, "Placeholder...");
    lv_textarea_set_one_line(ui_textwenshi, true);

    lv_obj_clear_flag(ui_textwenshi, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_align(ui_textwenshi, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_textwenshi, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_textwenshi, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_textwenshi, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelWenShi

    ui_LabelWenShi = lv_label_create(ui_PanelDetail);

    lv_obj_set_width(ui_LabelWenShi, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelWenShi, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelWenShi, 56);
    lv_obj_set_y(ui_LabelWenShi, 10);

    lv_obj_set_align(ui_LabelWenShi, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelWenShi, "T&H");

    lv_obj_clear_flag(ui_LabelWenShi, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_font(ui_LabelWenShi, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_PanelBattery

    ui_PanelBattery = lv_obj_create(ui_Screen1);

    lv_obj_set_width(ui_PanelBattery, 240);
    lv_obj_set_height(ui_PanelBattery, 50);

    lv_obj_set_x(ui_PanelBattery, 0);
    lv_obj_set_y(ui_PanelBattery, 0);

    lv_obj_set_align(ui_PanelBattery, LV_ALIGN_BOTTOM_MID);

    lv_obj_clear_flag(ui_PanelBattery, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_radius(ui_PanelBattery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelBattery, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelBattery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelBattery, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelBattery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_BatteryPositive

    ui_BatteryPositive = lv_img_create(ui_PanelBattery);
    lv_img_set_src(ui_BatteryPositive, &ui_img_1_png);

    lv_obj_set_width(ui_BatteryPositive, 9);
    lv_obj_set_height(ui_BatteryPositive, 27);

    lv_obj_set_x(ui_BatteryPositive, 13);
    lv_obj_set_y(ui_BatteryPositive, 3);

    lv_obj_set_align(ui_BatteryPositive, LV_ALIGN_BOTTOM_RIGHT);

    lv_obj_clear_flag(ui_BatteryPositive,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_barbattery

    ui_barbattery = lv_bar_create(ui_PanelBattery);
    lv_bar_set_range(ui_barbattery, 0, 100);
    lv_bar_set_value(ui_barbattery, 25, LV_ANIM_OFF);

    lv_obj_set_width(ui_barbattery, 220);
    lv_obj_set_height(ui_barbattery, 40);

    lv_obj_set_x(ui_barbattery, -4);
    lv_obj_set_y(ui_barbattery, 0);

    lv_obj_set_align(ui_barbattery, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_barbattery, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE);

    lv_obj_set_style_radius(ui_barbattery, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_barbattery, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_barbattery, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_barbattery, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_barbattery, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_barbattery, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_barbattery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_barbattery, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_barbattery, lv_color_hex(0xFF0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_barbattery, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_textleft

    ui_textleft = lv_textarea_create(ui_PanelBattery);

    lv_obj_set_width(ui_textleft, 91);
    lv_obj_set_height(ui_textleft, 47);

    lv_obj_set_x(ui_textleft, 7);
    lv_obj_set_y(ui_textleft, 0);

    lv_obj_set_align(ui_textleft, LV_ALIGN_CENTER);

    // if("" == "") lv_textarea_set_accepted_chars(ui_textleft, NULL);
    //lv_textarea_set_accepted_chars(ui_textleft, "");

    lv_textarea_set_max_length(ui_textleft, 4);
    lv_textarea_set_text(ui_textleft, "50KM");
    lv_textarea_set_placeholder_text(ui_textleft, "Placeholder...");
    lv_textarea_set_one_line(ui_textleft, true);

    lv_obj_clear_flag(ui_textleft, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_align(ui_textleft, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_textleft, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_textleft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_textleft, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_textleft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_textleft, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_textleft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_textleft, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_textleft, lv_color_hex(0x000000), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_textleft, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_textleft, lv_color_hex(0x000000), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_textleft, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_textleft, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);

}
void ui_Screen2_screen_init(void)
{

    // ui_Screen2

    ui_Screen2 = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Screen2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE |
                      LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM);

    lv_obj_set_style_bg_color(ui_Screen2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_PanelTop1

    ui_PanelTop1 = lv_obj_create(ui_Screen2);

    lv_obj_set_width(ui_PanelTop1, 240);
    lv_obj_set_height(ui_PanelTop1, 30);

    lv_obj_set_x(ui_PanelTop1, 0);
    lv_obj_set_y(ui_PanelTop1, 0);

    lv_obj_set_align(ui_PanelTop1, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_PanelTop1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_radius(ui_PanelTop1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelTop1, lv_color_hex(0x393939), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelTop1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelTop1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_textsatellites1

    ui_textsatellites1 = lv_textarea_create(ui_PanelTop1);

    lv_obj_set_width(ui_textsatellites1, 46);
    lv_obj_set_height(ui_textsatellites1, 44);

    lv_obj_set_x(ui_textsatellites1, 102);
    lv_obj_set_y(ui_textsatellites1, 0);

    lv_obj_set_align(ui_textsatellites1, LV_ALIGN_CENTER);

    // if("" == "") lv_textarea_set_accepted_chars(ui_textsatellites1, NULL);
    //lv_textarea_set_accepted_chars(ui_textsatellites1, "");

    lv_textarea_set_max_length(ui_textsatellites1, 2);
    lv_textarea_set_text(ui_textsatellites1, "12");
    lv_textarea_set_placeholder_text(ui_textsatellites1, "Placeholder...");
    lv_textarea_set_one_line(ui_textsatellites1, true);

    lv_obj_clear_flag(ui_textsatellites1,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_textsatellites1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_textsatellites1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_textsatellites1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_textsatellites1, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_textsatellites1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_textsatellites1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_textsatellites1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_textsatellites1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_textsatellites1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_textsatellites1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_texttimenow1

    ui_texttimenow1 = lv_textarea_create(ui_PanelTop1);

    lv_obj_set_width(ui_texttimenow1, 90);
    lv_obj_set_height(ui_texttimenow1, 43);

    lv_obj_set_x(ui_texttimenow1, 0);
    lv_obj_set_y(ui_texttimenow1, 0);

    lv_obj_set_align(ui_texttimenow1, LV_ALIGN_CENTER);

    // if("" == "") lv_textarea_set_accepted_chars(ui_texttimenow1, NULL);
    //lv_textarea_set_accepted_chars(ui_texttimenow1, "");

    lv_textarea_set_max_length(ui_texttimenow1, 7);
    lv_textarea_set_text(ui_texttimenow1, "12 : 34");
    lv_textarea_set_placeholder_text(ui_texttimenow1, "Placeholder...");
    lv_textarea_set_one_line(ui_texttimenow1, true);

    lv_obj_clear_flag(ui_texttimenow1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_texttimenow1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_texttimenow1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_texttimenow1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_texttimenow1, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_texttimenow1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_texttimenow1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_texttimenow1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_texttimenow1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_texttimenow1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_texttimenow1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_imgbluetooth1

    ui_imgbluetooth1 = lv_img_create(ui_PanelTop1);
    lv_img_set_src(ui_imgbluetooth1, &ui_img_bt24_w_png);

    lv_obj_set_width(ui_imgbluetooth1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_imgbluetooth1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_imgbluetooth1, 35);
    lv_obj_set_y(ui_imgbluetooth1, -10);

    lv_obj_clear_flag(ui_imgbluetooth1, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_imgsdcard1

    ui_imgsdcard1 = lv_img_create(ui_PanelTop1);
    lv_img_set_src(ui_imgsdcard1, &ui_img_sdcard_w_png);

    lv_obj_set_width(ui_imgsdcard1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_imgsdcard1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_imgsdcard1, -108);
    lv_obj_set_y(ui_imgsdcard1, 0);

    lv_obj_set_align(ui_imgsdcard1, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_imgsdcard1, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_imglocating1

    ui_imglocating1 = lv_img_create(ui_PanelTop1);
    lv_img_set_src(ui_imglocating1, &ui_img_locating_png);

    lv_obj_set_width(ui_imglocating1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_imglocating1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_imglocating1, 75);
    lv_obj_set_y(ui_imglocating1, 0);

    lv_obj_set_align(ui_imglocating1, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_imglocating1, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_imglocated1

    ui_imglocated1 = lv_img_create(ui_PanelTop1);
    lv_img_set_src(ui_imglocated1, &ui_img_located_png);

    lv_obj_set_width(ui_imglocated1, 24);
    lv_obj_set_height(ui_imglocated1, 24);

    lv_obj_set_x(ui_imglocated1, 75);
    lv_obj_set_y(ui_imglocated1, 0);

    lv_obj_set_align(ui_imglocated1, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_imglocated1, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_imgp1

    ui_imgp1 = lv_img_create(ui_PanelTop1);
    lv_img_set_src(ui_imgp1, &ui_img_p_png);

    lv_obj_set_width(ui_imgp1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_imgp1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_imgp1, -84);
    lv_obj_set_y(ui_imgp1, 0);

    lv_obj_set_align(ui_imgp1, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_imgp1, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_Imgrecording1

    ui_Imgrecording1 = lv_img_create(ui_PanelTop1);
    lv_img_set_src(ui_Imgrecording1, &ui_img_recording_png);

    lv_obj_set_width(ui_Imgrecording1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Imgrecording1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Imgrecording1, 52);
    lv_obj_set_y(ui_Imgrecording1, 0);

    lv_obj_set_align(ui_Imgrecording1, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Imgrecording1, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_Imgrecordidle1

    ui_Imgrecordidle1 = lv_img_create(ui_PanelTop1);
    lv_img_set_src(ui_Imgrecordidle1, &ui_img_record_idle_png);

    lv_obj_set_width(ui_Imgrecordidle1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Imgrecordidle1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Imgrecordidle1, 52);
    lv_obj_set_y(ui_Imgrecordidle1, 0);

    lv_obj_set_align(ui_Imgrecordidle1, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Imgrecordidle1,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_PanelSpeed1

    ui_PanelSpeed1 = lv_obj_create(ui_Screen2);

    lv_obj_set_width(ui_PanelSpeed1, 100);
    lv_obj_set_height(ui_PanelSpeed1, 100);

    lv_obj_set_x(ui_PanelSpeed1, -57);
    lv_obj_set_y(ui_PanelSpeed1, -73);

    lv_obj_set_align(ui_PanelSpeed1, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_PanelSpeed1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_bg_color(ui_PanelSpeed1, lv_color_hex(0x393939), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelSpeed1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_textspeed1

    ui_textspeed1 = lv_textarea_create(ui_PanelSpeed1);

    lv_obj_set_width(ui_textspeed1, 100);
    lv_obj_set_height(ui_textspeed1, 80);

    lv_obj_set_x(ui_textspeed1, 0);
    lv_obj_set_y(ui_textspeed1, 0);

    lv_obj_set_align(ui_textspeed1, LV_ALIGN_CENTER);

    // if("" == "") lv_textarea_set_accepted_chars(ui_textspeed1, NULL);
    //lv_textarea_set_accepted_chars(ui_textspeed1, "");

    lv_textarea_set_max_length(ui_textspeed1, 2);
    lv_textarea_set_text(ui_textspeed1, "88");
    lv_textarea_set_placeholder_text(ui_textspeed1, "Placeholder...");
    lv_textarea_set_one_line(ui_textspeed1, true);

    lv_obj_clear_flag(ui_textspeed1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_textspeed1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_textspeed1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_textspeed1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_textspeed1, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_textspeed1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_textspeed1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_textspeed1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_textspeed1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Labelkmh1

    ui_Labelkmh1 = lv_label_create(ui_PanelSpeed1);

    lv_obj_set_width(ui_Labelkmh1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Labelkmh1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Labelkmh1, 0);
    lv_obj_set_y(ui_Labelkmh1, 33);

    lv_obj_set_align(ui_Labelkmh1, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Labelkmh1, "km/h");

    lv_obj_clear_flag(ui_Labelkmh1, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_Labelkmh1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Labelkmh1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Labelkmh1, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_PanelDirrection1

    ui_PanelDirrection1 = lv_obj_create(ui_Screen2);

    lv_obj_set_width(ui_PanelDirrection1, 100);
    lv_obj_set_height(ui_PanelDirrection1, 100);

    lv_obj_set_x(ui_PanelDirrection1, 57);
    lv_obj_set_y(ui_PanelDirrection1, -73);

    lv_obj_set_align(ui_PanelDirrection1, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_PanelDirrection1,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_bg_color(ui_PanelDirrection1, lv_color_hex(0x393939), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelDirrection1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_imgdirection1

    ui_imgdirection1 = lv_img_create(ui_PanelDirrection1);
    lv_img_set_src(ui_imgdirection1, &ui_img_direction_w_png);

    lv_obj_set_width(ui_imgdirection1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_imgdirection1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_imgdirection1, 0);
    lv_obj_set_y(ui_imgdirection1, 0);

    lv_obj_set_align(ui_imgdirection1, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_imgdirection1, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_scrollbar_mode(ui_imgdirection1, LV_SCROLLBAR_MODE_OFF);

    // ui_PanelDetail1

    ui_PanelDetail1 = lv_obj_create(ui_Screen2);

    lv_obj_set_width(ui_PanelDetail1, 216);
    lv_obj_set_height(ui_PanelDetail1, 120);

    lv_obj_set_x(ui_PanelDetail1, 0);
    lv_obj_set_y(ui_PanelDetail1, -56);

    lv_obj_set_align(ui_PanelDetail1, LV_ALIGN_BOTTOM_MID);

    lv_obj_clear_flag(ui_PanelDetail1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_bg_color(ui_PanelDetail1, lv_color_hex(0x393939), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelDetail1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_texttriptime1

    ui_texttriptime1 = lv_textarea_create(ui_PanelDetail1);

    lv_obj_set_width(ui_texttriptime1, 90);
    lv_obj_set_height(ui_texttriptime1, 47);

    lv_obj_set_x(ui_texttriptime1, 59);
    lv_obj_set_y(ui_texttriptime1, -13);

    lv_obj_set_align(ui_texttriptime1, LV_ALIGN_CENTER);

    // if("" == "") lv_textarea_set_accepted_chars(ui_texttriptime1, NULL);
    //lv_textarea_set_accepted_chars(ui_texttriptime1, "");

    lv_textarea_set_max_length(ui_texttriptime1, 7);
    lv_textarea_set_text(ui_texttriptime1, "12 : 34");
    lv_textarea_set_placeholder_text(ui_texttriptime1, "Placeholder...");
    lv_textarea_set_one_line(ui_texttriptime1, true);

    lv_obj_clear_flag(ui_texttriptime1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_texttriptime1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_texttriptime1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_texttriptime1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_texttriptime1, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_texttriptime1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_texttriptime1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_texttriptime1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_texttriptime1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelTime1

    ui_LabelTime1 = lv_label_create(ui_PanelDetail1);

    lv_obj_set_width(ui_LabelTime1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelTime1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelTime1, 58);
    lv_obj_set_y(ui_LabelTime1, -40);

    lv_obj_set_align(ui_LabelTime1, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelTime1, "TripTime");

    lv_obj_clear_flag(ui_LabelTime1, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_LabelTime1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTime1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTime1, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_texttrip1

    ui_texttrip1 = lv_textarea_create(ui_PanelDetail1);

    lv_obj_set_width(ui_texttrip1, 81);
    lv_obj_set_height(ui_texttrip1, 47);

    lv_obj_set_x(ui_texttrip1, -53);
    lv_obj_set_y(ui_texttrip1, -15);

    lv_obj_set_align(ui_texttrip1, LV_ALIGN_CENTER);

    // if("" == "") lv_textarea_set_accepted_chars(ui_texttrip1, NULL);
    //lv_textarea_set_accepted_chars(ui_texttrip1, "");

    lv_textarea_set_max_length(ui_texttrip1, 5);
    lv_textarea_set_text(ui_texttrip1, "8.12");
    lv_textarea_set_placeholder_text(ui_texttrip1, "Placeholder...");
    lv_textarea_set_one_line(ui_texttrip1, true);

    lv_obj_clear_flag(ui_texttrip1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_texttrip1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_texttrip1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_texttrip1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_texttrip1, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_texttrip1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_texttrip1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_texttrip1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_texttrip1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelTrip1

    ui_LabelTrip1 = lv_label_create(ui_PanelDetail1);

    lv_obj_set_width(ui_LabelTrip1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelTrip1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelTrip1, -56);
    lv_obj_set_y(ui_LabelTrip1, -40);

    lv_obj_set_align(ui_LabelTrip1, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelTrip1, "Trip(km)");

    lv_obj_clear_flag(ui_LabelTrip1, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_LabelTrip1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTrip1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTrip1, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_texttotal1

    ui_texttotal1 = lv_textarea_create(ui_PanelDetail1);

    lv_obj_set_width(ui_texttotal1, 81);
    lv_obj_set_height(ui_texttotal1, 47);

    lv_obj_set_x(ui_texttotal1, -52);
    lv_obj_set_y(ui_texttotal1, 35);

    lv_obj_set_align(ui_texttotal1, LV_ALIGN_CENTER);

    // if("" == "") lv_textarea_set_accepted_chars(ui_texttotal1, NULL);
    //lv_textarea_set_accepted_chars(ui_texttotal1, "");

    lv_textarea_set_max_length(ui_texttotal1, 5);
    lv_textarea_set_text(ui_texttotal1, "123.4");
    lv_textarea_set_placeholder_text(ui_texttotal1, "Placeholder...");
    lv_textarea_set_one_line(ui_texttotal1, true);

    lv_obj_clear_flag(ui_texttotal1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_texttotal1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_texttotal1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_texttotal1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_texttotal1, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_texttotal1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_texttotal1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_texttotal1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_texttotal1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelTotal1

    ui_LabelTotal1 = lv_label_create(ui_PanelDetail1);

    lv_obj_set_width(ui_LabelTotal1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelTotal1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelTotal1, -56);
    lv_obj_set_y(ui_LabelTotal1, 10);

    lv_obj_set_align(ui_LabelTotal1, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelTotal1, "Total(km)");

    lv_obj_clear_flag(ui_LabelTotal1, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_LabelTotal1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTotal1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTotal1, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_textwenshi1

    ui_textwenshi1 = lv_textarea_create(ui_PanelDetail1);

    lv_obj_set_width(ui_textwenshi1, 115);
    lv_obj_set_height(ui_textwenshi1, 47);

    lv_obj_set_x(ui_textwenshi1, 58);
    lv_obj_set_y(ui_textwenshi1, 36);

    lv_obj_set_align(ui_textwenshi1, LV_ALIGN_CENTER);

    // if("" == "") lv_textarea_set_accepted_chars(ui_textwenshi1, NULL);
    //lv_textarea_set_accepted_chars(ui_textwenshi1, "");

    lv_textarea_set_max_length(ui_textwenshi1, 8);
    lv_textarea_set_text(ui_textwenshi1, "30C 65%");
    lv_textarea_set_placeholder_text(ui_textwenshi1, "Placeholder...");
    lv_textarea_set_one_line(ui_textwenshi1, true);

    lv_obj_clear_flag(ui_textwenshi1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_textwenshi1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_textwenshi1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_textwenshi1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_textwenshi1, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_textwenshi1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_textwenshi1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_textwenshi1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_textwenshi1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelWenShi1

    ui_LabelWenShi1 = lv_label_create(ui_PanelDetail1);

    lv_obj_set_width(ui_LabelWenShi1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelWenShi1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelWenShi1, 56);
    lv_obj_set_y(ui_LabelWenShi1, 10);

    lv_obj_set_align(ui_LabelWenShi1, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelWenShi1, "T&H");

    lv_obj_clear_flag(ui_LabelWenShi1, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_LabelWenShi1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelWenShi1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelWenShi1, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_PanelBattery1

    ui_PanelBattery1 = lv_obj_create(ui_Screen2);

    lv_obj_set_width(ui_PanelBattery1, 240);
    lv_obj_set_height(ui_PanelBattery1, 50);

    lv_obj_set_x(ui_PanelBattery1, 0);
    lv_obj_set_y(ui_PanelBattery1, 0);

    lv_obj_set_align(ui_PanelBattery1, LV_ALIGN_BOTTOM_MID);

    lv_obj_clear_flag(ui_PanelBattery1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_radius(ui_PanelBattery1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelBattery1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelBattery1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelBattery1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelBattery1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_BatteryPositive1

    ui_BatteryPositive1 = lv_img_create(ui_PanelBattery1);
    lv_img_set_src(ui_BatteryPositive1, &ui_img_1_png);

    lv_obj_set_width(ui_BatteryPositive1, 9);
    lv_obj_set_height(ui_BatteryPositive1, 27);

    lv_obj_set_x(ui_BatteryPositive1, 12);
    lv_obj_set_y(ui_BatteryPositive1, 3);

    lv_obj_set_align(ui_BatteryPositive1, LV_ALIGN_BOTTOM_RIGHT);

    lv_obj_clear_flag(ui_BatteryPositive1,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_img_recolor(ui_BatteryPositive1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_BatteryPositive1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_barbattery1

    ui_barbattery1 = lv_bar_create(ui_PanelBattery1);
    lv_bar_set_range(ui_barbattery1, 0, 100);
    lv_bar_set_value(ui_barbattery1, 25, LV_ANIM_OFF);

    lv_obj_set_width(ui_barbattery1, 215);
    lv_obj_set_height(ui_barbattery1, 40);

    lv_obj_set_x(ui_barbattery1, -2);
    lv_obj_set_y(ui_barbattery1, 0);

    lv_obj_set_align(ui_barbattery1, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_barbattery1, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE);

    lv_obj_set_style_radius(ui_barbattery1, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_barbattery1, lv_color_hex(0xBFE3F0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_barbattery1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_barbattery1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_barbattery1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_barbattery1, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_barbattery1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_barbattery1, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_barbattery1, lv_color_hex(0xFF0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_barbattery1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_textleft1

    ui_textleft1 = lv_textarea_create(ui_PanelBattery1);

    lv_obj_set_width(ui_textleft1, 91);
    lv_obj_set_height(ui_textleft1, 47);

    lv_obj_set_x(ui_textleft1, 7);
    lv_obj_set_y(ui_textleft1, 0);

    lv_obj_set_align(ui_textleft1, LV_ALIGN_CENTER);

    // if("" == "") lv_textarea_set_accepted_chars(ui_textleft1, NULL);
    //lv_textarea_set_accepted_chars(ui_textleft1, "");

    lv_textarea_set_max_length(ui_textleft1, 4);
    lv_textarea_set_text(ui_textleft1, "50KM");
    lv_textarea_set_placeholder_text(ui_textleft1, "Placeholder...");
    lv_textarea_set_one_line(ui_textleft1, true);

    lv_obj_clear_flag(ui_textleft1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_textleft1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_textleft1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_textleft1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_textleft1, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_textleft1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_textleft1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_textleft1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_textleft1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_textleft1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_textleft1, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_textleft1, lv_color_hex(0x000000), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_textleft1, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_textleft1, lv_color_hex(0x000000), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_textleft1, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_textleft1, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui_Screen2_screen_init();
    lv_disp_load_scr(ui_Screen1);
}

    