#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <string>

int szer_cmd();
void wys(const std::string& tekst);
int losuj_oddo(int min, int max);
int wczytaj_int(const std::string& komunikat);
void pauza();
void pomoc_menu();
void czysc();
void utnij_bialy_koniec(std::string& tekst);
bool pytanie_tak_nie(std::string pytanie);
void pomoc_SVG(); // Pomoc/informacje do podstawowego i zaawansowanego SVG
void pomoc_XO();
void pomoc_Warcaby();
void pomoc_ogolna();    
std::string wybor_koloru(); 

#endif
