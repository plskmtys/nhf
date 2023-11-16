#include <stdio.h>
#include <stdlib.h>

#ifndef NHF_VCARD_H
#define NHF_VCARD_H

/** @brief Teljes név tárolására használt struktúra.*/
typedef struct fullname{
    char prefix[10];
    char *first;
    char *middle;
    char *last;
    char suffix[10];
}fullname;

/** @brief Cím tárolására használt struktúra.*/
typedef struct address{
    char *type;
    char zip[12];
    char *street_no;
    char *city;
    char *country;
    char *county;
}address;

/** @brief Egy kontakt összes adatának tárolására használt struktúra.*/
typedef struct contact{
    char phone[20];
    char *fn;
    fullname name;
    char *email;
    address address;
    char bday[6];
    char *note;
    char *org;
    char *title;
}contact;

fullname InitName(fullname empty);

contact InitContact(contact empty);

address InitAddress();

void writecard(char *filename, contact out);

#endif //VCARD_H