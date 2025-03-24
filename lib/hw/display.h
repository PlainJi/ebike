#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#ifdef __cplusplus
extern "C" {
#endif

void display_init();
void setBrightness(unsigned char value);
void lvgl_init();

#ifdef __cplusplus
}
#endif

#endif