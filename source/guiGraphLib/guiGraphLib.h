/*
	This file contains definitions for external graphic library

	This file is library-specific

*/

#ifndef __GUI_GRAPH_LIB_H_
#define __GUI_GRAPH_LIB_H_


#include "lcd_lib.h"

/*
#ifndef rect_t
	typedef struct {
	    int16_t x1;
	    int16_t y1;
	    int16_t x2;
	    int16_t y2;
	} rect_t;
#endif

#ifndef point_t
	typedef struct {
	    int16_t x1;
	    int16_t y1;
	    int16_t x2;
	    int16_t y2;
	} point_t;
#endif




// External functions

extern void LCD_PutPixel(uint16_t x, uint16_t y, color_t color);
extern color_t LCD_GetPixel(uint16_t x, uint16_t y);
extern void LCD_SetFont(const tFont *newFont);
extern void LCD_SetPenColor(const color_t newColor);
extern void LCD_SetAltPenColor(const color_t newColor);
extern void LCD_SetFillColor(const color_t newColor);
extern void LCD_SetImageOutput(uint8_t newMode);
extern void LCD_SetLineStyle(uint8_t newStyle);
extern void LCD_FillRect(rect_t* rect);
extern void LCD_DrawHorLine(uint16_t x, uint16_t y, uint16_t length);
extern void LCD_DrawVertLine(uint16_t x, uint16_t y, uint16_t length);
extern void LCD_DrawRect(rect_t *rect);
extern void LCD_drawPackedImage(const uint8_t *img, uint16_t x_pos, uint16_t y_pos, uint16_t img_width, uint16_t img_height);
extern void LCD_PrintString(char *str, uint8_t x, uint8_t y);
extern void LCD_PrintStringAligned(char *str, rect_t *rect, uint8_t alignment);
extern void LCD_DrawLine(int16_t x1, int16_t y1, int16_t x2, int16_t y2);
extern void LCD_DrawCircle(int16_t x0, int16_t y0, int16_t radius);
extern void LCD_DrawFilledCircle(int16_t x0, int16_t y0, int16_t radius);
*/



#endif	// __GUI_GRAPH_PORT_H_
