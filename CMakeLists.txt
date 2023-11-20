cmake_minimum_required(VERSION 3.26)
project(nhf C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(nhf
        include/debugmalloc.h
        main.c
        #func_test.c
        include/menu.c
        include/vcard.c
        include/lista.c
)
