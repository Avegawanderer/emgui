#ifndef __GUI_GRAPH_WIDGETS_
#define __GUI_GRAPH_WIDGETS_

#include <stdint.h>
#include "guiConfig.h"
#include "guiGraphLib.h"
#include "guiWidgets.h"

#include "guiButton.h"
#include "guiPanel.h"
#include "guiTextLabel.h"
#include "guiCheckBox.h"
#include "guiRadioButton.h"


// System color palette size
#define COLOR_PALETTE_SIZE  8
// System palette indexes
#define COLOR_INDEX_WIDGET_BACKGROUND     0
#define COLOR_INDEX_BUTTON_BACKGROUND   1
#define COLOR_INDEX_3DFRAME_LIGHT1      2
#define COLOR_INDEX_3DFRAME_LIGHT2      3
#define COLOR_INDEX_3DFRAME_DARK1       4
#define COLOR_INDEX_3DFRAME_DARK2       5
#define COLOR_INDEX_FOCUS_FRAME         6
#define COLOR_INDEX_TEXT_ACTIVE         7


#define FRAME_NONE                      0x00
#define FRAME3D_RAISED                  0x01
#define FRAME3D_SUNKEN                  0x02
#define FRAME_SINGLE                    0x03


// Widget Appearance


//---------------------------------------------//
// Button
#define BUTTON_FOCUS_RECT_MARGIN    2



//---------------------------------------------//
// Panel
#define PANEL_FOCUS_RECT_MARGIN    2


//---------------------------------------------//
// Radiobutton
#define RADIOBUTTON_RADIUS  6
#define RADIOBUTTON_CHECK_RADIUS  2
#define RADIOBUTTON_TEXT_MARGIN  5

//---------------------------------------------//
// Textlabel
#define TEXT_LABEL_TEXT_MARGIN  2

#ifdef emGUI_MONOCHROME
// Pixel output modes
#define PIXEL_MODE_REWRITE  0x00
#define PIXEL_MODE_AND      0x01
#define PIXEL_MODE_OR       0x02
#define PIXEL_MODE_XOR      0x03

// Image output modes
#define IMAGE_MODE_NORMAL    0x01
#define IMAGE_MODE_INVERSE   0x00
// Aliases for fill rect
#define FILL_WITH_BLACK      0x01
#define FILL_WITH_WHITE      0x00

#define LCD_FillRect(x_pos, y_pos, width, height, mode) \
    LCD_DrawImage(0, x_pos, y_pos, width, height, mode)

#endif

#ifdef emGUI_COLORED
extern const color_t colorPalette1[];
color_t *colorPalette;
#endif

extern int16_t wx;
extern int16_t wy;

void guiGraph_SetBaseXY(int16_t x, int16_t y);
void guiGraph_OffsetBaseXY(int16_t dx, int16_t dy);

void guiGraph_Draw3DFrame(rect_t *rect, uint8_t frameState);

void guiGraph_DrawTextLabel(guiTextLabel_t *textLabel);
void guiGraph_DrawButton(guiButton_t *button);
void guiGraph_DrawRadioButton(guiRadioButton_t *button);






#endif
