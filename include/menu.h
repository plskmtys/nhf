//
// Created by Matyi on 2023. 10. 31..
//
#include <stdio.h>
#include "debugmalloc.h"
#ifndef NHF_MENU_H
#define NHF_MENU_H

typedef enum mainmenu {
    newc = 0,
    browse = 1,
    search = 2,
    exportall = 3
}mainmenu;

typedef enum newcon{
    name = 0,
    num = 1,
    mail = 2,
    addr = 3,
    bday = 4,
    note = 5,
    org = 6,
    title = 7
}newcon;

const char *main_options[] = {
    "új kontakt",
    "kontaktok megtekintése",
    "keresés",
    "összes exportálása",
    NULL
};

const char *newc_options[] = {
    "név",
    "telefonszám",
    "email",
    "cím",
    "születésnap",
    "cég",
    "foglalkozás",
    "megjegyzés",
    NULL
};

const char *view_options[] = {
    "szerkesztés",
    "exportálás",
    "törlés",
    NULL
};

int fomenu(){
    printf("telefonkönyv\nFŐMENÜ\n");
    for(int i=0; i<4; i++) printf("(%d) %s\n", i+1, main_options[i]);
    printf("\n");
    int choice=0;
    scanf(" %d", &choice);
    return choice;
}

int menukiir(const char **lista){
    int choice=0;
    for(int i=0; lista[i] != NULL; i++) printf("(%d) %s\n", i+1, lista[i]);
    printf("\n");
    scanf(" %d", &choice);
    return choice;
}

#endif //NHF_MENU_H
