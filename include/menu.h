#include <stdio.h>
#include <stdlib.h>
#include "vcard.h"
#include "debugmalloc.h"
#ifndef NHF_MENU_H
#define NHF_MENU_H

extern const char *main_options[];

extern const char *newc_options[];

extern const char *name_options[];

extern const char *org_options[];

extern const char *view_options[];

extern const char *address_options[];

void olvas(char *s, size_t len);

char menukiir(const char **lista);

char *beker(const char *prompt, char *dest, size_t size);

char *beker_keres(const char *prompt, char *dest, size_t size);

char contactmenu(contact *c);

char namemenu(contact *c);

void clear();

contact *edit_contact(contact *c, char *next);

#endif //NHF_MENU_H