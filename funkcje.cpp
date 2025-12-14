#include "funkcje.h"
#include <windows.h>
#include <iostream>
#include <limits>

using namespace std;

static int szerokosc_konsoli() // sprawdza szerokosc konsoli aby wykozystac to przy wysrodkowaniu
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

void wys(const string& tekst) // wysrodkowuje napis
{
    int szerokosc = szerokosc_konsoli();
    int dlugosc = tekst.length();
    int spacje = (szerokosc - dlugosc) / 2;
    if (spacje < 0) spacje = 0;
    cout << string(spacje, ' ') << tekst << endl;
}

int losuj_oddo(int min, int max) // losuje liczbe od do 
{
    return min + rand() % (max - min + 1);
}

int wczytaj_int(const std::string& komunikat) // Sprawdza czy wpisalismy liczbe
{
    int x;
    while (true)
    {
        std::cout << komunikat;
        if (std::cin >> x)
        {
            return x;              
        }

        std::cout << "To nie jest liczba, sprobuj jeszcze raz" << std::endl;

        // czyścimy błąd
        std::cin.clear();
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void pauza() // Wola Enter
{
   
    wys("Nacisnij Enter, aby kontynuowac");
    std::string linia;
    std::getline(std::cin, linia);
    
    

    
}