

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

/*
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
*/

void war_plansza(char war[8][8])
{
    int pw = ((szer_cmd() - 30) / 2) - 2;
    int kw = ((szer_cmd() - 30) / 2) - 1;

    cout << endl
         << endl;
    cout << setw(kw + 30) << "a   b   c   d   e   f   g   h" << endl;
    cout << setw(kw + 32) << "+---+---+---+---+---+---+---+---+" << endl;

    cout << setw(pw) << "1 " << "|" << " " << war[0][0] << " | " << war[0][1] << " | " << war[0][2] << " | " << war[0][3]
         << " | " << war[0][4] << " | " << war[0][5] << " | " << war[0][6] << " | " << war[0][7] << " " << "|" << " 1" << endl;

    cout << setw(kw) << "|" << "---+---+---+---+---+---+---+---" << "|" << endl;

    cout << setw(pw) << "2 " << "|" << " " << war[1][0] << " | " << war[1][1] << " | " << war[1][2] << " | " << war[1][3]
         << " | " << war[1][4] << " | " << war[1][5] << " | " << war[1][6] << " | " << war[1][7] << " " << "|" << " 2" << endl;

    cout << setw(kw) << "|" << "---+---+---+---+---+---+---+---" << "|" << endl;

    cout << setw(pw) << "3 " << "|" << " " << war[2][0] << " | " << war[2][1] << " | " << war[2][2] << " | " << war[2][3]
         << " | " << war[2][4] << " | " << war[2][5] << " | " << war[2][6] << " | " << war[2][7] << " " << "|" << " 3" << endl;

    cout << setw(kw) << "|" << "---+---+---+---+---+---+---+---" << "|" << endl;

    cout << setw(pw) << "4 " << "|" << " " << war[3][0] << " | " << war[3][1] << " | " << war[3][2] << " | " << war[3][3]
         << " | " << war[3][4] << " | " << war[3][5] << " | " << war[3][6] << " | " << war[3][7] << " " << "|" << " 4" << endl;

    cout << setw(kw) << "|" << "---+---+---+---+---+---+---+---" << "|" << endl;

    cout << setw(pw) << "5 " << "|" << " " << war[4][0] << " | " << war[4][1] << " | " << war[4][2] << " | " << war[4][3]
         << " | " << war[4][4] << " | " << war[4][5] << " | " << war[4][6] << " | " << war[4][7] << " " << "|" << " 5" << endl;

    cout << setw(kw) << "|" << "---+---+---+---+---+---+---+---" << "|" << endl;

    cout << setw(pw) << "6 " << "|" << " " << war[5][0] << " | " << war[5][1] << " | " << war[5][2] << " | " << war[5][3]
         << " | " << war[5][4] << " | " << war[5][5] << " | " << war[5][6] << " | " << war[5][7] << " " << "|" << " 6" << endl;

    cout << setw(kw) << "|" << "---+---+---+---+---+---+---+---" << "|" << endl;

    cout << setw(pw) << "7 " << "|" << " " << war[6][0] << " | " << war[6][1] << " | " << war[6][2] << " | " << war[6][3]
         << " | " << war[6][4] << " | " << war[6][5] << " | " << war[6][6] << " | " << war[6][7] << " " << "|" << " 7" << endl;

    cout << setw(kw) << "|" << "---+---+---+---+---+---+---+---" << "|" << endl;

    cout << setw(pw) << "8 " << "|" << " " << war[7][0] << " | " << war[7][1] << " | " << war[7][2] << " | " << war[7][3]
         << " | " << war[7][4] << " | " << war[7][5] << " | " << war[7][6] << " | " << war[7][7] << " " << "|" << " 8" << endl;

    cout << setw(kw + 32) << "+---+---+---+---+---+---+---+---+" << endl;
    cout << setw(kw + 30) << "a   b   c   d   e   f   g   h" << endl;
}

//===================================================================================================================================================================

