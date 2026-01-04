// Maciej Zdeb s208293 ACiR gr.3 Zadanie domowe Podstawy Programowania 2025/26

#ifndef XO_H
#define XO_H

#include <string>
#include <vector>


// Menu trybu gry w kolko i krzyzyk
void menu_XO(bool& XO_ods, bool& XO_graf, int& XO_czas); 


void ustawienia_XO(bool& XO_ods, bool& XO_graf, int& XO_czas);

// Gra kolko i krzyzyk gracz vs gracz w konsoli z obsluga czasu i opcjonalnie SVG
void gra_XO(bool XO_ods, bool XO_graf, int XO_czas); 

// Gra kolko i krzyzyk gracz vs komputer (algorytm blokuj, stawianie znaku obok znaku, losowo) z obsluga czasu gracza i opcjonalnie SVG
void gra_XO_PC(bool XO_ods, bool XO_graf, int XO_czas); 

// Rysuje plansze XO w ASCII w konsoli plus czas (czasO i czasX) graf_plansza_XO trzyma pomocnicze znaki pol
void XO_plansza(char XO[3][3], char graf_plansza_XO[3][3], int czasO, int czasX, int XO_czas);

// Rysuje koncowy stan planszy w konsoli po zakonczeniu gry (wygrana, remis)
void XO_plansza_wygrana(char XO[3][3]);

// Generuje plik XO.svg z aktualnym stanem planszy (siatka plus znaki X i O)
void XO_svg_plansza(char XO[3][3]);

// Dopisuje numer pola do listy kandydatow tylko jesli jeszcze go tam nie ma
void sprawdz_czy_n_jest(std::vector<int>& kandydat, int n);

// Szuka ruchu blokujacego przeciwnika ustawia n na pole blokady i zwraca true jesli znalazl
bool blokuj_gracza(char XO[3][3], char gznak, int &n);

// Szuka ruchu obok swojego znaku zbiera mozliwe pola obok kznak losuje jedno do n i zwraca true jesli cos znalazl
bool znak_obok_znaku(char XO[3][3], char kznak, int &n);


#endif
