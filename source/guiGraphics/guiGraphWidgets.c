/**********************************************************
  Module guiGraphWidgets contains functions for drawing widgets. (hi, Cap!)



**********************************************************/

#include <stdint.h>
#include "guiConfig.h"
#include "guiGraphWidgets.h"
#include "guiGraphLib.h"
#include "guiGraphImages.h"
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





//-------------------------------------------------------//
// Draw a textLabel
//
//
//-------------------------------------------------------//
void guiGraph_DrawTextLabel(guiTextLabel_t *textLabel)
{
    rect_t rect1;

    rect1.x1 = wx;
    rect1.x2 = wx + textLabel->width - 1;
    rect1.y1 = wy;
    rect1.y2 = wy + textLabel->height - 1;

    if ( ((textLabel->redrawForced) || (textLabel->redrawFocus)) &&
         (textLabel->showFocus))
    {
        if (textLabel->isFocused)
        {
            LCD_SetLineStyle(LINE_STYLE_DOTTED);
            LCD_SetPenColor(colorPalette[COLOR_INDEX_FOCUS_FRAME]);
        }
        else
        {
            LCD_SetLineStyle(LINE_STYLE_SOLID);
            if (textLabel->hasFrame)
                 LCD_SetPenColor(CL_GREEN); // FIXME
            else
                 LCD_SetPenColor(colorPalette[COLOR_INDEX_WIDGET_BACKGROUND]);
        }
        LCD_DrawRect(&rect1);
    }

   if (textLabel->redrawForced)
   {
       // Erase rectangle
       LCD_SetFillColor(colorPalette1[COLOR_INDEX_WIDGET_BACKGROUND]);
       rect1.x1 = wx + 1;
       rect1.x2 = wx  + textLabel->width - 2;
       rect1.y1 = wy + 1;
       rect1.y2 = wy + textLabel->height - 2;
       LCD_FillRect(&rect1);

       // Draw string
       if ((textLabel->text) && (textLabel->font))
       {
           LCD_SetFont(textLabel->font);
           LCD_SetPenColor(colorPalette1[COLOR_INDEX_TEXT_ACTIVE]);
           rect1.x1 = wx + 1 + TEXT_LABEL_TEXT_MARGIN;
           rect1.y1 = wy + 1;
           rect1.x2 = wx + textLabel->width - 2 - TEXT_LABEL_TEXT_MARGIN;
           rect1.y2 = wy + textLabel->height - 2;
           LCD_PrintStringAligned(textLabel->text, &rect1, textLabel->textAlignment);
       }
   }
}



void guiGraph_DrawButton(guiButton_t *button)
{
    rect_t rect1;
    rect1.x1 = wx + 2;
    rect1.x2 = wx + button->width - 3;
    rect1.y1 = wy + 2;
    rect1.y2 = wy + button->height - 3;


    if (button->redrawForced)
    {
        LCD_SetFillColor(colorPalette1[COLOR_INDEX_BUTTON_BACKGROUND]);
        LCD_FillRect(&rect1);
        LCD_SetFont(button->font);
        LCD_SetAltPenMode(PEN_TRANSPARENT);
        LCD_SetPen(PEN_SOLID, colorPalette1[COLOR_INDEX_TEXT_ACTIVE]);
        LCD_PrintStringAligned(button->text, &rect1, button->textAlignment);
    }

    if ((button->redrawForced) || (button->redrawFocus))
    {
        if (button->isFocused)
        {
            LCD_SetPen(PEN_SOLID, colorPalette[COLOR_INDEX_FOCUS_FRAME]);
            LCD_SetAltPen(PEN_SOLID, colorPalette[COLOR_INDEX_BUTTON_BACKGROUND]);
            LCD_SetLineStyle(LINE_STYLE_DOTTED);
        }
        else
        {
            LCD_SetPen(PEN_SOLID, colorPalette[COLOR_INDEX_BUTTON_BACKGROUND]);
            LCD_SetLineStyle(LINE_STYLE_SOLID);
        }

        rect1.x1 = wx + BUTTON_FOCUS_RECT_MARGIN;
        rect1.x2 = wx + button->width - 1 - BUTTON_FOCUS_RECT_MARGIN;
        rect1.y1 = wy + BUTTON_FOCUS_RECT_MARGIN;
        rect1.y2 = wy + button->height - 1 - BUTTON_FOCUS_RECT_MARGIN;
        LCD_DrawRect(&rect1);
    }

    if ((button->redrawForced) || (button->redrawPressedState))
    {
        rect1.x1 = wx;
        rect1.x2 = wx + button->width - 1;
        rect1.y1 = wy;
        rect1.y2 = wy + button->height - 1;
        if (button->isPressed)
            guiGraph_Draw3DFrame(&rect1, FRAME3D_SUNKEN);
        else
            guiGraph_Draw3DFrame(&rect1, FRAME3D_RAISED);
    }

}








