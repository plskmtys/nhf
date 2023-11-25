#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vcard.h"

/** @brief Egy nevet inicializál, üres értékekkel tölti fel.
 *  @returns Üres értékekkel feltöltött, fullname típusú változó.
*/

fullname InitName(fullname empty){
    empty.first[0] = '\0';
    empty.last[0] = '\0';
    empty.middle[0] = '\0';
    empty.prefix[0] ='\0';
    empty.suffix[0] ='\0';
    return empty;
}


/** @brief Egy címet inicializál, üres értékekkel tölti fel.
 *  @returns Üres értékekkel feltöltött, address típusú változó.
*/

address InitAddress(address empty){
    empty.street_no[0] = '\0';
    empty.city[0] = '\0';
    empty.zip[0]= '\0';
    empty.county[0] = '\0';
    empty.country[0] = '\0';
    //empty.type[0] = '\0';
    return empty;
}


/** @brief Egy kontaktot inicializál, üres értékekkel tölti fel.
 * @returns Üres értékekkel feltöltött, contact típusú változó.
*/

contact InitContact(contact empty){
    empty.phone[0]='\0';
    empty.fn[0] = '\0';
    fullname defaultname;
    empty.name = InitName(defaultname);
    empty.email[0] = '\0';
    address defaultaddress;
    empty.address = InitAddress(defaultaddress);
    empty.bday[0] = '\0';
    empty.org[0] = '\0';
    empty.title[0] = '\0';
    empty.note[0] = '\0';
    return empty;
}

char *straddr(address *a){
    char *ret = (char*) malloc(sizeof(*a)+5*sizeof(char));
    char *attr[] = {
            a->zip,
            a->city,
            a->street_no,
            a->county,
            a->country
    };
    for(int i=0; i<5; i++) {
        if (attr[i][0] != '\0') {
            strcat(ret, attr[i]);
            if (i != 4) strcat(ret, " ");
        }
    }
    return ret;
}

char *strfn(fullname *n){
    char *ret = (char*) malloc(sizeof(*n));
    char *attr[] = {
            n->prefix,
            n->first,
            n->middle,
            n->last,
            n->suffix
    };
    for(int i=0; i<5; i++) if(attr[i][0] != '\0') sprintf(ret, "%s %s", ret, attr[i]);
    return ret;
}

/** @brief A paraméterként megadott contact típusú változó adatait vCard kiterjesztésű fájlba írja.
 * @param filename Kimenő fájl neve
 * @param out A kiírandó contact típusú változó
 * @todo hibakezelés
*/
void writecard(char *filename, contact *out){
    sprintf(filename, "cards/%s.vcard", filename);
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "BEGIN:VCARD\nVERSION:4.0\n");
    fprintf(fp, "FN:%s\n", out->fn);
    fprintf(fp, "N:%s;%s;%s;%s;%s\n", out->name.last, out->name.first, out->name.middle, out->name.prefix, out->name.suffix);
    fprintf(fp, "TEL:%s\n", out->phone);
    fprintf(fp, "ADDR;TYPE=home:;;%s;%s;%s;%s;%s\n", out->address.street_no, out->address.city, out->address.county, out->address.zip, out->address.country);
    fprintf(fp, "BDAY:%s\n",out->bday);
    fprintf(fp, "EMAIL:%s\n", out->email);
    fprintf(fp, "NOTE:%s\n", out->note);
    fprintf(fp, "END:VCARD");
}

contact *readcard(char *filename, contact *c) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Nem sikerült megnyitni a fájlt: %s\n", filename);
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
    printf("\nSikeres beolvasás.\n");
    return c;
}