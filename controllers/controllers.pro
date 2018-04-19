TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += sql

SOURCES += main.cpp \
<<<<<<< HEAD
    maincontroller.cpp \
    ../db/user_db.cpp \
    ../db/db_manager.cpp

HEADERS += \
    maincontroller.h \
    ../db/user_db.h \
    ../db/db_manager.h
=======
    maincontroller.cpp\
    ../db/db_manager.cpp\
    ../db/user_db.cpp


HEADERS += \
    maincontroller.h\
    ../db/db_manager.h\
    ../db/user_db.h

>>>>>>> 3a18b025449d259385e369773772235841e5de4c
