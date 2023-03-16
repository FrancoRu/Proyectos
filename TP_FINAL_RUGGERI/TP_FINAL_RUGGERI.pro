QT       += core gui \
            multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
SOURCES += \
    GUI/inicio.cpp \
    main.cpp \
    Ships/barco.cpp \
    Ships/crucero.cpp \
    Ships/destructor.cpp \
    LogicGame/gestor.cpp \
    LogicGame/juego.cpp \
    Ships/lanchacom.cpp \
    LogicGame/mapa.cpp \
    Ships/portaaviones.cpp \
    Ships/submarino.cpp

HEADERS += \
    GUI/inicio.h \
    Ships/barco.h \
    Ships/crucero.h \
    Ships/destructor.h \
    LogicGame/gestor.h \
    LogicGame/juego.h \
    Ships/lanchacom.h \
    LogicGame/mapa.h \
    Ships/portaaviones.h \
    Ships/submarino.h

FORMS += \
    inicio.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
