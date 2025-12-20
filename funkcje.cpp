#include "funkcje.h"
#include <windows.h>
#include <iostream>
#include <limits>




int szerokosc_konsoli() // Sprawdza szerokosc konsoli aby wykozystac to przy wysrodkowaniu
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

void wys(const std::string& tekst) // wysrodkowuje napis
{
    int szerokosc = szerokosc_konsoli();
    int dlugosc = tekst.length();
    int spacje = (szerokosc - dlugosc) / 2;
    if (spacje < 0) spacje = 0;
    std::cout << std::string(spacje, ' ') << tekst << std::endl;
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

        czysc();
    }
}

void pauza() // Wola Enter aby kontynuowac
{
    
    wys("Nacisnij Enter, aby kontynuowac");
    std::string linia;
    std::getline(std::cin, linia);
}

void czysc() // Czysci bledne dane z wejscia
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void pomoc()
{
    system("cls");
       while(true)
    {
    std::string tryb;
    wys("\\\\\\\\\\\\\\\\ POMOC ////////");
    wys("- (1) Gra w Kolko i Krzyzyk -");
    wys("- (2) Gra w Warcaby -");
    wys("- (3) SVG -");
    wys("- (X) Powrot do MENU -");
    std::cout << "Wybierz opcje: "; 
    std::getline(std::cin >> std::ws, tryb);
    if(tryb.size() == 1 && (tryb[0] == '1' || tryb[0] == '2' || tryb[0] == '3' || tryb[0] == 'X' || tryb[0] == 'x'))
{

    switch (tryb[0])
    {
        case '1':
            system("cls");
            pomoc_XO();
            system("cls");
            break;;

        case '2':
            system("cls");
            pomoc_Warcaby();
            system("cls");
            break;

        case '3':
            system("cls");
            pomoc_ogolna();
            system("cls");
            break;

        case 'X':
        case 'x':
            return;

    default:
        system("cls");
        std::cout << "Nieprawidlowa opcja. Sprobuj ponownie." << std::endl;
        break;
    }
    }
    else
    {
        system("cls");
        std::cout << "Nieprawidlowa opcja. Sprobuj ponownie." << std::endl;
    }
}
}

 void pomoc_XO()
 {
    wys("INSTRUKCJA DO GRY KOLKO I KRZYZYK");
    std::cout << std::endl;
    wys("- Gra toczy sie na planszy 3x3 pola.");
    wys("- Gracze lub gracz i komputer, na zmiane wybieraja pola na planszy, aby postawic swoj znak (Kolo lub Krzyzyk).");
    wys("- Celem gry jest ustawienie trzech swoich znakow w linii poziomej, pionowej lub ukosnej.");
    wys("- Aby wybrac pole, nalezy wpisac liczbe od 1 do 9, odpowiadajaca niezajetemu polu na planszy.");
    wys("- Gracz O zawsze zaczyna jako pierwszy.");
    std::cout << std::endl;
    wys("Po lewej stronie znajduje sie numeracja pol:");
    wys("A pod nia informacja, ktory gracz wykonuje ruch.");
    std::cout << std::endl;
    wys("1 | 2 | 3");
    wys("---+---+---");
    wys("4 | 5 | 6");
    wys("---+---+---");
    wys("7 | 8 | 9");
    std::cout << std::endl;
    wys("Cyfra w polu oznacza ze jest ono wolne.");
    wys("Gdy gracz wybierze pole, numer zniknie, co oznacza ze pole jest juz zajete.");
    std::cout << std::endl;
    wys("Na srodku widoczna jest aktualna plansza gry:");
    std::cout << std::endl;
    wys("   |   |   ");
    wys("---+---+---");
    wys("   |   |   ");
    wys("---+---+---");
    wys("   |   |   ");
    std::cout << std::endl;
   
    std::cout << std::endl;
    wys("PLIK SVG DO GRY:");
    wys("W trakcie realizacji");
    /*wys("W trakcie gry generowany jest plik SVG,");
    wys("ktory wizualizuje aktualny stan planszy gry w kolko i krzyzyk.");
    wys("Plik ten jest nadpisywany przy kazdym ruchu gracza i nalezy odswierzyc, aby zobaczyć zmiany.");
    wys("Jezeli chcesz zobaczyc plik SVG, znajdziesz go w katalogu z programem pod nazwa 'XO.svg'.");*/
    std::cout << std::endl;
    wys("MILEJ ZABAWY!!!");
    std::cout << std::endl << std::endl;
    pauza();
 }

 void pomoc_Warcaby()
 {
    wys("INSTRUKCJA DO GRY WARCABY");
    pauza();
 }

  void pomoc_ogolna()
  {
    wys("INSTRUKCJA DO SVG");
    pauza();
  }