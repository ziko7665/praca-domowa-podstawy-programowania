

#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <string>

// Zwraca szerokosc okna konsoli (kolumny). Używane do wysrodkowania tekstu
int szer_cmd();

// Wypisuje tekst wysrodkowany w konsoli (na podstawie szerokości konsoli)
void wys(const std::string &tekst);

// Losuje liczbę całkowitą z przedziału od min do max
int losuj_oddo(int min, int max);

// Sprawdza w petli czy uzytkownik podal liczbe
int wczytaj_int(const std::string &komunikat);

// Pauzuje program do wcisniecia Enter
void pauza();

// Menu pomocy programu
void pomoc_menu();

// Czysci resztki z buforu (po bledzie wpisania do inta 123abc, znak konca linii \n tak zeby np. pauza() go nie pobrala)
void czysc();

// Usuwa biale znaki z konca stringa (np. spacje na końcu nazwy pliku)
void utnij_bialy_koniec(std::string &tekst);

// Zadaje pytanie tak/nie, akceptuje odpowiedzi uzytkownika i zwraca true dla "tak", false dla "nie"
bool pytanie_tak_nie(std::string pytanie);

// Wyswietla pomoc/informacje do SVG
void pomoc_SVG();

// Wyswietla pomoc do gry kolko i krzyzyk (zasady sterowania i dzialania)
void pomoc_XO();

// Wyświetla pomoc do warcabow (zasady sterowania i dzialania)
void pomoc_Warcaby();

// Wyświetla ogólne informacje/pomoc programu
void pomoc_ogolna();

// Wyświetla listę kolorów i zwraca wybrany kolor jako string do SVG
std::string wybor_koloru();

#endif
