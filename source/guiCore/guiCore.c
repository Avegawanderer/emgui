/**********************************************************
    Module guiCore




**********************************************************/

#include <stdint.h>
//#include "guiFonts.h"
//#include "guiGraphPrimitives.h"
#include "guiEvents.h"
#include "guiWidgets.h"
#include "guiForm.h"




const guiEvent_t guiEvent_DRAW = {GUI_EVENT_DRAW, 0};
const guiEvent_t guiEvent_DRAW_ALL = {GUI_EVENT_DRAW_ALL, 0};
const guiEvent_t guiEvent_SELECT = {GUI_EVENT_SELECT, 0};
const guiEvent_t guiEvent_DESELECT = {GUI_EVENT_DESELECT, 0};
const guiEvent_t guiEvent_UPDATE = {GUI_EVENT_UPDATE, 0};

const guiEvent_t guiEvent_HIDE = {GUI_EVENT_HIDE, 0};
const guiEvent_t guiEvent_SHOW = {GUI_EVENT_SHOW, 0};



guiGenericWidget_t *rootWidget;




//=======================================================//


//-------------------------------------------------------//
// Makes specified rectangle invalid - it must be redrawn
//
//-------------------------------------------------------//
void guiCore_InvalidateRect(void *rect)
{
    /*
        Approach 1:
            Add this rectangle to the list of invalidated rectangles of thew form.
            Redrawing will be split into two stages:
                a.  Traverse whole widget tree and find for each container if it intercepts with any of the rectangles.
                    If there is some interseption, mark the container to fully redraw it and it's content if rectangle is
                    not an exact widget.
                    For each widget in the container also check interseption with the rectangles and mark those
                    who has interception.
                b.  Add marked widgets and containers to redraw list. Sort list by Z-index and redraw every widget.
        Approach 2:
            Check if the rectangle lies on the parent widget completely. If so, mark parent to be redrawn and exit.
            If rectangle spands over the parent's borders, check the same for parent's parent and so on, until
            root widget is reached - i.e. propagate up the tree.

        If using Z-order, possibly put all form widgets into single array?

    */
}



//=======================================================//


//-------------------------------------------------------//
//  Top function for GUI core initializing
//  All components must be already initialized
//-------------------------------------------------------//
void guiCore_Init(guiGenericWidget_t *rootObject)
{

    rootWidget = rootObject;
    //prootWidget->processEvent(guiEvent_SELECT);
}



void guiCore_RedrawAll(void)
{
    guiGenericWidget_t *widget;
    guiGenericWidget_t *nextWidget;
    uint8_t index;

    // Update root widget. Root widget can further call
    // update for any other widget.
    rootWidget->processEvent(rootWidget, guiEvent_UPDATE);

    // Start widget tree traverse from root widget
    widget = rootWidget;

    while(1)
    {
        // Process widget
        if (widget->redrawRequired)
        {
            // The redrawRequired flag is reset by widget after processing DRAW event
            widget->processEvent(widget, guiEvent_DRAW);
        }
        // Check if widget has children
        if (widget->isContainer)
        {
            // If container has unprocessed children
            if ( ((guiGenericContainer_t *)widget)->widgets.traverseIndex <
                 ((guiGenericContainer_t *)widget)->widgets.count )
            {
                // switch to next one if possible
                index = ((guiGenericContainer_t *)widget)->widgets.traverseIndex++;
                nextWidget = ((guiGenericContainer_t *)widget)->widgets.elements[index];
                // check if widget actually exists and is visible
                if (nextWidget == 0)
                    continue;
                if (nextWidget->isVisible == 0)
                    continue;
                // Check if widget must be redrawn forcibly
                if (widget->redrawForced)
                {
                    nextWidget->redrawForced = 1;
                    nextWidget->redrawRequired = 1;
                }
                if ((nextWidget->redrawRequired) || (nextWidget->isContainer))
                    widget = nextWidget;
            }
            else
            {
                // All container child items are processed. Reset counter of processed items and move up.
                ((guiGenericContainer_t *)widget)->widgets.traverseIndex = 0;
                widget->redrawForced = 0;
                if (widget->parent == 0)    // root widget has no parent
                    break;
                else
                    widget = widget->parent;
            }
        }
        else
        {
            // Widget has no children. Move up.
            widget->redrawForced = 0;
            widget = widget->parent;
        }
    }
}




