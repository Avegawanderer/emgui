#ifndef __GUI_GRAPH_HAL_
#define __GUI_GRAPH_HAL_

#include <stdint.h>


// Size definitions in points
#define LCD_XSIZE 320
#define LCD_YSIZE 240


typedef uint32_t color_t;

#define colorFromRgb(red, green, blue) ((uint32_t)red | ((uint32_t)green << 8) | ((uint32_t)blue << 16))
#define CL_WHITE colorFromRgb(255,255,255)
#define CL_BLACK colorFromRgb(0,0,0)
#define CL_RED colorFromRgb(255,0,0)
#define CL_GREEN colorFromRgb(0,255,0)
#define CL_BLUE colorFromRgb(0,0,255)
#define CL_YELLOW colorFromRgb(255,255,0)

extern color_t guiLcdBuffer[];

void guiGraph_putPixel(uint16_t x, uint16_t y, color_t color);
color_t guiGraph_getPixel(uint16_t x, uint16_t y);






#endif