void guiGraph_DrawRadioButton(guiRadioButton_t *button)
{
    int8_t y_aligned;
    int8_t x_aligned;
    rect_t rect1;

    rect1.x1 = wx;
    rect1.x2 = wx + button->width - 1;
    rect1.y1 = wy;
    rect1.y2 = wy + button->height - 1;


    y_aligned = wy + button->height / 2;
    x_aligned = wx + RADIOBUTTON_RADIUS;


    if (button->redrawForced)
    {
        // Erase rectangle
        LCD_SetFillColor(colorPalette1[COLOR_INDEX_WIDGET_BACKGROUND]);
        //LCD_SetFillColor(CL_WHITE);
        LCD_FillRect(&rect1);

        // Draw string
        if (button->text)
        {
            LCD_SetPen(PEN_SOLID, colorPalette1[COLOR_INDEX_TEXT_ACTIVE]);
            LCD_SetAltPenMode(PEN_TRANSPARENT);
            LCD_SetFont(button->font);
            rect1.x1 = wx + 2 + RADIOBUTTON_RADIUS*2 + RADIOBUTTON_TEXT_MARGIN;
            rect1.y1 = wy + 1;
            rect1.x2 = wx + button->width - 2;
            rect1.y2 = wy + button->height - 2;
            LCD_PrintStringAligned(button->text, &rect1, button->textAlignment);
        }
    }

    LCD_SetPenMode(PEN_SOLID);

    if ((button->redrawForced) || (button->redrawCheckedState))
    {
        LCD_SetFillColor(CL_WHITE);
        LCD_DrawFilledCircle(x_aligned,y_aligned,RADIOBUTTON_RADIUS);
        //LCD_SetPenColor(colorFromRgb(140,140,140));
        LCD_SetPenColor(colorPalette1[COLOR_INDEX_3DFRAME_DARK2]);
        LCD_DrawCircle(x_aligned,y_aligned,RADIOBUTTON_RADIUS);
        //LCD_SetPenColor(colorFromRgb(70,70,70));
        LCD_SetPenColor(colorPalette1[COLOR_INDEX_3DFRAME_DARK1]);
        LCD_DrawCircle(x_aligned,y_aligned,RADIOBUTTON_RADIUS-1);
        //LCD_SetPenColor(colorPalette1[COLOR_INDEX_3DFRAME_DARK1]);
        //LCD_DrawCircle(x_aligned,y_aligned,RADIOBUTTON_RADIUS-1);

        if (button->isChecked)
        {
            LCD_SetFillColor(CL_BLACK);
            LCD_DrawFilledCircle(x_aligned,y_aligned,RADIOBUTTON_CHECK_RADIUS);
        }
    }



    if ((button->redrawForced) || (button->redrawFocus))
    {
        rect1.x1 = wx + 3 + RADIOBUTTON_RADIUS*2 + RADIOBUTTON_TEXT_MARGIN/2;
        rect1.y1 = wy + 1;
        rect1.x2 = wx + button->width - 2;
        rect1.y2 = wy + button->height - 2;

        if (button->isFocused)
        {
          LCD_SetLineStyle(LINE_STYLE_DOTTED);
          LCD_SetPen(PEN_SOLID, colorPalette[COLOR_INDEX_FOCUS_FRAME]);
          LCD_SetAltPen(PEN_SOLID, colorPalette[COLOR_INDEX_WIDGET_BACKGROUND]);
          LCD_DrawRect(&rect1);
        }
        else
        {
          LCD_SetLineStyle(LINE_STYLE_SOLID);
          LCD_SetPen(PEN_SOLID, colorPalette[COLOR_INDEX_WIDGET_BACKGROUND]);
          LCD_DrawRect(&rect1);
        }
    }

}

#endif //emGUI_COLORED


#ifdef emGUI_MONOCHROME


//-------------------------------------------------------//
// Draw a textLabel
//
//
//-------------------------------------------------------//
void guiGraph_DrawTextLabel(guiTextLabel_t *textLabel)
{
    rect_t rect;

    //-----------------------------------------//
    // Draw background and text
    if (textLabel->redrawForced)
    {
        // Erase rectangle
        LCD_SetFillColor(0);
        LCD_FillRectP(wx ,wy, wx + textLabel->width - 1, wy + textLabel->height - 1);

        // Draw string
        if (textLabel->text)
        {
            LCD_SetFont(textLabel->font);
            LCD_SetPen(PEN_SOLID, CL_BLACK);
            LCD_SetAltPen(PEN_TRANSPARENT, CL_WHITE);
            rect.x1 = wx + 0 + TEXT_LABEL_TEXT_MARGIN;
            rect.y1 = wy + 0;
            rect.x2 = wx + textLabel->width - 1 - TEXT_LABEL_TEXT_MARGIN;
            rect.y2 = wy + textLabel->height - 1;
            LCD_PrintStringAligned(textLabel->text, &rect, textLabel->textAlignment);
        }
    }

    //-----------------------------------------//
    // Draw focus
    if (((textLabel->redrawForced) || (textLabel->redrawFocus)) &&
        (textLabel->showFocus))
    {
        if (textLabel->isFocused)
        {
            LCD_SetLineStyle(LINE_STYLE_DOTTED);
            LCD_SetPen(PEN_SOLID, CL_BLACK);
            LCD_SetAltPen(PEN_SOLID, CL_WHITE);
            LCD_DrawRectP(wx, wy, wx + textLabel->width - 1, wy + textLabel->height - 1);
        }
        else
        {
            LCD_SetLineStyle(LINE_STYLE_SOLID);
            if (textLabel->hasFrame)
                LCD_SetPen(PEN_SOLID, CL_BLACK);
            else
                LCD_SetPen(PEN_SOLID, CL_WHITE);
            LCD_DrawRectP(wx, wy, wx + textLabel->width - 1, wy + textLabel->height - 1);
        }
    }
}



#endif //emGUI_MONOCHROME