void war_svg(char war[8][8], bool war_ods, bool war_graf)
{
    if (war_graf == true)
    {

        ofstream plik("warcaby.svg");
        if (!plik.is_open())
        {
            cout << "Blad otwarcia pliku" << endl;
            return;
        }

        plik << "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 1000 1000\" "
                "preserveAspectRatio=\"xMidYMid meet\" "
                "style=\"display:block; width:100vw; height:100vh; background:#000000; overflow:hidden;\">\n";

        plik << "<rect x=\"0\" y=\"0\" width=\"100%\" height=\"100%\" fill=\"#000000\" />\n";

        plik << "<rect x=\"65\" y=\"65\" width=\"870\" height=\"870\" fill=\"#ffffff\" />\n";
        plik << "<rect x=\"67.5\" y=\"67.5\" width=\"865\" height=\"865\" fill=\"#000000\" />\n";
        plik << "<rect x=\"117.5\" y=\"117.5\" width=\"765\" height=\"765\" fill=\"#ffffff\" />\n";
        plik << "<rect x=\"120\" y=\"120\" width=\"760\" height=\"760\" fill=\"#000000\" />\n";

        int R_pola = 87;

        int polaX[8] = {150, 238, 326, 414, 502, 590, 678, 766};
        int polaY[8] = {150, 238, 326, 414, 502, 590, 678, 766};

        plik << "<rect x=\"150\" y=\"150\" width=\"703\" height=\"703\" fill=\"none\" stroke=\"#ddd8d8ff\" stroke-width=\"3\" />\n";

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                string kolor;
                if ((i + j) % 2 == 0)
                {
                    kolor = "#ddd8d8ff";
                }
                else
                {
                    kolor = "#181717ff";
                }
                plik << "<rect x=\"" << polaX[j] << "\" y=\"" << polaY[i]
                     << "\" width=\"" << R_pola << "\" height=\"" << R_pola
                     << "\" fill=\"" << kolor << "\" />\n";
            }
        }

        double gora = 92.5;
        double dol = 907.5;
        double lewo = 92.5;
        double prawo = 907.5;

        plik << "<g font-family=\"Arial\" font-size=\"30\" fill=\"#ffffff\" "
                "text-anchor=\"middle\" dominant-baseline=\"middle\">\n";

        const char litery[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

        for (int j = 0; j < 8; j++)
        {
            int cx = polaX[j] + R_pola / 2;
            plik << "<text x=\"" << cx << "\" y=\"" << gora << "\">" << litery[j] << "</text>\n";
            plik << "<text x=\"" << cx << "\" y=\"" << dol << "\">" << litery[j] << "</text>\n";
        }

        for (int i = 0; i < 8; i++)
        {
            int cy = polaY[i] + R_pola / 2;
            plik << "<text x=\"" << lewo << "\" y=\"" << cy << "\">" << (i + 1) << "</text>\n";
            plik << "<text x=\"" << prawo << "\" y=\"" << cy << "\">" << (i + 1) << "</text>\n";
        }
        //---------------------------------------------------------------------------------------------------------------------------------------------------------------

        int r_krazka = R_pola * 0.45;
        int r_l1_krazka = R_pola * 0.35;
        int r_l2_krazka = R_pola * 0.20;

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (war[i][j] != 'O' && war[i][j] != '@' && war[i][j] != '%' && war[i][j] != '&')
                    continue;

                int cx = polaX[j] + R_pola / 2;
                int cy = polaY[i] + R_pola / 2;

                string k_pionka;
                string k_lini;

                if (war[i][j] == 'O' || war[i][j] == '%')
                {
                    k_pionka = "#9e8259ff";
                    k_lini = "#806948ff";
                }
                else if (war[i][j] == '@' || war[i][j] == '&')
                {
                    k_pionka = "#3f3629ff";
                    k_lini = "#2e281eff";
                }

                if (war[i][j] == 'O' || war[i][j] == '@')
                {
                    plik << "<circle cx=\"" << cx << "\" cy=\"" << cy
                         << "\" r=\"" << r_krazka << "\" fill=\"" << k_pionka << "\" />\n";

                    plik << "<circle cx=\"" << cx << "\" cy=\"" << cy
                         << "\" r=\"" << r_l1_krazka
                         << "\" fill=\"none\" stroke=\"" << k_lini << "\" stroke-width=\"4\" />\n";

                    plik << "<circle cx=\"" << cx << "\" cy=\"" << cy
                         << "\" r=\"" << r_l2_krazka
                         << "\" fill=\"none\" stroke=\"" << k_lini << "\" stroke-width=\"4\" />\n";
                }

                else if (war[i][j] == '%' || war[i][j] == '&')
                {
                    plik << "<circle cx=\"" << cx << "\" cy=\"" << cy
                         << "\" r=\"" << r_krazka << "\" fill=\"" << k_pionka << "\" />\n";

                    plik << "<circle cx=\"" << cx << "\" cy=\"" << cy
                         << "\" r=\"" << r_l1_krazka
                         << "\" fill=\"none\" stroke=\"" << k_lini << "\" stroke-width=\"4\" />\n";

                    // korona
                    double kor_x = cx - (r_krazka * 0.95) / 2.0;
                    double kor_y = cy - (r_krazka * 0.5) / 4.0;

                    // podstawa
                    plik << "<rect x=\"" << kor_x << "\" y=\"" << kor_y + 12
                         << "\" width=\"" << (r_krazka * 0.95) << "\" height=\"" << (r_krazka * 0.5) - 12
                         << "\" fill=\"" << k_lini << "\" />\n";

                    // W
                    plik << "<text x=\"" << cx << "\" y=\"" << (kor_y + (r_krazka * 0.5) / 2.0)
                         << "\" font-family=\"Arial\" font-size=\"" << (r_krazka)
                         << "\" font-weight=\"700\" fill=\"" << k_lini
                         << "\" text-anchor=\"middle\" dominant-baseline=\"middle\">W</text>\n";

                    // boki
                    plik << "<line x1=\"" << kor_x - 1 << "\" y1=\"" << kor_y - 9
                         << "\" x2=\"" << kor_x << "\" y2=\"" << (kor_y + (r_krazka * 0.5))
                         << "\" stroke=\"" << k_lini << "\" stroke-width=\"5\" />\n";

                    plik << "<line x1=\"" << (kor_x + (r_krazka * 0.95) + 1) << "\" y1=\"" << kor_y - 9
                         << "\" x2=\"" << (kor_x + (r_krazka * 0.95)) << "\" y2=\"" << (kor_y + (r_krazka * 0.5))
                         << "\" stroke=\"" << k_lini << "\" stroke-width=\"5\" />\n";
                }
            }
        }

        plik << "</g>\n";
        plik << "</svg>\n";
        plik.close();

        if (war_ods)
        {
            string cmd = "start warcaby.svg";
            system(cmd.c_str());
        }
    }
}

//===================================================================================================================================================================

void ustaw_war_plansz_0(char war[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 0)
            {
                war[i][j] = ' ';
            }
            else
            {
                war[i][j] = '*';
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 1)
                war[i][j] = '@';
        }
    }

    for (int i = 5; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 1)
                war[i][j] = 'O';
        }
    }
}

//===================================================================================================================================================================

bool pole_na_tab(std::string &x, int &wier, int &kol)
{
    if (x.size() != 2)
        return false;
    char lit = tolower(x[0]);
    char cyf = x[1];

    if (lit < 'a' || lit > 'h')
        return false;
    if (cyf < '1' || cyf > '8')
        return false;
    wier = cyf - '1';
    kol = lit - 'a';
    return true;
}

//===================================================================================================================================================================

bool ruch_bicia(char war[8][8], int wier_po_sr, int kol_po_sr, int zwier, int zkol, int dwier, int dkol)
{
    char fig = war[zwier][zkol];
    war[wier_po_sr][kol_po_sr] = '*';
    war[zwier][zkol] = '*';
    war[dwier][dkol] = fig;
    return true;
}

//===================================================================================================================================================================

