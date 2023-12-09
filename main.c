#include <stdio.h>
#include <stdlib.h>
#include "include/debugmalloc.h"
#include "include/vcard.h"
#include <stdio.h>
#ifdef _WIN32
    #include <windows.h>
#endif
#include "include/menu.h"
#include "include/lista.h"
#include <string.h>

int main(){
    #ifdef _WIN32
        SetConsoleCP(1250);
        SetConsoleOutputCP(1250);
    #endif
    printf("\n----TELEFONKÖNYV----\nvezérlés:\n-az adott menübe lépéshez adja meg a sorszámát. ha kész, ENTER.\n-kilépés: 'x'\n-visszalépés: 'b'\n");

    //az összes mentett adat beolvasása a listába
    ListaElem *elso = NULL;
    elso = import_all(elso);
    char next = '0';
    while(next != 'x'){
        printf("\n----FŐMENÜ----\n");
        next=menukiir(main_options);
        switch(next){
            //új
            case '1': {
                contact uj;
                uj = InitContact(uj);
                while (next != 'x' && next != 'b') {
                    edit_contact(&uj, &next);
                }
                elso = beszur(elso, uj);
                reset(&next);
                break;
            }

            //összes megtekintése
            case '2': {
                while (next != 'x' && next != 'b') {
                    clear();
                    printf("Összes kontakt:\n\n");
                    lista_kiir_short(elso);
                    printf("\nMelyiket szeretné megtekinteni/szerkeszteni?\n");
                    char n = next;
                    scanf(" %c", &n);
                    clear();

                    //hibakezelés: ha invalid listaindexet ad meg a felhasználó
                    while(n != 'x' && n != 'b' && nth(elso, n-0x30) == NULL) {
                        printf("Összes kontakt:\n\n");
                        lista_kiir_short(elso);
                        printf("\nMelyiket szeretné megtekinteni/szerkeszteni?\n");
                        scanf(" %c", &n);
                        clear();
                    }

                    //a kiválasztott elem szerkesztése, ha nem lép ki a felhasználó és megad egy létező indexet
                    while(n != 'x' && n != 'b'){
                        edit_contact(&(nth(elso, n-0x30))->adat, &next); //
                        if(next == 'x' || next == 'b') n = next;
                    }
                    /* a szerkesztés után sajnos egyből ki kell lépni a főmenübe. oka: lehetséges eset, hogy 120 darab kontakt van.
                     * és mivel a kilépésre használt betű 'x' ascii kódja a 120, a felhasználó sosem tudna kilépni, mert mindig a 120-as sorszámú
                     * elemet "választaná ki".
                     * */
                }

                reset(&next);
                clear();
                break;
            }
            //keresés
            case '3': {
                char needle[256];
                clear();
                beker_keres("keresett kifejezés", needle, sizeof(needle));

                //elemek megkeresése
                ListaElemIndex *results_eleje = NULL;
                results_eleje = keres(elso, needle);
                if(results_eleje == NULL){
                    printf("\nNincs találat.\nKilépés...\n");
                    reset(&next);
                    sleep(1);
                    clear();
                    break;
                }

                //eredmények kiírása
                while (next != 'x' && next != 'b') {

                    clear();
                    printf("Keresési eredmények a követezőre: %s\n\n", needle);
                    lista_kiir_indirekt(results_eleje);
                    printf("\nMelyiket szeretné megtekinteni/szerkeszteni?\n");
                    char n = next;
                    scanf(" %c", &n);
                    clear();

                    //hibakezelés: ha invalid listaindexet ad meg a felhasználó
                    while(n != 'x' && n != 'b' && nth_i(results_eleje, n-0x30) == NULL) {
                        printf("Keresési eredmények a követezőre: %s\n\n", needle);
                        lista_kiir_indirekt(results_eleje);
                        printf("\nMelyiket szeretné megtekinteni/szerkeszteni?\n");
                        scanf(" %c", &n);
                        clear();
                    }

                    //a kiválasztott elem szerkesztése, ha nem lép ki a felhasználó és megad egy létező indexet
                    while(n != 'x' && n != 'b'){
                        edit_contact(&(nth_i(results_eleje, n-0x30))->elemptr->adat, &next); //
                        if(next == 'x' || next == 'b') n = next;
                    }
                    /* a szerkesztés után sajnos itt is egyből ki kell lépni a főmenübe.*/
                }
                reset(&next);
                clear();
                lista_free_i(results_eleje);
                break;
            }
            //export
            case '4': {
                clear();
                export_all(elso);
                break;
            }
            //import
            case '5':{
                clear();
                elso = import_all(elso);
                break;
            }
            default:
                clear();
                break;
        }
        clear();
    }

    printf("\nKileptel.\n");
    //kilépéskor az összes mentése
    export_all(elso);
    printf("Adatok mentese kesz.\n");
    if(elso != NULL){
        lista_free(elso);
    }
}