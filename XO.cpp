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
    void XO_svg_plansza(char XO[3][3])
    {
        ofstream plik("XO.svg");
        if(!plik.is_open())
        {
            cout << "Błąd otwarcia pliku" << endl; 
            return;
        }
        
        plik << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        plik << "<svg width=\"1000\"  height=\"1000\" xmlns=\"http://www.w3.org/2000/svg\">\n";
       
        
        plik << "<line x1=\"350\" y1=\"150\" x2=\"350\" y2=\"750\" stroke=\"black\" stroke-width=\"5\" />\n";
        plik << "<line x1=\"550\" y1=\"150\" x2=\"550\" y2=\"750\" stroke=\"black\" stroke-width=\"5\" />\n";
        plik << "<line x1=\"150\" y1=\"350\" x2=\"750\" y2=\"350\" stroke=\"black\" stroke-width=\"5\" />\n";
        plik << "<line x1=\"150\" y1=\"550\" x2=\"750\" y2=\"550\" stroke=\"black\" stroke-width=\"5\" />\n";

        
        for( int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(XO[i][j] == 'X')
                {
                    int x1 = 200 + j * 200;
                    int y1 = 200 + i * 200;
                    int x2 = 300 + j * 200;
                    int y2 = 300 + i * 200;
                    plik << "<line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2 << "\" stroke=\"red\" stroke-width=\"5\" />\n";
                    plik << "<line x1=\"" << x1 << "\" y1=\"" << y2 << "\" x2=\"" << x2 << "\" y2=\"" << y1 << "\" stroke=\"red\" stroke-width=\"5\" />\n";
                }
                else if(XO[i][j] == 'O')
                {
                    int cx = 250 + j * 200;
                    int cy = 250 + i * 200;
                    plik << "<circle cx=\"" << cx << "\" cy=\"" << cy << "\" r=\"50\" stroke=\"blue\" stroke-width=\"5\" fill=\"none\" />\n";
                }
            }
        }

        plik << "</svg>\n";
        plik.close();
        system("cls");
       

    }

//====================================================================================================================================================================
// Rysowanie planszy do gry w kolko i krzyzyk
void XO_plansza(char XO[3][3], char graf_plansza_XO[3][3]) 
{
    
    int w = (szer_cmd() - 30) / 2; 
    cout << " " << graf_plansza_XO[0][0] << " | " << graf_plansza_XO[0][1] << " | " << graf_plansza_XO[0][2] << " " << setw(w) << XO[0][0] << " | " << XO[0][1] << " | " << XO[0][2] << " " << endl;
    cout << "---+---+---" << setw(w+9) << "---+---+---" << endl;
    cout << " " << graf_plansza_XO[1][0] << " | " << graf_plansza_XO[1][1] << " | " << graf_plansza_XO[1][2] << " " << setw(w) << XO[1][0] << " | " << XO[1][1] << " | " << XO[1][2] << " " << endl;
    cout << "---+---+---" << setw(w+9) << "---+---+---" << endl;
    cout << " " << graf_plansza_XO[2][0] << " | " << graf_plansza_XO[2][1] << " | " << graf_plansza_XO[2][2] << " " << setw(w) << XO[2][0] << " | " << XO[2][1] << " | " << XO[2][2] << " " << endl;
   
}   

