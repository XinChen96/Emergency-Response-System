TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += core
QT += sql
QT += network

HEADERS += \
        maincontroller.h \
        ../db/db_manager.h \
        ../db/user_db.h \
        ../db/simulation_db.h \
        ../db/emergency_db.h \
        ../db/group_db.h \
        ../users/user.h \
        ../users/planner.h \
        ../users/civilian.h \
        ../users/dbitem.h \
        ../users/response.h \
        ../db/response_db.h \
        ../db/notification_db.h \
        db_table.h \
        clientthread.h \
        client.h \
        server.h


SOURCES += \
        main.cpp \
        maincontroller.cpp \
        ../db/db_manager.cpp \
        ../db/user_db.cpp \
        ../db/simulation_db.cpp \
        ../db/emergency_db.cpp \
        ../db/group_db.cpp \
        ../users/user.cpp \
        ../users/planner.cpp \
        ../users/civilian.cpp \
        ../users/dbitem.cpp \
	../users/response.cpp \
        ../db/response_db.cpp \
        ../db/notification_db.cpp \
        clientthread.cpp \
        client.cpp \
        server.cpp

SOURCES += ../googletest-master/googletest/src/gtest-all.cc

INCLUDEPATH +=  ../googletest-master                                   \
                ../googletest-master/googletest                        \
                ../googletest-master/googletest/include                \
                ../googletest-master/googletest/include/gtest


