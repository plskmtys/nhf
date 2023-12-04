cmake_minimum_required(VERSION 3.26)
project(nhf C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(nhf
        include/debugmalloc.h
        main.c
        #func_test.c
        include/menu.c
        include/vcard.c
        include/lista.c
)
