#include <stdio.h>
#include <stdlib.h>
#include "include/debugmalloc.h"
#include "include/vcard.h"
#include "include/menu.h"
#include "include/lista.h"
#include <string.h>

int main(){
    contact c;
    c = InitContact(c);
    //strcpy(c.address.country, "HU");
    //strcpy(c.address.county, "Vas");
    strcpy(c.address.street_no, "69 yo moms street");
    strcpy(c.address.city, "Otthonfalva");
    //strcpy(c.address.zip, "69420");

    printf("%s\n", straddr(&c.address));
    char choice = contactmenu(&c);
    printf("\nvalasztas: %c\n", choice);
    char next = '0';
    beker("adj meg egy nevet", c.fn, sizeof(c.fn) ,&next);
    printf("a nev: %s\n", c.fn);
    printf("%lu", sizeof(c.fn));

}