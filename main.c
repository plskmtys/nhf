#include <stdio.h>
#include <stdlib.h>
#include "include/debugmalloc.h"
#include "include/vcard.h"
#include <stdio.h>
#ifdef _WIN32
    #include <windows.h>
#endif
#include "include/menu.h"

int main(){
    #ifdef _WIN32
        SetConsoleCP(1250);
        SetConsoleOutputCP(1250);
    #endif
    int next=menukiir(main_options);
    printf("valasztas: %d\n", next);
    switch(next){
        case(1):
            contact uj;
            InitContact(uj);
            next = menukiir(newc_options);
            switch (next)
            {
            case 1:
                uj.fn = beker(newc_options[1]);
                break;
            
            default:
                break;
            }

        case(2):
            next = menukiir(view_options);

        case 3:
            /*search*/
            break;

        case 4: 
            /*export*/
            break;
        default:
            next = menukiir(main_options);
    }
}