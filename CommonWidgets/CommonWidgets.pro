QT = gui widgets multimedia

TARGET = CommonWidgets
TEMPLATE = lib
DEFINES += COMMONWIDGETS_LIB
DEFINES += MATHEMATICS_LIB
DEFINES += TASKFILEMANAGER_LIB

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
    GraphEdit.cpp \
    KeyBoard.cpp \
    KeyboardButton.cpp \
    Panel.cpp \
    XPGedit.cpp \
    XPcursor.cpp \
    commonwidgets.cpp

HEADERS += \
    commonwidgets.h \
    CommonWidgets_global.h \
    GraphEdit.h \
    KeyBoard.h \
    KeyboardButton.h \
    Panel.h \
    XPGedit.h \
    XPcursor.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../FormulaPainter/release/ -lFormulaPainter
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../FormulaPainter/debug/ -lFormulaPainter

INCLUDEPATH += $$PWD/../FormulaPainter
DEPENDPATH += $$PWD/../FormulaPainter

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Mathematics/release/ -lMathematics
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Mathematics/debug/ -lMathematics

INCLUDEPATH += $$PWD/../Mathematics
DEPENDPATH += $$PWD/../Mathematics

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../TaskFileManager/release/ -lTaskFileManager
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../TaskFileManager/debug/ -lTaskFileManager

INCLUDEPATH += $$PWD/../TaskFileManager
DEPENDPATH += $$PWD/../TaskFileManager

RESOURCES += \
  Resources.qrc
