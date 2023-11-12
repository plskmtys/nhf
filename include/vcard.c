#include <stdio.h>
#include <stdlib.h>
#include "vcard.h"

address StrToAddr(char *instr){
    address ret;
    return ret;
}

char *StrToDate(char *instr){
    char *out = "------";
    return out;
}

fullname InitName(fullname empty){
    empty.first = "";
    empty.last="";
    empty.middle="";
    empty.prefix="";
    empty.suffix="";
}

contact InitContact(contact empty){
    empty.phone="";
    empty.fn="";
    fullname defaultname;
    empty.name=InitName(defaultname);
    empty.email="";
    empty.address1=StrToAddr("");
    empty.bday="";
    empty.org="";
    empty.title="";
    empty.note="";
}

void writecard(char *filename, contact out){
    sprintf(filename, "cards/%s.vcard", filename);
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "BEGIN:VCARD\nVERSION:4.0\n");
    fprintf(fp, "FN:%s\n", out.fn);
    fprintf(fp, "N:%s;%s;%s;%s;%s\n", out.name.last, out.name.first, out.name.middle, out.name.prefix, out.name.suffix);
    fprintf(fp, "TEL:%s\n", out.phone);
    fprintf(fp, "ADDR;TYPE=home:;;%s;%s;%s;%d;%s\n", out.address1.street_no, out.address1.city, out.address1.county, out.address1.zip, out.address1.country);
    fprintf(fp, "BDAY:%s\n",out.bday);
    fprintf(fp, "EMAIL:%s\n", out.email);
    fprintf(fp, "NOTE:%s\n", out.note);
    fprintf(fp, "END:VCARD");
}