#include <iostream> 
#include <fstream>
#include <string> 
#include <ctime>
#include <vector>
#include <limits>
#include <windows.h>
#include "svg.h"
#include "funkcje.h"
using namespace std; 


void svg_pod()      // Generownie pustego pliku svg i otwieranie go przez strone 
{
    string nazwapliku;
    cout << "Podaj nazwe pliku svg: " << endl;
    getline(cin >> ws, nazwapliku); // pobieranie od uzytkownika nazwy pliku 
    nazwapliku += ".svg"; 

    ofstream plik(nazwapliku); 
    if(!plik.is_open())         //sprawdzenie czy plik sie otworzyl
    {
        cout << "Błąd otwarcia pliku" << endl; 
        return;
    }  
         
    plik << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    plik << "<svg width=\"500\"  height=\"500\" xmlns=\"http://www.w3.org/2000/svg\">\n";
      


    plik << "</svg>\n";
    plik.close();
    system("cls");
    cout << "Czy chcesz otworzyc swoj pusty plik svg? (tak/nie)" << endl; 
    while (true)
    {
    string zgoda;
    getline(cin >> ws, zgoda); 
    if(zgoda.size() >= 3 && zgoda.substr(0,3) == "tak")
    {
        string cmd = "start " + nazwapliku;
        system(cmd.c_str());
        break;
     }
     else if (zgoda.size() >= 3 && zgoda.substr(0,3) == "nie")
     {
        break;
     }      
     else
     {
        cout << "Wpisz tak/nie" << endl; 

     }
    }
     system("cls");
}


