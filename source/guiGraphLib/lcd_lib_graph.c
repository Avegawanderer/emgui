/********************************************************************
	
	LCD library graphical functions
	
	There may exist more efficient platform-specific implementations
	of some functions - set LcdLibConfig_UseDefaultXXX to 0 and
	implement them in other source file

	LcdLibConfig_UseDefaultXXX are defined in LCD library config file
	
********************************************************************/



#include "lcd_lib.h"
#include "lcd_lib_private.h"


//=================================================================//
// Pixel operations
//
//=================================================================//


#if LcdLibConfig_UseDefaultPutPixel == 1
void LCD_PutPixel(uint16_t x, uint16_t y, color_t color)
{
	uint32_t bufferOffset = y;
    uint8_t shiftb;
    uint32_t temp;
	bufferOffset *= LCD_XSIZE;
	bufferOffset += x;
    // Wrap buffer
    if (bufferOffset >= (LCD_XSIZE * LCD_YSIZE))
        bufferOffset %= (LCD_XSIZE * LCD_YSIZE);
#if LCD_LIB_COLOR_MODE == LCD_LIB_COLOR_RGB888
    lcdBuffer[bufferOffset] = (uint32_t)color;
#elif LCD_LIB_COLOR_MODE == LCD_LIB_COLOR_RGB565
    shiftb = (bufferOffset & 0x01) ? 16 : 0;
    bufferOffset >>= 1;
    temp = lcdBuffer[bufferOffset];
    temp &= ~(0x0000FFFF << shiftb);
    temp |= (uint32_t)color << shiftb;
    lcdBuffer[bufferOffset] = temp;
#elif LCD_LIB_COLOR_MODE == LCD_LIB_COLOR_RGB233
	shiftb = (bufferOffset & 0x03) << 3;
    bufferOffset >>= 2;
    temp = lcdBuffer[bufferOffset];
    temp &= ~(0x000000FF << shiftb);
    temp |= (uint32_t)color << shiftb;
    lcdBuffer[bufferOffset] = temp;
#endif
}
#endif //LcdLibConfig_UseDefaultPutPixel


#if LcdLibConfig_UseDefaultGetPixel == 1
color_t LCD_GetPixel(uint16_t x, uint16_t y)
{
	uint32_t bufferOffset = y;
    uint8_t shiftb;
    uint32_t temp;
	bufferOffset *= LCD_XSIZE;
	bufferOffset += x;
    // Wrap buffer
    if (bufferOffset >= (LCD_XSIZE * LCD_YSIZE))
        bufferOffset %= (LCD_XSIZE * LCD_YSIZE);

#if LCD_LIB_COLOR_MODE == LCD_LIB_COLOR_RGB888
    temp = lcdBuffer[bufferOffset];
#elif LCD_LIB_COLOR_MODE == LCD_LIB_COLOR_RGB565
    shiftb = (bufferOffset & 0x01) ? 16 : 0;
    bufferOffset >>= 1;
    temp = lcdBuffer[bufferOffset];
    temp >>= shiftb;
    temp &= 0x0000FFFF;
#elif LCD_LIB_COLOR_MODE == LCD_LIB_COLOR_RGB233
	shiftb = (bufferOffset & 0x03) << 3;
    bufferOffset >>= 2;
    temp = lcdBuffer[bufferOffset];
    temp >>= shiftb;
    temp &= 0x000000FF;
    lcdBuffer[bufferOffset] = temp;
#endif    
    return (color_t)temp;
}
#endif //LcdLibConfig_UseDefaultGetPixel




//=================================================================//
// Graph primitives
//
//=================================================================//



