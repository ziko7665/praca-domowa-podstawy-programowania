// Maciej Zdeb s208293 ACiR gr.3 Zadanie domowe Podstawy Programowania 2025/26

#include <iostream> 
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h>
#include "svg.h"
#include "funkcje.h"

using namespace std;


void svg_zaw();
void gra_XO();
void gra_XO_PC();
void gra_warcaby();
void pomoc();




int main() {
    char opcje;
    srand(time(nullptr));
     system("cls");
    // Menu glowne
        do
    {
        wys( "\\\\\\\\\\\\\\\\ MENU GLOWNE ////////"); 
        wys("- (1) Podstawowe SVG - "); 
        wys("- (2) Zawansowane SVG - ");
        wys("- (3) Gra w kolko i krzyzyk - ");
        wys("- (4) Gra w kolko i krzyzyk z komputerem - ");
        wys("- (5) Gra w warcaby - ");
        wys("- (H) Pomoc - ");
        wys("- (X) Wyjscie z programu - ");
        cout << "Wybierz opcje: " << endl;
        cin >> opcje;

            switch (opcje) 
        {
            case '1':
                 system("cls");
                svg_pod();
                 system("cls");
                break;
            case '2': 
                 system("cls");
                svg_zaw();
                 system("cls");
                break;
            case '3':
                 system("cls");
                gra_XO();
                 system("cls");
                break;
            case '4':
                 system("cls");
                gra_XO_PC();
                 system("cls");
                break;
            case '5':
                 system("cls");
                gra_warcaby();
                 system("cls");
                break;
            case 'H':
            case 'h':
                 system("cls");
                pomoc();
                 system("cls");
                break;
            case 'X':
            case 'x':
                cout << "Wyjscie z programu." << endl;
                return 0;
            default:
                system("cls");
                cout << "Nieprawidlowa opcja. Sprobuj ponownie." << endl;
                break;

        
        }
    } while(opcje != 'X' && opcje != 'x');
     system("cls");
    return 0;
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
