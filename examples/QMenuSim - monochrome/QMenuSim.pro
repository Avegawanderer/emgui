#-------------------------------------------------
#
# Project created by QtCreator 2013-11-15T11:14:14
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QMenuSim
TEMPLATE = app

INCLUDEPATH = ./
INCLUDEPATH += ./gui_top/
INCLUDEPATH += ../common/
INCLUDEPATH += ../../source/guiWidgets/
INCLUDEPATH += ../../source/guiWidgets/
INCLUDEPATH += ../../source/guiCore/
INCLUDEPATH += ../../source/utils/
INCLUDEPATH += ../../source/guiGraphics/
INCLUDEPATH += ../../source/guiGraphLib/

SOURCES += main.cpp\
		mainwindow.cpp \
    ../common/pixeldisplay.cpp \
    ../../source/guiCore/guiCore.c \
	gui_top/guiTop.c \
    ../../source/utils/utils.c \
    ../common/keydriver.cpp \
    ../../source/guiWidgets/guiPanel.c \
    ../../source/guiWidgets/guiTextLabel.c \
    ../../source/guiCore/guiCoreMemory.c \
    ../../source/guiCore/guiCoreTimers.c \
    ../../source/guiGraphics/guiGraphWidgets.c \
    gui_top/guiMainForm.c \
    ../../source/guiGraphics/guiGraphPanel.c \
    ../../source/guiGraphLib/lcd_font_6x8_mono.c \
    ../../source/guiGraphLib/lcd_font_h10.c \
    ../../source/guiGraphLib/lcd_font_h10_bold.c \
    ../../source/guiGraphLib/lcd_font_h12.c \
    ../../source/guiGraphLib/lcd_font_h32.c \
    ../../source/guiGraphLib/lcd_lib.c \
    ../../source/guiGraphLib/lcd_lib_font.c \
    ../../source/guiGraphLib/lcd_lib_graph.c \
    ../../source/guiGraphLib/portable/lcd_lib_graph_3310.c \
    ../../source/guiWidgets/guiCheckBox.c \
    ../../source/guiGraphics/guiGraphCheckbox.c \
    ../../source/guiGraphics/guiGraphTextLabel.c \
    ../../source/guiWidgets/guiRadioButton.c \
    ../../source/guiGraphics/guiGraphRadioButton.c
	

HEADERS  += mainwindow.h \
    ../common/pixeldisplay.h \
	../../source/guiGraphics_monochrome/guiFonts.h \
	../../source/guiGraphics_monochrome/guiImages.h \
	../../source/guiGraphics_monochrome/guiGraphHAL.h \
    ../../source/guiGraphics_monochrome/guiGraphPrimitives.h \
	../../source/guiGraphics_monochrome/guiGraphWidgets.h \
	../../source/guiCore/guiEvents.h \
    ../../source/guiCore/guiCore.h \
	../../source/guiCore/guiWidgets.h \
    gui_top/guiConfig.h \
	gui_top/guiTop.h \
    ../../source/utils/utils.h \
    ../common/keydriver.h \
    ../../source/guiGraphics/guiGraphWidgets.h \
    gui_top/lcd_lib_config.h \
    gui_top/guiMainForm.h \
    ../../source/guiWidgets/guiPanel.h \
    ../../source/guiWidgets/guiTextLabel.h \
    ../../source/guiGraphics/guiGraphPanel.h \
    ../../source/guiGraphLib/guiGraphLib.h \
    ../../source/guiGraphLib/lcd_font_typedef.h \
    ../../source/guiGraphLib/lcd_lib.h \
    ../../source/guiGraphLib/lcd_lib_private.h \
    ../../source/guiWidgets/guiCheckBox.h \
    ../../source/guiGraphics/guiGraphCheckbox.h \
    ../../source/guiGraphics/guiGraphTextLabel.h \
    ../../source/guiWidgets/guiRadioButton.h \
    ../../source/guiGraphics/guiGraphRadioButton.h
    
    
	


FORMS    += mainwindow.ui

