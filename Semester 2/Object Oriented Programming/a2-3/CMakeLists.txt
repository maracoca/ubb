cmake_minimum_required(VERSION 3.27)
project(a2_3_maracoca C)

set(CMAKE_C_STANDARD 11)

add_executable(a2_3_maracoca
        domain.c
        ui.c
        domain.h
        repository.h
        repository.c
        service.h
        service.c
        dynamicArray.c
        undo_redo.c
        ui.h
)
