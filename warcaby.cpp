// Maciej Zdeb s208293 ACiR gr.3 Zadanie domowe Podstawy Programowania 2025/26


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
#include <sstream>
#include "funkcje.h"
#include "warcaby.h"

using namespace std;



void war_plansza(char war[8][8])
{
   int pw = ((szer_cmd() - 30) / 2)-2; 
   int kw = ((szer_cmd() - 30)  / 2)-1;
    cout << endl << endl; 
    cout << setw(kw+30) << "a   b   c   d   e   f   g   h" << endl;
    cout << setw(kw+32) << "+---+---+---+---+---+---+---+---+" << endl;

    cout << setw(pw) << "1 " << "|" << " " << war[0][0] << " | " << war[0][1] << " | " << war[0][2] << " | " << war[0][3] 
    << " | " <<  war[0][4] << " | " << war[0][5] << " | " << war[0][6] << " | " << war[0][7] << " " << "|" <<  endl;  

    cout << setw(kw) << "|" << "---+---+---+---+---+---+---+---" << "|" << endl;

    cout << setw(pw) << "2 " << "|" << " " << war[1][0] << " | " << war[1][1] << " | " << war[1][2] << " | " << war[1][3] 
    << " | " <<  war[1][4] << " | " << war[1][5] << " | " << war[1][6] << " | " << war[1][7] << " " << "|" << endl;  

    cout << setw(kw) << "|" << "---+---+---+---+---+---+---+---" << "|" << endl;

    cout << setw(pw) << "3 " << "|" << " " << war[2][0] << " | " << war[2][1] << " | " << war[2][2] << " | " << war[2][3] 
    << " | " <<  war[2][4] << " | " << war[2][5] << " | " << war[2][6] << " | " << war[2][7] << " " << "|" << endl;  

    cout << setw(kw) << "|" << "---+---+---+---+---+---+---+---" << "|" << endl;

    cout << setw(pw) << "4 " << "|" << " " << war[3][0] << " | " << war[3][1] << " | " << war[3][2] << " | " << war[3][3] 
    << " | " <<  war[3][4] << " | " << war[3][5] << " | " << war[3][6] << " | " << war[3][7] << " " << "|" << endl;  

    cout << setw(kw) << "|" << "---+---+---+---+---+---+---+---" << "|" << endl;

    cout << setw(pw) << "5 " << "|" << " " << war[4][0] << " | " << war[4][1] << " | " << war[4][2] << " | " << war[4][3] 
    << " | " <<  war[4][4] << " | " << war[4][5] << " | " << war[4][6] << " | " << war[4][7] << " " << "|" << endl; 

    cout << setw(kw) << "|" << "---+---+---+---+---+---+---+---" << "|" << endl;

    cout << setw(pw) << "6 " << "|" << " " << war[5][0] << " | " << war[5][1] << " | " << war[5][2] << " | " << war[5][3] 
    << " | " <<  war[5][4] << " | " << war[5][5] << " | " << war[5][6] << " | " << war[5][7] << " " << "|" << endl;  

    cout << setw(kw) << "|" << "---+---+---+---+---+---+---+---" << "|" << endl;

    cout << setw(pw) << "7 " << "|" << " " << war[6][0] << " | " << war[6][1] << " | " << war[6][2] << " | " << war[6][3] 
    << " | " <<  war[6][4] << " | " << war[6][5] << " | " << war[6][6] << " | " << war[6][7] << " " << "|" << endl; 
     
    cout << setw(kw) << "|" << "---+---+---+---+---+---+---+---" << "|" << endl;

    cout << setw(pw) << "8 " << "|" << " " << war[7][0] << " | " << war[7][1] << " | " << war[7][2] << " | " << war[7][3] 
    << " | " <<  war[7][4] << " | " << war[7][5] << " | " << war[7][6] << " | " << war[7][7] << " " << "|" << endl;  

    cout << setw(kw+32) << "+---+---+---+---+---+---+---+---+" << endl;
}

//=======================================================================================================================================================================

