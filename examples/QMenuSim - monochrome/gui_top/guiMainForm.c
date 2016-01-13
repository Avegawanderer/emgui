

#include "guiCore.h"
#include "guiCoreMemory.h"
#include "guiEvents.h"
#include "guiWidgets.h"

#include "guiPanel.h"
#include "guiTextLabel.h"
#include "guiCheckBox.h"
#include "guiRadioButton.h"


//----------- GUI Form  -----------//
guiPanel_t     guiMainForm;



//--------- Form elements ---------//
static guiTextLabel_t textLabel_time;
static guiCheckBox_t checkBox1;
static guiCheckBox_t checkBox2;
static guiRadioButton_t radioButton1;
static guiRadioButton_t radioButton2;




void guiMainForm_Initialize(void)
{
    // Initialize form
    guiPanel_Initialize(&guiMainForm, 0);   // Root has no parent
    guiCore_AllocateWidgetCollection((guiGenericContainer_t *)&guiMainForm, 10);
    guiMainForm.isVisible = 1;
    guiMainForm.redrawRequired = 1;
    guiMainForm.redrawForced = 1;
    guiMainForm.x = 0;
    guiMainForm.y = 0;
    guiMainForm.width = LCD_XSIZE;
    guiMainForm.height = LCD_YSIZE;
    //guiMainForm.frame = 1;
    //guiMainForm.showFocus = 1;

    // Text label for time display
    guiTextLabel_Initialize(&textLabel_time, 0);
    textLabel_time.x = 10;
    textLabel_time.y = 5;
    textLabel_time.width = 50;
    textLabel_time.height = 12;
    textLabel_time.text = guiCore_calloc(20);
    textLabel_time.font = &font_6x8_mono;

    guiCheckBox_Initialize(&checkBox1,(guiGenericWidget_t *)&guiMainForm);
    checkBox1.x = 10;
    checkBox1.y = 20;
    checkBox1.width = 80;
    checkBox1.height = 16;
    checkBox1.text = "Box 1";
    checkBox1.font = &font_h10;
    checkBox1.tabIndex = 12;

    guiCheckBox_Initialize(&checkBox2,(guiGenericWidget_t *)&guiMainForm);
    checkBox2.x = 100;
    checkBox2.y = 20;
    checkBox2.width = 80;
    checkBox2.height = 16;
    checkBox2.text = "Box 2";
    checkBox2.font = &font_h10;
    checkBox2.tabIndex = 17;

    guiRadioButton_Initialize(&radioButton1, (guiGenericWidget_t *)&guiMainForm);
    radioButton1.x = 10;
    radioButton1.y = 40;
    radioButton1.width = 80;
    radioButton1.height = 16;
    radioButton1.text = "Radio 1";
    radioButton1.font = &font_h10;
    radioButton1.tabIndex = 20;

    guiRadioButton_Initialize(&radioButton2, (guiGenericWidget_t *)&guiMainForm);
    radioButton2.x = 100;
    radioButton2.y = 40;
    radioButton2.width = 80;
    radioButton2.height = 16;
    radioButton2.text = "Radio 2";
    radioButton2.font = &font_h10;
    radioButton2.tabIndex = 21;

    guiCore_AddWidgetToCollection((guiGenericWidget_t *)&textLabel_time, (guiGenericContainer_t *)&guiMainForm);
    guiCore_AddWidgetToCollection((guiGenericWidget_t *)&checkBox1, (guiGenericContainer_t *)&guiMainForm);
    guiCore_AddWidgetToCollection((guiGenericWidget_t *)&checkBox2, (guiGenericContainer_t *)&guiMainForm);
    guiCore_AddWidgetToCollection((guiGenericWidget_t *)&radioButton1, (guiGenericContainer_t *)&guiMainForm);
    guiCore_AddWidgetToCollection((guiGenericWidget_t *)&radioButton2, (guiGenericContainer_t *)&guiMainForm);




    guiTextLabel_SetText(&textLabel_time, "Hi there!");
}



