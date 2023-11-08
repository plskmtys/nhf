#include <stdlib.h>

#ifndef VCARD_H
#define VCARD_H

typedef struct fullname{
    char *prefix;
    char *first;
    char *middle;
    char *last;
    char *suffix;
}fullname;

typedef struct address{
    char *type;
    int zip;
    char *street_no;
    char *city;
    char *country;
    char *county;
}address;

typedef struct contact{
    char *phone;
    char *fn;
    fullname name;
    char *email;
    address address1;
    char *bday;
    char *note;
    char *org;
    char *title;
}contact;

fullname StrToName(char *instr){
    fullname ret;
    if(sscanf(instr, "%s %s %s %s %s") == 5)
        sscanf(instr, "%s %s %s %s %s", ret.prefix, ret.first, ret.middle, ret.last, ret.suffix);
    else if(sscanf(instr, "%s %s %s %s")==4){
        sscanf(instr, "%s %s %s %s", ret.prefix, ret.first, ret.last, ret.suffix);
    }
    return ret;
}

address StrToAddr(){
    address ret;
    return ret;
}

contact InitContact(contact empty){
    empty.phone="";
    empty.fn="";
    empty.name=StrToName("");
    empty.email="";
    empty.address1=StrToAddr("");
    empty.bday="------";
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
    fprintf(fp, "BDAY:%s",out.bday);
    fprintf(fp, "EMAIL:%s", out.email);
    fprintf(fp, "END:VCARD");
}

#endif