//-------------------------------------------------------//
// Draws horizontal line with penColor
//
//-------------------------------------------------------//
#if LcdLibConfig_UseDefaultDrawHorLine == 1
void LCD_DrawHorLine(uint16_t x, uint16_t y, uint16_t length)
{
    uint8_t dashCompare;
    uint8_t dashPeriod;
    uint8_t dashCounter = 0;

    switch(lineStyle)
    {
        case LINE_STYLE_DASHED:
            dashPeriod = LCD_DASH_PERIOD;
            dashCompare = LCD_DASH_COMPARE;
            break;
        case LINE_STYLE_DOTTED:
            dashPeriod = LCD_DOT_PERIOD;
            dashCompare = LCD_DOT_COMPARE;
            break;
         default: //LINE_STYLE_SOLID:
            dashPeriod = 10;
            dashCompare = 10;   // arbitrary, but >= dashPeriod
            break;
    }

    while(length--)
    {
        if (dashCounter < dashCompare)
            LCD_PutPixel(x,y,penColor);

        x++;
        dashCounter++;
        if (dashCounter == dashPeriod)
            dashCounter = 0;
    }
}
#endif //LcdLibConfig_UseDefaultDrawHorLine


//-------------------------------------------------------//
// Draws vertical line with penColor
//
//-------------------------------------------------------//
#if LcdLibConfig_UseDefaultDrawVertLine == 1
void LCD_DrawVertLine(uint16_t x, uint16_t y, int16_t length)
{
    uint8_t dashCompare;
    uint8_t dashPeriod;
    uint8_t dashCounter = 0;
    int16_t y_increment;

    if (length < 0)
    {
        length = -length;
        y_increment = -1;
    }
    else
    {
        y_increment = 1;
    }

    switch(lineStyle)
    {
        case LINE_STYLE_DASHED:
            dashPeriod = LCD_DASH_PERIOD;
            dashCompare = LCD_DASH_COMPARE;
            break;
        case LINE_STYLE_DOTTED:
            dashPeriod = LCD_DOT_PERIOD;
            dashCompare = LCD_DOT_COMPARE;
            break;
         default: //LINE_STYLE_SOLID:
            dashPeriod = 10;
            dashCompare = 10;   // arbitrary, but >= dashPeriod
            break;
    }

    while(length--)
    {
        if (dashCounter < dashCompare)
            LCD_PutPixel(x,y,penColor);

        y += y_increment;
        dashCounter++;
        if (dashCounter == dashPeriod)
            dashCounter = 0;
    }
}
#endif //LcdLibConfig_UseDefaultDrawVertLine


//-------------------------------------------------------//
// Draws rectangle line with penColor
//
//-------------------------------------------------------//
#if LcdLibConfig_UseDefaultDrawRectP == 1
void LCD_DrawRectP(int16_t x1, int16_t y1, int16_t x2, int16_t y2)
{
    uint16_t width, height;
    if ((x1 > x2) || (y1 > y2))
        return;
    width = x2 - x1 + 1;
    height = y2 - y1 + 1;
    LCD_DrawVertLine(x1,y1,height);
    LCD_DrawVertLine(x2,y1,height);
    LCD_DrawHorLine(x1,y1,width);
    LCD_DrawHorLine(x1,y2,width);
}
#endif //LcdLibConfig_UseDefaultDrawRectP


//-------------------------------------------------------//
// Fills a rectangle with fillColor
//
//-------------------------------------------------------//
#if LcdLibConfig_UseDefaultFillRectP == 1
void LCD_FillRectP(int16_t x1, int16_t y1, int16_t x2, int16_t y2)
{
	uint16_t x,y;
	for (y=y1; y<=y2; y++)
    	for (x=x1; x<=x2; x++)
            LCD_PutPixel(x,y,fillColor);
}
#endif


//-------------------------------------------------------//
// Draws rectangle line with penColor
//
//-------------------------------------------------------//
void LCD_DrawRect(rect_t *rect)
{
    LCD_DrawRectP(rect->x1, rect->y1, rect->x2, rect->y2);
}


//-------------------------------------------------------//
// Fills a rectangle with fillColor
//
//-------------------------------------------------------//
void LCD_FillRect(rect_t* rect)
{
    LCD_FillRectP(rect->x1, rect->y1, rect->x2, rect->y2);
}





