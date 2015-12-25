
#include "lcd_lib.h"
#include "lcd_lib_private.h"


color_t penColor;             // Pen is used for drawing lines, frames, circles, etc
color_t altPenColor;          //
color_t fillColor;            // Used for filling objects
const tFont* currentFont;     // Font that currently used
uint8_t imageOutputMode;       // Specifies text background - OUTPUT_MODE_TRANSPARENT or OUTPUT_MODE_SOLID
uint8_t lineStyle;


const tFont* currentFont;


//-------------------------------------------------------//
// Sets current font for text printing
//-------------------------------------------------------//
void LCD_SetFont(const tFont *newFont)
{
    currentFont = newFont;
}

//-------------------------------------------------------//
// Sets pen color
//-------------------------------------------------------//
void LCD_SetPenColor(const color_t newColor)
{
    penColor = newColor;
}

//-------------------------------------------------------//
// Sets alternate pen color
//-------------------------------------------------------//
void LCD_SetAltPenColor(const color_t newColor)
{
    altPenColor = newColor;
}

//-------------------------------------------------------//
// Sets filling color
//-------------------------------------------------------//
void LCD_SetFillColor(const color_t newColor)
{
    fillColor = newColor;
}

//-------------------------------------------------------//
// Sets image output mode
//-------------------------------------------------------//
void LCD_SetImageOutputMode(uint8_t newMode)
{
    imageOutputMode = newMode & (IMAGE_PAINT_SET_PIXELS | IMAGE_PAINT_VOID_PIXELS);
}

//-------------------------------------------------------//
// Sets line style
//-------------------------------------------------------//
void LCD_SetLineStyle(uint8_t newStyle)
{
    lineStyle = newStyle;
}


