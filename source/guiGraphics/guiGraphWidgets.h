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


// Common widget appearance settings

#ifdef emGUI_COLORED

// System palette indexes
enum ColorPaletteIndicies {
    COLOR_INDEX_WIDGET_BACKGROUND,
    COLOR_INDEX_BUTTON_BACKGROUND,
    COLOR_INDEX_3DFRAME_LIGHT1,
    COLOR_INDEX_3DFRAME_LIGHT2,
    COLOR_INDEX_3DFRAME_DARK1,
    COLOR_INDEX_3DFRAME_DARK2,
    COLOR_INDEX_FOCUS_FRAME,
    COLOR_INDEX_TEXT_ACTIVE,
    // System color palette size
    COLOR_PALETTE_SIZE
};

extern const color_t colorPalette1[];
extern color_t *colorPalette;

#endif //emGUI_COLORED

#ifdef emGUI_MONOCHROME
#endif //emGUI_MONOCHROME


#define FRAME_NONE                          0x00
#define FRAME3D_RAISED                      0x01
#define FRAME3D_SUNKEN                      0x02
#define FRAME_SINGLE                        0x03



extern int16_t wx;
extern int16_t wy;

void guiGraph_SetBaseXY(int16_t x, int16_t y);
void guiGraph_OffsetBaseXY(int16_t dx, int16_t dy);
#ifdef emGUI_COLORED
void guiGraph_Draw3DFrame(rect_t *rect, uint8_t frameState);
#endif //emGUI_COLORED



#endif
