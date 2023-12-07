#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "vcard.h"
#include "debugmalloc.h"
#include "lista.h"
#include "menu.h"

/** @brief Láncolt lista hosszát számolja meg, laborhoz használt függvény átalakított verziója.
 * @param eleje A lista eleje.
*/
int listahossz(ListaElem *elso){
    ListaElem *eleje = elso;
    int hossz=0;
    for (ListaElem *current = eleje; current != NULL; current=current->next) hossz++;
    return hossz;
}

/** @brief Láncolt listát szabadít fel, laborhoz használt függvény átalakított verziója.
 * @param eleje A lista eleje.
*/
void lista_free(ListaElem *eleje) {
    ListaElem *p = eleje;
    while (p != NULL) {
        ListaElem *tmp = p->next;
        free(p);
        p = tmp;
    }
}

/** @brief Láncolt lista elejére szúr be adatot, laborhoz használt függvény átalakított verziója.
 * @param eleje A lista eleje.
 * @param adat A beszúrandó adat.
*/
ListaElem *elore_beszur(ListaElem *eleje, contact adat) {
   ListaElem *uj;
   uj = (ListaElem*) malloc(sizeof(ListaElem));
   uj->adat = adat;
   uj->next = eleje;
   return uj;
}

/** @brief Láncolt lista utolsó elemét keresi meg, laborhoz használt függvény átalakított verziója.
 * @param eleje A lista eleje.
*/
ListaElem *GetLastItem(ListaElem *eleje){
    ListaElem *last;
    for (last = eleje; ; last=last->next)
    {
        if(last->next  == NULL) return last; 
    }
    return eleje;
}

/** @brief Láncolt lista végére szúr be adatot, laborhoz használt függvény átalakított verziója.
 * @param eleje A lista eleje.
 * @param mit A beszúrandó adat.
*/
ListaElem *vegere_beszur(ListaElem *eleje, contact mit) {
    ListaElem *uj = (ListaElem *) malloc(sizeof(ListaElem)); /* Új elem */
 
    uj->adat = mit; /* Adat bemásolása */
    uj->next = NULL; /* Ez lesz a lista vége, ezért NULL a következő elem */
    if (eleje == NULL) {
        return uj; /* Ha üres a lista, akkor ez lesz az eleje */
    } else {
        ListaElem *p = eleje; /* Elmegyünk az utolsó elemig (aminek a pointere NULL pointer) */
        while (p->next != NULL) p = p->next;
        p->next = uj; /* És hozzáfűzzük */
        return eleje;
    }
}

/** @brief Megkeres egy kifejezést az adatbázisban, és visszaad egy listát az összes olyan kontakttal, ami tartalmazza a keresett kifejezést valamilyen mezőben.
 * @param eleje A láncolt lista (első elemének címe), amelyben megkeresi a kifejezést.
 * @param keresett A keresett kifejezés (string).
 * @returns Láncolt lista a keresési eredményekkel.
*/
ListaElem *keres(ListaElem *eleje, char *needle){
    ListaElem *iter;
    ListaElem *ret = NULL;
    char *datastr;
    for (iter = eleje; iter != NULL; iter=iter->next) {
        datastr = (char *) malloc(sizeof(*iter) + sizeof(char) * 60);
        sprintf(datastr, "%s %s %s %s %s %s%c", iter->adat.fn, iter->adat.phone, straddr(&iter->adat.address),
                iter->adat.email, iter->adat.org, iter->adat.title, '\0');
        if (strstr(datastr, needle) != NULL) ret = vegere_beszur(ret, iter->adat);
        free(datastr);
    }
    return ret;
}

/** @brief Dinamikus memórával egy hosszú sort beolvasó függvény. A program végül nem használja, a sok realloc helyett hatékonyabb 
 * a tipikusnál nem sokkal nagyobb (vagy szabványos adatok, pl. irányítószám esetén a szabvány által meghatározott maximális méretű) 
 * terület foglalása.
 * @returns Dinamikusan foglalt string
*/
char* sor_olvas() {
    size_t bufsize = 32;
    size_t position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;
    if (!buffer) {
        printerror("sor_olvas: memóriafoglalási hiba");
        fprintf(stderr, "sor_olvas: memóriafoglalási hiba\n");
        exit(EXIT_FAILURE);
    }
    while (1) {
        c = getchar();
        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }
        position++;
        if (position >= bufsize) {
            bufsize += 32;
            buffer = realloc(buffer, bufsize);
            if (!buffer) {
                printerror("sor_olvas: memóriafoglalási hiba");
                fprintf(stderr, "sor_olvas: memóriafoglalási hiba\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

/** @brief Kiírja egy kontaktokból álló láncolt lista elemeinek nevét és telefonszámukat.
 * @param eleje A lista eleje.
*/
void lista_kiir_short(ListaElem *eleje){
    ListaElem *iter;
    int i = 1;
    for (iter = eleje; iter != NULL ; iter = iter->next, i++) {
        printf("(%d) %s %s\n", i, iter->adat.fn, iter->adat.phone);
    }
}

/** @brief Az összes kártyát importálja a /cards mappából.
 * @param eleje A lista eleje, amibe beilleszti az elemeket.
*/
ListaElem *import_all(ListaElem *eleje) {
    DIR *d;
    struct dirent *dir;
    struct stat path_stat;
    char filepath[512];

    d = opendir("cards");
    if(d == NULL) {
        printerror("nem lehet megnyitni a mappát.");
        return eleje;
    }
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            snprintf(filepath, sizeof(filepath), "cards/%s", dir->d_name);  // construct the full path
            if(stat(filepath, &path_stat) == 0 && S_ISREG(path_stat.st_mode)) {
                //printf("importálás: %s\n", dir->d_name);
                contact c;
                InitContact(c);
                readcard(dir->d_name, &c);
                eleje = vegere_beszur(eleje, c);
            }
        }
        closedir(d);
    }
    return eleje;
}

/** @brief Egy láncolt lista n-edik elemét keresi meg és adja vissza. Túlindexeléskor figyelmeztet és NULL pointert ad vissza.
 * @param eleje A lista eleje
 * @param n Hányadik elemet adja vissza
 * @returns A lista n-edik eleme
*/
ListaElem *nth(ListaElem *eleje, size_t n){
    size_t i = 0;
    for(ListaElem *iter = eleje; iter != NULL; iter = iter->next){
        if(n-1 == i++) return iter;
    }
    printerror("TÚLINDEXELTED A LISTÁT!");
    return NULL;
}