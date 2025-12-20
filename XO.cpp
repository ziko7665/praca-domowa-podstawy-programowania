#include "XO.h"
#include <iostream> 
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h>
#include "funkcje.h"

using namespace std;

//Menu wyboru trybu gry w kolko i krzyzyk   
void menu_XO()
{
     while(true)
     {
    string tryb;
    wys("\\\\\\\\\\\\\\\\ TRYB GRY ////////");
    wys("- (1) Gracz VS Gracz -");
    wys("- (2) Gracz VS PC -");
    wys("- (H) Instrukcja do gry -");
    wys("- (X) Powrot do MENU -");
    cout << "Wybierz opcje: "; 
    getline(cin >> ws, tryb);
    if(tryb.size() == 1 && (tryb[0] == '1' || tryb[0] == '2' || tryb[0] == 'H' || tryb[0] == 'h' || tryb[0] == 'X' || tryb[0] == 'x'))
{

    switch (tryb[0])
    {
        case '1':
            gra_XO();
            system("cls");
            break;;

        case '2':
            gra_XO_PC();
            system("cls");
            break;

        case 'H':
        case 'h':
            
            pomoc();
            system("cls");
            break;

        case 'X':
        case 'x':
            return;

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
}

}

//====================================================================================================================================================================
// Tworzenie pliku SVG do gry w kolko i krzyzyk
void XO_svg()
{
    ofstream plik("XO.svg");
    if(!plik.is_open())
    {
        cout << "Błąd otwarcia pliku" << endl; 
        return;
    }
    plik << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    plik << "<svg width=\"500\"  height=\"500\" xmlns=\"http://www.w3.org/2000/svg\">\n";
    
      


    plik << "</svg>\n";
    plik.close();
    system("cls");


}

//====================================================================================================================================================================
// Rysowanie planszy do gry w kolko i krzyzyk
void XO_plansza(char XO[3][3], char graf_plansza_XO[3][3]) 
{
    
    int w = (szerokosc_konsoli() - 30) / 2; 
    cout << " " << graf_plansza_XO[0][0] << " | " << graf_plansza_XO[0][1] << " | " << graf_plansza_XO[0][2] << " " << setw(w) << XO[0][0] << " | " << XO[0][1] << " | " << XO[0][2] << " " << endl;
    cout << "---+---+---" << setw(w+9) << "---+---+---" << endl;
    cout << " " << graf_plansza_XO[1][0] << " | " << graf_plansza_XO[1][1] << " | " << graf_plansza_XO[1][2] << " " << setw(w) << XO[1][0] << " | " << XO[1][1] << " | " << XO[1][2] << " " << endl;
    cout << "---+---+---" << setw(w+9) << "---+---+---" << endl;
    cout << " " << graf_plansza_XO[2][0] << " | " << graf_plansza_XO[2][1] << " | " << graf_plansza_XO[2][2] << " " << setw(w) << XO[2][0] << " | " << XO[2][1] << " | " << XO[2][2] << " " << endl;
   
}   

//====================================================================================================================================================
// Rysowanie planszy do gry w kolko i krzyzyk przy zakonczeniu gry
void XO_plansza_wygrana(char XO[3][3]) 
{
    char pusteXO[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
    int w = (szerokosc_konsoli() - 7) / 2; 
    cout << setw(w) << XO[0][0] << " | " << XO[0][1] << " | " << XO[0][2] << " " << endl;
    cout << setw(w+9) << "---+---+---" << endl;
    cout << setw(w) << XO[1][0] << " | " << XO[1][1] << " | " << XO[1][2] << " " << endl;
    cout << setw(w+9) << "---+---+---" << endl;
    cout << setw(w) << XO[2][0] << " | " << XO[2][1] << " | " << XO[2][2] << " " << endl;
   
}

//====================================================================================================================================================================
//Kolko i krzyzyk Gracz vs Gracz
void gra_XO() 
{
                  
        system("cls");

        XO_svg();
        
        wys("Przyklej okno konsoli do lewej strony ekranu, a okno z graficzna reprezentacja do prawej strony ekranu.");
        wys("Jesli jestes gotowy");
        pauza();
        system("cls");

    char graf_plansza_XO[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
    char XO[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
    XO_plansza(XO, graf_plansza_XO);
   
    for(int i = 0; i < 9; i++)
{
   
    int n;
    cout << endl;
    if(i % 2 == 0)
    {
        cout << "Ruch gracza O" << endl;
    }
    else 
    {
       cout << "Ruch gracza X" << endl;
    }
    
    n = wczytaj_int("Wybierz pole: ");
    //Stawianie znaków na planszy
    if(n >= 1 && n <= 9)
    {
        int wiersz = (n - 1) / 3;
        int kolumna = (n - 1) % 3;
        if(XO[wiersz][kolumna] != 'X' && XO[wiersz][kolumna] != 'O')
        {
            if(i % 2 == 0)
            {
                XO[wiersz][kolumna] = 'O';
                graf_plansza_XO[wiersz][kolumna] = ' ';
            }
            else 
            {
                XO[wiersz][kolumna] = 'X';
                graf_plansza_XO[wiersz][kolumna] = ' ';
            }
            system("cls");
            XO_plansza(XO, graf_plansza_XO);
        }
        else
        {
            cout << "Pole juz zajete. Sprobuj ponownie." << endl;
            i--;
            continue;
        }
        //Warunek wygranej
       if(( XO[0][0] == XO[0][1] && XO[0][1] == XO[0][2]) && (XO[0][0] == 'X' || XO[0][0] == 'O') || //wiersz 1
           (XO[1][0] == XO[1][1] && XO[1][1] == XO[1][2]) && (XO[1][0] == 'X' || XO[1][0] == 'O') || //wiersz 2
           (XO[2][0] == XO[2][1] && XO[2][1] == XO[2][2]) && (XO[2][0] == 'X' || XO[2][0] == 'O') || //wiersz 3
           (XO[0][0] == XO[1][0] && XO[1][0] == XO[2][0]) && (XO[0][0] == 'X' || XO[0][0] == 'O') || //kolumna 1
           (XO[0][1] == XO[1][1] && XO[1][1] == XO[2][1]) && (XO[0][1] == 'X' || XO[0][1] == 'O') || //kolumna 2 
           (XO[0][2] == XO[1][2] && XO[1][2] == XO[2][2]) && (XO[0][2] == 'X' || XO[0][2] == 'O') || //kolumna 3
           (XO[0][0] == XO[1][1] && XO[1][1] == XO[2][2]) && (XO[0][0] == 'X' || XO[0][0] == 'O') || //przekatna 1
           (XO[0][2] == XO[1][1] && XO[1][1] == XO[2][0]) && (XO[0][2] == 'X' || XO[0][2] == 'O'))   //przekatna 2
       {
            system("cls");
            wys("KONIEC GRY!!!");
            cout << endl;
            XO_plansza_wygrana(XO);
            
           if(i % 2 == 0)
           {
                cout << endl;
                wys("$$$ GRACZ O WYGRYWA $$$");
           }
           else if(i % 2 != 0)
           {
                cout << endl;
                wys("$$$ GRACZ X WYGRYWA $$$");
           }

            break;
       }
       else if(i == 8)
       {
            system("cls");
            wys("KONIEC GRY!!!");
            cout << endl;
            XO_plansza_wygrana(XO);
            cout << endl;
            wys("REMIS :(");
            break;
       }
        
    }
     else
    {
        cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;
        i--;
        continue;   
    }
}
    czysc();
    cout << endl << endl;
    wys("Przywroc okno do orginalnego rozmiaru.");
    pauza();  
}

//====================================================================================================================================================================
// Kolko i krzyzyk Gracz vs PC
void gra_XO_PC() 
{
    system("cls");
    pauza();
}

