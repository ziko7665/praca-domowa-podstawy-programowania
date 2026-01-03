// Maciej Zdeb s208293 ACiR gr.3 Zadanie domowe Podstawy Programowania 2025/26

#include "XO.h"
#include <iostream> 
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h>
#include <cctype>
#include <chrono>
#include "funkcje.h"

using namespace std;

   
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
            
            pomoc_menu();
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
        plik << "<rect x=\" 0\" y=\" 0\" width=\" 1500\" height=\"1500\" fill=\" #0B0B12\" />\n";
       
        
        plik << "<line x1=\"350\" y1=\"150\" x2=\"350\" y2=\"750\" stroke=\"#B8B8C2\" stroke-width=\"6\" />\n";
        plik << "<line x1=\"550\" y1=\"150\" x2=\"550\" y2=\"750\" stroke=\"#B8B8C2\" stroke-width=\"6\" />\n";
        plik << "<line x1=\"150\" y1=\"350\" x2=\"750\" y2=\"350\" stroke=\"#B8B8C2\" stroke-width=\"6\" />\n";
        plik << "<line x1=\"150\" y1=\"550\" x2=\"750\" y2=\"550\" stroke=\"#B8B8C2\" stroke-width=\"6\" />\n";

        
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
                    plik << "<line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2 << "\" stroke=\"#2DE2E6\" stroke-width=\"10\" />\n";
                    plik << "<line x1=\"" << x1 << "\" y1=\"" << y2 << "\" x2=\"" << x2 << "\" y2=\"" << y1 << "\" stroke=\"#2DE2E6\" stroke-width=\"10\" />\n";
                }
                else if(XO[i][j] == 'O')
                {
                    int cx = 250 + j * 200;
                    int cy = 250 + i * 200;
                    plik << "<circle cx=\"" << cx << "\" cy=\"" << cy << "\" r=\"50\" stroke=\"#B300FF\" stroke-width=\"10\" fill=\"none\" />\n";
                }
            }
        }

        plik << "</svg>\n";
        plik.close();
        system("cls");
       

    }

//====================================================================================================================================================================

void XO_plansza(char XO[3][3], char graf_plansza_XO[3][3], int czasO, int czasX) 
{
    
    int w = (szer_cmd() - 30) / 2; 
    int x = szer_cmd() - 20;
    int sekO = czasO % 60;
    int sekX = czasX % 60; 
    cout << " " << graf_plansza_XO[0][0] << " | " << graf_plansza_XO[0][1] << " | " << graf_plansza_XO[0][2] << " " << setw(w) << XO[0][0] << " | " << XO[0][1] << " | " << XO[0][2] << " " << endl;
    cout << "---+---+---" << setw(w+9) << "---+---+---" << endl;
    cout << " " << graf_plansza_XO[1][0] << " | " << graf_plansza_XO[1][1] << " | " << graf_plansza_XO[1][2] << " " << setw(w) << XO[1][0] << " | " << XO[1][1] << " | " << XO[1][2] << " " << endl;
    cout << "---+---+---" << setw(w+9) << "---+---+---" << endl;
    cout << " " << graf_plansza_XO[2][0] << " | " << graf_plansza_XO[2][1] << " | " << graf_plansza_XO[2][2] << " " << setw(w) << XO[2][0] << " | " << XO[2][1] << " | " << XO[2][2] << " " << endl;
   
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{(SHORT)x, (SHORT)0}); //ustawianie kursora pod wypisanie czasu
    if(czasO == 67) cout << "                   " << endl; // brak wypisania czasu jezeli czas jest rowny 67
    else if(sekO < 10) cout << "Czas gracza O: 0:0" << sekO << endl; 
    else cout << "Czas gracza O: 0:" << sekO << endl;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{(SHORT)x, (SHORT)2});
    if(czasO == 67)SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{(SHORT)x, (SHORT)0}); // ustawienie kursora w miejsce czasu O gdy komputer gra jako O
    if(czasX == 67) cout << "                   " << endl;
    else if(sekX < 10) cout << "Czas gracza X: 0:0" << sekX << endl;
    else cout << "Czas gracza X: 0:" << sekX << endl;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{(SHORT)0, (SHORT)5});
}   

//=====================================================================================================================================================================

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

