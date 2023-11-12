#include <stdio.h>
#include <stdlib.h>

#ifndef NHF_VCARD_H
#define NHF_VCARD_H

typedef struct fullname{
    char *prefix;
    char *first;
    char *middle;
    char *last;
    char *suffix;
}fullname;

typedef struct address{
    char *type;
    int zip;
    char *street_no;
    char *city;
    char *country;
    char *county;
}address;

typedef struct contact{
    char *phone;
    char *fn;
    fullname name;
    char *email;
    address address1;
    char *bday;
    char *note;
    char *org;
    char *title;
}contact;

address StrToAddr(char *instr);

char *StrToDate(char *instr);

fullname InitName(fullname empty);

contact InitContact(contact empty);

void writecard(char *filename, contact out);

#endif //VCARD_H