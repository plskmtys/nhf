#include <stdio.h>
#include <stdlib.h>
#include "include/debugmalloc.h"

typedef struct fullname{
    char *prefix;
    char *first;
    char *middle;
    char *last;
    char *suffix;
}fullname;

typedef struct address{
    int zip;
    char *city;
    char *street;
    int num;
    char *country;
}address;

typedef struct contact{
    char *num;
    fullname name;
    char *mail;
    address address1;

}contact;

int main(){

}