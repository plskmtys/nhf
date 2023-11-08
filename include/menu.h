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

//UNUSED
int fomenu(){
    printf("telefonkönyv\nFŐMENÜ\n");
    for(int i=0; i<4; i++) printf("(%d) %s\n", i+1, main_options[i]);
    printf("\n");
    int choice=0;
    scanf(" %d", &choice);
    return choice;
}
//END_UNUSED

char menukiir(const char **lista){
    char choice;
    for(int i=0; lista[i] != NULL; i++) printf("(%d) %s\n", i+1, lista[i]);
    printf("\n");
    scanf(" %c", &choice);
    return choice;
}

char *beker(const char *prompt){
    char *ans = "";
    printf("\n%s ", prompt);
    scanf(" %s", ans);
    return ans;
}

#endif //NHF_MENU_H
