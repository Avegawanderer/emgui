
#include <stdint.h>
#include "guiGraphLib.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DISPLAY_XSIZE           LCD_XSIZE
#define DISPLAY_YSIZE           LCD_YSIZE


//-----------------------------------//
// Callbacks
#define LOG_FROM_TOP      10
#define LOG_FROM_BOTTOM   11

typedef void (*cbLogPtr)(int type, char *string);
typedef void (*cbLcdUpdatePtr)(void *buffer);



void registerLogCallback(cbLogPtr fptr);
void registerLcdUpdateCallback(cbLcdUpdatePtr fptr);

void guiInitialize(void);
void guiDrawAll(void);
void guiTouchMoved(int x, int y);
void guiTouchPressed(int x, int y);
void guiTouchReleased(int x, int y);
void guiButtonEvent(uint16_t buttonCode, uint8_t eventType);
void guiEncoderRotated(int32_t delta);

// Functions for calling from GUI
void guiLogEvent(char *string);



#ifdef __cplusplus
}
#endif
