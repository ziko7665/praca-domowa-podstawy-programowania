#include "funkcje.h"
#include <windows.h>
#include <iostream>

using namespace std;

static int szerokosc_konsoli()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

void wys(const string& tekst)
{
    int szerokosc = szerokosc_konsoli();
    int dlugosc = tekst.length();
    int spacje = (szerokosc - dlugosc) / 2;
    if (spacje < 0) spacje = 0;
    cout << string(spacje, ' ') << tekst << endl;
}
