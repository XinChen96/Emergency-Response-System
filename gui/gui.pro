#-------------------------------------------------
#
# Project created by QtCreator 2018-04-09T15:01:48
#
#-------------------------------------------------

#QT      += core gui
#QT      += sql
#QT      += webengine webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets core gui sql webengine webenginewidgets

TARGET = gui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp\
        ../controllers/maincontroller.cpp\
        ../db/db_manager.cpp\
        ../db/user_db.cpp\
        ../db/simulation_db.cpp\
        ../users/user.cpp\
        ../users/dbitem.cpp\
        ../users/simulation.cpp\
        ../users/civilian.cpp\
        ../users/group.cpp \
        ../db/group_db.cpp \
	../users/planner.cpp

HEADERS += \
        mainwindow.h\
        ../controllers/maincontroller.h\
        ../db/db_manager.h\
        ../db/simulation_db.h\
        ../db/user_db.h\
        ..//db/simulation_db.h\
        ../users/user.h\
        ../users/dbitem.h\
        ../users/simulation.h\
        ../users/civilian.h\
        ../users/planner.cpp \
        ../users/roles.h\

FORMS += \
        mainwindow.ui



RESOURCES += \
    map_resource.qrc \
    images.qrc
