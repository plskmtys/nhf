#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#ifndef NHF_VCARD_H
#define NHF_VCARD_H

/** @brief Teljes név tárolására használt struktúra.*/
typedef struct fullname{
    char prefix[16];
    char first[96];
    char middle[96];
    char last[96];
    char suffix[16];
}fullname;

/** @brief Cím tárolására használt struktúra.*/
typedef struct address{
    //char type[64];
    char zip[16];
    char street_no[128];
    char city[96];
    char country[96];
    char county[96];
}address;

/** @brief Egy kontakt összes adatának tárolására használt struktúra.*/
typedef struct contact{
    char phone[20];
    char fn[324];
    fullname name;
    char email[256];
    address address;
    char bday[9];
    char note[256];
    char org[96];
    char title[96];
}contact;

fullname InitName(fullname empty);

contact InitContact(contact empty);

address InitAddress(address empty);

char *straddr(address *a);

char *strfn(fullname *n);

int writecard(char *filename, contact *out);

contact *readcard(char *filename, contact *c);

#endif //NHF_VCARD_H