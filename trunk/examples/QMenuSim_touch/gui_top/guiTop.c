#include <stdio.h>

#include "guiTop.h"
#include "guiGraphHAL.h"
#include "guiGraphPrimitives.h"
#include "guiFonts.h"

// Callback functions
cbLogPtr addLogCallback;
cbLcdUpdatePtr updateLcdCallback;




//guiEventArgButtons_t argButtons;



//-----------------------------------//
// Callbacks
void registerLogCallback(cbLogPtr fptr)
{
    addLogCallback = fptr;
}

void registerLcdUpdateCallback(cbLcdUpdatePtr fptr)
{
    updateLcdCallback = fptr;
}

void guiLogEvent(char *string)
{
    addLogCallback(LOG_FROM_BOTTOM, string);
}

void guiDrawIsComplete(void)
{
    updateLcdCallback(guiLcdBuffer);
}
//-----------------------------------//




//-----------------------------------//
// Commands to GUI

void guiInitialize(void)
{


    guiGraph_setDrawingArea(0,0,LCD_XSIZE-1,LCD_YSIZE-1);
    guiGraph_fillRect(&drawArea, CL_BLACK);

    // Test
    rect_t someRect;
    someRect.x1 = 0;
    someRect.x2 = 50;
    someRect.y1 = 0;
    someRect.y2 = 100;
    guiGraph_fillRect(&someRect, CL_GREEN);



    //penColor = CL_BLUE;


    currentFont = &font_h12;

    fontForeColor = CL_RED;
    fontBackColor = CL_YELLOW;
    fontOutputMode = FONT_OUTPUT_SOLID;
    guiGraph_printTextXY(20,20,"Hello world!");


    fontForeColor = CL_BLUE;
    fontOutputMode = FONT_OUTPUT_TRANSPARENT;
    guiGraph_printTextXY(20,50,"������ �i�!");

    guiDrawIsComplete();

    //guiMainForm_Initialize();
    //guiSetupForm_Initialize();
    //guiCore_Init(&guiMainForm);
}



void guiDrawAll(void)
{
     addLogCallback(LOG_FROM_TOP, "Requesting GUI redraw procedure");
   
    // GUI function call
    //guiCore_RedrawAll();
}



void guiTouchMoved(int x, int y)
{
    guiGraph_putPixel(x,y,CL_GREEN);
}

void guiTouchPressed(int x, int y)
{
    guiGraph_putPixel(x,y,CL_RED);
    guiDrawIsComplete();
}

void guiTouchReleased(int x, int y)
{
    guiGraph_putPixel(x,y,CL_YELLOW);
    guiDrawIsComplete();
}


void guiButtonClicked(uint32_t buttonCode)
{
 //  guiEvent_t bEvent;
    addLogCallback(LOG_FROM_TOP, "Generated button event");
 /*
    bEvent.type = GUI_EVENT_BUTTONS_ENCODER;
    bEvent.args = &argButtons;
    argButtons.buttonCode = buttonCode;
    argButtons.encoderDelta = 0;

    guiCore_ProcessEvent(bEvent);
	*/
}

void guiEncoderRotated(int32_t delta)
{

//    guiEvent_t bEvent;
    addLogCallback(LOG_FROM_TOP, "Generated encoder event");
/*
    bEvent.type = GUI_EVENT_BUTTONS_ENCODER;
    bEvent.args = &argButtons;
    argButtons.buttonCode = 0;
    argButtons.encoderDelta = delta;

    guiCore_ProcessEvent(bEvent);
	*/
}

//-----------------------------------//





