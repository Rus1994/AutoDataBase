QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AbstractDataWindow.cpp \
    CarsWindow.cpp \
    ManufactFirmsWindow.cpp \
    ModelsCarsWindow.cpp \
    OwnersWindow.cpp \
    main.cpp \
    AutoDataBase.cpp

HEADERS += \
    AbstractDataWindow.h \
    AutoDataBase.h \
    CarsWindow.h \
    ManufactFirmsWindow.h \
    ModelsCarsWindow.h \
    OwnersWindow.h

FORMS += \
    AbstractDataWindow.ui \
    AutoDataBase.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