void svg_zaw( ) // Generowanie kształtów w pliku, ktore na siebie nie nachodza 
{

        
    
    wys("Pole pliku svg to 1500x1500"); // wysrodkowanie tekstu
    pauza(); // czekanie na reakcje
    system("cls"); // czyszczenie konsoli 
    
    string nazwapliku;
    cout << "Podaj nazwe pliku svg: " << endl; 
    getline(cin >> ws, nazwapliku); // pobieranie od uzytkownika nazwy pliku 
    nazwapliku += ".svg"; 

    ofstream plik(nazwapliku); 
    if(!plik.is_open())         //sprawdzenie czy plik sie otworzyl
    {
        cout << "Błąd otwarcia pliku" << endl; 
        return;
    }       
    plik << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    plik << "<svg width=\"1500\"  height=\"1500\" xmlns=\"http://www.w3.org/2000/svg\">\n";
      

    //KOLO 
   int cx, cy, r, nrkoloru;
        string ckolor;
        cx = wczytaj_int("Podaj wspolrzedna x srodka kola: "); // pozwalanie na wczystanie jedynie liczby
        cy = wczytaj_int("Podaj wspolrzedna y srodka kola: ");
        r = wczytaj_int("Podaj promien okregu: ");
        cout << "Wybierz kolor dla kola:" << endl; 
        ckolor = wybor_koloru();
        
        plik << "<circle cx=\"" << cx;
        plik << "\" cy=\"" << cy;
        plik << "\" r=\"" << r;
        plik << "\" fill=\"" << ckolor;
        plik << "\" />\n";

        //granice kola
        int clg = cx - r; // lewa granica kola
        int cpg = cx + r; // prawa granica kola
        int cgg = cy - r; // gorna granica kola
        int cdg = cy + r; // dolna granica kola

//=================================================================================================================
        //PROSTOKAT
        int rx, ry, rw, rh; 
        int rlg, rpg, rgg, rdg;
        string rkolor;
        while(true)
    {
        rx = wczytaj_int("Podaj wspolrzedna x lewego gornego rogu prostokata: ");
        ry = wczytaj_int("Podaj wspolrzedna y lewego gornego rogu prostokata: ");
        rw = wczytaj_int("Podaj szerokosc prostokata: ");
        rh = wczytaj_int("Podaj wysokosc prostokata: ");

        //granice prostokata 
        rlg = rx; // lewa granica prostokata
        rpg = rx + rw;  // prawa granica prostokata 
        rgg = ry; // gorna granica prostokata
        rdg = ry + rh; // dolna granica prostokata

        bool rect_vs_circle = 
        (
            rpg < clg ||
            rlg > cpg || 
            rdg < cgg ||
            rgg > cdg 
        );
        
        
        if(rect_vs_circle == true)
        {
        cout << "Wybierz kolor prostokata:" << endl; 
        rkolor = wybor_koloru();
        
        
        plik << "<rect x=\"" << rx;
        plik << "\" y=\"" << ry;
        plik << "\" width=\"" << rw;
        plik << "\" height=\"" << rh;
        plik << "\" fill=\"" << rkolor;
        plik << "\" />\n";
        break;
        }

        else if(rect_vs_circle == false)
        {
            cout << "Prostokat nachodzi na okrag, podaj inne dane!!!" << endl;
            cout << endl; 
        }
    }

//=================================================================================================================
        // LINIA 
        int x1, y1, x2, y2, szerokosc; 
        string lkolor;
        while(true)
    {
        x1 = wczytaj_int("Podaj wspolrzedna x pierwszego konca linii: ");
        y1 = wczytaj_int("Podaj wspolrzedna y pierwszego konca linii: ");
        x2 = wczytaj_int("Podaj wspolrzedna x drugiego konca linii: ");
        y2 = wczytaj_int("Podaj wspolrzedna y drugiego konca linii: ");
        szerokosc = wczytaj_int("Podaj szerokosc linii: ");

        int llg = min(x1, x2) - szerokosc/2; // lewa granica linii 
        int lpg = max(x1, x2) + szerokosc/2; // prawa granica linii 
        int lgg = min(y1, y2) - szerokosc/2; // gorna granica linii 
        int ldg = max(y1, y2) + szerokosc/2; // dolna granica linni 

        bool line_vs_circle=    // brak kolizja z kolem 
        (      
            lpg < clg ||
            llg > cpg ||
            ldg < cgg ||
            lgg > cdg 
        );
        bool line_vs_rect=  // brak kolizji z prostokatem
        (
            lpg < rlg ||
            llg > rpg ||
            ldg < rgg ||
            lgg > rdg 
        );

        if(line_vs_circle == true && line_vs_rect    == true)
        {
        cout << "Wybierz kolor linii:" << endl; 
        lkolor = wybor_koloru();
        
        
        plik << "<line x1=\"" << x1;
        plik << "\" y1=\"" << y1;
        plik << "\" x2=\"" << x2;
        plik << "\" y2=\"" << y2;
        plik << "\" stroke=\"" << lkolor;
        plik << "\" stroke-width=\"" << szerokosc;
        plik << "\" />\n";
        break;
        }
        else if(line_vs_circle == false && line_vs_rect == true)
        {
            cout << "Linia nachodzi na kolo, podaj inne dane!!!" << endl;
            cout << endl; 
        }
        else if(line_vs_circle == true && line_vs_rect == false)
        {
            cout << "Linia nachodzi na prostokat, podaj inne dane!!!" << endl;
            cout << endl;
        }
        else if(line_vs_circle == false && line_vs_rect == false)
        {
            cout << "Linia nachodzi na prostokat i kolo, podaj inne dane!!!" << endl;
            cout << endl;
        }
    }
    plik << "</svg>\n";
    plik.close();    
    system("cls");
     cout << "Czy chcesz otworzyc swoj plik svg? (tak/nie)" << endl; 
    while (true)
    {
    string zgoda;
    getline(cin >> ws, zgoda); 

    if(zgoda.size() >= 3 && zgoda.substr(0,3) == "tak")
    {
        string cmd = "start " + nazwapliku;
        system(cmd.c_str());
        break;
     }
     else if (zgoda.size() >= 3 && zgoda.substr(0,3) == "nie")
     {
        break;
     }      
     else
     {
        cout << "Wpisz tak/nie" << endl; 

     }
    }
     system("cls");
}



