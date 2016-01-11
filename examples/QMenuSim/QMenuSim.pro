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
INCLUDEPATH += ../../source/guiCore/
INCLUDEPATH += ../../source/guiGraphics/
INCLUDEPATH += ../../source/guiGraphLib/


SOURCES += main.cpp\
        mainwindow.cpp \
        gui_top/guiTop.c \
        gui_top/guiMainForm.c \
        gui_top/guiPanel1.c \
        gui_top/guiPanel2.c \
	../common/pixeldisplay.cpp \
        ../../source/guiCore/guiCore.c \
        ../../source/guiCore/guiCoreTimers.c \
        ../../source/guiCore/guiCoreMemory.c \
        ../../source/guiWidgets/guiButton.c \
        ../../source/guiWidgets/guiRadioButton.c \
        ../../source/guiWidgets/guiPanel.c \
	../../source/guiWidgets/guiTextLabel.c \
	../../source/guiWidgets/guiCheckBox.c \
        ../../source/guiGraphics/guiGraphWidgets.c \
        ../../source/guiGraphics/guiGraphImages.c \
        ../../source/guiGraphLib/lcd_lib.c \
        ../../source/guiGraphLib/lcd_lib_font.c \
        ../../source/guiGraphLib/lcd_lib_graph.c \
        ../../source/guiGraphLib/lcd_font_h32.c \
        ../../source/guiGraphLib/lcd_font_h12.c \
        ../../source/guiGraphLib/lcd_font_h10_bold.c \
        ../../source/guiGraphLib/lcd_font_h10.c \
        ../../source/guiGraphLib/lcd_font_6x8_mono.c


HEADERS  += mainwindow.h \
        gui_top/guiTop.h \
        gui_top/guiMainForm.h \
        gui_top/guiPanel1.h \
        gui_top/guiPanel2.h \
        gui_top/guiConfig.h \
        gui_top/lcd_lib_config.h \
        ../common/pixeldisplay.h \
        ../../source/guiCore/guiCore.h \
        ../../source/guiCore/guiCoreMemory.h \
        ../../source/guiCore/guiEvents.h \
        ../../source/guiCore/guiCoreTimers.h \
        ../../source/guiCore/guiWidgets.h \
        ../../source/guiWidgets/guiButton.h \
        ../../source/guiWidgets/guiRadioButton.h \
        ../../source/guiWidgets/guiPanel.h \
	../../source/guiWidgets/guiTextLabel.h \
	../../source/guiWidgets/guiCheckBox.h \
        ../../source/guiGraphics/guiGraphWidgets.h \
        ../../source/guiGraphics/guiGraphImages.h \
        ../../source/guiGraphLib/guiGraphLib.h \
        ../../source/guiGraphLib/lcd_lib.h \
        ../../source/guiGraphLib/lcd_lib_private.h \
        ../../source/guiGraphLib/lcd_font_typedef.h

	

FORMS    += mainwindow.ui

