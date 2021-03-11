QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    RF24/utility/RPi/spi.cpp \
    RF24/RF24.cpp \
    comm.cpp \
    main.cpp \
    mainwindow.cpp \
    RF24/utility/RPi/bcm2835.c \

HEADERS += \
    RF24/utility/RPi/bcm2835.h \
    RF24/utility/RPi/includes.h \
    RF24/utility/RPi/interrupt.h \
    RF24/utility/RPi/spi.h \
    RF24/utility/includes.h \
    RF24/nRF24L01.h \
    RF24/printf.h \
    RF24/RF24.h \
    RF24/RF24_config.h \
    comm.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

LIBS += -lrf24

DISTFILES += \
    RF24/library.json \
    RF24/librf24.so.1.3.3 \
    RF24/configure \
    RF24/keywords.txt \
    RF24/library.properties