bool czy_musi_bic(char war[8][8], char gracz, char nie_gracz)
{

    char nie_damka;
    if (nie_gracz == '@')
        nie_damka = '&';
    else
        nie_damka = '%';

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {

            if (gracz == 'O')
            {
                if (war[i][j] == 'O') // bicie do gory
                {

                    if (i - 2 >= 0 && j - 2 >= 0)
                        if ((war[i - 1][j - 1] == nie_gracz || war[i - 1][j - 1] == nie_damka) && war[i - 2][j - 2] == '*')
                            return true;

                    if (i - 2 >= 0 && j + 2 <= 7)
                        if ((war[i - 1][j + 1] == nie_gracz || war[i - 1][j + 1] == nie_damka) && war[i - 2][j + 2] == '*')
                            return true;
                }
                else if (war[i][j] == '%') // damka bije w 4 kierunkach
                {

                    if (i - 2 >= 0 && j - 2 >= 0)
                        if ((war[i - 1][j - 1] == nie_gracz || war[i - 1][j - 1] == nie_damka) && war[i - 2][j - 2] == '*')
                            return true;

                    if (i - 2 >= 0 && j + 2 <= 7)
                        if ((war[i - 1][j + 1] == nie_gracz || war[i - 1][j + 1] == nie_damka) && war[i - 2][j + 2] == '*')
                            return true;

                    if (i + 2 <= 7 && j - 2 >= 0)
                        if ((war[i + 1][j - 1] == nie_gracz || war[i + 1][j - 1] == nie_damka) && war[i + 2][j - 2] == '*')
                            return true;

                    if (i + 2 <= 7 && j + 2 <= 7)
                        if ((war[i + 1][j + 1] == nie_gracz || war[i + 1][j + 1] == nie_damka) && war[i + 2][j + 2] == '*')
                            return true;
                }
            }

            if (gracz == '@')
            {
                if (war[i][j] == '@') // bicie w dol
                {

                    if (i + 2 <= 7 && j - 2 >= 0)
                        if ((war[i + 1][j - 1] == nie_gracz || war[i + 1][j - 1] == nie_damka) && war[i + 2][j - 2] == '*')
                            return true;

                    if (i + 2 <= 7 && j + 2 <= 7)
                        if ((war[i + 1][j + 1] == nie_gracz || war[i + 1][j + 1] == nie_damka) && war[i + 2][j + 2] == '*')
                            return true;
                }
                else if (war[i][j] == '&') // damka bije w 4 kierunkach
                {

                    if (i - 2 >= 0 && j - 2 >= 0)
                        if ((war[i - 1][j - 1] == nie_gracz || war[i - 1][j - 1] == nie_damka) && war[i - 2][j - 2] == '*')
                            return true;

                    if (i - 2 >= 0 && j + 2 <= 7)
                        if ((war[i - 1][j + 1] == nie_gracz || war[i - 1][j + 1] == nie_damka) && war[i - 2][j + 2] == '*')
                            return true;

                    if (i + 2 <= 7 && j - 2 >= 0)
                        if ((war[i + 1][j - 1] == nie_gracz || war[i + 1][j - 1] == nie_damka) && war[i + 2][j - 2] == '*')
                            return true;

                    if (i + 2 <= 7 && j + 2 <= 7)
                        if ((war[i + 1][j + 1] == nie_gracz || war[i + 1][j + 1] == nie_damka) && war[i + 2][j + 2] == '*')
                            return true;
                }
            }
        }
    }
    return false;
}

//===================================================================================================================================================================

bool pion_ma_bicie(char war[8][8], int dwier, int dkol)
{

    char fig = war[dwier][dkol];

    if (fig == 'O')
    {
        if (dwier - 2 >= 0 && dkol - 2 >= 0)
        {
            if ((war[dwier - 1][dkol - 1] == '@' || war[dwier - 1][dkol - 1] == '&') &&
                (war[dwier - 2][dkol - 2] == '*'))
            {
                return true;
            }
        }
        if (dwier - 2 >= 0 && dkol + 2 <= 7)
        {
            if ((war[dwier - 1][dkol + 1] == '@' || war[dwier - 1][dkol + 1] == '&') &&
                (war[dwier - 2][dkol + 2] == '*'))
            {
                return true;
            }
        }
        return false;
    }

    if (fig == '@')
    {
        if (dwier + 2 <= 7 && dkol - 2 >= 0)
        {
            if ((war[dwier + 1][dkol - 1] == 'O' || war[dwier + 1][dkol - 1] == '%') &&
                (war[dwier + 2][dkol - 2] == '*'))
            {
                return true;
            }
        }
        if (dwier + 2 <= 7 && dkol + 2 <= 7)
        {
            if ((war[dwier + 1][dkol + 1] == 'O' || war[dwier + 1][dkol + 1] == '%') &&
                (war[dwier + 2][dkol + 2] == '*'))
            {
                return true;
            }
        }
        return false;
    }

    if (fig == '%')
    {
        // gora lewo
        if (dwier - 2 >= 0 && dkol - 2 >= 0)
        {
            if ((war[dwier - 1][dkol - 1] == '@' || war[dwier - 1][dkol - 1] == '&') &&
                (war[dwier - 2][dkol - 2] == '*'))
            {
                return true;
            }
        }
        // gora prawo
        if (dwier - 2 >= 0 && dkol + 2 <= 7)
        {
            if ((war[dwier - 1][dkol + 1] == '@' || war[dwier - 1][dkol + 1] == '&') &&
                (war[dwier - 2][dkol + 2] == '*'))
            {
                return true;
            }
        }
        // dol lewo
        if (dwier + 2 <= 7 && dkol - 2 >= 0)
        {
            if ((war[dwier + 1][dkol - 1] == '@' || war[dwier + 1][dkol - 1] == '&') &&
                (war[dwier + 2][dkol - 2] == '*'))
            {
                return true;
            }
        }
        // dol prawo
        if (dwier + 2 <= 7 && dkol + 2 <= 7)
        {
            if ((war[dwier + 1][dkol + 1] == '@' || war[dwier + 1][dkol + 1] == '&') &&
                (war[dwier + 2][dkol + 2] == '*'))
            {
                return true;
            }
        }
        return false;
    }

    if (fig == '&')
    {
        // gora lewo
        if (dwier - 2 >= 0 && dkol - 2 >= 0)
        {
            if ((war[dwier - 1][dkol - 1] == 'O' || war[dwier - 1][dkol - 1] == '%') &&
                (war[dwier - 2][dkol - 2] == '*'))
            {
                return true;
            }
        }
        // gora prawo
        if (dwier - 2 >= 0 && dkol + 2 <= 7)
        {
            if ((war[dwier - 1][dkol + 1] == 'O' || war[dwier - 1][dkol + 1] == '%') &&
                (war[dwier - 2][dkol + 2] == '*'))
            {
                return true;
            }
        }
        // dol lewo
        if (dwier + 2 <= 7 && dkol - 2 >= 0)
        {
            if ((war[dwier + 1][dkol - 1] == 'O' || war[dwier + 1][dkol - 1] == '%') &&
                (war[dwier + 2][dkol - 2] == '*'))
            {
                return true;
            }
        }
        // dol prawo
        if (dwier + 2 <= 7 && dkol + 2 <= 7)
        {
            if ((war[dwier + 1][dkol + 1] == 'O' || war[dwier + 1][dkol + 1] == '%') &&
                (war[dwier + 2][dkol + 2] == '*'))
            {
                return true;
            }
        }
        return false;
    }

    return false;
}

