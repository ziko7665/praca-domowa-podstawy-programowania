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
#include "XO.h"
#include "funkcje.h"

using namespace std;




void gra_warcaby();





int main() {
    string opcje;
    srand(time(nullptr));
     system("cls");
    // Menu glowne
        do
    {
        wys( "\\\\\\\\\\\\\\\\ MENU GLOWNE ////////"); 
        wys("- (1) Podstawowe SVG -"); 
        wys("- (2) Zawansowane SVG -");
        wys("- (3) Gra w kolko i krzyzyk -");
        wys("- (4) Gra w warcaby - ");
        wys("- (H) Pomoc -");
        wys("- (X) Wyjscie z programu -");
        cout << "Wybierz opcje: " << endl;
        getline(cin >> ws, opcje);
        if(opcje.size() == 1 && (opcje[0] == '1' || opcje[0] == '2' || opcje[0] == '3' || opcje[0] == '4' || opcje[0] == 'H' || opcje[0] == 'h' || opcje[0] == 'X' || opcje[0] == 'x'))
        {

            switch (opcje[0]) 
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
                menu_XO();
                 system("cls");
                break;

            case '4':
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
                system("cls");
                return 0;
            default:
                system("cls");
                cout << "Nieprawidlowa opcja. Sprobuj ponownie." << endl;
                break;

        
        }
    }
    else
    {
        system("cls");
        cout << "Nieprawidlowa opcja. Sprobuj ponownie." << endl;
    }
    } while(opcje[0] != 'X' && opcje[0] != 'x');
     system("cls");
    return 0;
}




void gra_warcaby() 
{
    cout << "Funkcja gra_warcaby" << endl;
    pauza();

}
