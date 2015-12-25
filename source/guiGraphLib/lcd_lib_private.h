/**********************************************************

**********************************************************/


#ifndef __LCD_LIB_PRIVATE_H_
#define __LCD_LIB_PRIVATE_H_

#include "stdint.h"
#include "lcd_font_typedef.h"


extern color_t penColor;             // Pen is used for drawing lines, frames, circles, etc
extern color_t altPenColor;             
extern color_t fillColor;            // Used for filling objects
extern const tFont* currentFont;     // Font that is currently used
//extern color_t fontForeColor;        // Used when printing text
//extern color_t fontBackColor;        //
extern uint8_t fontOutputMode;       // Specifies text background print mode
extern uint8_t imageOutputMode;
extern uint8_t lineStyle;

#endif //__LCD_LIB_PRIVATE_H_
