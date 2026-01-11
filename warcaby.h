// Maciej Zdeb s208293 ACiR gr.3 Zadanie domowe Podstawy Programowania 2025/26

#ifndef WARCABY_H
#define WARCABY_H

#include <string>


// Rysuje pansze aktualnego stanu gry
void war_plansza(char war[8][8]);

// Tworzy plik warcaby.svg z reprezentacja graficzna 
void war_svg(char war[8][8], bool war_ods, bool war_graf);

// Ustawia plansze startowa warcabow
void ustaw_war_plansz_0(char war[8][8]);

// Zamienia wpis typu "a1" na indeksy tablicy (wier, kol)
bool pole_na_tab(std::string& x, int& wier, int& kol);

// Wykonuje bicie, usuwa pionek przeciwnika z pola posredniego i przenosi pionek gracza
bool ruch_bicia(char war[8][8], int wier_po_sr, int kol_po_sr, int zwier, int zkol, int dwier, int dkol);

// Sprawdza czy gracz ma jakiekolwiek bicie na calej planszy
bool czy_musi_bic(char war[8][8], char gracz, char nie_gracz);

// Sprawdza czy pionek na pozycji (dwier, dkol) ma mozliwe bicie
bool pion_ma_bicie(char war[8][8], int dwier, int dkol);

// Sprawdza czy ktorys gracz nie ma juz pionkow
bool bez_piona(char war[8][8]);

// Sprawdza czy aktualny gracz ma jakakowlwiek mozliwosc ruchu
bool czy_jest_ruch(char war[8][8], char gracz, char nie_gracz);

// Wyswietla menu glowne warcabow i obsluguje wybor opcji
void menu_warcaby(bool& war_ods, bool& war_graf);

// Wyswietla menu ustawien gry i pozwala zmienic tryb grafiki oraz odswiezanie
void ustawienia(bool& war_ods, bool& war_graf);

// Zapisuje aktualny stan gry do pliku
bool zapis_gry(const std::string& nr_zapisu, char war[8][8], char gracz, bool war_ods, bool war_graf);

// Wczytuje stan gry z pliku i ustawia plansze, gracza oraz ustawienia
bool wczyt_gry(const std::string& nr_zapisu, char war[8][8], char& gracz, bool& war_ods, bool& war_graf);

// Wyswietla menu wczytywania gry i pozwala wybrac slot zapisu
void menu_wczyt(bool& war_ods, bool& war_graf);

// Menu do zapisu w trakcie gry
bool menu_zapisu(char war[8][8], char gracz, bool war_ods, bool war_graf);

// Sprawdza czy slot zapisu jest zajety oraz czy plik ma poprawny format
bool slot_zajety(const std::string& zapis);

// Zwraca nazwe pliku odpowiadajaca wybranemu slotowi
std::string plik_war_slot(int slot);

// Usuwa znak karetki z konca linii po wczytaniu z pliku
void usun_karetke(std::string& linia);

// Uruchamia nowa gre 
void warcaby(bool& war_ods, bool& war_graf);

// Uruchamia gre na podstawie podanej planszy i aktualnego gracza
void warcaby_wczytane(char war[8][8], char gracz, bool& war_ods, bool& war_graf);


#endif 