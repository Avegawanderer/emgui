#ifndef __LCD_CONFIG_H_
#define __LCD_CONFIG_H_

#include "stdint.h"
#include "lcd_font_typedef.h"

// Values are arbitrary
#define LCD_LIB_COLOR_RGB233    0
#define LCD_LIB_COLOR_RGB565    1
#define LCD_LIB_COLOR_RGB888    2
#define LCD_LIB_MONOCHROME      255


// Mandatory
typedef uint8_t color_t;
#define LCD_LIB_COLOR_MODE  LCD_LIB_MONOCHROME
#define colorFromRgb(red, green, blue) ( (red | green | blue) ? 0x00 : 0xFF )


// Screen size definitions in pixels
#define LCD_XSIZE 240
#define LCD_YSIZE 120

// Buffer size in bytes (1 byte = 8 pixels, just like regular Nokia 3310 display)
#define LCD_BUFFER_SIZE (LCD_XSIZE  *LCD_YSIZE / 8)

// LCD functions settings
//#define SOFT_HORIZ_REVERSED






// Dashed and dotted line style settings
// Counter increments from 0 to LCD_xxx_PERIOD-1
// if counter < LCD_xxx_COMPARE, pixel is put unchaged
// if counter >= LCD_xxx_COMPARE, pixel is put inversed
#define LCD_DOT_PERIOD      4
#define LCD_DOT_COMPARE     2
#define LCD_DASH_PERIOD     7
#define LCD_DASH_COMPARE    5



// Default functions for LCD library
#define LcdLibConfig_UseDefaultPutPixel			0
#define LcdLibConfig_UseDefaultGetPixel			0
#define LcdLibConfig_UseDefaultDrawHorLine		1
#define LcdLibConfig_UseDefaultDrawVertLine		1
#define LcdLibConfig_UseDefaultDrawRectP		1
#define LcdLibConfig_UseDefaultFillRectP		1
#define LcdLibConfig_UseDefaultDrawPackedImage  1





// Buffer
#define lcdBuffer guiLcdBuffer
extern uint8_t guiLcdBuffer[];



#endif //__LCD_CONFIG_H_
