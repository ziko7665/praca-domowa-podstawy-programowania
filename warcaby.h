// Maciej Zdeb s208293 ACiR gr.3 Zadanie domowe Podstawy Programowania 2025/26

#ifndef WARCABY_H
#define WARCABY_H

#include <string>



// Rysuje pansze aktualnego stanu gry
void war_plansza(char war[8][8]);

void war_svg(char war[8][8], bool war_ods, bool war_graf);

// Ustawia plansze startowa warcabow
void ustaw_war_plansz_0(char war[8][8]);

// Zamienia wpis typu "a1" na indeksy tablicy (wier, kol)
bool pole_na_tab(std::string& x, int& wier, int& kol);

// Wykonuje bicie, usuwa pionek przeciwnika z pola posredniego i przenosi pionek gracza.
bool ruch_bicia(char war[8][8], int wier_po_sr, int kol_po_sr, int zwier, int zkol, int dwier, int dkol);

// Sprawdza czy gracz ma jakiekolwiek bicie na calej planszy
bool czy_musi_bic(char war[8][8], char gracz, char nie_gracz);

// Sprawdza czy pionek na pozycji (dwier, dkol) ma mozliwe bicie
bool pion_ma_bicie(char war[8][8], int dwier, int dkol);

// Sprawdza czy ktorys gracz nie ma juz pionkow
bool bez_piona(char war[8][8]);

// Sprawdza czy aktualny gracz ma jakakowlwiek mozliwosc ruchu
bool czy_jest_ruch(char war[8][8], char gracz, char nie_gracz);

void menu_warcaby(bool& war_ods, bool& war_graf);


void ustawienia(bool& war_ods, bool& war_graf);

void zapis();

// Glowna funkcja gry w warcaby, tury na zmiane, walidacja wejscia, ruchy i bicia,
// wymuszenie bicia, wielokrotne bicie w jednej turze, odswiezanie planszy i koniec gry
void warcaby(bool ods, bool graf); 

#endif 