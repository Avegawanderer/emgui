
#include "guiGraphWidgets.h"
#include "guiGraphButton.h"
#include "guiGraphLib.h"

#ifdef emGUI_COLORED


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

#endif //emGUI_COLORED



#ifdef emGUI_MONOCHROME

#error Button widget drawing for monochrome LCD is not supported

#endif //emGUI_MONOCHROME
