cmake_minimum_required(VERSION 3.27)
project(oop_a6_7_maracoca)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(oop_a6_7_maracoca
        main.cpp
        Movie.cpp
        Movie.h
        Repository.cpp
        Repository.h
        service.cpp
        service.h
        ui.cpp
        ui.h
        repoTest.cpp
        serviceTest.cpp
        movieTest.cpp
        FileWatchList.cpp
        csvWL.cpp
        HTMLwl.cpp
        WatchList.cpp
        Exceptions.cpp)