void ustaw_war_plansz_0(char war[8][8])
{
for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
         if((i+j) % 2 == 0)
            {
                war[i][j] = ' ';
         }
            else 
            {
                war[i][j] = '*';
            }
        }
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 8; j ++)
        { 
            if ((i+j)%2==1) war[i][j]='@';
        }
    }

    for(int i = 5; i < 8; i++)
    {
        for(int j = 0; j < 8; j ++)
        { 
            if ((i+j)%2==1) war[i][j]='O';
        }
    }    
}

//=======================================================================================================================================================================

bool pole_na_tab(std::string& x, int& wier, int& kol)
{
    if(x.size() != 2) return false;
    char lit = tolower(x[0]);
    char cyf = x[1];

    if(lit < 'a' || lit > 'h') return false;
    if(cyf < '1' || cyf > '8') return false;
    wier = cyf - '1';
    kol = lit - 'a';
    return true;
}

//=======================================================================================================================================================================

bool ruch_bicia(char war[8][8], char gracz, char nie_gracz, int wier_po_sr, int kol_po_sr, int zwier, int zkol, int dwier, int dkol)
{
    if(gracz == 'O')
    {
        war[wier_po_sr][kol_po_sr] = '*';
        war[zwier][zkol] = '*';
        war[dwier][dkol] = gracz;
        return true;
    }
    else if(gracz == '@')
    {
        war[wier_po_sr][kol_po_sr] = '*';
        war[zwier][zkol] = '*';
        war[dwier][dkol] = gracz;
        return true;
    }
    return false;
}

//=======================================================================================================================================================================

bool czy_musi_bic(char war[8][8], char gracz, char nie_gracz)
{
    bool jest_bicie = false; 

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(war[i][j] == gracz)
            {
                if(gracz == 'O')
                {
                if(i - 1 >= 0 && j - 1 >= 0 && i - 2 >= 0 && j - 2 >= 0)
                {
                    if((war[i - 1][j -1] == nie_gracz) && (war[i - 2][j - 2] == '*'))
                    {
                        return true;  
                    }
                }
                if((i - 1 >= 0 && j + 1 <= 7 && i - 2 >= 0 && j + 2 <= 7))
                {
                    if((war[i - 1][j + 1] == nie_gracz) && (war[i - 2][j + 2] == '*'))
                    {
                        return true;  
                    }
                }
                }

                if(gracz == '@')
                {
                    if(i + 1 <= 7 && j - 1 >= 0 && i + 2 <= 7 && j - 2 >= 0)
                    {
                        if((war[i + 1][j - 1] == nie_gracz) && (war[i + 2][j - 2] == '*'))
                        {
                            return true;   
                        }
                    }
                    if(i + 1 <= 7 && j + 1 <= 7 && i + 2 <= 7 && j + 2 <= 7)
                    {
                        if((war[i + 1][j + 1] == nie_gracz) && (war[i + 2][j + 2] == '*'))
                        {
                            return true;   
                        } 
                    }  
                }
            }
        }
    }
    return false; 
}

//=======================================================================================================================================================================

bool pion_ma_bicie(char war[8][8], char gracz, char nie_gracz, int dwier, int dkol)
{

    if(war[dwier][dkol] == 'O')
    {
        if(dwier - 1 >= 0 && dkol - 1 >= 0 && dwier - 2 >= 0 && dkol - 2 >= 0)
        {
            if((war[dwier - 1][dkol -1] == nie_gracz) && (war[dwier - 2][dkol - 2] == '*'))
            {
                return true;  
            }
        }
        if((dwier - 1 >= 0 && dkol + 1 <= 7 && dwier - 2 >= 0 && dkol + 2 <= 7))
        {
            if((war[dwier - 1][dkol + 1] == nie_gracz) && (war[dwier - 2][dkol + 2] == '*'))
            {
                return true;  
            }
        }
    }


       else if(war[dwier][dkol] == '@')
    {
        if(dwier + 1 <= 7 && dkol - 1 >= 0 && dwier + 2 <= 7 && dkol - 2 >= 0)
        {
            if((war[dwier + 1][dkol - 1] == nie_gracz) && (war[dwier + 2][dkol - 2] == '*'))
            {
                return true;   
            }
           
        }
        if(dwier + 1 <= 7 && dkol + 1 <= 7 && dwier + 2 <= 7 && dkol + 2 <= 7)
        {
            if((war[dwier + 1][dkol + 1] == nie_gracz) && (war[dwier + 2][dkol + 2] == '*'))
            {
                return true;   
            } 
        }

    }
    else
    { 
    return false;
    }

return false;
}

