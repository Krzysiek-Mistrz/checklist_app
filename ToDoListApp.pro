QT += widgets

TARGET = ToDoListApp
TEMPLATE = app

SOURCES +=  src/main.cpp \ 
            src/main_window.cpp

HEADERS += include/main_window.hpp

INCLUDEPATH += $$PWD/include

RESOURCES += resources/resources.qrc