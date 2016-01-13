#ifndef __GUI_GRAPH_CHECKBOX_H_
#define __GUI_GRAPH_CHECKBOX_H_

#include "guiConfig.h"
#include "guiCheckBox.h"

// TODO - bring checkbox size selection to some config.h file

//---------------------------------------------//
// Checkbox
#ifdef emGUI_COLORED
/*
#define CHECKBOX_GRAPH_XSIZE  10
#define CHECKBOX_GRAPH_YSIZE  10
#define CHECKBOX_TEXT_MARGIN  6
#define CHECKBOX_IMG_CHECKED  checkbox_10x10_checked_no_frame
#define CHECKBOX_IMG_EMPTY  checkbox_10x10_empty_no_frame
*/ /*
#define CHECKBOX_GRAPH_XSIZE  8
#define CHECKBOX_GRAPH_YSIZE  8
#define CHECKBOX_TEXT_MARGIN  4
#define CHECKBOX_IMG_CHECKED  checkbox_8x8_checked_no_frame
#define CHECKBOX_IMG_EMPTY  checkbox_8x8_empty_no_frame
*/
#define CHECKBOX_GRAPH_XSIZE  9
#define CHECKBOX_GRAPH_YSIZE  9
#define CHECKBOX_TEXT_MARGIN  5
#define CHECKBOX_IMG_CHECKED  checkbox_9x9_checked_no_frame
#define CHECKBOX_IMG_EMPTY  checkbox_9x9_empty_no_frame

#endif

#ifdef emGUI_MONOCHROME
#define CHECKBOX_GRAPH_XSIZE  10
#define CHECKBOX_GRAPH_YSIZE  10
#define CHECKBOX_TEXT_MARGIN  6
#define CHECKBOX_IMG_CHECKED  checkbox_10x10_checked
#define CHECKBOX_IMG_EMPTY  checkbox_10x10_empty
#endif


void guiGraph_DrawCheckBox(guiCheckBox_t * checkBox);







#endif //__GUI_GRAPH_CHECKBOX_H_
