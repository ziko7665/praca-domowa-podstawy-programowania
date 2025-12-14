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
    cin >> nazwapliku; // pobieranie od uzytkownika nazwy pliku 
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
    cout << "Czy chcesz otworzyc swoj pusty plik svg? (tak/nie)" << endl; 
    while (true)
    {
    string zgoda;
    cin >> zgoda; 
    if(zgoda == "tak")
    {
        string cmd = "start " + nazwapliku;
        system(cmd.c_str());
        break;
     }
     else if (zgoda == "nie")
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
    wys("Pole pliku svg to 1500x1500");
    wys("Nacisnij Enter aby kontynuowac");
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
cin.get();
    
    string nazwapliku;
    cout << "Podaj nazwe pliku svg: " << endl; 
    cin >> nazwapliku; // pobieranie od uzytkownika nazwy pliku 
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
        cout << "Podaj wspolrzedne srodka okregu (x,y): " << endl;
        cin >> cx >> cy;
        cout << "Podaj promien okregu: " << endl; 
        cin >> r;
        cout << "Wybierz kolor dla okregu:" << endl; 
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
        cout << "Podaj wspolrzedne lewego gornego rogu prostokata(x,y): " << endl;
        cin >> rx >> ry;
        cout << "Podaj szerokosc prostokata: " << endl; 
        cin >> rw;
        cout << "Podaj wysokosc prostokata" << endl;
        cin >> rh;

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
        cout << "Podaj wspolrzedne pierwszego konca linii(x,y): " << endl;
        cin >> x1 >> y1;
        cout << "Podaj wspolrzedne drugiego konca linii(x,y): " << endl; 
        cin >> x2 >> y2;
        cout << "Podaj szerokosc lini" << endl;
        cin >> szerokosc;

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

        if(line_vs_circle == true && line_vs_circle == true)
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
    cin >> zgoda; 
    if(zgoda == "tak")
    {
        string cmd = "start " + nazwapliku;
        system(cmd.c_str());
        break;
     }
     else if (zgoda == "nie")
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

string wybor_koloru()       //Wybor koloru dla ksztaltu
{
    int nrkoloru;
    string kolor; 
        cout << "(1) czerwony" << endl; 
        cout << "(2) niebieski" << endl; 
        cout << "(3) zielony" << endl; 
        cout << "(4) czarny" << endl; 
        cout << "(5) secret" << endl;
        cin >> nrkoloru;
        
         switch (nrkoloru)
            {
                case 1:
                    kolor = "red";
                    break;
                case 2: 
                    kolor = "blue";
                    break;
                 case 3:
                    kolor = "green";
                    break;
                case 4:
                    kolor = "black";
                    break;
                case 5:
                {
                    vector<string> sekretnykolor = 
                    {   "purple",
                        "darkorange",
                        "brown",
                        "darkgreen",
                        "crimson",
                        "navy",
                        "teal",
                        "gold",
                        "deeppink",
                        "orange",
                    };
                    int losowa = rand() % 10;
                    kolor = sekretnykolor[losowa];
                    break;
                }
                default:
                    cout << "Nieprawidlowa opcja. Sprobuj ponownie." << endl;
                    break;
            }
    return kolor;
}
