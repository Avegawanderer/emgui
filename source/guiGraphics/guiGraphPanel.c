
#include "guiGraphWidgets.h"
#include "guiGraphPanel.h"

#ifdef emGUI_COLORED

//-------------------------------------------------------//
// Draw a panel
//
//
//-------------------------------------------------------//
void guiGraph_DrawPanel(guiPanel_t *panel)
{
    rect_t rect1;

    if (panel->redrawForced)
    {
        // Background
        LCD_SetFillColor(colorPalette1[COLOR_INDEX_WIDGET_BACKGROUND]);
        rect1.x1 = wx;
        rect1.x2 = wx + panel->width - 1;
        rect1.y1 = wy;
        rect1.y2 = wy + panel->height - 1;
        LCD_FillRect(&rect1);

        /* Frame
        rect1.x1 = wx;
        rect1.x2 = wx + panel->width - 1;
        rect1.y1 = wy;
        rect1.y2 = wy + panel->height - 1; */

        if ((panel->frame == FRAME3D_SUNKEN) || (panel->frame == FRAME3D_RAISED))
        {
            guiGraph_Draw3DFrame(&rect1, panel->frame);
        }
        else if (panel->frame == FRAME_SINGLE)
        {
            LCD_SetPenColor(colorPalette[COLOR_INDEX_3DFRAME_DARK1]);
            LCD_SetLineStyle(LINE_STYLE_SOLID);
            LCD_DrawRect(&rect1);
        }

    }

    if ((panel->redrawForced) || (panel->redrawFocus))
    {
        if (panel->showFocus)
        {
            if (panel->isFocused)
            {
                LCD_SetPenColor(colorPalette[COLOR_INDEX_FOCUS_FRAME]);
                LCD_SetLineStyle(LINE_STYLE_DOTTED);
            }
            else
            {
                LCD_SetPenColor(colorPalette[COLOR_INDEX_WIDGET_BACKGROUND]);
                LCD_SetLineStyle(LINE_STYLE_SOLID);
            }
            rect1.x1 = wx + PANEL_FOCUS_RECT_MARGIN;
            rect1.x2 = wx + panel->width - 1 - PANEL_FOCUS_RECT_MARGIN;
            rect1.y1 = wy + PANEL_FOCUS_RECT_MARGIN;
            rect1.y2 = wy + panel->height - 1 - PANEL_FOCUS_RECT_MARGIN;
            LCD_DrawRect(&rect1);
        }
    }
}

#endif //emGUI_COLORED



#ifdef emGUI_MONOCHROME

//-------------------------------------------------------//
// Draw a panel
//
//
//-------------------------------------------------------//
void guiGraph_DrawPanel(guiPanel_t *panel)
{

    //-----------------------------------------//
    // Draw background
    if (panel->redrawForced)
    {
        // Erase rectangle
        LCD_SetFillColor(CL_WHITE);
        LCD_FillRectWH(wx, wy, panel->width, panel->height);
    }

    LCD_SetPenMode(PEN_SOLID);
    LCD_SetAltPenMode(PEN_SOLID);

    //-----------------------------------------//
    // Draw focus / frame
    if (((panel->redrawForced) || (panel->redrawFocus))  &&
        (panel->showFocus))
    {
        if (panel->isFocused)
        {
            LCD_SetLineStyle(LINE_STYLE_DOTTED);
            LCD_SetPenColor(CL_BLACK);
            LCD_SetAltPenColor(CL_WHITE);
            LCD_DrawRectWH(wx, wy, panel->width, panel->height);
        }
        else
        {
            LCD_SetLineStyle(LINE_STYLE_SOLID);
            if (panel->frame)
                LCD_SetPenColor(CL_BLACK);
            else
                LCD_SetPenColor(CL_WHITE);
            LCD_DrawRectWH(wx, wy, panel->width, panel->height);
        }
    }
}


#endif //emGUI_MONOCHROME


