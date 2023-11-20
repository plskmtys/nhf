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
                uj = InitContact(uj);
                while (next != 'b' && next != 'x') {
                    //next = menukiir(newc_options);
                    next = contactmenu(&uj);
                    switch (next) {
                        //név
                        case '1': {
                            while (next != 'b' && next != 'x') {
                                next = namemenu(&uj);
                                switch (next) {
                                    case '1':
                                        printf("%s:\t\t(max. %lu karakter)\n", name_options[0],
                                               sizeof(uj.name.prefix) - 1);
                                        scanf(" %s", uj.name.prefix);

                                        fflush(stdin);
                                        break;
                                    case '2':
                                        printf("%s:\t\t(max. %lu karakter)\n", name_options[1],
                                               sizeof(uj.name.first) - 1);
                                        scanf(" %s", uj.name.first);

                                        fflush(stdin);
                                        break;
                                    case '3':
                                        printf("%s:\t\t(max. %lu karakter)\n", name_options[2],
                                               sizeof(uj.name.middle) - 1);
                                        scanf(" %s", uj.name.middle);
                                        next = '0';
                                        fflush(stdin);
                                        break;
                                    case '4':
                                        printf("%s:\t\t(max. %lu karakter)\n", name_options[3],
                                               sizeof(uj.name.last) - 1);
                                        scanf(" %s", uj.name.last);
                                        next = '0';
                                        fflush(stdin);
                                        break;
                                    case '5':
                                        printf("%s:\t\t(max. %lu karakter)\n", name_options[0],
                                               sizeof(uj.name.suffix) - 1);
                                        scanf(" %s", uj.name.suffix);
                                        next = '0';
                                        fflush(stdin);
                                        break;
                                    default:
                                        break;
                                }
                            }
                            strcpy(uj.fn, strfn(&uj.name));
                            next = '0';
                            break; //endcase nev
                        }

                        //tel
                        case '2':
                            beker(newc_options[1], uj.phone, sizeof(uj.phone));
                            break; //endcase tel

                        //email
                        case '3':
                            beker(newc_options[2], uj.email, sizeof(uj.email));
                            break; //endcase email

                        //address
                        case '4':
                            //uj->address = InitAddress(uj->address);
                            while (next != 'x' && next != 'b') {
                                next = menukiir(address_options);
                                switch (next) {
                                    //TODO cím
                                    case 1:
                                        //utca, hsz
                                        beker(address_options[0], uj.address.street_no, sizeof(uj.address.street_no));
                                        break;
                                    case 2:
                                        //varos
                                        beker(address_options[1], uj.address.city, sizeof(uj.address.city));
                                        break;
                                    case 3:
                                        //megye
                                        beker(address_options[2], uj.address.county, sizeof(uj.address.county));
                                        break;
                                    case 4:
                                        //irsz.
                                        beker(address_options[3], uj.address.zip, sizeof(uj.address.zip));
                                        break;
                                    case 5:
                                        //orszag
                                        beker(address_options[4], uj.address.country, sizeof(uj.address.country));
                                        break;
                                }
                            }
                            break; //endcase address

                        //bday
                        case '5':
                            beker(newc_options[4], uj.bday, sizeof(uj.bday));
                            break; //endcase bday

                        //org
                        case '6':
                            beker(newc_options[5], uj.org, sizeof(uj.org));
                            break; //endcase org

                        //title
                        case '7':
                            beker(newc_options[6], uj.title, sizeof(uj.title));
                            break; //endcase title

                        //note
                        case '8':
                            beker(newc_options[7], uj.note, sizeof(uj.note));
                            break; //endcase note

                        //save
                        case 's':
                            /*code for save action*/
                            break; //endcase save

                        default:
                            break;
                    }
                }
                elso = vegere_beszur(elso, uj);
                next = '0';
                break;
            }
            //view all
            case '2': {
                lista_kiir_short(elso);
                next = menukiir(view_options);
                break;
            }
            //search
            case '3': {
                /*code for search*/
                break;
            }

            //export
            case '4': {
                /*code for export*/
                break;
            }

            default:
                break;
        }
    }
}