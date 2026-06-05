

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h>
#include <cctype>
#include "svg.h"
#include "XO.h"
#include "funkcje.h"
#include "warcaby.h"

using namespace std;

int main()
{
    string opcje;
    srand(time(nullptr));

    // Ustawienia domyslne gier
    bool war_graf = true;
    bool war_ods = false;
    bool XO_graf = true;
    bool XO_ods = false;
    int XO_czas = 30;

    system("cls");
    // Menu glowne
    do
    {
        wys("\\\\\\\\\\\\\\\\ MENU GLOWNE ////////");
        cout << endl;
        wys("- (1) Podstawowe SVG -");
        wys("- (2) Zawansowane SVG -");
        wys("- (3) Gra w kolko i krzyzyk -");
        wys("- (4) Gra w warcaby - ");
        wys("- (H) Pomoc -");
        wys("- (X) Wyjscie z programu -");
        cout << "Wybierz opcje: ";
        getline(cin >> ws, opcje);
        if (opcje.empty())
            continue;
        if (opcje.size() == 1 && (opcje[0] == '1' || opcje[0] == '2' || opcje[0] == '3' || opcje[0] == '4' || opcje[0] == 'H' || opcje[0] == 'h' || opcje[0] == 'X' || opcje[0] == 'x'))
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
                menu_XO(XO_ods, XO_graf, XO_czas);
                system("cls");
                break;

            case '4':
                system("cls");
                menu_warcaby(war_ods, war_graf);
                system("cls");
                break;

            case 'H':
            case 'h':
                system("cls");
                pomoc_menu();
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
    } while (opcje[0] != 'X' && opcje[0] != 'x');
    system("cls");
    return 0;
}
