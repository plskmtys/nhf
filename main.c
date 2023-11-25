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

int main(int argc, char **argv){
    #ifdef _WIN32
        SetConsoleCP(1250);
        SetConsoleOutputCP(1250);
    #endif
    clear();
    printf("\n----TELEFONKÖNYV----\nvezérlés:\n-az adott menübe lépéshez adja meg a sorszámát. ha kész, ENTER.\n-kilépés: 'x'\n-visszalépés: 'b'\n");

    ListaElem *elso = NULL;
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
                next = '0';
                break;
            }
            //view all
            case '2': {
                clear();
                lista_kiir_short(elso);
                next = menukiir(view_options);
                clear();
                break;
            }
            //search
            case '3': {
                /*code for search*/
                clear();
                char needle[256];
                beker("keresett kifejezés: ", needle, sizeof(needle));
                ListaElem *results_eleje = keres(elso, needle);
                lista_kiir_short(results_eleje);
                //clear();

                //free(results_eleje);
                //free(needle);
                break;
            }

            //export
            case '4': {
                /*code for export*/
                clear();
                break;
            }

            default:
                clear();
                break;
        }
    }
    clear();
    free(elso);
}