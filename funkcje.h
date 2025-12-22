#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <string>

int szer_cmd();
void wys(const std::string& tekst);
int losuj_oddo(int min, int max);
int wczytaj_int(const std::string& komunikat);
void pauza();
void pomoc();
void czysc();
void pomoc_XO();
void pomoc_Warcaby();
void pomoc_ogolna();
std::string wybor_koloru(); //Wybor koloru dla ksztaltu

#endif
