// MALTEROS LAPÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁT
#include <stdio.h>
#include "menu.h"
#include "vcard.h"
#include <string.h>

/** @brief A főmenü opcióit tartalmazó lista.*/
const char *main_options[] = {
    "új kontakt",
    "kontaktok megtekintése",
    "keresés",
    "összes exportálása",
    "összes importálása",
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

void olvas(char *s, size_t len) {
    int ch;
    size_t i = 0;
    while ((ch = fgetc(stdin)) != '\n' && ch != EOF) if (i < len - 1) s[i++] = ch;
    s[i] = '\0';
}

void olvas1(char *s, size_t len) {
    //printf("Enter a string: ");
    fgets(s, len, stdin);
    s[strcspn(s, "\n")] = 0; // remove trailing newline
}

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
    //while ((getchar()) != '\n');
    clear();
    printf("%s:\t\t(max. %lu karakter)\n", prompt, size-1);
    //while ((getchar()) != '\n');
    olvas(dest, size);
    //while ((getchar()) != '\n');
    //debug
    printf("beolvasva: \"%s\"\n", dest);
    return dest;
}

/** @brief Kiírja a kontakt adatait tartalmazó menüt.
 * @param c A kontakt adatait tartalmazó struktúrára mutató pointer.
 * @returns A kontakt azon adatának sorszáma, amit megnyitunk szerkesztésre/megtekintésre.
*/
char contactmenu(contact *c){
    char choice;
    char *adr = straddr(&c->address);
    char *attr[] = {c->fn, c->phone, c->email, adr, c->bday, c->org, c->title, c->note, NULL};
    for(int i=0; attr[i]!=NULL; i++) printf("(%d) %s:  %s\n", i+1, newc_options[i], attr[i]);
    scanf(" %c", &choice);
    while ((getchar()) != '\n');
    return choice;
}

/** @brief Kiírja a kontakt nevét tartalmazó menüt.
 * @param c A kontakt adatait tartalmazó struktúrára mutató pointer.
 * @returns A név azon részének sorszáma, amit megnyitunk szerkesztésre/megtekintésre.
*/
char namemenu(contact *c){
    char choice;
    char *attr[] = {c->name.prefix, c->name.first, c->name.middle, c->name.last, c->name.suffix, NULL};
    for(int i=0; attr[i] != NULL; i++) printf("(%d) %s:  %s\n", i+1, name_options[i], attr[i]);
    scanf(" %c", &choice);
    while ((getchar()) != '\n');
    return choice;
}

/** @brief Kiírja a kontakt címének adatait tartalmazó menüt.
 * @param c A kontakt adatait tartalmazó struktúrára mutató pointer.
 * @returns A cím azon részének sorszáma, amit megnyitunk szerkesztésre/megtekintésre.
*/
char addressmenu(contact *c){
    char choice;
    char *attr[] = {c->address.street_no, c->address.city, c->address.county, c->address.zip, c->address.country, NULL};
    for(int i=0; attr[i] != NULL; i++) printf("(%d) %s:  %s\n", i+1, address_options[i], attr[i]);
    scanf(" %c", &choice);
    while ((getchar()) != '\n');
    return choice;
}

/** @brief Ez a függvény egy regular expressiont használ a képernyő törlésére. Nem platform- vagy compiler specifikus.
 * @bug CLion-ban az integrált terminálban nem töröl semmit.
*/
void clear(){
    printf("\e[1;1H\e[2J");
}

contact* edit_contact(contact *c, char *next){
    clear();
    //next = menukiir(newc_options);
    *next = contactmenu(c);
    switch (*next) {
        //név
        case '1': {
            while (*next != 'b' && *next != 'x') {
                clear();
                *next = namemenu(c);
                switch (*next) {
                    case '1':
                        beker(name_options[0], c->name.prefix, sizeof(c->name.prefix));
                        break;
                    case '2':
                        beker(name_options[1], c->name.first, sizeof(c->name.first));
                        break;
                    case '3':
                        beker(name_options[2], c->name.middle, sizeof(c->name.middle));
                        break;
                    case '4':
                        beker(name_options[3], c->name.last, sizeof(c->name.last));
                        break;
                    case '5':
                        beker(name_options[4], c->name.suffix, sizeof(c->name.suffix));
                        break;
                    default:
                        break;
                }
            }
            strcpy(c->fn, strfn(&c->name));
            *next = '0';
            break; //endcase nev
        }
        //tel
        case '2':
            beker(newc_options[1], c->phone, sizeof(c->phone));
            break; //endcase tel
        //email
        case '3':
            beker(newc_options[2], c->email, sizeof(c->email));
            break; //endcase email
        //address
        case '4':
            //uj->address = InitAddress(uj->address);
            while (*next != 'x' && *next != 'b') {
                clear();
                *next = addressmenu(c);
                switch (*next) {
                    //TODO cím
                    case '1':
                        //utca, hsz
                        beker(address_options[0], c->address.street_no, sizeof(c->address.street_no));
                        break;
                    case '2':
                        //varos
                        beker(address_options[1], c->address.city, sizeof(c->address.city));
                        break;
                    case '3':
                        //megye
                        beker(address_options[2], c->address.county, sizeof(c->address.county));
                        break;
                    case '4':
                        //irsz.
                        beker(address_options[3], c->address.zip, sizeof(c->address.zip));
                        break;
                    case '5':
                        //orszag
                        beker(address_options[4], c->address.country, sizeof(c->address.country));
                        break;
                }
            }
            *next = '0';
            break; //endcase address
        //bday
        case '5':
            beker(newc_options[4], c->bday, sizeof(c->bday));
            break; //endcase bday
        //org
        case '6':
            beker(newc_options[5], c->org, sizeof(c->org));
            break; //endcase org
        //title
        case '7':
            beker(newc_options[6], c->title, sizeof(c->title));
            break; //endcase title
        //note
        case '8':
            beker(newc_options[7], c->note, sizeof(c->note));
            break; //endcase note
        //save
        case 's':
            /*code for save action*/
            break; //endcase save
        default:
            clear();
            break;
    }
    return c;
}