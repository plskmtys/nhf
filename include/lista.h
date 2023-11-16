#include <stdlib.h>
#include "vcard.h"

#ifndef NHF_LISTA_H
#define NHF_LISTA_H

typedef struct ListaElem{
    contact adat;
    struct ListaElem *next;
}ListaElem;

int listahossz(ListaElem *eleje);

void lista_free(ListaElem *eleje);

ListaElem *elore_beszur(ListaElem *eleje, contact adat);

ListaElem *GetLastItem(ListaElem *eleje);

ListaElem *vegere_beszur(ListaElem *elso, contact uj);

ListaElem *keres(ListaElem *eleje, char *keresett);

#endif //NHF_LISTA_H