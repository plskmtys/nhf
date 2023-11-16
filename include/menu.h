#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"
#ifndef NHF_MENU_H
#define NHF_MENU_H

extern const char *main_options[];

extern const char *newc_options[];

extern const char *name_options[];

extern const char *org_options[];

extern const char *view_options[];

extern const char *address_options[];

char menukiir(const char **lista);

char *beker(const char *prompt);

#endif //NHF_MENU_H