/*
//-------------------------------------------------------//
//  Top GUI function for processing events
//
//-------------------------------------------------------//
void guiCore_ProcessEvent(guiEvent_t event)
{

    prootWidget->processEvent(event);

    // Check if there is a request to switch to other form
    if (pNextForm != 0)
    {
        prootWidget->processEvent(guiEvent_DESELECT);
        prootWidget = pNextForm;
        prootWidget->processEvent(guiEvent_SELECT);
        pNextForm = 0;
    }

//        guiCore_RedrawAll();        // CHECKME - force redraw
}


//-------------------------------------------------------//
//  This puts request for switching form.
//  Should be called inside the form's event handler
//-------------------------------------------------------//
void guiCore_RequestSwitchForm(guiForm_t* pFormToSwitch)
{
    pNextForm = pFormToSwitch;
}


void guiCore_RequestFullRedraw(void)
{
    prootWidget->redrawFlags |= WF_REDRAW;
}









void guiCore_SelectWidget(guiWidgetCollection_t *pCollection, guiGenericWidget_t *pWidgetToSelect)
{

    if ((pCollection->pSelected != 0) && (pCollection->pSelected != pWidgetToSelect))
        ((guiGenericWidget_t *)pCollection->pSelected)->processEvent(pCollection->pSelected, guiEvent_DESELECT);
    if (pWidgetToSelect != 0)
    {
        if (pWidgetToSelect->properties & WP_IS_VISIBLE)
        {
            pWidgetToSelect->processEvent(pWidgetToSelect, guiEvent_SELECT);
            if (pWidgetToSelect->state & WF_IS_SELECTED)
                pCollection->pSelected = pWidgetToSelect;
        }
    }
}


void guiCore_SelectNextWidget(guiWidgetCollection_t *pCollection, int8_t tabDir)
{
    uint8_t currentTabIndex, i;
    uint16_t minTabIndex = 0x200;   // maximum x2
    uint8_t minWidgetIndex = pCollection->count;
    int16_t tmp;
    guiGenericWidget_t *pWidget;

    // Get current widget's tabIndex
    if (pCollection->pSelected != 0)
        currentTabIndex = ((guiGenericWidget_t *)pCollection->pSelected)->tabIndex;
    else
        currentTabIndex = 0;

    // Find widget with next tabIndex
    for (i = 0; i < pCollection->count; i++)
    {
        pWidget = (guiGenericWidget_t *)pCollection->elements[i];
        if ((pWidget->tabIndex != 0) && (pWidget->properties & WP_IS_VISIBLE))
        {
            if (tabDir >= 0)
                tmp = (pWidget->tabIndex <= currentTabIndex) ? pWidget->tabIndex + 256 : pWidget->tabIndex;
            else
                tmp = (pWidget->tabIndex >= currentTabIndex) ? 256 - pWidget->tabIndex : pWidget->tabIndex;

            if (tmp < minTabIndex)
            {
                minTabIndex = tmp;
                minWidgetIndex = i;
            }
        }
    }

    if (minWidgetIndex < pCollection->count)
    {
        pWidget = (guiGenericWidget_t *)pCollection->elements[minWidgetIndex];
        guiCore_SelectWidget(pCollection, pWidget);
    }
}




void guiCore_SetVisibleByTag(guiWidgetCollection_t *pCollection, uint8_t minTag, uint8_t maxTag, uint8_t mode)
{
    uint8_t i;
    uint8_t tagInRange;
    guiGenericWidget_t *pWidget;
    for(i=0; i<pCollection->count; i++)
    {
        pWidget = (guiGenericWidget_t *)pCollection->elements[i];
        if (pWidget == 0)
            continue;
        tagInRange = ((pWidget->tag >= minTag) && (pWidget->tag <= maxTag)) ? mode & 0x3 : mode & 0xC;
        if ((tagInRange == ITEMS_IN_RANGE_ARE_VISIBLE) || (tagInRange == ITEMS_OUT_OF_RANGE_ARE_VISIBLE))
            pWidget->processEvent(pWidget, guiEvent_SHOW);
        else if ((tagInRange == ITEMS_IN_RANGE_ARE_INVISIBLE) || (tagInRange == ITEMS_OUT_OF_RANGE_ARE_INVISIBLE))
            pWidget->processEvent(pWidget, guiEvent_HIDE);
    }
}


uint8_t guiCore_CallEventHandler(guiGenericWidget_t *pWidget, uint8_t eventType)
{
    uint8_t i;
    uint8_t handlerIsFound = 0;
    for(i=0; i<pWidget->handlers.count; i++)
    {
        if (pWidget->handlers.elements[i].eventType == eventType)
        {
            pWidget->handlers.elements[i].handler(pWidget);
            handlerIsFound = 1;
        }
    }

    // TODO - return value:
    //  - not found
    //  - found, return what handler returned

    // TODO - check processing of the events by containers - first pass to selected child ?
    // if child cannot process, process by container
    // what to do with OK/ESC (fall deeper or pop up focus ?)

    return handlerIsFound;
}

*/










