#include <stdio.h>
//#include "menu.h"

char menukiir(const char **lista){
    char choice;
    for(int i=0; lista[i] != NULL; i++) printf("(%d) %s\n", i+1, lista[i]);
    printf("\n");
    scanf(" %c", &choice);
    return choice;
}

char *beker(const char *prompt){
    char *ans = "";
    printf("\n%s ", prompt);
    scanf(" %s", ans);
    return ans;
}