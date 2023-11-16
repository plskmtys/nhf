#include <stdio.h>
#include <stdlib.h>
#include "vcard.h"

/** @brief Egy nevet inicializál, üres értékekkel tölti fel.
 *  @returns Üres értékekkel feltöltött, fullname típusú változó.
*/
fullname InitName(fullname empty){
    empty.first = "";
    empty.last="";
    empty.middle="";
    empty.prefix[0]='\0';
    empty.suffix[0]='\0';
}

/** @brief Egy címet inicializál, üres értékekkel tölti fel.
 *  @returns Üres értékekkel feltöltött, address típusú változó.
*/
address InitAddress(address empty){
    empty.street_no = "";
    empty.city = "";
    empty.zip[0]= '\0';
    empty.county = "";
    empty.country = "";
    empty.type = "";
}

/** @brief Egy kontaktot inicializál, üres értékekkel tölti fel.
 * @returns Üres értékekkel feltöltött, contact típusú változó.
*/
contact InitContact(contact empty){
    empty.phone[0]='\0';
    empty.fn="";
    fullname defaultname;
    empty.name=InitName(defaultname);
    empty.email="";
    address defaultaddress;
    empty.address=InitAddress(defaultaddress);
    empty.bday[0]='\0';
    empty.org="";
    empty.title="";
    empty.note="";
}

/** @brief A paraméterként megadott contact típusú változó adatait vCard kiterjesztésű fájlba írja.
 * @param filename Kimenő fájl neve
 * @param out A kiírandó contact típusú változó
 * @todo hibakezelés
*/
void writecard(char *filename, contact out){
    sprintf(filename, "cards/%s.vcard", filename);
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "BEGIN:VCARD\nVERSION:4.0\n");
    fprintf(fp, "FN:%s\n", out.fn);
    fprintf(fp, "N:%s;%s;%s;%s;%s\n", out.name.last, out.name.first, out.name.middle, out.name.prefix, out.name.suffix);
    fprintf(fp, "TEL:%s\n", out.phone);
    fprintf(fp, "ADDR;TYPE=home:;;%s;%s;%s;%s;%s\n", out.address.street_no, out.address.city, out.address.county, out.address.zip, out.address.country);
    fprintf(fp, "BDAY:%s\n",out.bday);
    fprintf(fp, "EMAIL:%s\n", out.email);
    fprintf(fp, "NOTE:%s\n", out.note);
    fprintf(fp, "END:VCARD");
}