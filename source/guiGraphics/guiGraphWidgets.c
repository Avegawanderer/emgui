/**********************************************************
  Module guiGraphWidgets contains functions for drawing widgets. (hi, Cap!)



**********************************************************/

#include <stdint.h>
#include "guiConfig.h"
#include "guiGraphWidgets.h"
#include "guiGraphLib.h"
#include "guiWidgets.h"



int16_t wx;
int16_t wy;

#ifdef emGUI_COLORED
const color_t colorPalette1[COLOR_PALETTE_SIZE] = {

#if 1
    //  WIN32 boring grey style
    colorFromRgb(210,210,210),      // COLOR_INDEX_WIDGET_BACKGROUND
    colorFromRgb(220,220,220),      // COLOR_INDEX_BUTTON_BACKGROUND
    colorFromRgb(240,240,240),      // COLOR_INDEX_3DFRAME_LIGHT1
    colorFromRgb(200,200,200),      // COLOR_INDEX_3DFRAME_LIGHT2
    colorFromRgb(100,100,100),      // COLOR_INDEX_3DFRAME_DARK1
    colorFromRgb(150,150,150),      // COLOR_INDEX_3DFRAME_DARK2
    colorFromRgb(0,0,0),            // COLOR_INDEX_FOCUS_FRAME
    colorFromRgb(0,0,0),            // COLOR_INDEX_TEXT_ACTIVE
#else
    // Dark-orange
    colorFromRgb(0,0,0),            // COLOR_INDEX_WIDGET_BACKGROUND
    colorFromRgb(0xDE,0x8D,0x31),   // COLOR_INDEX_BUTTON_BACKGROUND
    colorFromRgb(0xFF,0xA1,0x36),   // COLOR_INDEX_3DFRAME_LIGHT1
    colorFromRgb(0xC9,0x82,0x30),   // COLOR_INDEX_3DFRAME_LIGHT2
    colorFromRgb(0x69,0x47,0x21),   // COLOR_INDEX_3DFRAME_DARK1
    colorFromRgb(0x7A,0x51,0x22),   // COLOR_INDEX_3DFRAME_DARK2
    colorFromRgb(200,200,0),        // COLOR_INDEX_FOCUS_FRAME
    colorFromRgb(255,255,255),      // COLOR_INDEX_TEXT_ACTIVE
#endif
};

color_t *colorPalette = (color_t *)colorPalette1;
#endif //emGUI_COLORED



//-------------------------------------------------------//
// Sets point (0,0) of coordinate system
// Parameters x and y must be absolute values
// Widget's geometry is relative to (wx,wy)
//-------------------------------------------------------//
void guiGraph_SetBaseXY(int16_t x, int16_t y)
{
    wx = x;
    wy = y;
}

//-------------------------------------------------------//
// Sets point (0,0) of coordinate system
//-------------------------------------------------------//
void guiGraph_OffsetBaseXY(int16_t dx, int16_t dy)
{
    wx += dx;
    wy += dy;
}


#ifdef emGUI_COLORED

//-------------------------------------------------------//
// Draws nice 3-D frame
// Line style is set to SOLID
//-------------------------------------------------------//
void guiGraph_Draw3DFrame(rect_t *rect, uint8_t frameState)
{
    uint8_t c1,c2,c3,c4;
    switch (frameState)
    {
        case FRAME3D_SUNKEN:
            c1 = COLOR_INDEX_3DFRAME_DARK2;
            c2 = COLOR_INDEX_3DFRAME_DARK1;
            c3 = COLOR_INDEX_3DFRAME_LIGHT1;
            c4 = COLOR_INDEX_3DFRAME_LIGHT2;
            break;
        default:        // Raised
            c1 = COLOR_INDEX_3DFRAME_LIGHT1;
            c2 = COLOR_INDEX_3DFRAME_LIGHT2;
            c3 = COLOR_INDEX_3DFRAME_DARK1;
            c4 = COLOR_INDEX_3DFRAME_DARK2;
    }

    LCD_SetLineStyle(LINE_STYLE_SOLID);
    LCD_SetPenMode(PEN_SOLID);

    // top, left
    LCD_SetPenColor(colorPalette1[c1]);
    LCD_DrawHorLine(rect->x1, rect->y1, rect->x2 - rect->x1);
    LCD_DrawVertLine(rect->x1, rect->y1 + 1, rect->y2 - rect->y1 - 1);

    LCD_SetPenColor(colorPalette1[c2]);
    LCD_DrawHorLine(rect->x1 + 1, rect->y1 + 1, rect->x2 - rect->x1 - 2);
    LCD_DrawVertLine(rect->x1 + 1, rect->y1 + 2, rect->y2 - rect->y1 - 3);

    // bottom, right
    LCD_SetPenColor(colorPalette1[c3]);
    LCD_DrawHorLine(rect->x1, rect->y2, rect->x2 - rect->x1 + 1);
    LCD_DrawVertLine(rect->x2, rect->y1, rect->y2 - rect->y1);

    LCD_SetPenColor(colorPalette1[c4]);
    LCD_DrawHorLine(rect->x1 + 1, rect->y2 - 1, rect->x2 - rect->x1 - 1);
    LCD_DrawVertLine(rect->x2 - 1, rect->y1 + 1, rect->y2 - rect->y1 - 1);
}




#endif //emGUI_COLORED





#ifdef emGUI_MONOCHROME


#endif //emGUI_MONOCHROME