void gra_XO()  
{
        int czas = 30;
        int czasO = czas;
        int czasX = czas;           
        system("cls");
        char XO[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
        bool zgodasvg = pytanie_tak_nie("Czy chcesz zagrac w kolko i krzyzyk w trybie graficznym? (tak/nie)");
        if(zgodasvg)
        {
            XO_svg_plansza(XO);
            string cmd = "start XO.svg";
            system(cmd.c_str());
            wys("Przyklej okno konsoli do lewej strony ekranu, a okno z graficzna reprezentacja do prawej strony ekranu.");
            wys("Jesli jestes gotowy");
        
            pauza();
            system("cls");
        }
        else
        {
            system("cls"); 
        }
      
    
    
    char XO_svg[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
    char graf_plansza_XO[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
    
    XO_plansza(XO, graf_plansza_XO, czasO, czasX);
   
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
    
    auto lc_start = std::chrono::steady_clock::now(); // poczatek liczenia czasu

    n = wczytaj_int("Wybierz pole: "); // wczytanie n 

    auto lc_koniec = std::chrono::steady_clock::now(); // koniec liczenia czasu
    auto ile_czas = std::chrono::duration_cast<std::chrono::seconds>(lc_koniec - lc_start).count(); //sprawdzenie ile czasu gracz stawial znak
    if(i % 2 == 0) // odjecie czasu stawiania od czasu gracza
        {
            czasO -= ile_czas;
        }
        else 
        {
            czasX -= ile_czas;
        }
    
    if(czasO <= 0) // sprawdzenie czy czas sie skonczyl
        {
            system("cls");
            wys("KONIEC GRY!!!");
            cout << endl;
            XO_plansza_wygrana(XO);
            cout << endl;
            wys("$$$ GRACZ X WYGRYWA $$$");
            cout << endl;
            wys(":( CZAS GRACZA O SIE SKONCZYL :(");
            
            break;  
        }
            else if(czasX <= 0)
        {
            system("cls");
            wys("KONIEC GRY!!!");
            cout << endl;
            XO_plansza_wygrana(XO);
            cout << endl;
            wys("$$$ GRACZ O WYGRYWA $$$");
            cout << endl;
            wys(":( CZAS GRACZA X SIE SKONCZYL :(");
            break;  
        }
    
    if(n >= 1 && n <= 9) //Stawianie znaków na planszy
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
            XO_plansza(XO, graf_plansza_XO, czasO, czasX);
            
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
    
    if(zgodasvg)
    {
        wys("Przywroc okno do orginalnego rozmiaru.");
        pauza();
        return;  
    }
    else
    {
        pauza();
        return;
    }  
}

//====================================================================================================================================================================

void gra_XO_PC()  
{
    
    
        int czasO;
        int czasX;      
        system("cls");
        char XO[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
        bool zgodasvg = pytanie_tak_nie("Czy chcesz zagrac w kolko i krzyzyk w trybie graficznym? (tak/nie)");
        XO_svg_plansza(XO);
        if(zgodasvg)
        {
            string cmd = "start XO.svg";
            system(cmd.c_str());
            wys("Przyklej okno konsoli do lewej strony ekranu, a okno z graficzna reprezentacja do prawej strony ekranu.");
            wys("Jesli jestes gotowy");
        
            pauza();
            system("cls");
        }
        else
        {
            system("cls");   
        }
    
    
    
    char XO_svg[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
        char graf_plansza_XO[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
    

    bool gracz_start;
    bool start = pytanie_tak_nie("Czy chcesz zaczynac gre jako pierwszy? (tak/nie)"); // ustalenie kto zaczyna oraz tego ktory czas bedzie wyswietlany 
    if(start)
    {
        gracz_start = true; 
        czasO = 30;
        czasX = 67;
    }
    else 
    {
        gracz_start = false;
        czasO = 67;
        czasX = 30;
    }
    
    for(int i = 0; i < 9; i++)
{
   int n;
    
    system("cls");
    XO_plansza(XO, graf_plansza_XO, czasO, czasX);
    auto lc_start = std::chrono::steady_clock::now(); // poczatek liczenia czasu
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
    
    if(i % 2 == 0 && gracz_start == true || i % 2 != 0 && gracz_start == false)
    {
        
        cout << "Postaw " << gznak << endl;
        
        n = wczytaj_int("Wybierz pole: ");
    
        

    }
    else 
    { 
      //ustawienie czasu komputera na 67, co powoduje ze jego czas nie bedzie wyswietlany 
      if(kznak == 'O') czasO = 67; 
      else if(kznak == 'X') czasX = 67; 
      
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
       else if(blokuj_gracza(XO, gznak, n) )
       {

       } // komputer sprawdza czy moze postawic znak obok juz postawionego swojego znaku
       else if(znak_obok_znaku(XO, kznak, n) )
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
    auto lc_koniec = std::chrono::steady_clock::now(); // koniec liczenia czasu
        auto ile_czas = std::chrono::duration_cast<std::chrono::seconds>(lc_koniec - lc_start).count(); //sprawdzenie ile czasu gracz stawial znak

    if(gznak == 'O') // odjecie czasu stawiania od czasu gracza
        {
            czasO -= ile_czas;
        }
        else if (gznak == 'X') 
        {
            czasX -= ile_czas;
        }
    
    if(czasO <= 0) // sprawdzenie czy czas sie skonczyl
        {
            system("cls");
            wys("KONIEC GRY!!!");
            cout << endl;
            XO_plansza_wygrana(XO);
            cout << endl;
            wys(":( CZAS GRACZA O SIE SKONCZYL :(");
            wys("$$$ GRACZ X WYGRYWA $$$");
            break;  
        }
        else if(czasX <= 0)
        {
            system("cls");
            wys("KONIEC GRY!!!");
            cout << endl;
            XO_plansza_wygrana(XO);
            cout << endl;
            wys(":( CZAS GRACZA X SIE SKONCZYL :(");
            wys("$$$ GRACZ O WYGRYWA $$$");
            break;  
        }
    XO_plansza(XO, graf_plansza_XO, czasO, czasX);
    
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
            XO_plansza(XO, graf_plansza_XO, czasO, czasX);
            
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
    

    if(zgodasvg)
    {
        wys("Przywroc okno do orginalnego rozmiaru.");
        czysc();
        pauza();
        return;  
    }
    else
    {
        czysc();
        pauza();
        return;
    }

}

//====================================================================================================================================================================

void sprawdz_czy_n_jest(vector<int>& kandydat, int n)  
{
   bool n_juz_jest = false;
    for(int i = 0; i < kandydat.size(); i++)
    {
        if(kandydat[i] == n)
        {
            n_juz_jest = true;
            break;
        }
    }
    if(!n_juz_jest)
    {
        kandydat.push_back(n);
    } 
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

bool znak_obok_znaku(char XO[3][3], char kznak, int &n)  
{
    vector<int> kandydat; 
    for(int w = 0; w < 3; w++)
    {
        for(int k = 0; k < 3; k++)
        {
            if(XO[w][k] == kznak)
            {
                if((w+1) <= 2 && XO[w+1][k] == ' ') // sprawdzenie pola niezej 
                {
                 n = 3*(w+1) + k + 1;
                 sprawdz_czy_n_jest(kandydat, n);
                }

                 if((w-1) >= 0 && XO[w-1][k] == ' ') // sprawdzenie pola wyzej
                {
                 n = 3*(w-1) + k + 1;
                 sprawdz_czy_n_jest(kandydat, n);
                }

                 if((k+1) <= 2 && XO[w][k+1] == ' ') //sprawdzenie pola po prawo
                {
                 n = 3*w + (k+1) + 1;
                 sprawdz_czy_n_jest(kandydat, n);
                }

                 if((k-1) >= 0 && XO[w][k-1] == ' ') // sprawdzenie pola po lewo 
                {
                 n = 3*w + (k-1) + 1;
                 sprawdz_czy_n_jest(kandydat, n);
                }

                 if((w+1) <= 2 && (k+1) <= 2 && XO[w+1][k+1] == ' ') // sprawdzenie pola po skosie dol prawo
                {
                  n = 3*(w+1) + (k+1) + 1;
                  sprawdz_czy_n_jest(kandydat, n);  
                }

                 if((w+1) <= 2 && (k-1) >=0 && XO[w+1][k-1] == ' ') // sprawdzenie pola po skosie dol lewo
                {
                  n = 3*(w+1) + (k-1) + 1;
                  sprawdz_czy_n_jest(kandydat, n);  
                }

                 if((w-1) >=0 && (k+1) <=2 && XO[w-1][k+1] == ' ') // sprawdzenie pola po skosie gora prawo
                {
                  n = 3*(w-1) + (k+1) + 1;
                  sprawdz_czy_n_jest(kandydat, n);  
                }
                
                 if((w-1) >= 0 && (k-1) >=0 && XO[w-1][k-1] == ' ') // sprawdzenie pola po skosie gora lewo
                {
                  n = 3*(w-1) + (k-1) + 1;
                  sprawdz_czy_n_jest(kandydat, n);  
                }
            }
        }
    }
    if(kandydat.empty())
    {
        return false;
    }
    else
    {
        int r = losuj_oddo(0, (kandydat.size() - 1));
        n = kandydat[r];
        return true;
    }
}

//====================================================================================================================================================================

bool blokuj_gracza(char XO[3][3], char gznak, int &n) 
{
    int blokady[8][3] =
    {
    {1, 2, 3}, // wiersz 1
    {4, 5, 6}, // wiersz 2 
    {7, 8, 9}, // wiersz 3
    {1, 4, 7}, // kolumna 1
    {2, 5, 8}, // kolumna 2 
    {3, 6, 9}, // kolumna 3
    {1, 5, 9}, // przekatna 1
    {3, 5, 7}  // przekatna 2 
    };
    for(int i = 0; i < 8; i++)
    {
        int pole;
        int l_gznak = 0;
        int l_pznak = 0;
        int puste_pole = 67;
        for(int j = 0; j < 3; j++)
        {
            pole = blokady[i][j];
            int wiersz = (pole-1)/3;
            int kolumna = (pole-1)%3;
          if(XO[wiersz][kolumna] == gznak)
          {
            l_gznak++;
          }
          if(XO[wiersz][kolumna] == ' ')
          {
            l_pznak++;
            puste_pole = pole;
          }
        }
        if(l_gznak == 2 && l_pznak == 1)
        {
            n = puste_pole;
            return true;
        }
    }
    
    return false;
        
       
}

