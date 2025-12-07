#include <iostream> 
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h>
#include "svg.h"

using namespace std;


void svg_zaw();
void gra_XO();
void gra_XO_PC();
void gra_warcaby();
void pomoc();
void wysrodkuj(const string& tekst); // Funkcja do wysrodkowania tekstu w konsoli


int main() {
    char opcje;
    srand(time(nullptr));

    // Menu glowne
        do
    {
        wysrodkuj( "\\\\\\\\\\ MENU GLOWNE ///////"); 
        wysrodkuj("- (1) Podstawowe SVG - "); 
        wysrodkuj("- (2) Zawansowane SVG - ");
        wysrodkuj("- (3) Gra w kolko i krzyzyk - ");
        wysrodkuj("- (4) Gra w kolko i krzyzyk z komputerem - ");
        wysrodkuj("- (5) Gra w warcaby - ");
        wysrodkuj("- (6) Pomoc - ");
        wysrodkuj("- (X) Wyjscie z programu - ");
        cout << "Wybierz opcje: " << endl;
        cin >> opcje;

            switch (opcje) 
        {
            case '1':
                svg_pod();
                break;
            case '2': 
                svg_zaw();
                break;
            case '3':
                gra_XO();
                break;
            case '4':
                gra_XO_PC();
                break;
            case '5':
                gra_warcaby();
                break;
            case '6':   
                pomoc();
                break;
            case 'X':
            case 'x':
                cout << "Wyjscie z programu." << endl;
                return 0;
            default:
                cout << "Nieprawidlowa opcja. Sprobuj ponownie." << endl;
                break;

        
        }
    } while(opcje != 'X' && opcje != 'x');
    
    return 0;
}

int szerokosc_konsoli() // Funcja sprawdzenia szerokosci konsoli 
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

void wysrodkuj(const string& tekst) 
{
  int szerokosc = szerokosc_konsoli();
  int dlugosc = tekst.length();
  int spacje = (szerokosc - dlugosc) / 2;
  if(spacje < 0) spacje = 0; 
    cout << string(spacje, ' ') << tekst << endl;
}

void svg_zaw() 
{
    cout << "Funkcja svg_zaw zostala wywolana." << endl;
    // Implementacja funkcji zaawansowanego SVG
}
void gra_XO() 
{
    cout << "Funkcja gra_XO zostala wywolana." << endl;
    // Implementacja funkcji gry XO
}
void gra_XO_PC() 
{
    cout << "Funkcja gra_XO_PC zostala wywolana." << endl;
    // Implementacja funkcji gry XO z komputerem
}
void gra_warcaby() 
{
    cout << "Funkcja gra_warcaby zostala wywolana." << endl;
    // Implementacja funkcji gry w warcaby
}
void pomoc() 
{
    cout << "Funkcja pomoc zostala wywolana." << endl;
    // Implementacja funkcji pomocy
}