//===================================================================================================================================================================

bool bez_piona(char war[8][8])
{
    int czarne = 0;
    int biale = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (war[i][j] == 'O' || war[i][j] == '%')
            {
                biale++;
            }
            else if (war[i][j] == '@' || war[i][j] == '&')
            {
                czarne++;
            }
        }
    }
    if (biale == 0) // warunek wygranej
    {
        system("cls");
        war_plansza(war);
        cout << endl
             << endl;
        wys("$$$ GRACZ @ WYGRYWA $$$");
        cout << endl;
        wys("Zbito wszystkie pionki gracza O");
        return true;
    }
    else if (czarne == 0)
    {
        system("cls");
        war_plansza(war);
        cout << endl
             << endl;
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

//===================================================================================================================================================================

bool czy_jest_ruch(char war[8][8], char gracz, char nie_gracz)
{
    if (czy_musi_bic(war, gracz, nie_gracz))
    {
        return true;
    }

    char damka_gracza;
    if (gracz == 'O')
        damka_gracza = '%';
    else
        damka_gracza = '&';

    int l_ruch = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {

            if (war[i][j] != gracz && war[i][j] != damka_gracza)
                continue;

            if (war[i][j] == gracz) // zwykly pionek
            {
                if (gracz == 'O')
                {
                    if (i - 1 >= 0 && j - 1 >= 0 && war[i - 1][j - 1] == '*')
                        l_ruch++;
                    if (i - 1 >= 0 && j + 1 <= 7 && war[i - 1][j + 1] == '*')
                        l_ruch++;
                }
                else // '@'
                {
                    if (i + 1 <= 7 && j - 1 >= 0 && war[i + 1][j - 1] == '*')
                        l_ruch++;
                    if (i + 1 <= 7 && j + 1 <= 7 && war[i + 1][j + 1] == '*')
                        l_ruch++;
                }
            }
            else // damka
            {
                if (i - 1 >= 0 && j - 1 >= 0 && war[i - 1][j - 1] == '*')
                    l_ruch++;
                if (i - 1 >= 0 && j + 1 <= 7 && war[i - 1][j + 1] == '*')
                    l_ruch++;
                if (i + 1 <= 7 && j - 1 >= 0 && war[i + 1][j - 1] == '*')
                    l_ruch++;
                if (i + 1 <= 7 && j + 1 <= 7 && war[i + 1][j + 1] == '*')
                    l_ruch++;
            }
        }
    }

    if (l_ruch != 0)
        return true;

    if (gracz == 'O') // warunek wygranej
    {
        system("cls");
        war_plansza(war);
        cout << endl
             << endl;
        wys("$$$ GRACZ @ WYGRYWA $$$");
        cout << endl;
        wys("Gracz O nie moze wykonac ruchu");
        cout << endl
             << endl;
        return false;
    }
    else
    {
        system("cls");
        war_plansza(war);
        cout << endl
             << endl;
        wys("$$$ GRACZ O WYGRYWA $$$");
        cout << endl;
        wys("Gracz @ nie moze wykonac ruchu");
        cout << endl;
        return false;
    }
}

//===================================================================================================================================================================