//=================================================================//
// Graph primitives - generic
//
//=================================================================//


//-------------------------------------------------------//
// Draws arbitrary line
//
//-------------------------------------------------------//
void LCD_DrawLine(int16_t x1, int16_t y1, int16_t x2, int16_t y2)
{
    int16_t dy = 0;
    int16_t dx = 0;
    int16_t stepx = 0;
    int16_t stepy = 0;
    int16_t fraction = 0;

//       if (x1>LCD_X_RES || x2>LCD_X_RES || y1>LCD_Y_RES || y2>LCD_Y_RES) return;

    dy = y2 - y1;
    dx = x2 - x1;
    if (dy < 0)
    {
        dy = -dy;
        stepy = -1;
    }
    else stepy = 1;
    if (dx < 0)
    {
        dx = -dx;
        stepx = -1;
    }
    else stepx = 1;
    dy <<= 1;
    dx <<= 1;
    LCD_PutPixel(x1,y1,penColor);
    if (dx > dy)
    {
        fraction = dy - (dx >> 1);
        while (x1 != x2)
        {
            if (fraction >= 0)
            {
                y1 += stepy;
                fraction -= dx;
            }
            x1 += stepx;
            fraction += dy;
            LCD_PutPixel(x1,y1,penColor);
        }
    }
    else
    {
        fraction = dx - (dy >> 1);
        while (y1 != y2)
        {
            if (fraction >= 0)
            {
                x1 += stepx;
                fraction -= dy;
            }
            y1 += stepy;
            fraction += dx;
            LCD_PutPixel(x1,y1,penColor);
        }
    }
}


//-------------------------------------------------------//
// Draws circle
//
//-------------------------------------------------------//
void LCD_DrawCircle(int16_t x0, int16_t y0, int16_t radius)
{
    int16_t x = radius;
    int16_t y = 0;
    int16_t xChange = 1 - (radius << 1);
    int16_t yChange = 0;
    int16_t radiusError = 0;

    while (x >= y)
    {
        LCD_PutPixel(x0 - x, y0 + y, penColor);
        LCD_PutPixel(x0 + x, y0 + y, penColor);
        LCD_PutPixel(x0 - x, y0 - y, penColor);
        LCD_PutPixel(x0 + x, y0 - y, penColor);

        LCD_PutPixel(x0 - y, y0 + x, penColor);
        LCD_PutPixel(x0 + y, y0 + x, penColor);
        LCD_PutPixel(x0 - y, y0 - x, penColor);
        LCD_PutPixel(x0 + y, y0 - x, penColor);

        y++;
        radiusError += yChange;
        yChange += 2;
        if (((radiusError << 1) + xChange) > 0)
        {
            x--;
            radiusError += xChange;
            xChange += 2;
        }
    }
}


//-------------------------------------------------------//
// Draws filled circle
//
//-------------------------------------------------------//
void LCD_DrawFilledCircle(int16_t x0, int16_t y0, int16_t radius)
{
    int16_t x = radius;
    int16_t y = 0;
    int16_t xChange = 1 - (radius << 1);
    int16_t yChange = 0;
    int16_t radiusError = 0;
    int16_t i;

    while (x >= y)
    {
        for (i = x0 - x; i <= x0 + x; i++)
        {
            LCD_PutPixel(i, y0 + y, fillColor);
            LCD_PutPixel(i, y0 - y, fillColor);
        }
        for (i = x0 - y; i <= x0 + y; i++)
        {
            LCD_PutPixel(i, y0 + x, fillColor);
            LCD_PutPixel(i, y0 - x, fillColor);
        }

        y++;
        radiusError += yChange;
        yChange += 2;
        if (((radiusError << 1) + xChange) > 0)
        {
            x--;
            radiusError += xChange;
            xChange += 2;
        }
    }
}




