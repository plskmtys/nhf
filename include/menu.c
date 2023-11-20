#include <stdio.h>
#include "menu.h"
#include "vcard.h"

/** @brief A főmenü opcióit tartalmazó lista.*/
const char *main_options[] = {
    "új kontakt",
    "kontaktok megtekintése",
    "keresés",
    "összes exportálása",
    NULL
};

/** @brief Az új kontakt létrehozásánál megjelenített opciókat tartalmazó lista.*/
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

/** @brief A név opcióit tartalmazó lista.*/
const char *name_options[] = {
    "név előtag",
    "keresztnév",
    "második név",
    "vezetéknév",
    "név utótag",
    NULL
};

/** @brief A cég opcióit tartalmazó lista.*/
const char *org_options[] = {
    "szervezet",
    "beosztás",
    NULL
};

/** @brief A megtekintés opcióit tartalmazó lista.*/
const char *view_options[] = {
    "szerkesztés",
    "exportálás",
    "törlés",
    NULL
};

/** @brief A cím opcióit tartalmazza.*/
const char *address_options[] = {
    "utca, házszám",
    "város",
    "megye",
    "irányítószám",
    "ország"
};

/** @brief Kiírja az argumentumként megadott lista elemeit számozva, külön-külön sorba.
 *  A felhasználó megadhatja a szabványos bemeneten az általa választott opció sorszámát.
 * @param lista Lista, amely tartalmazza a kiírandó opciókat.
 * @returns Visszatér a felhasználótól bekért karakterrel.
*/
char menukiir(const char **lista){
    char choice;
    for(int i=0; lista[i] != NULL; i++) printf("(%d) %s\n", i+1, lista[i]);
    printf("\n");
    scanf(" %c", &choice);
    return choice;
}

/** @brief A paraméterben megadott szöveg kiírása után bekér a felhasználótól egy karaktert a szabványos bemeneten.
 * @param prompt
 * @returns Visszatér a felhasználótól bekért karakterrel.
*/ 
char *beker(const char *prompt, char* dest, size_t size){
    printf("%s:\t\t(max. %lu karakter)\n", prompt, size-1);
    scanf(" %s", dest);
    fflush(stdin);
    return dest;
}

char contactmenu(contact *c){
    char choice;
    char *adr = straddr(&c->address);
    char *attr[] = {c->fn, c->phone, c->email, adr, c->bday, c->org, c->title, c->note, NULL};
    for(int i=0; attr[i]!=NULL; i++) printf("(%d) %s:  %s\n", i+1, newc_options[i], attr[i]);
    scanf(" %c", &choice);
    return choice;
}

char namemenu(contact *c){
    char choice;
    char *attr[] = {c->name.prefix, c->name.first, c->name.middle, c->name.last, c->name.suffix, NULL};
    for(int i=0; attr[i] != NULL; i++) printf("(%d) %s:  %s\n", i+1, name_options[i], attr[i]);
    scanf(" %c", &choice);
    return choice;
}
