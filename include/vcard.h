#ifndef VCARD_H
#define VCARD_H

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
    fullname name;
    char *email;
    address address1;
    char *bday;
    char *note;
    char *org;
    char *title;
}contact;

#endif