//=======================================================================================================================================================================

bool bez_piona(char war[8][8])
{
    int czarne = 0;
    int biale = 0;

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(war[i][j] == 'O')
            {
                biale++;
            }
            else if(war[i][j] == '@')
            {
                czarne++;
            }
        }
    }
    if(biale == 0)
    {
        system("cls");
        war_plansza(war);
        cout << endl << endl;
        wys("$$$ GRACZ @ WYGRYWA $$$");
        cout << endl;
        wys("Zbito wszystkie pionki gracza O");
        return true;
    }
    else if(czarne == 0)
    {
        system("cls");
        war_plansza(war);
        cout << endl << endl;
        wys("$$$ GRACZ O WYGRYWA $$$");
        cout << endl;
        wys("Zbito wszystkie pionki gracza @");
        return true;
    }
    else
    {
        return false;
    }
    return false; 
}

//=======================================================================================================================================================================

bool czy_jest_ruch(char war[8][8], char gracz, char nie_gracz)
{
    if(czy_musi_bic(war, gracz, nie_gracz)) 
    {
        return true;
    }
    else
    {

    int l_ruch = 0;

        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(war[i][j] == gracz)
                {
                    if(gracz == 'O')
                    {
                        if(i - 1 >= 0 && j - 1 >= 0)
                        {
                            if(war[i - 1][j - 1] == '*')
                            {
                                l_ruch++;
                            }
                        }
                        if(i - 1 >= 0 && j + 1 <= 7)
                        {
                            if((war[i - 1][j + 1] == '*'))
                            {
                                l_ruch++;
                            }
     
                        }
                    }
                    else
                    {
                        if(i + 1 <= 7 && j - 1 >= 0)
                        {
                           if(war[i + 1][j - 1] == '*')
                           {
                                l_ruch++;
                           } 
                        }
                        if(i + 1 <= 7 && j + 1 <= 7)
                        {
                            if(war[i + 1][j + 1] == '*')
                            {
                                l_ruch++;
                            }
                        }
                    }
                }
                
            }
        }

        if(l_ruch != 0)
        {
            return true;
        }
        else
        {
            if(gracz == 'O')
            {
            system("cls");
            war_plansza(war);
            cout << endl << endl;
            wys("$$$ GRACZ @ WYGRYWA $$$");
            cout << endl;
            wys("Gracz O nie moze wykonac ruchu"); 
            cout << endl;
            cout << endl;
            
            return false;
            }
            else
            {
            system("cls");
            war_plansza(war);
            cout << endl << endl;
            wys("$$$ GRACZ O WYGRYWA $$$");
            cout << endl;
            wys("Gracz @ nie moze wykonac ruchu"); 
            cout << endl;
           
            return false;   
            }
        }
    }
    return false;
}

//=======================================================================================================================================================================

