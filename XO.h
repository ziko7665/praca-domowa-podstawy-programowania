#ifndef XO_H
#define XO_H

#include <string>

void menu_XO();
void gra_XO();
void gra_XO_PC();
void XO_plansza(char XO[3][3], char graf_plansza_XO[3][3]);
void XO_plansza_wygrana(char XO[3][3]);
void XO_svg_plansza(char XO[3][3]);
bool n_dla_pkt2(char XO[3][3], char kznak, char gznak,   int &n);
bool n_dla_pkt3(char XO[3][3], char kznak, int &n);


#endif
