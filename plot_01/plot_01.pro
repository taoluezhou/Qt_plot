#-------------------------------------------------
#
# Project created by QtCreator 2019-06-03T17:16:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = plot_01
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    globals.cpp \
    subwindow.cpp \
    drawing.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    globals.h \
    subwindow.h \
    drawing.h \
    qcustomplot.h

FORMS    += mainwindow.ui \
    subwindow.ui \
    drawing.ui
