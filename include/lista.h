#include <stdlib.h>
#include "vcard.h"

#ifndef NHF_LISTA_H
#define NHF_LISTA_H

/** @brief A láncolt lista egy eleme.
 * @param adat Az elem által tárolt adat.
 * @param next A következő listaelem címe. Ha nincs, NULL.
*/
typedef struct ListaElem{
    contact adat;
    struct ListaElem *next;
}ListaElem;

/** @brief Láncolt lista egy elemére mutató, és egymás után láncolható struktúra. Keresésre, indexelésre használható. */
typedef struct ListaElemIndex{
    /** @brief Egy láncoltlista-elemre mutató pointer*/
    ListaElem *elemptr;
    /** @brief Következő listaelem-index típusú elemre mutató pointer*/
    struct ListaElemIndex *next;
}ListaElemIndex;

void reset(char *next);

int listahossz(ListaElem *eleje);

void lista_free(ListaElem *eleje);

void lista_free_i(ListaElemIndex *eleje);

ListaElem *beszur(ListaElem *eleje, contact mit);

ListaElem *GetLastItem(ListaElem *eleje);

ListaElemIndex *keres(ListaElem *eleje, char *keresett);

char *sor_olvas();

void lista_kiir_short(ListaElem *eleje);

void lista_kiir_indirekt(ListaElemIndex *eleje);

ListaElem *import_all(ListaElem *eleje);

void export_all(ListaElem *eleje);

ListaElem *nth(ListaElem *eleje, size_t n);

ListaElemIndex *nth_i(ListaElemIndex *eleje, size_t n);

#endif //NHF_LISTA_H