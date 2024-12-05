cmake_minimum_required(VERSION 3.28)
project(oop_a8_9_maracoca)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

find_package(Qt6 COMPONENTS
        Core
        Widgets
        REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(oop_a8_9_maracoca
        csvWL.cpp
        csvWL.h
        Exceptions.cpp
        Exceptions.h
        FileWatchList.cpp
        FileWatchList.h
        HTMLwl.cpp
        HTMLwl.h
        main.cpp
        Movie.cpp
        Movie.h
        Repository.cpp
        Repository.h
        service.cpp
        service.h
        ui.cpp
        ui.h
        appgui.cpp
        appgui.h
        appgui.ui
        user.cpp
        user.h
        user.ui
        admin.cpp
        admin.h
        admin.ui
        watchlisttablemodel.cpp
        watchlisttablemodel.h
)


#find_package(Qt6Widgets REQUIRED)
target_link_libraries(oop_a8_9_maracoca
        Qt::Core
        Qt6::Widgets
)