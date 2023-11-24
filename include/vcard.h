#include <stdio.h>
#include <stdlib.h>

#ifndef NHF_VCARD_H
#define NHF_VCARD_H

/** @brief Teljes név tárolására használt struktúra.*/
typedef struct fullname{
    char prefix[16];
    char first[128];
    char middle[128];
    char last[128];
    char suffix[16];
}fullname;

/** @brief Cím tárolására használt struktúra.*/
typedef struct address{
    //char type[64];
    char zip[16];
    char street_no[128];
    char city[128];
    char country[128];
    char county[128];
}address;

/** @brief Egy kontakt összes adatának tárolására használt struktúra.*/
typedef struct contact{
    char phone[20];
    char fn[420];
    fullname name;
    char email[256];
    address address;
    char bday[9];
    char note[512];
    char org[128];
    char title[128];
}contact;

fullname InitName(fullname empty);

contact InitContact(contact empty);

address InitAddress(address empty);

char *straddr(address *a);

char *strfn(fullname *n);

void writecard(char *filename, contact *out);

contact *readcard(char *filename);

#endif //NHF_VCARD_H