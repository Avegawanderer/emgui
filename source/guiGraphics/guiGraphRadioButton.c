

#include "guiGraphWidgets.h"
#include "guiGraphRadioButton.h"
#include "guiGraphLib.h"

#ifdef emGUI_COLORED

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
// Draw radioButton
//
//
//-------------------------------------------------------//
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
    x_aligned = wx + RADIOBUTTON_RADIUS + 2;


    if (button->redrawForced)
    {
        // Erase rectangle
        LCD_SetFillColor(CL_WHITE);
        LCD_FillRectWH(wx+1, wy+1, button->width-2, button->height-2);


        // Draw string
        if (button->text)
        {
            LCD_SetPenColor(CL_BLACK);
            LCD_SetFont(button->font);
            rect1.x1 = wx + 2 + RADIOBUTTON_RADIUS*2 + RADIOBUTTON_TEXT_MARGIN;
            rect1.y1 = wy + 1;
            rect1.x2 = wx + button->width - 2;
            rect1.y2 = wy + button->height - 2;
            LCD_PrintStringAligned(button->text, &rect1, button->textAlignment);
        }
    }

    //-----------------------------------------//
    // Draw radiobutton circles
    if ((button->redrawForced) || (button->redrawCheckedState))
    {
        LCD_SetFillColor(CL_WHITE);
        LCD_SetPen(PEN_SOLID, CL_BLACK);
        LCD_DrawFilledCircle(x_aligned,y_aligned,RADIOBUTTON_RADIUS);
        LCD_DrawCircle(x_aligned,y_aligned,RADIOBUTTON_RADIUS);
        if (button->isChecked)
        {
            LCD_SetFillColor(CL_BLACK);
            LCD_DrawFilledCircle(x_aligned,y_aligned,RADIOBUTTON_CHECK_RADIUS);
        }
    }

    //-----------------------------------------//
    // Draw focus / frame
    if ((button->redrawForced) || (button->redrawFocus))
    {
        if (button->isFocused)
        {
            LCD_SetLineStyle(LINE_STYLE_DOTTED);
            LCD_SetPen(PEN_SOLID, CL_BLACK);
            LCD_SetAltPen(PEN_SOLID, CL_WHITE);
        }
        else
        {
            LCD_SetLineStyle(LINE_STYLE_SOLID);
            LCD_SetPen(PEN_SOLID, CL_WHITE);
        }
        LCD_DrawRectWH(wx, wy, button->width, button->height);
    }

}


#endif //emGUI_MONOCHROME