//=====================================================================================================================================================================
// Rysowanie planszy do gry w kolko i krzyzyk przy zakonczeniu gry
void XO_plansza_wygrana(char XO[3][3]) 
{
    char pusteXO[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
    int w = (szer_cmd() - 7) / 2; 
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
        char XO[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
        cout << "Czy chcesz zagrac w kolko i krzyzyk w trybie graficznym? (tak/nie)" << endl;
        while(true)
    {
       
        string zgoda;
        string xkolor; 
        string ckolor; 
        getline(cin >> ws, zgoda);
        
        if(zgoda.size() >= 3 && zgoda.substr(0,3) == "tak")
        {
        
        XO_svg_plansza(XO);
        string cmd = "start XO.svg";
        system(cmd.c_str());
        wys("Przyklej okno konsoli do lewej strony ekranu, a okno z graficzna reprezentacja do prawej strony ekranu.");
        wys("Jesli jestes gotowy");
        
        pauza();
        system("cls");
        break;
        }
        else if(zgoda.size() >= 3 && zgoda.substr(0,3) == "nie")
        {
            system("cls");
            break;
        }
        else
        {
            system("cls");
            cout << "Wpisz tak/nie: ";
            
        }
    }
    
    
    char XO_svg[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
    char graf_plansza_XO[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
    
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
            XO_svg_plansza(XO);
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
    string zgodasvg;
    
              
        system("cls");
        char XO[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
        cout << "Czy chcesz zagrac w kolko i krzyzyk w trybie graficznym? (tak/nie)" << endl;
        string zgoda;
        while(true)
    {
       
        
        getline(cin >> ws, zgodasvg);
        
        if(zgodasvg.size() >= 3 && zgodasvg.substr(0,3) == "tak")
        {
        XO_svg_plansza(XO);
        string cmd = "start XO.svg";
        system(cmd.c_str());
        wys("Przyklej okno konsoli do lewej strony ekranu, a okno z graficzna reprezentacja do prawej strony ekranu.");
        wys("Jesli jestes gotowy");
        
        pauza();
        system("cls");
        break;
        }
        else if(zgodasvg.size() >= 3 && zgodasvg.substr(0,3) == "nie")
        {
            system("cls");
            break;
        }
        else
        {   
            
            cout << "Wpisz tak/nie: ";
            
        }
    }
    
    
    
    char XO_svg[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
        char graf_plansza_XO[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
    

    bool gracz_start;
        cout << "Czy chcesz zaczynac gre jako pierwszy? (tak/nie)" << endl;
    while (true)
    {
        

        string start;
        getline(cin >> ws, start);
        if(start.size() >= 3 && start.substr(0,3) == "tak")
        {
            gracz_start = true;
            break;
        }
        else if(start.size() >= 3 && start.substr(0,3) == "nie")
        {
            gracz_start = false;
            break;
        }
        else
        {
           
            cout << "Wpisz tak/nie: ";
        }
    }
   
    for(int i = 0; i < 9; i++)
{
   int n;
    
    system("cls");
    XO_plansza(XO, graf_plansza_XO);
    
    if(i % 2 == 0 && gracz_start == true || i % 2 != 0 && gracz_start == false)
    {
        char znak;
        if(i % 2 == 0) 
        {
            znak = 'O';
        }
        else 
        {
            znak = 'X';
        }
        cout << "Postaw " << znak << endl;
        n = wczytaj_int("Wybierz pole: ");
        
    }
    else 
    {
        char kznak;
        char gznak;
        if(gracz_start == true) //ustalenie znakow komputera i gracza
        {
            kznak = 'X';
            gznak = 'O';
        }
        else 
        {
            kznak = 'O';
            gznak = 'X';
        }

       if(i == 0 && gracz_start == false) // stawianie pierwszego znaku przez komputer na srodku planszy
       {
            n = 5;
       }
       else if(i == 1 && gracz_start == true) // jesli gracz zaczyna to sprawdza czy srodek jest zajety, jesli tak to losuje pole, jesli nie to stawia znak na srodku
       {
            if(XO[1][1] == ' ')
            {
                n = 5; 

            }
            else 
            {
                while(true)
                {
                    n = losuj_oddo(1,9);
                    int wiersz = (n - 1) / 3;
                    int kolumna = (n - 1) % 3;
                    if(XO[wiersz][kolumna] != 'X' && XO[wiersz][kolumna] != 'O')
                    {
                        break;
                    }
                }
            }
       } // komputer sprawdza czy gracz lub on sam moze wygrac i blokuje ruch gracza albo stawia wygrywajacy znak
       else if(n_dla_pkt2(XO, kznak, gznak, n) )
       {

       } // komputer sprawdza czy moze postawic znak obok juz postawionego swojego znaku
       else if(n_dla_pkt3(XO, kznak, n) )
       {

       }
       else 
       {
            while(true)
            {
                n = losuj_oddo(1,9);
                int wiersz = (n - 1) / 3;
                int kolumna = (n - 1) % 3;
                if(XO[wiersz][kolumna] != 'X' && XO[wiersz][kolumna] != 'O')
                {
                    break;
                }
            }
       }   
    }

    XO_plansza(XO, graf_plansza_XO);
    
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
            XO_svg_plansza(XO);
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
    
    cout << endl << endl;
    


    if(zgodasvg.size() >= 3 && zgodasvg.substr(0,3) == "tak")
    {
    wys("Przywroc okno do orginalnego rozmiaru.");
    czysc();
    pauza();
    }
    else 
    {
        return;
    }    
  

}
//====================================================================================================================================================================
// Funkcja do sprawdzania mozliwosci postawienia znaku obok postawionego znaku 
bool n_dla_pkt3(char XO[3][3], char kznak, int &n)
{
    for(int w = 0; w < 3; w++)
    {
        for(int k = 0; k < 3; k++)
        {
            if(XO[w][k] == kznak)
            {
                if(XO[w][k+1] == ' ')
                {
                    n = w * 3 + k + 2;
                    return true;
                }
                else if(XO[w][k-1] == ' ')
                {
                    n = w * 3 + k;
                    return true;
                }
                else if(XO[w+1][k] == ' ')
                {
                    n = (w + 1) * 3 + k + 1;
                    return true;
                }
                else if(XO[w-1][k] == ' ')
                {
                    n = (w - 1) * 3 + k + 1;
                    return true;
                }
                else if(XO[w+1][k+1] == ' ')
                {
                    n = (w + 1) * 3 + (k + 1) + 1;
                    return true;
                }
                else if(XO[w-1][k-1] == ' ')
                {
                    n = (w - 1) * 3 + (k - 1) + 1;
                    return true;
                }
                else if(XO[w+1][k-1] == ' ')
                {
                    n = (w + 1) * 3 + (k - 1) + 1;
                    return true;
                }
                else if(XO[w-1][k+1] == ' ')
                {
                    n = (w - 1) * 3 + (k + 1) + 1;
                    return true;
                }

            }
            else
            {
                return false;
            }
        }
    }
    return false;
}

//====================================================================================================================================================================
// Funkcja do sprawdzenia czy da sie wygrac albo zablokowac wygrywajacy ruch przeciwnika
bool n_dla_pkt2(char XO[3][3], char kznak, char gznak, int &n)
{
    
        if(XO[0][0] == XO[0][1] && (XO[0][0] == gznak || XO[0][0] == kznak) && XO[0][2] == ' ')
       {
            n = 3;
            return true;
            /*
             # | # | $   
            ---+---+--- 
             4 | 5 | 6   
            ---+---+--- 
             7 | 8 | 9
            */
       }
       else if(XO[1][0] == XO[1][1] && (XO[1][0] == gznak || XO[1][0] == kznak) && XO[1][2] == ' ')
       {
            n = 6;
            return true;
            /*
                1 | 2 | 3
                ---+---+---
                # | # | $
                ---+---+---
                7 | 8 | 9
            */
       }
       else if(XO[2][0] == XO[2][1] && (XO[2][0] == gznak || XO[2][0] == kznak) && XO[2][2] == ' ')
       {
            n = 9;
            return true;
            /*
                1 | 2 | 3
                ---+---+---
                4 | 5 | 6
                ---+---+---
                # | # | $
            */
       }
       else if(XO[0][0] == XO[1][0] && (XO[0][0] == gznak || XO[0][0] == kznak) && XO[2][0] == ' ')
       {
            n = 7;
            return true;
            /*
                # | 2 | 3
                ---+---+---
                # | 5 | 6
                ---+---+---
                $ | 8 | 9
            */
       }
       else if(XO[0][1] == XO[1][1] && (XO[0][1] == gznak || XO[0][1] == kznak) && XO[2][1] == ' ')
       {
            n = 8;
            return true;
            /*
                1 | # | 3
                ---+---+---
                4 | # | 6
                ---+---+---
                7 | $ | 9
            */
       }
       else if(XO[0][2] == XO[1][2] && (XO[0][2] == gznak || XO[0][2] == kznak) && XO[2][2] == ' ')
       {
            n = 9;
            return true;
            /*
                1 | 2 | #
                ---+---+---
                4 | 5 | #
                ---+---+---
                7 | 8 | $
            */
       }
       else if(XO[0][0] == XO[1][1] && (XO[0][0] == gznak || XO[0][0] == kznak) && XO[2][2] == ' ')
       {
            n = 9;
            return true;
            /*
                # | 2 | 3
                ---+---+---
                4 | # | 6
                ---+---+---
                7 | 8 | $
            */
       }
       else if(XO[0][2] == XO[1][1] && (XO[0][2] == gznak || XO[0][2] == kznak) && XO[2][0] == ' ')
       {
            n = 7;
            return true;
            /*
                1 | 2 | #
                ---+---+---
                4 | # | 6
                ---+---+---
                $ | 8 | 9
            */
       }
       else if(XO[0][2] == XO[0][1] && (XO[0][2] == gznak || XO[0][2] == kznak) && XO[0][0] == ' ')
       {
            n = 1;
            return true;
            /*
                $ | # | #
                ---+---+---
                4 | 5 | 6
                ---+---+---
                7 | 8 | 9
            */
       }
       else if(XO[1][2] == XO[1][1] && (XO[1][2] == gznak || XO[1][2] == kznak) && XO[1][0] == ' ')
       {
            n = 4;
            return true;
            /*
                1 | 2 | 3
                ---+---+---
                $ | # | #
                ---+---+---
                7 | 8 | 9
            */
       }
       else if(XO[2][2] == XO[2][1] && (XO[2][2] == gznak || XO[2][2] == kznak) && XO[2][0] == ' ')
       {
            n = 7;
            return true;
            /*
                1 | 2 | 3
                ---+---+---
                4 | 5 | 6
                ---+---+---
                $ | # | #
            */
       }
       else if(XO[2][0] == XO[1][0] && (XO[2][0] == gznak || XO[2][0] == kznak) && XO[0][0] == ' ')
       {
            n = 1;
            return true;
            /*
                $ | 2 | 3
                ---+---+---
                # | 5 | 6
                ---+---+---
                # | 8 | 9
            */
       }
       else if(XO[2][1] == XO[1][1] && (XO[2][1] == gznak || XO[2][1] == kznak) && XO[0][1] == ' ')
       {
            n = 2;
            return true;
            /*
                1 | $ | 3
                ---+---+---
                4 | # | 6
                ---+---+---
                7 | # | 9
            */
       }
       else if(XO[2][2] == XO[1][2] && (XO[2][2] == gznak || XO[2][2] == kznak) && XO[0][2] == ' ')
       {
            n = 3;
            return true;
            /*
                1 | 2 | $
                ---+---+---
                4 | 5 | #
                ---+---+---
                7 | 8 | #
            */
       }
       else if (XO[2][2] == XO[1][1] && (XO[2][2] == gznak || XO[2][2] == kznak) && XO[0][0] == ' ')
       {
            n = 1;
            return true;
            /*
                $ | 2 | 3
                ---+---+---
                4 | # | 6
                ---+---+---
                7 | 8 | #
            */
       }
       else if(XO[2][0] == XO[1][1] && (XO[2][0] == gznak || XO[2][0] == kznak) && XO[0][2] == ' ')
       {
            n = 3;
            return true;
            /*
                1 | 2 | $
                ---+---+---
                4 | # | 6
                ---+---+---
                # | 8 | 9
            */
       }
       else if(XO[0][0] == XO[0][2] && (XO[0][0] == gznak || XO[0][0] == kznak) && XO[0][1] == ' ')
       {
            n = 2;
            /*
                # | $ | #
                ---+---+---
                4 | 5 | 6
                ---+---+---
                7 | 8 | 9   
            */
            return true;
       }
       else if(XO[1][0] == XO[1][2] && (XO[1][0] == gznak || XO[1][0] == kznak) && XO[1][1] == ' ')
       {
            n = 5;
            /*
                1 | 2 | 3
                ---+---+---
                # | $ | #
                ---+---+---
                7 | 8 | 9   
            */
            return true;
       }
       else if(XO[2][0] == XO[2][2] && (XO[2][0] == gznak || XO[2][0] == kznak) && XO[2][1] == ' ')
       {
            n = 8;
            /*
                1 | 2 | 3
                ---+---+---
                4 | 5 | 6
                ---+---+---
                # | $ | #   
            */
            return true;
       }
       else if(XO[0][0] == XO[2][0] && (XO[0][0] == gznak || XO[0][0] == kznak) && XO[1][0] == ' ')
       {
            n = 4;
            /*
                # | 2 | 3
                ---+---+---
                $ | 5 | 6
                ---+---+---
                # | 8 | 9   
            */
            return true;
       }
       else if(XO[0][1] == XO[2][1] && (XO[0][1] == gznak || XO[0][1] == kznak) && XO[1][1] == ' ')
       {
            n = 5;
            /*
                1 | # | 3
                ---+---+---
                4 | $ | 6
                ---+---+---
                7 | # | 9   
            */
            return true;
       }
       else if(XO[0][2] == XO[2][2] && (XO[0][2] == gznak || XO[0][2] == kznak) && XO[1][2] == ' ')
       {
            n = 6;
            /*
                1 | 2 | #
                ---+---+---
                4 | 5 | $
                ---+---+---
                7 | 8 | #   
            */
            return true;
       }
       else if(XO[0][0] == XO[2][2] && (XO[0][0] == gznak || XO[0][0] == kznak) && XO[1][1] == ' ')
       {
            n = 5;
            /*
                # | 2 | 3
                ---+---+---
                4 | $ | 6
                ---+---+---
                7 | 8 | #   
            */
            return true;
       }
       else if(XO[0][2] == XO[2][0] && (XO[0][2] == gznak || XO[0][2] == kznak) && XO[1][1] == ' ')
       {
            n = 5;
            /*
                1 | 2 | #
                ---+---+---
                4 | $ | 6
                ---+---+---
                # | 8 | 9   
            */
            return true;
       }
       else if (XO[0][1] == XO[0][2] && (XO[0][1] == gznak || XO[0][1] == kznak) && XO[0][0] == ' ')
       {
            n = 1;
            
            return true;
       }
       else 
       {
            return false;
       }
       return false;
       
}

