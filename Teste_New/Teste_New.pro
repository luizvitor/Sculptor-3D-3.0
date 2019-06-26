#-------------------------------------------------
#
# Project created by QtCreator 2019-06-07T07:16:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Teste_New
TEMPLATE = app


SOURCES += main.cpp\
    cutbox.cpp \
    cutellipsoid.cpp \
    cutsphere.cpp \
    cutvoxel.cpp \
    dialognew.cpp \
    dialogopen.cpp \
    geometricfigure.cpp \
        mainwindow.cpp \
        plotter.cpp \
    plottercolor.cpp \
    putbox.cpp \
    putellipsoid.cpp \
    putsphere.cpp \
    putvoxel.cpp \
    sculptor.cpp

HEADERS  += mainwindow.h \
    cutbox.h \
    cutellipsoid.h \
    cutsphere.h \
    cutvoxel.h \
    dialognew.h \
    dialogopen.h \
    geometricfigure.h \
    plotter.h \
    plottercolor.h \
    putbox.h \
    putellipsoid.h \
    putsphere.h \
    putvoxel.h \
    sculptor.h

FORMS    += mainwindow.ui \
    dialognew.ui \
    dialogopen.ui

RESOURCES += \
    resource.qrc