void menu_warcaby(bool &war_ods, bool &war_graf)
{
    while (true)
    {
        string tryb;
        wys("\\\\\\\\\\\\\\\\ WARCABY ////////");
        cout << endl;
        wys("- (1) Nowa Gra -");
        wys("- (2) Wczytaj Zapis -");
        wys("- (3) Ustawienia -");
        wys("- (H) Instrukcja do gry -");
        wys("- (X) Powrot do MENU -");
        cout << "Wybierz opcje: ";
        getline(cin >> ws, tryb);
        if (tryb.size() == 1 && (tryb[0] == '1' || tryb[0] == '2' || tryb[0] == '3' || tryb[0] == 'H' || tryb[0] == 'h' || tryb[0] == 'X' || tryb[0] == 'x'))
        {

            switch (tryb[0])
            {
            case '1':
                system("cls");
                warcaby(war_ods, war_graf);
                system("cls");
                break;
                ;

            case '2':
                system("cls");
                menu_wczyt(war_ods, war_graf);
                system("cls");
                break;

            case '3':
                system("cls");
                ustawienia(war_ods, war_graf);
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

//===================================================================================================================================================================

void ustawienia(bool &war_ods, bool &war_graf)
{

    while (true)
    {
        string tryb;
        wys("\\\\\\\\\\\\\\\\ WARCABY USTAWIENIA ////////");
        cout << endl;
        wys("- (1) Tryb Graficzny -");
        wys("- (2) Odswierzanie -");
        wys("- (X) Powrot do MENU -");

        cout << "- Tryb Graficzny: ";
        if (war_graf == true)
            cout << "ON" << endl;
        else
            cout << "OFF" << endl;
        cout << "- Odswierzanie: ";
        if (war_ods == true)
            cout << "ON" << endl;
        else
            cout << "OFF" << endl;

        cout << endl;
        cout << "Wybierz opcje: ";
        getline(cin >> ws, tryb);

        if (tryb.size() == 1 && (tryb[0] == '1' || tryb[0] == '2' || tryb[0] == 'X' || tryb[0] == 'x'))
        {

            switch (tryb[0])
            {
            case '1':
            {
                system("cls");
                cout << endl
                     << endl;
                war_graf = pytanie_tak_nie("Czy chcesz grac z reprezentacja graficzna w SVG? (tak/nie)");

                system("cls");
                break;
                ;
            }

            case '2':
                system("cls");
                cout << endl
                     << endl;
                war_ods = pytanie_tak_nie("Czy wlaczyc odswierzanie automatyczne? (tak/nie)");
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

//===================================================================================================================================================================

void damkowanie(char war[8][8], int wier, int kol)
{
    if (war[wier][kol] == 'O' && wier == 0)
        war[wier][kol] = '%';
    if (war[wier][kol] == '@' && wier == 7)
        war[wier][kol] = '&';
}

//===================================================================================================================================================================

void menu_wczyt(bool &war_ods, bool &war_graf)
{
    while (true)
    {
        string tryb;
        wys("\\\\\\\\\\\\\\\\ WCZYTAJ GRE ////////");
        cout << endl;

        bool s1 = slot_zajety(plik_war_slot(1));
        bool s2 = slot_zajety(plik_war_slot(2));
        bool s3 = slot_zajety(plik_war_slot(3));
        bool s4 = slot_zajety(plik_war_slot(4));

        string stan1, stan2, stan3, stan4;

        if (s1)
            stan1 = "zajety";
        else
            stan1 = "pusty";
        if (s2)
            stan2 = "zajety";
        else
            stan2 = "pusty";
        if (s3)
            stan3 = "zajety";
        else
            stan3 = "pusty";
        if (s4)
            stan4 = "zajety";
        else
            stan4 = "pusty";

        wys("- (1) SLOT 1 [" + stan1 + "] -");
        wys("- (2) SLOT 2 [" + stan2 + "] -");
        wys("- (3) SLOT 3 [" + stan3 + "] -");
        wys("- (4) SLOT 4 [" + stan4 + "] -");

        wys("- (X) Powrot do MENU -");
        cout << "Wybierz opcje: ";
        getline(cin >> ws, tryb);
        if (tryb.size() == 1 && (tryb[0] == '1' || tryb[0] == '2' || tryb[0] == '3' || tryb[0] == '4' || tryb[0] == 'X' || tryb[0] == 'x'))
        {

            switch (tryb[0])
            {
            case '1':
            {
                system("cls");

                char war[8][8];
                char gracz = 'O';

                bool ods_z_p = war_ods;
                bool graf_z_p = war_graf;

                bool ok = wczyt_gry(plik_war_slot(1), war, gracz, ods_z_p, graf_z_p);
                if (!ok)
                {
                    cout << "Slot 1 jest pusty albo zapis jest uszkodzony.\n";
                    pauza();
                    system("cls");
                    break;
                }

                war_ods = ods_z_p;
                war_graf = graf_z_p;

                warcaby_wczytane(war, gracz, war_ods, war_graf);
                system("cls");
                break;
            }

            case '2':
            {
                system("cls");

                char war[8][8];
                char gracz = 'O';

                bool ods_z_p = war_ods;
                bool graf_z_p = war_graf;

                bool ok = wczyt_gry(plik_war_slot(2), war, gracz, ods_z_p, graf_z_p);
                if (!ok)
                {
                    cout << "Slot 2 jest pusty albo zapis jest uszkodzony.\n";
                    pauza();
                    system("cls");
                    break;
                }

                war_ods = ods_z_p;
                war_graf = graf_z_p;

                warcaby_wczytane(war, gracz, war_ods, war_graf);
                system("cls");
                break;
            }

            case '3':
            {
                system("cls");

                char war[8][8];
                char gracz = 'O';

                bool ods_z_p = war_ods;
                bool graf_z_p = war_graf;

                bool ok = wczyt_gry(plik_war_slot(3), war, gracz, ods_z_p, graf_z_p);
                if (!ok)
                {
                    cout << "Slot 3 jest pusty albo zapis jest uszkodzony.\n";
                    pauza();
                    system("cls");
                    break;
                }

                war_ods = ods_z_p;
                war_graf = graf_z_p;

                warcaby_wczytane(war, gracz, war_ods, war_graf);
                system("cls");
                break;
            }

            case '4':
            {
                system("cls");

                char war[8][8];
                char gracz = 'O';

                bool ods_z_p = war_ods;
                bool graf_z_p = war_graf;

                bool ok = wczyt_gry(plik_war_slot(4), war, gracz, ods_z_p, graf_z_p);
                if (!ok)
                {
                    cout << "Slot 4 jest pusty albo zapis jest uszkodzony.\n";
                    pauza();
                    system("cls");
                    break;
                }

                war_ods = ods_z_p;
                war_graf = graf_z_p;

                warcaby_wczytane(war, gracz, war_ods, war_graf);
                system("cls");
                break;
            }

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

//===================================================================================================================================================================

bool menu_zapisu(char war[8][8], char gracz, bool war_ods, bool war_graf)
{
    while (true)
    {
        string tryb;
        wys("\\\\\\\\\\\\\\\\ ZAPIS GRY ////////");
        cout << endl;

        bool s1 = slot_zajety(plik_war_slot(1));
        bool s2 = slot_zajety(plik_war_slot(2));
        bool s3 = slot_zajety(plik_war_slot(3));
        bool s4 = slot_zajety(plik_war_slot(4));

        string stan1, stan2, stan3, stan4;

        if (s1)
            stan1 = "zajety";
        else
            stan1 = "pusty";
        if (s2)
            stan2 = "zajety";
        else
            stan2 = "pusty";
        if (s3)
            stan3 = "zajety";
        else
            stan3 = "pusty";
        if (s4)
            stan4 = "zajety";
        else
            stan4 = "pusty";

        wys("- (1) SLOT 1 [" + stan1 + "] -");
        wys("- (2) SLOT 2 [" + stan2 + "] -");
        wys("- (3) SLOT 3 [" + stan3 + "] -");
        wys("- (4) SLOT 4 [" + stan4 + "] -");
        wys("- (P) Powrot do gry -");
        wys("- (X) Powrot do MENU -");
        cout << "Wybierz opcje: ";
        getline(cin >> ws, tryb);
        if (tryb.size() == 1 && (tryb[0] == '1' || tryb[0] == '2' || tryb[0] == '3' ||
                                 tryb[0] == '4' || tryb[0] == 'p' || tryb[0] == 'P' || tryb[0] == 'X' || tryb[0] == 'x'))
        {

            switch (tryb[0])
            {
            case '1':
            {
                system("cls");

                if (s1)
                {
                    bool nadpisz = pytanie_tak_nie("Slot 1 jest zajety. Nadpisac? (tak/nie)");
                    if (!nadpisz)
                    {
                        system("cls");
                        break;
                    }
                }

                bool zapisane = zapis_gry(plik_war_slot(1), war, gracz, war_ods, war_graf);
                if (zapisane)
                    wys("Zapisano do SLOT 1");
                else
                    wys("Blad zapisu do pliku");

                pauza();
                system("cls");
                break;
            }

            case '2':
            {
                system("cls");

                if (s2)
                {
                    bool nadpisz = pytanie_tak_nie("Slot 2 jest zajety. Nadpisac? (tak/nie)");
                    if (!nadpisz)
                    {
                        system("cls");
                        break;
                    }
                }

                bool zapisane = zapis_gry(plik_war_slot(2), war, gracz, war_ods, war_graf);
                if (zapisane)
                    wys("Zapisano do SLOT 2");
                else
                    wys("Blad zapisu do pliku");

                pauza();
                system("cls");
                break;
            }

            case '3':
            {
                system("cls");

                if (s3)
                {
                    bool nadpisz = pytanie_tak_nie("Slot 3 jest zajety. Nadpisac? (tak/nie)");
                    if (!nadpisz)
                    {
                        system("cls");
                        break;
                    }
                }

                bool zapisane = zapis_gry(plik_war_slot(3), war, gracz, war_ods, war_graf);
                if (zapisane)
                    wys("Zapisano do SLOT 3");
                else
                    wys("Blad zapisu do pliku");

                pauza();
                system("cls");
                break;
            }

            case '4':
            {
                system("cls");

                if (s4)
                {
                    bool nadpisz = pytanie_tak_nie("Slot 4 jest zajety. Nadpisac? (tak/nie)");
                    if (!nadpisz)
                    {
                        system("cls");
                        break;
                    }
                }

                bool zapisane = zapis_gry(plik_war_slot(4), war, gracz, war_ods, war_graf);
                if (zapisane)
                    wys("Zapisano do SLOT 4");
                else
                    wys("Blad zapisu do pliku");

                pauza();
                system("cls");
                break;
            }

            case 'P':
            case 'p':
                return false;

            case 'X':
            case 'x':
                return true;

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
    return false;
}

//===================================================================================================================================================================

bool zapis_gry(const string &zapis, char war[8][8], char gracz, bool war_ods, bool war_graf)
{
    ofstream plik(zapis.c_str());
    if (!plik.is_open())
    {
        return false;
    }

    plik << "gracz=" << gracz << "\n";

    int p_graf = 0;
    int p_ods = 0;
    if (war_graf)
        p_graf = 1;
    if (war_ods)
        p_ods = 1;

    plik << "graf=" << p_graf << "\n";
    plik << "ods=" << p_ods << "\n";

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char pust = war[i][j];
            if (pust == ' ')
                pust = '.';
            plik << pust;
        }
        plik << "\n";
    }

    return true;
}

//===================================================================================================================================================================

string plik_war_slot(int slot)
{
    if (slot == 1)
        return "war_slot1.txt";
    if (slot == 2)
        return "war_slot2.txt";
    if (slot == 3)
        return "war_slot3.txt";
    if (slot == 4)
        return "war_slot4.txt";
    return "";
}

//===================================================================================================================================================================

void usun_karetke(string &linia)
{
    if (!linia.empty() && linia[linia.size() - 1] == '\r')
    {
        linia.erase(linia.size() - 1);
    }
}

//===================================================================================================================================================================

bool slot_zajety(const string &zapis)
{
    ifstream plik(zapis.c_str());
    if (!plik.is_open())
    {
        return false;
    }

    string l1, l2, l3;

    if (!getline(plik, l1))
        return false;
    if (!getline(plik, l2))
        return false;
    if (!getline(plik, l3))
        return false;

    usun_karetke(l1);
    usun_karetke(l2);
    usun_karetke(l3);

    if (l1.size() < 7)
        return false;
    if (l1.substr(0, 6) != "gracz=")
        return false;
    if (l1[6] != 'O' && l1[6] != '@')
        return false;

    if (l2.size() < 6)
        return false;
    if (l2.substr(0, 5) != "graf=")
        return false;
    if (l2[5] != '0' && l2[5] != '1')
        return false;

    if (l3.size() < 5)
        return false;
    if (l3.substr(0, 4) != "ods=")
        return false;
    if (l3[4] != '0' && l3[4] != '1')
        return false;

    for (int i = 0; i < 8; i++)
    {
        string p_wier;
        if (!getline(plik, p_wier))
            return false;
        usun_karetke(p_wier);

        if (p_wier.size() != 8)
            return false;

        for (int j = 0; j < 8; j++)
        {
            char c = p_wier[j];

            if (c != '*' && c != '.' && c != 'O' && c != '@' && c != '%' && c != '&')
            {
                return false;
            }
        }
    }

    return true;
}

//===================================================================================================================================================================

bool wczyt_gry(const string &zapis, char war[8][8], char &gracz, bool &war_ods, bool &war_graf)
{
    ifstream plik(zapis.c_str());

    if (!plik.is_open())
    {
        return false;
    }

    string l1;
    string l2;
    string l3;

    if (!getline(plik, l1))
        return false;
    if (!getline(plik, l2))
        return false;
    if (!getline(plik, l3))
        return false;

    // ussuniecie karetki na wszelki wypadek
    usun_karetke(l1);
    usun_karetke(l2);
    usun_karetke(l3);

    // wyluskanie ifnormacji jakiego gracza teraz jest kolej
    if (l1.size() < 7)
        return false;
    if (l1.substr(0, 6) != "gracz=")
        return false;

    char czy_gracz = l1[6];
    if (czy_gracz != 'O' && czy_gracz != '@')
        return false;
    gracz = czy_gracz;

    // ustawienia: wizualiacja graficzna
    if (l2.size() < 6)
        return false;
    if (l2.substr(0, 5) != "graf=")
        return false;

    char czy_graf = l2[5];
    if (czy_graf == '0')
        war_graf = false;
    else if (czy_graf == '1')
        war_graf = true;
    else
        return false;

    // ustawienia: automatyczne odswierzanie
    if (l3.size() < 5)
        return false;
    if (l3.substr(0, 4) != "ods=")
        return false;

    char czy_ods = l3[4];
    if (czy_ods == '0')
        war_ods = false;
    else if (czy_ods == '1')
        war_ods = true;
    else
        return false;

    // wczytanie planszy
    for (int i = 0; i < 8; i++)
    {
        string p_wier;
        if (!getline(plik, p_wier))
            return false;

        usun_karetke(p_wier);

        if (p_wier.size() != 8)
            return false;

        for (int j = 0; j < 8; j++)
        {
            char komurka = p_wier[j];
            if (komurka == '.')
                komurka = ' ';

            if (komurka != '*' && komurka != ' ' && komurka != 'O' && komurka != '@' && komurka != '%' && komurka != '&')
            {
                return false;
            }

            war[i][j] = komurka;
        }
    }

    return true;
}

//===================================================================================================================================================================

void warcaby(bool &war_ods, bool &war_graf)
{
    char war[8][8];
    ustaw_war_plansz_0(war);

    char gracz = 'O';

    warcaby_wczytane(war, gracz, war_ods, war_graf);
}

//===================================================================================================================================================================

void warcaby_wczytane(char war[8][8], char gracz, bool &war_ods, bool &war_graf)
{
    bool koniec = false;

    war_svg(war, war_ods, war_graf);

    if (war_ods == false && war_graf == true)
    {
        string cmd = "start warcaby.svg";
        system(cmd.c_str());
        wys("Przyklej okno konsoli do lewej strony ekranu, a okno z graficzna reprezentacja do prawej strony ekranu.");
        wys("Jesli jestes gotowy");
        pauza();
        system("cls");
    }
    else if (war_ods == true && war_graf == true)
    {
        wys("Przyklej okno konsoli do lewej strony ekranu, a okno z graficzna reprezentacja do prawej strony ekranu.");
        wys("Jesli jestes gotowy");
        pauza();
        system("cls");
    }

    war_plansza(war);

    while (!koniec)
    {
        char nie_gracz;
        if (gracz == 'O')
            nie_gracz = '@';
        else
            nie_gracz = 'O';

        if (bez_piona(war)) // Sprawdzenie czy ktorys gracz wygral
        {
            koniec = true;
            break;
        }
        if (!czy_jest_ruch(war, gracz, nie_gracz))
        {
            koniec = true;
            break;
        }

        string z, d;
        bool musi_bic = czy_musi_bic(war, gracz, nie_gracz);

        cout << "Ruch gracza: " << gracz << endl;

        bool dobry_ruch = false;
        while (!dobry_ruch) // walidacja ruchu
        {
            cout << "Podaj pole startowe: ";
            cin >> z;
            czysc();

            if (z.size() == 1 && (z[0] == 'x' || z[0] == 'X'))
            {
                system("cls");
                bool do_menu = menu_zapisu(war, gracz, war_ods, war_graf);
                system("cls");

                if (do_menu)
                    return; // wracamy do menu

                war_plansza(war);
                cout << "Ruch gracza: " << gracz << endl;
                war_svg(war, war_ods, war_graf);
                continue; // wracamy do gry
            }

            cout << "Podaj pole docelowe: ";
            cin >> d;
            czysc();

            if (d.size() == 1 && (d[0] == 'x' || d[0] == 'X'))
            {
                system("cls");
                bool do_menu = menu_zapisu(war, gracz, war_ods, war_graf);
                system("cls");

                if (do_menu)
                    return; // wracamy do menu

                war_plansza(war);
                cout << "Ruch gracza: " << gracz << endl;
                war_svg(war, war_ods, war_graf);
                continue; // wracamy do gry
            }

            int zwier, zkol, dwier, dkol;

            bool OKz = pole_na_tab(z, zwier, zkol);
            bool OKd = pole_na_tab(d, dwier, dkol);

            if (!OKz || !OKd)
            {
                cout << "Niepoprawny foramt ruchu, sprobuj ponownie." << endl
                     << endl;
                continue;
            }

            char S_fig = war[zwier][zkol];

            if (gracz == 'O') // biale
            {
                if (S_fig != 'O' && S_fig != '%')
                {
                    cout << "Pole startowe jest niepoprawne, sprobuj ponownie." << endl
                         << endl;
                    continue;
                }
            }
            else // czarne
            {
                if (S_fig != '@' && S_fig != '&')
                {
                    cout << "Pole startowe jest niepoprawne, sprobuj ponownie." << endl
                         << endl;
                    continue;
                }
            }

            if (war[dwier][dkol] != '*')
            {
                cout << "Pole docelowe jest niepoprawne, sprobuj ponownie." << endl
                     << endl;
                continue;
            }

            int kier_weir = dwier - zwier;
            int kier_kol = dkol - zkol;
            int kier;
            int wier_po_sr;
            int kol_po_sr;

            bool damka = (war[zwier][zkol] == '%' || war[zwier][zkol] == '&');

            if (!damka)
            {
                if (gracz == 'O')
                    kier = -1;
                else
                    kier = 1;
            }

            bool zwykly_ruch = false;

            if (!damka)
            {
                if (kier_weir == kier && (kier_kol == 1 || kier_kol == -1))
                {
                    zwykly_ruch = true;
                }
            }
            else // damka moze gora dol
            {
                if ((kier_weir == 1 || kier_weir == -1) && (kier_kol == 1 || kier_kol == -1))
                {
                    zwykly_ruch = true;
                }
            }

            if (zwykly_ruch)
            {
                if (musi_bic == false)
                {
                    char fig = war[zwier][zkol];
                    war[zwier][zkol] = '*';
                    war[dwier][dkol] = fig;
                    damkowanie(war, dwier, dkol);
                    dobry_ruch = true;
                }
                else
                {
                    cout << "Masz bicie, musisz je wykonac" << endl
                         << endl;
                    continue;
                }
            }

            else if ((!damka && (kier_weir == 2 * kier) && (kier_kol == 2 || kier_kol == -2)) ||
                     (damka && ((kier_weir == 2 || kier_weir == -2) && (kier_kol == 2 || kier_kol == -2))))
            {
                bool warunek_bicia = true;

                wier_po_sr = (zwier + dwier) / 2;
                kol_po_sr = (zkol + dkol) / 2;

                char srodek = war[wier_po_sr][kol_po_sr];
                bool jest_przeciwnik = false;

                if (gracz == 'O')
                {
                    if (srodek == '@' || srodek == '&')
                        jest_przeciwnik = true;
                }
                else
                {
                    if (srodek == 'O' || srodek == '%')
                        jest_przeciwnik = true;
                }

                if (!jest_przeciwnik)
                {
                    cout << "Nie ma tam przeciwnika do zbicia." << endl
                         << endl;
                    continue;
                }

                ruch_bicia(war, wier_po_sr, kol_po_sr, zwier, zkol, dwier, dkol);
                system("cls");
                war_plansza(war);
                war_svg(war, war_ods, war_graf);

                int bwier = dwier;
                int bkol = dkol;

                bool koniec_bicia = false;
                if (!damka)
                {
                    if (gracz == 'O' && bwier == 0)
                        koniec_bicia = true;
                    if (gracz == '@' && bwier == 7)
                        koniec_bicia = true;
                }

                while (!koniec_bicia && pion_ma_bicie(war, bwier, bkol))
                {
                    // start bicia z aktualnej pozycji pionka
                    zwier = bwier;
                    zkol = bkol;

                    cout << "Podaj pole docelowe: ";
                    cin >> d;
                    czysc();

                    if (d.size() == 1 && (d[0] == 'x' || d[0] == 'X'))
                    {
                        system("cls");
                        bool do_menu = menu_zapisu(war, gracz, war_ods, war_graf);
                        system("cls");

                        if (do_menu)
                            return;

                        war_plansza(war);
                        cout << "Ruch gracza: " << gracz << endl;
                        war_svg(war, war_ods, war_graf);
                        continue;
                    }

                    // docelowe pole na tymczasowej zmiennej
                    int nwier, nkol;
                    bool OKd = pole_na_tab(d, nwier, nkol);
                    if (!OKd)
                    {
                        cout << "Niepoprawny format ruchu, sprobuj ponownie." << endl
                             << endl;
                        continue;
                    }

                    if (war[nwier][nkol] != '*')
                    {
                        cout << "Niepoprawny ruch, sprobuj ponownie." << endl
                             << endl;
                        continue;
                    }

                    kier_weir = nwier - zwier;
                    kier_kol = nkol - zkol;

                    warunek_bicia = false;
                    if (damka)
                    {
                        if ((kier_weir == 2 || kier_weir == -2) && (kier_kol == 2 || kier_kol == -2))
                            warunek_bicia = true;
                    }
                    else
                    {
                        if ((kier_weir == 2 * kier) && (kier_kol == 2 || kier_kol == -2))
                            warunek_bicia = true;
                    }

                    if (!warunek_bicia)
                    {
                        cout << "Niepoprawny ruch, sprobuj ponownie." << endl
                             << endl;
                        continue;
                    }

                    wier_po_sr = (zwier + nwier) / 2;
                    kol_po_sr = (zkol + nkol) / 2;

                    srodek = war[wier_po_sr][kol_po_sr];
                    jest_przeciwnik = false;

                    if (gracz == 'O')
                    {
                        if (srodek == '@' || srodek == '&')
                            jest_przeciwnik = true;
                    }
                    else
                    {
                        if (srodek == 'O' || srodek == '%')
                            jest_przeciwnik = true;
                    }

                    if (!jest_przeciwnik)
                    {
                        cout << "Nie ma tam przeciwnika do zbicia." << endl
                             << endl;
                        continue;
                    }

                    ruch_bicia(war, wier_po_sr, kol_po_sr, zwier, zkol, nwier, nkol);

                    // aktualizujemy pozycji pionka bo bicie juz przeszlo
                    bwier = nwier;
                    bkol = nkol;

                    system("cls");
                    war_plansza(war);
                    war_svg(war, war_ods, war_graf);

                    if (!damka)
                    {
                        if (gracz == 'O' && bwier == 0)
                            koniec_bicia = true;
                        if (gracz == '@' && bwier == 7)
                            koniec_bicia = true;
                    }
                }

                // dopiero po CALEJ serii bic przenosimy zmienne na dwier i dkol
                dwier = bwier;
                dkol = bkol;

                damkowanie(war, dwier, dkol);
                dobry_ruch = true;
            }
            else
            {
                cout << "Niepoprawny ruch, sprobuj ponownie." << endl
                     << endl;
                continue;
            }
        }
        if (gracz == 'O')
            gracz = '@';
        else
            gracz = 'O';
        system("cls");
        war_plansza(war);
        war_svg(war, war_ods, war_graf);
    }
    czysc();
    cout << endl
         << endl;

    if (war_graf)
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
