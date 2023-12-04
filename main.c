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
                while (next != 'b' && next != 'x') {
                    edit_contact(&uj, &next);
                }
                elso = vegere_beszur(elso, uj);
                reset(&next);
                break;
            }
            //view all
            case '2': {
                clear();
                lista_kiir_short(elso);
                scanf(" %c");
                while ((getchar()) != '\n');
                clear();
                break;
            }
            //search
            case '3': {
                char needle[256];
                clear();
                beker_keres("keresett kifejezés", needle, sizeof(needle));

                ListaElem *results_eleje = NULL;
                results_eleje = keres(elso, needle);

                while (next != 'b' && next != 'x') {
                    lista_kiir_short(results_eleje);
                    int n = 0;
                    printf("melyiket szeretnéd megtekinteni/szerkeszteni?\n");
                    scanf(" %d", &n);
                    if(nth(results_eleje, n) == NULL) {
                        sleep(1);
                        break;
                    }
                    edit_contact(&nth(results_eleje, n)->adat, &next);
                }
                reset(&next);
                lista_free(results_eleje);
                clear();
                break;
            }
            //export
            case '4': {
                clear();
                for(ListaElem *iter = elso; iter != NULL; iter = iter->next){
                    if(writecard(iter->adat.fn, &iter->adat)){
                        printf("sikertelen export: %s\n", iter->adat.fn);
                    } else {
                        printf("sikeres export: %s\n", iter->adat.fn);
                    }
                }
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
    if(elso != NULL){
        lista_free(elso);
    }
}