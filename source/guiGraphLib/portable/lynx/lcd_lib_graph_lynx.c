

#include "lcd_lib.h"
#include "lcd_lib_private.h"
#include "core_utils.h"




#if LcdLibConfig_UseDefaultPutPixel == 0


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
    
	__write_u16(((uint32_t)lcdBuffer << 1) + bufferOffset, color);
    
#elif LCD_LIB_COLOR_MODE == LCD_LIB_COLOR_RGB233
	
	__write_u8(((uint32_t)lcdBuffer << 2) + bufferOffset, color);

#endif
	
}

#endif








#if 0
//-------------------------------------------------------//
// Fills a rectangle with fillColor
//-------------------------------------------------------//
void LCD_FillRect(rect_t* rect)
{
	uint32_t buffer_offset_start;
	uint32_t buffer_index;
	uint16_t width;
    uint16_t height = rect->y2 - rect->y1 + 1;
	uint32_t temp;
	
    buffer_offset_start = rect->y1 * LCD_XSIZE + rect->x1;
    // Wrap buffer
    if (buffer_offset_start >= (LCD_XSIZE * LCD_YSIZE))
        buffer_offset_start %= (LCD_XSIZE * LCD_YSIZE);

	while(height)
	{
		buffer_index = buffer_offset_start / 2;
        width = rect->x2 - rect->x1 + 1;
		// Prepare
        if (width & 0x01)
		{
            temp = lcdBuffer[buffer_index];
			temp &= 0x0000FFFF;
			temp |= (uint32_t)fillColor << 16;;
            lcdBuffer[buffer_index] = temp;
			width--;
            buffer_index++;
		}
		// Main fill loop
        while(width >= 2)
		{
			lcdBuffer[buffer_index++] = ((uint32_t)fillColor << 16) | (fillColor);
			width-=2;
		}
		// Finish
		if (width)
		{
			temp = lcdBuffer[buffer_index];
			temp &= 0xFFFF0000;
			temp |= (uint16_t)fillColor;
			lcdBuffer[buffer_index] = temp;
		}
		height--;
		buffer_offset_start += LCD_XSIZE;
	}
	
	

}




//-------------------------------------------------------//
// Draws vertical line with penColor
//-------------------------------------------------------//
void LCD_DrawVertLine(uint16_t x, uint16_t y, int16_t length)
{
    uint8_t dashCompare;
    uint8_t dashPeriod;
    uint8_t dashCounter = 0;
    int32_t buffer_index_increment;
    uint32_t clear_mask;
    uint32_t color_mask;
    uint32_t buffer_index;
    uint32_t temp;

    buffer_index = y * LCD_XSIZE + x;
    // Wrap buffer
    if (buffer_index >= (LCD_XSIZE * LCD_YSIZE))
        buffer_index %= (LCD_XSIZE * LCD_YSIZE);

    if (buffer_index & 0x01)
    {
        clear_mask = 0x0000FFFF;
        color_mask = (uint16_t)penColor << 16;
    }
    else
    {
        clear_mask = 0xFFFF0000;
        color_mask = (uint16_t)penColor;
    }
    buffer_index /= 2;

    if (length > 0)
    {
        buffer_index_increment = LCD_XSIZE / 2;
    }
    else
    {
        length = -length;
        buffer_index_increment = -LCD_XSIZE / 2;
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
        {
            //LCD_PutPixel(x,y,penColor);
            temp = lcdBuffer[buffer_index];
            temp &= clear_mask;
            temp |= color_mask;
            lcdBuffer[buffer_index] = temp;
        }

        buffer_index += buffer_index_increment;
        dashCounter++;
        if (dashCounter == dashPeriod)
            dashCounter = 0;
    }
}
#endif


