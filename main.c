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

    ListaElem *elso = (ListaElem*) malloc(sizeof(ListaElem));
    elso->next = NULL;
    char next = '0';
    while(next != 'x'){
        printf("\n----FŐMENÜ----\n");
        next=menukiir(main_options);
        //printf("valasztas: %c\n", next);
        switch(next){

            //új
            case '1': {
                //contact *uj = (contact*) malloc(sizeof(contact));
                contact uj;
                //uj = InitContact(uj);
                while (next != 'b' && next != 'x') {
                    next = menukiir(newc_options);
                    switch (next) {
                        //név
                        case '1':
                            //printf("%s:\t(max. %lu karakter)\n", newc_options[0], sizeof(uj.fn)-1);

                            while(next != 'b' && next != 'x'){
                                next = menukiir(name_options);
                                switch (next) {
                                    case '1':
                                        printf("%s:\t\t(max. %lu karakter)\n", name_options[0], sizeof(uj.name.prefix)-1);
                                        scanf(" %s", uj.name.prefix);
                                        next = '0';
                                        fflush(stdin);
                                        break;
                                    case '2':
                                        printf("%s:\t\t(max. %lu karakter)\n", name_options[1], sizeof(uj.name.first)-1);
                                        scanf(" %s", uj.name.first);
                                        next = '0';
                                        fflush(stdin);
                                        break;
                                    case '3':
                                        printf("%s:\t\t(max. %lu karakter)\n", name_options[2], sizeof(uj.name.middle)-1);
                                        scanf(" %s", uj.name.middle);
                                        next = '0';
                                        fflush(stdin);
                                        break;
                                    case '4':
                                        printf("%s:\t\t(max. %lu karakter)\n", name_options[3], sizeof(uj.name.last)-1);
                                        scanf(" %s", uj.name.last);
                                        next = '0';
                                        fflush(stdin);
                                        break;
                                    case '5':
                                        printf("%s:\t\t(max. %lu karakter)\n", name_options[0], sizeof(uj.name.suffix)-1);
                                        scanf(" %s", uj.name.suffix);
                                        next = '0';
                                        fflush(stdin);
                                        break;
                                    default:
                                        break;
                                }
                            }
                            break;

                        //tel
                        case '2':
                            printf("%s:\t\t(max. %lu karakter)\n", newc_options[1], sizeof(uj.phone)-1);
                            scanf(" %s", uj.phone);
                            next = '0';
                            fflush(stdin);
                            break;

                        //email
                        case '3':
                            printf("%s\n", newc_options[2]);
                            strcpy(uj.email, sor_olvas());
                            break;

                        //address
                        case '4':
                            //uj->address = InitAddress(uj->address);
                            while (next != 'b') {
                                next = menukiir(address_options);
                                switch (next) {
                                    //TODO cím
                                }
                            }
                            next = '0';
                            break;

                        //bday
                        case '5':
                            printf("%s\n", newc_options[4]);
                            strcpy(uj.bday, sor_olvas());
                            break;

                        //org
                        case '6':
                            printf("%s\n", newc_options[5]);
                            strcpy(uj.org, sor_olvas());
                            break;

                        //title
                        case '7':
                            printf("%s\n", newc_options[6]);
                            strcpy(uj.title, sor_olvas());
                            break;

                        //note
                        case '8':
                            printf("%s\n", newc_options[7]);
                            strcpy(uj.note, sor_olvas());
                            break;

                        //save
                        case 's':
                            /*code for save action*/
                        default:
                            break;
                    }
                }
                elso = vegere_beszur(elso, uj);
                break;
            }
            //view all
            case '2':
                next = menukiir(view_options);
                break;
            //search
            case '3':
                /*code for search*/
                break;

            //export
            case '4':
                /*code for export*/
                break;

            default:
                break;
        }
    }
}