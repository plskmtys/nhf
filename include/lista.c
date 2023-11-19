#include <stdlib.h>
#include "vcard.h"
#include "debugmalloc.h"
#include "lista.h"
#include <string.h>

int listahossz(ListaElem *elso){
    ListaElem *eleje = elso;
    int hossz=0;
    for (ListaElem *current = eleje; current != NULL; current=current->next) hossz++;
    return hossz;
}

void lista_free(ListaElem *eleje){
    ListaElem *iter = eleje;
    while (iter != NULL) {
        ListaElem *next = iter->next;
        free(iter);
        iter = next;
    }
}

ListaElem *elore_beszur(ListaElem *eleje, contact adat) {
   ListaElem *uj;
   uj = (ListaElem*) malloc(sizeof(ListaElem));
   uj->adat = adat;
   uj->next = eleje;
   return uj;
}

ListaElem *GetLastItem(ListaElem *eleje){
    ListaElem *last;
    for (last = eleje; ; last=last->next)
    {
        if(last->next  == NULL) return last; 
    }
    return NULL;
}

ListaElem *vegere_beszur(ListaElem *eleje, contact adat){
    ListaElem *uj;
    uj = (ListaElem*) malloc(sizeof(ListaElem));
    uj->adat = adat;
    uj->next = NULL;
    if (eleje == NULL) {
        eleje = uj;
    } else {
        ListaElem *vege = GetLastItem(eleje);
        vege->next = uj;
        vege = uj;
    }
    return eleje;
}

/** @brief Megkeres egy kifejezést az adatbázisban, és visszaad egy listát az összes olyan kontakttal, ami tartalmazza a keresett kifejezést valamilyen mezőben.
 * @param eleje A láncolt lista (első elemének címe), amelyben megkeresi a kifejezést.
 * @param keresett A keresett kifejezés (string).
 * @returns Láncolt lista a keresési eredményekkel.
*/
ListaElem *keres(ListaElem *eleje, char *keresett){
    ListaElem *iter;
    ListaElem *ret;
    char *datastr;
    for (iter = eleje; iter != NULL; iter=iter->next)
        datastr = (char*) malloc(sizeof(iter)+sizeof(char)*20);
        sprintf(datastr, "%s %s %s %s %s %s %s %s %s %s", iter->adat.phone, iter->adat.fn, iter->adat.address.street_no, iter->adat.address.city, iter->adat.address.zip, iter->adat.address.county, iter->adat.address.country, iter->adat.email, iter->adat.org, iter->adat.title);
        if(strstr(datastr, keresett) != NULL) vegere_beszur(ret, iter->adat);
        free(datastr);
    return ret;
}

char* sor_olvas() {
    size_t bufsize = 32;
    size_t position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;
    if (!buffer) {
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
                fprintf(stderr, "sor_olvas: memóriafoglalási hiba\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}