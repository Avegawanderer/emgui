
#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif

/*
typedef struct {
    int16_t x;
    int16_t y;
    uint8_t isPressed;
} touchPanelState_t;
*/

//-----------------------------------//
// Callbacks
#define LOG_FROM_TOP      10
#define LOG_FROM_BOTTOM   11

typedef void (*cbLogPtr)(int type, char *string);
//typedef void (*cbLcdUpdatePtr)(int display, uint16_t *buffer);
typedef void (*cbLcdUpdatePtr)(uint32_t *buffer);

void registerLogCallback(cbLogPtr fptr);
void registerLcdUpdateCallback(cbLcdUpdatePtr fptr);
//-----------------------------------//





// Functions for top-level
void guiInitialize(void);
void guiDrawAll(void);
void guiButtonClicked(uint32_t buttonCode);
void guiEncoderRotated(int32_t delta);

void guiTouchMoved(int x, int y);
void guiTouchPressed(int x, int y);
void guiTouchReleased(int x, int y);


// Functions for calling from GUI
void guiLogEvent(char *string);
void guiDrawIsComplete(void);



#ifdef __cplusplus
}
#endif
