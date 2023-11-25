#include <stdio.h>
#include <stdlib.h>
#include "include/debugmalloc.h"
#include "include/vcard.h"
#include "include/menu.h"
#include "include/lista.h"
#include <string.h>

void read_vcard_file(char *filename, contact *c) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("nem sikerült megnyitni a %s nevű fájlt.\n", filename);
        return;
    }

    char line[512];
    while (fgets(line, sizeof(line), file)) {
        char *value = strchr(line, ':');
        if (value != NULL) {
            *value = '\0';
            value++;

            if (strcmp(line, "FN") == 0) {
                value[strcspn(value, "\n")] = 0;
                strncpy(c->fn, value, sizeof(c->fn));
            } else if (strcmp(line, "N") == 0) {
                value[strcspn(value, "\n")] = 0;
                sscanf(value, "%[^;];%[^;];%[^;];%[^;];%s", c->name.last, c->name.first, c->name.middle, c->name.prefix, c->name.suffix);
            } else if (strcmp(line, "TEL") == 0) {
                value[strcspn(value, "\n")] = 0;
                strncpy(c->phone, value, sizeof(c->phone));
            } else if (strncmp(line, "ADR", 3) == 0) {
                value[strcspn(value, "\n")] = 0;
                sscanf(value, ";;%[^;];%[^;];%[^;];%[^;];%s", c->address.street_no, c->address.city, c->address.county, c->address.zip, c->address.country);
            } else if (strcmp(line, "BDAY") == 0) {
                value[strcspn(value, "\n")] = 0;
                strncpy(c->bday, value, sizeof(c->bday));
            } else if (strcmp(line, "EMAIL") == 0) {
                value[strcspn(value, "\n")] = 0;
                strncpy(c->email, value, sizeof(c->email));
            }
        }
    }
    fclose(file);
    printf("\nsikeres beolvasás.\n");
}

int main(){
    contact c;
    c = InitContact(c);
    //char path[128] = "nhf/cards/";
    //char filename[128];
    //olvas(filename, sizeof(filename));
    //strcat(path, filename);
    read_vcard_file("cards/1.vcf", &c);
    printf("cím:\n%s\n", straddr(&c.address));
    printf("beolvasott adatok:\n%s\n%s\n%s\n%s\n", c.fn, c.phone, c.bday, c.email);
}