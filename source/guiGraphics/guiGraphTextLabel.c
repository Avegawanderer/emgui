

#include "guiGraphWidgets.h"
#include "guiGraphTextLabel.h"
#include "guiGraphLib.h"


#ifdef emGUI_COLORED


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
