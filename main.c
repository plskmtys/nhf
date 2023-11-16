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



int main(){
    #ifdef _WIN32
        SetConsoleCP(1250);
        SetConsoleOutputCP(1250);
    #endif

    //ListaElem *elso = (ListaElem*) malloc(sizeof(ListaElem));
    char next = '0';
    while(next != 'x'){
        char next=menukiir(main_options);
        //printf("valasztas: %c\n", next);
        switch(next){

            //új
            case('1'):
                contact *uj = (contact*) malloc(sizeof(contact));
                //vegere_beszur(elso, *uj);
                InitContact(*uj);
                while(next != 'b'){
                    next = menukiir(newc_options);
                    switch (next)
                    {
                        //név
                        case '1':
                            uj->fn = beker(newc_options[0]);
                            break;

                        //tel
                        case '2':
                            uj->phone = beker(newc_options[1]);
                            break;

                        //email
                        case '3':
                            uj->email = beker(newc_options[2]);
                            break;

                        //address
                        case '4':
                            uj->address = InitAddress(uj->address);
                            while(next != 'b'){
                                next = menukiir(address_options);
                                switch(next){
                                    //TODO cím
                                }
                            }
                            next = '0';
                            break;

                        //bday
                        case '5':
                            uj->bday = beker(newc_options[4]);
                            break;

                        //org
                        case '6':
                            uj->org = beker(newc_options[5]);
                            break;

                        //title
                        case '7':
                            uj->title = beker(newc_options[6]);
                            break;

                        //note
                        case '8':
                            uj->note = beker(newc_options[7]);
                            break;

                        //save
                        case 's':
                            /*code for save action*/
                        default:
                            break;
                    }
                    break;
                }

            //view all
            case('2'):
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