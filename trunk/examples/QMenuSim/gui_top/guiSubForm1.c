/**********************************************************
    Module guiSubForm1




**********************************************************/

#include <stdio.h>      // due to printf
#include <stdint.h>

#include "guiFonts.h"
#include "guiGraphPrimitives.h"
#include "guiGraphWidgets.h"
#include "guiEvents.h"
#include "guiWidgets.h"
#include "guiTextLabel.h"
#include "guiForm.h"
#include "guiCore.h"

// Other forms - in order to switch between them
#include "guiMainForm.h"
#include "guiSubForm1.h"


extern void guiLogEvent(char *string);


static void textLabel1_updateCallback(void);
static void textLabel2_updateCallback(void);

static uint8_t guiSubForm1_ProcessEvents(guiGenericWidget_t *pWidget, guiEvent_t event);
//static void guiSubForm1_drawStatic(void);


//--------- Form elements ---------//
static guiTextLabel_t textLabel1;
static char textLabel1_data[20];
//static guiWidgetHandler_t textLabel1Handlers[2];

static guiTextLabel_t textLabel2;
static char textLabel2_data[20];
//static guiWidgetHandler_t textLabel2Handlers[2];


//----------- GUI Form  -----------//
guiForm_t   guiSubForm1;
static void *guiSubForm1Elements[2];


void guiSubForm1_Initialize(void)
{
    // Initialize gui elements

    guiForm_Initialize(&guiSubForm1);
    guiSubForm1.parent = (guiGenericWidget_t *)&guiMainForm;
    guiSubForm1.processEvent = guiSubForm1_ProcessEvents;
    guiSubForm1.widgets.count = 2;
    guiSubForm1.widgets.elements = guiSubForm1Elements;
    guiSubForm1.widgets.elements[0] = &textLabel1;
    guiSubForm1.widgets.elements[1] = &textLabel2;
    guiSubForm1.x = 10;
    guiSubForm1.y = 10;
    guiSubForm1.width = 200;
    guiSubForm1.height = 90;


    guiTextLabel_Initialize(&textLabel1, (guiGenericWidget_t *)&guiSubForm1);
    textLabel1.tabIndex = 1;
    textLabel1.acceptFocus = 1;
    textLabel1.acceptFocusByTab = 1;
    textLabel1.x = 5;
    textLabel1.y = 10;
    textLabel1.width = 130;
    textLabel1.height = 20;
    textLabel1.alignment = ALIGN_LEFT;
    textLabel1.text = textLabel1_data;
    textLabel1.hasFrame = 1;

    guiTextLabel_Initialize(&textLabel2, (guiGenericWidget_t *)&guiSubForm1);
    textLabel2.tabIndex = 2;
    textLabel2.acceptFocus = 1;
    textLabel2.acceptFocusByTab = 1;
    textLabel2.x = 5;
    textLabel2.y = 40;
    textLabel2.width = 130;
    textLabel2.height = 20;
    textLabel2.alignment = ALIGN_LEFT;
    textLabel2.text = textLabel2_data;
    textLabel2.hasFrame = 1;
}


static uint8_t guiSubForm1_ProcessEvents(struct guiGenericWidget_t *pWidget, guiEvent_t event)
{
    // Process GUI messages - select, draw, etc
    switch(event.type)
    {
          case GUI_EVENT_UPDATE:
            textLabel1_updateCallback();
            textLabel2_updateCallback();
            break;
        case GUI_EVENT_DRAW:
            // Check if full redraw is required
            if (guiSubForm1.redrawForced)
            {
                // Widget must be fully redrawn - set all flags
                guiSubForm1.redrawFlags = FORM_REDRAW_FOCUS |
                                         FORM_REDRAW_BACKGROUND;
            }
            guiGraph_DrawForm(&guiSubForm1);
            // Reset flags
            guiSubForm1.redrawFlags = 0;
            guiSubForm1.redrawRequired = 0;
          break;
    }

/*        case GUI_EVENT_DRAW:
            guiForm_Draw(&guiSubForm1);     // Draws form and all childs
            if (guiSubForm1.redrawFlags & WF_REDRAW)
                guiSubForm1_drawStatic();
            guiSubForm1.redrawFlags = 0;
            break;
        case GUI_EVENT_SELECT:
            guiCore_SelectWidget(&guiSubForm1.widgets, (guiGenericWidget_t *)&TextLabel1);
            guiCore_RequestFullRedraw();
            break;
        case GUI_EVENT_DESELECT:
            guiCore_SelectWidget(&guiSubForm1.widgets, 0);
            break;
        default:
            // Process form logic
            // CHECKME - maybe pass event to selected widget - if appropriate handler is not found,
            // process here ?
            // If using containers, there should be a function that allows tabStop for any container, not only for form
            if (((guiEventArgButtons_t *)event.args)->buttonCode & GUI_BTN_ESC)
            {
                guiCore_RequestSwitchForm(&guiSetupForm);
            }
            else if (((guiEventArgButtons_t *)event.args)->buttonCode & GUI_BTN_LEFT)
            {
                guiCore_SelectNextWidget(&guiSubForm1.widgets, -1);
            }
            else if (((guiEventArgButtons_t *)event.args)->buttonCode & GUI_BTN_RIGHT)
            {
                guiCore_SelectNextWidget(&guiSubForm1.widgets, 1);
            }
                // Pass event to the widgets
    }
    guiCore_CallEventHandler((guiGenericWidget_t *)&guiSubForm1,event.type); */
    return 0;

}



static void textLabel1_updateCallback(void)
{
    guiLogEvent("Request update for MainForm.textLabel1");

    // Move label across form
    static int8_t increment = 1;
    if (textLabel1.x >= 20) increment = -1;
    else if (textLabel1.x <= -5) increment = 1;
    // Make parent redraw
    guiCore_InvalidateRect((guiGenericWidget_t *)&textLabel1,textLabel1.x,textLabel1.y,
                           textLabel1.x + textLabel1.width - 1,
                           textLabel1.y + textLabel1.height - 1);
    // Move
    textLabel1.x += increment;

    sprintf(textLabel1.text,"%s%d","Label x = ",textLabel1.x);
    //guiTextLabel_SetRedrawFlags(&textLabel1, TEXT_LABEL_REDRAW_TEXT);
}

static void textLabel2_updateCallback(void)
{
    static uint32_t calls = 0;
    guiLogEvent("Request update for MainForm.textLabel2");
    sprintf(textLabel2.text,"%s%d","Update calls: ",++calls);
    guiTextLabel_SetRedrawFlags(&textLabel2, TEXT_LABEL_REDRAW_TEXT);
}