void warcaby()
{
    char war[8][8];
    ustaw_war_plansz_0(war);
    war_plansza(war);
    bool koniec = false;
    char gracz = 'O';

    while(!koniec) 
    {   
        char nie_gracz;
        if (gracz == 'O') nie_gracz = '@';
        else nie_gracz = 'O';


        if(bez_piona(war))//Sprawdzenie czy ktorys gracz wygral
        {
            koniec = true;
            break;
        }
        if(!czy_jest_ruch(war, gracz, nie_gracz))
        {
            koniec = true;
            break;
        }

        string z, d; 
        bool musi_bic = czy_musi_bic(war, gracz, nie_gracz);
        
        cout << "Ruch gracza: " << gracz << endl;
        
        bool dobry_ruch = false;
        while(!dobry_ruch) //Walidacja ruchu 
        {
            cout << "Podaj pole startowe: ";
            cin >> z; czysc();
            cout << "Podaj pole docelowe: ";
            cin >> d; czysc();

            int zwier, zkol, dwier, dkol;
           
            bool OKz = pole_na_tab(z, zwier, zkol);
            bool OKd = pole_na_tab(d, dwier, dkol);

            if(!OKz || !OKd)
            {
                cout << "Niepoprawny foramt ruchu, sprobuj ponownie." << endl << endl;
                continue;
            }

            if(war[zwier][zkol] != gracz)
            {
                cout << "Pole startowe jest niepoprawne, sprobuj ponownie." << endl << endl;
                continue;
            }
            if(war[dwier][dkol] != '*')
            {
                cout << "Pole docelowe jest niepoprawne, sprobuj ponownie." << endl << endl;
                continue;
            }
            
            int kier_weir = dwier - zwier;
            int kier_kol = dkol - zkol;
            int kier;

            if (gracz == 'O')
            {
                kier = -1;   // biały idzie do góry (wiersz maleje)
            }
                else if (gracz == '@')
            {
                kier = 1;    // czarny idzie w dół (wiersz rośnie)
            }
            else
            {
                cout << "Blad: nieznany gracz" << endl;
                continue;
            }

            
            int wier_po_sr;
            int kol_po_sr;
            

            if(kier_weir == kier && (kier_kol == 1 || kier_kol == -1)) // Zwykly ruch, o 1 po skosie i w dobrym kierunku
            {
                if(musi_bic == false)
                {
                war[zwier][zkol] = '*';
                war[dwier][dkol] = gracz;
                dobry_ruch = true;
                }
                else 
                {
                    cout << "Masz bicie, musisz je wykonac" << endl << endl;
                    continue;
                }
            }
            
            
            else if(kier_weir == 2 * kier && (kier_kol == 2 || kier_kol == -2))  // Bicie, o 2 po skosie, w dobrym kierunku, a posrodku musi stac przeciwnik
            {
                wier_po_sr = (zwier + dwier) / 2;
                kol_po_sr = (zkol + dkol) / 2;


                if(war[wier_po_sr][kol_po_sr] == nie_gracz)
                {
                   
                    ruch_bicia(war, gracz, nie_gracz, wier_po_sr, kol_po_sr, zwier, zkol, dwier, dkol);
                    system("cls");
                    war_plansza(war);
                    while(pion_ma_bicie(war, gracz, nie_gracz, dwier, dkol)) // Petla ponownego bicia
                    {
                        zwier = dwier;
                        zkol = dkol;

                        cout << "Podaj pole docelowe: ";
                        cin >> d; czysc();
                        bool OKd = pole_na_tab(d, dwier, dkol);
                        kier_weir = dwier - zwier;
                        kier_kol = dkol - zkol;
                        wier_po_sr = (zwier + dwier) / 2;
                        kol_po_sr = (zkol + dkol) / 2;

                        if(!OKd)
                        {
                        cout << "Niepoprawny foramt ruchu, sprobuj ponownie." << endl << endl;
                        continue;
                        }
                        if(war[dwier][dkol] != '*')
                        {
                            cout << "Niepoprawny ruch, sprobuj ponownie." << endl << endl;
                            continue;
                        }
                        if(kier_weir == 2 * kier && (kier_kol == 2 || kier_kol == -2))
                        {
                            if(war[wier_po_sr][kol_po_sr] == nie_gracz)
                            {
                            ruch_bicia(war, gracz, nie_gracz, wier_po_sr, kol_po_sr, zwier, zkol, dwier, dkol);
                            system("cls");
                            war_plansza(war);
                            }
                            else
                            {
                                cout << "Nie ma tam przeciwnika do zbicia." << endl << endl;
                                continue;
                            }
                        }
                        else
                        {
                            cout << "Niepoprawny ruch, sprobuj ponownie." << endl << endl;
                            continue;
                        }
                      
                        
                    }
                    dobry_ruch = true;
                }
                else
                {
                    cout << "Nie ma tam przeciwnika do zbicia." << endl << endl;
                    continue;
                }
            }
                else
                {
                    cout << "Niepoprawny ruch po skosie." << endl << endl;
                    continue;
                }
            
        }
        if(gracz == 'O') gracz = '@';
        else gracz = 'O';
        system("cls");
        war_plansza(war);
    }
    czysc();
    pauza();
}




