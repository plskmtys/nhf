#include <stdio.h>
#include <stdlib.h>
#include "include/debugmalloc.h"
#include "include/vcard.h"

int main(){
    printf("hello\n");
    fullname belanev;
    belanev.first="Béla";
    belanev.last="Lugosi";
    belanev.prefix="Mr.";
    contact lugosi_bela;
    lugosi_bela.name=belanev;
}