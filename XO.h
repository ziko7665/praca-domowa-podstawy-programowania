#ifndef XO_H
#define XO_H

#include <string>
#include <vector>

void menu_XO();
void gra_XO();
void gra_XO_PC();
void XO_plansza(char XO[3][3], char graf_plansza_XO[3][3], int czasO, int czasX);
void XO_plansza_wygrana(char XO[3][3]);
void XO_svg_plansza(char XO[3][3]);
void sprawdz_czy_n_jest(std::vector<int>& kandydat, int n);
bool blokuj_gracza(char XO[3][3], char gznak, int &n);
bool znak_obok_znaku(char XO[3][3], char kznak, int &n);


#endif
