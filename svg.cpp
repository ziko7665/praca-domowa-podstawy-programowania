#include <iostream> 
#include <fstream>
#include <string> 
#include <ctime>
#include <vector>
#include "svg.h"
using namespace std; 

void svg_pod()
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
        int cx, cy, r, nrkoloru;
        string kolor;
        cout << "Podaj wspołrzedne srodka okregu (x,y): " << endl;
        cin >> cx >> cy;
        cout << "Podaj promien okregu: " << endl; 
        cin >> r;
        cout << "Wybierz kolor dla okregu:" << endl; 
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
        
        plik << "<circle cx=\"" << cx;
        plik << "\" cy=\"" << cy;
        plik << "\" r=\"" << r;
        plik << "\" fill=\"" << kolor;
        plik << "\" />\n";
   

         
        




    plik << "</svg>\n";
    plik.close();
    
        
    
}