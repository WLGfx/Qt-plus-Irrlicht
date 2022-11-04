QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    irrlichtwindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    irrlichtwindow.h \
    mainwindow.h

FORMS += \
    irrlichtwindow.ui \
    mainwindow.ui

LIBS += -LC:\src\irrlicht-1.8.5\bin\Win64-VisualStudio -lIrrlicht
INCLUDEPATH += C:\src\irrlicht-1.8.5\include

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
