#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"
#ifndef NHF_MENU_H
#define NHF_MENU_H

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

const char *name_options[] = {
    "név előtag",
    "keresztnév",
    "második név",
    "vezetéknév",
    "név utótag",
    NULL
};

const char *org_options[] = {
    "szervezet",
    "beosztás",
    NULL
};

const char *view_options[] = {
    "szerkesztés",
    "exportálás",
    "törlés",
    NULL
};

char menukiir(const char **lista);

char *beker(const char *prompt);

#endif //NHF_MENU_H