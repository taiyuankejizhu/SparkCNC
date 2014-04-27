#-------------------------------------------------
#
# Project created by QtCreator 2014-02-22T15:19:36
#
#-------------------------------------------------

QT       += core gui

TARGET = SparkCNC
TEMPLATE = app


SOURCES += main.cpp\
    qcheck.cpp \
    qcombox.cpp \
    seconlevel_f3.cpp \
    toplevel.cpp \
    qcomboxtime.cpp \
    maininterface.cpp \
    seconlevel_f4.cpp \
    qindicate.cpp \
    seconlevel_f5.cpp \
    seconlevel_f6.cpp \
    keyboard.cpp \
    mesgbox.cpp \
    qcommand.cpp \
    fm25v02.c \
    sparkthread.cpp \
    sparkinfo.cpp \
    groupdialog.cpp \
    coordialog.cpp \
    autodialog.cpp \
    qparameter.cpp \
    scanthread.cpp

HEADERS  += \
    qcheck.h \
    qcombox.h \
    seconlevel_f3.h \
    toplevel.h \
    qcomboxtime.h \
    maininterface.h \
    setting.h \
    seconlevel_f4.h \
    qindicate.h \
    seconlevel_f5.h \
    seconlevel_f6.h \
    keyboard.h \
    en_keymap.h \
    mesgbox.h \
    qcommand.h \
    fm25v02.h \
    sparkthread.h \
    sparkinfo.h \
    groupdialog.h \
    coordialog.h \
    autodialog.h \
    qparameter.h \
    scanthread.h

FORMS    += \
    seconlevel_f3.ui \
    toplevel.ui \
    toplevel.ui \
    seconlevel_f3.ui \
    maininterface.ui \
    seconlevel_f4.ui \
    seconlevel_f5.ui \
    seconlevel_f6.ui \
    keyboard.ui \
    mesgbox.ui \
    groupdialog.ui \
    coordialog.ui \
    autodialog.ui

RESOURCES += \
    resource.qrc

OTHER_FILES += \
    icon.png \
    en.qm

TRANSLATIONS+=en.ts
