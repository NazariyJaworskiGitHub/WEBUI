CONFIG += c++11
CONFIG += console
CONFIG += no_keywords

#Wt Web ToolKit
#CONFIG      += no_keywords # so Qt won't #define any non-all-caps 'keywords'
#INCLUDEPATH += E:\Wt\wt-3.3.5-rc2_Boost_1_60_MinGW_4.9.1_x64\include\
#INCLUDEPATH += E:\Boost\boost_1_60_0
#LIBS += E:\Wt\wt-3.3.5-rc2_Boost_1_60_MinGW_4.9.1_x64\lib\libwt.a
#LIBS += E:\Wt\wt-3.3.5-rc2_Boost_1_60_MinGW_4.9.1_x64\lib\libwthttp.a
#LIBS += E:\Boost\boost_1_60_0\lib\libboost_signals-mgw49-mt-1_60.a
#LIBS += E:\Boost\boost_1_60_0\lib\libboost_system-mgw49-mt-1_60.a
#LIBS += E:\Boost\boost_1_60_0\lib\libboost_thread-mgw49-mt-1_60.a
#LIBS += E:\Boost\boost_1_60_0\lib\libboost_filesystem-mgw49-mt-1_60.a
#LIBS += E:\Boost\boost_1_60_0\lib\libboost_regex-mgw49-mt-1_60.a
#LIBS += E:\Boost\boost_1_60_0\lib\libboost_random-mgw49-mt-1_60.a
#LIBS += E:\Boost\boost_1_60_0\lib\libboost_program_options-mgw49-mt-1_60.a
#LIBS += E:\Boost\boost_1_60_0\lib\libboost_date_time-mgw49-mt-1_60.a
#LIBS += -lws2_32
#LIBS += -lwsock32

CONFIG      += no_keywords # so Qt won't #define any non-all-caps 'keywords'
INCLUDEPATH += E:\Wt\Wt_3.3.0_boost_1.54.0_mingw_4.8.0_x32\include\
INCLUDEPATH += E:\Boost\boost_1_54_0
LIBS += E:\Wt\Wt_3.3.0_boost_1.54.0_mingw_4.8.0_x32\lib\libwt.a
LIBS += E:\Wt\Wt_3.3.0_boost_1.54.0_mingw_4.8.0_x32\lib\libwthttp.a
LIBS += E:\Boost\boost_1_54_0\lib\libboost_signals-mgw48-mt-1_54.a
LIBS += E:\Boost\boost_1_54_0\lib\libboost_system-mgw48-mt-1_54.a
LIBS += E:\Boost\boost_1_54_0\lib\libboost_thread-mgw48-mt-1_54.a
LIBS += E:\Boost\boost_1_54_0\lib\libboost_filesystem-mgw48-mt-1_54.a
LIBS += E:\Boost\boost_1_54_0\lib\libboost_regex-mgw48-mt-1_54.a
LIBS += E:\Boost\boost_1_54_0\lib\libboost_random-mgw48-mt-1_54.a
LIBS += E:\Boost\boost_1_54_0\lib\libboost_program_options-mgw48-mt-1_54.a
LIBS += E:\Boost\boost_1_54_0\lib\libboost_date_time-mgw48-mt-1_54.a
LIBS += -lws2_32
LIBS += -lwsock32

#For debugging
CONFIG(debug, release|debug):DEFINES += _DEBUG_MODE

HEADERS += \
    webserver.h \
    webhelloworld.h \
    volumerender.h

SOURCES += \
    webserver.cpp \
    main.cpp \
    volumerender.cpp
