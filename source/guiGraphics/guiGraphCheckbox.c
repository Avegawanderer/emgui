

#include "guiGraphWidgets.h"
#include "guiGraphCheckbox.h"
#include "guiGraphLib.h"


const uint8_t checkbox_10x10_checked[] =
{
    0xFF, 0x01, 0x39, 0x71, 0xE1, 0x71, 0x39, 0x1D,
    0x01, 0xFF, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02,
    0x02, 0x02, 0x02, 0x03
};


const uint8_t checkbox_10x10_empty[] =
{
    0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0xFF, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02,
    0x02, 0x02, 0x02, 0x03
};

const uint8_t checkbox_10x10_checked_no_frame[] =
{
    0x00, 0x1C, 0x38, 0x70, 0xE0, 0x70, 0x38, 0x1C,
    0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

const uint8_t checkbox_10x10_empty_no_frame[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

const uint8_t checkbox_8x8_checked_no_frame[] =
{
    0x00, 0x1C, 0x38, 0x70, 0x38, 0x1C, 0x0E, 0x00
};

const uint8_t checkbox_8x8_empty_no_frame[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t checkbox_9x9_checked_no_frame[] =
{
    0x00, 0x38, 0x70, 0xE0, 0x70, 0x38, 0x1C, 0x0E,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00
};

const uint8_t checkbox_9x9_empty_no_frame[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00
};




#ifdef emGUI_COLORED


void guiGraph_DrawCheckBox(guiCheckBox_t * checkBox)
{
    int8_t y_aligned;
    rect_t rect1;
    const uint8_t *img;

    y_aligned = checkBox->height - CHECKBOX_GRAPH_YSIZE;
    y_aligned /= 2;
    y_aligned = wy + y_aligned;


    rect1.x1 = wx;
    rect1.x2 = wx + checkBox->width - 1;
    rect1.y1 = wy;
    rect1.y2 = wy + checkBox->height - 1;


    if (checkBox->redrawForced)
    {
       // Erase rectangle
        LCD_SetFillColor(colorPalette1[COLOR_INDEX_WIDGET_BACKGROUND]);
        LCD_FillRect(&rect1);

       // Draw string
       if (checkBox->text)
       {
           LCD_SetPen(PEN_SOLID, colorPalette1[COLOR_INDEX_TEXT_ACTIVE]);
           LCD_SetAltPenMode(PEN_TRANSPARENT);
           LCD_SetFont(checkBox->font);
           rect1.x1 = wx + 2 + CHECKBOX_GRAPH_XSIZE + CHECKBOX_TEXT_MARGIN;
           rect1.y1 = wy + 1;
           rect1.x2 = wx + checkBox->width - 2;
           rect1.y2 = wy + checkBox->height - 2;
           LCD_PrintStringAligned(checkBox->text, &rect1, checkBox->textAlignment);
       }

       // Check frame
       rect1.x1 = wx;
       rect1.x2 = wx + 3 + CHECKBOX_GRAPH_XSIZE;
       rect1.y1 = y_aligned - 2;
       rect1.y2 = y_aligned + 1 + CHECKBOX_GRAPH_YSIZE;
       guiGraph_Draw3DFrame(&rect1, FRAME3D_SUNKEN);

       // Draw rectangle frame
       //LCD_SetPixelOutputMode(PIXEL_MODE_REWRITE);
       //LCD_DrawRect(wx + 2,y_aligned,CHECKBOX_GRAPH_XSIZE,CHECKBOX_GRAPH_YSIZE,1);
    }


    if ((checkBox->redrawForced) || (checkBox->redrawCheckedState))
    {
        LCD_SetPen(PEN_SOLID, CL_BLACK);
        LCD_SetAltPen(PEN_SOLID, CL_WHITE);
        img = (checkBox->isChecked) ? CHECKBOX_IMG_CHECKED :
                                     CHECKBOX_IMG_EMPTY;
        LCD_drawPackedImage(img, wx+2, y_aligned, CHECKBOX_GRAPH_XSIZE, CHECKBOX_GRAPH_YSIZE);

    }



    if ((checkBox->redrawForced) || (checkBox->redrawFocus))
    {
        rect1.x1 = wx + 3 + CHECKBOX_GRAPH_XSIZE + CHECKBOX_TEXT_MARGIN/2;
        rect1.y1 = wy + 1;
        rect1.x2 = wx + checkBox->width - 2;
        rect1.y2 = wy + checkBox->height - 2;

        LCD_SetAltPenMode(PEN_SOLID);
        LCD_SetPenMode(PEN_SOLID);

        if (checkBox->isFocused)
        {
            LCD_SetLineStyle(LINE_STYLE_DOTTED);
            LCD_SetPenColor(colorPalette[COLOR_INDEX_FOCUS_FRAME]);
            LCD_SetAltPenColor(colorPalette[COLOR_INDEX_WIDGET_BACKGROUND]);
        }
        else
        {
            LCD_SetLineStyle(LINE_STYLE_SOLID);
            LCD_SetPenColor(colorPalette[COLOR_INDEX_WIDGET_BACKGROUND]);
        }
        LCD_DrawRect(&rect1);
    }



}

#endif //emGUI_COLORED



#ifdef emGUI_MONOCHROME

//-------------------------------------------------------//
// Draw checkbox
//
//
//-------------------------------------------------------//
void guiGraph_DrawCheckBox(guiCheckBox_t * checkBox)
{
    int8_t y_aligned;
    rect_t rect;
    const uint8_t *img;

    y_aligned = checkBox->height - CHECKBOX_GRAPH_YSIZE;
    y_aligned /= 2;
    y_aligned = wy + y_aligned;

    LCD_SetPenMode(PEN_SOLID);
    LCD_SetAltPenMode(PEN_TRANSPARENT);

    //-----------------------------------------//
    // Draw background
    if (checkBox->redrawForced)
    {
        // Erase rectangle
        LCD_SetFillColor(CL_WHITE);
        LCD_FillRectWH(wx+1, wy+1, checkBox->width-2, checkBox->height-2);

        // Draw string
        if (checkBox->text)
        {
            LCD_SetFont(checkBox->font);
            LCD_SetPenColor(CL_BLACK);
            rect.x1 = wx + 2 + CHECKBOX_TEXT_MARGIN + CHECKBOX_GRAPH_XSIZE;
            rect.y1 = wy + 1;
            rect.x2 = wx + checkBox->width - 2;
            rect.y2 = wy + checkBox->height - 2;
            LCD_PrintStringAligned(checkBox->text, &rect, checkBox->textAlignment);
        }

        // Draw rectangle frame
        LCD_SetPenColor(CL_BLACK);
        LCD_DrawRectWH(wx + 2,y_aligned,CHECKBOX_GRAPH_XSIZE,CHECKBOX_GRAPH_YSIZE);
    }

    LCD_SetAltPenMode(PEN_SOLID);

    //-----------------------------------------//
    // Draw focus / frame
    if ((checkBox->redrawForced) || (checkBox->redrawFocus))
    {
        if (checkBox->isFocused)
        {
            LCD_SetLineStyle(LINE_STYLE_DOTTED);
            LCD_SetPenColor(CL_BLACK);
            LCD_SetAltPenColor(CL_WHITE);
        }
        else
        {
            LCD_SetLineStyle(LINE_STYLE_SOLID);
            if (checkBox->hasFrame)
                LCD_SetPenColor(CL_BLACK);
            else
                LCD_SetPenColor(CL_WHITE);
        }
        LCD_DrawRectWH(wx, wy, checkBox->width, checkBox->height);
    }

    //-----------------------------------------//
    // Draw box
    if ((checkBox->redrawForced) || (checkBox->redrawCheckedState))
    {
        LCD_SetPenColor(CL_BLACK);
        LCD_SetAltPenColor(CL_WHITE);
        img = (checkBox->isChecked) ? CHECKBOX_IMG_CHECKED :
                                      CHECKBOX_IMG_EMPTY;
        LCD_drawPackedImage(img,wx+2,y_aligned,CHECKBOX_GRAPH_XSIZE, CHECKBOX_GRAPH_YSIZE);
    }

}



#endif //emGUI_MONOCHROME


