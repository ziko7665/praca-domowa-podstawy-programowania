

#include "funkcje.h"
#include <algorithm>
#include <windows.h>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <cctype>

int szer_cmd()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

//===================================================================================================================================================================

void wys(const std::string &tekst)
{
    int szerokosc = szer_cmd();
    int dlugosc = tekst.length();
    int spacje = (szerokosc - dlugosc) / 2;
    if (spacje < 0)
        spacje = 0;
    std::cout << std::string(spacje, ' ') << tekst << std::endl;
}

//===================================================================================================================================================================

int losuj_oddo(int min, int max)
{
    return min + rand() % (max - min + 1);
}

//===================================================================================================================================================================

int wczytaj_int(const std::string &komunikat)
{
    int x;
    while (true)
    {
        std::cout << komunikat;
        if (std::cin >> x)
        {
            return x;
        }

        std::cout << "To nie jest liczba, sprobuj jeszcze raz" << std::endl;
        czysc();
    }
}

//===================================================================================================================================================================

void pauza()
{

    wys("Nacisnij Enter, aby kontynuowac");
    std::string linia;
    std::getline(std::cin, linia);
}

//===================================================================================================================================================================

void czysc()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//===================================================================================================================================================================

void utnij_bialy_koniec(std::string &tekst)
{

    while (!tekst.empty() && std ::isspace(tekst.back()))
    {
        tekst.pop_back();
    }
}

//===================================================================================================================================================================

bool pytanie_tak_nie(const std::string pytanie)
{
    std::string tn;
    std::cout << pytanie << std::endl;
    while (true)
    {

        std::getline(std::cin >> std::ws, tn);
        utnij_bialy_koniec(tn);
        for (int i = 0; i < tn.length(); i++)
        {
            tn[i] = std::tolower(tn[i]);
        }
        if (tn == "tak")
        {
            return true;
        }
        else if (tn == "nie")
        {
            return false;
        }
        else
        {
            std::cout << "Wpisz tak/nie: ";
        }
    }
}

//===================================================================================================================================================================

void pomoc_menu()
{
    system("cls");
    while (true)
    {
        std::string tryb;
        wys("\\\\\\\\\\\\\\\\ POMOC ////////");
        wys("- (1) Pod. i Zaw. SVG -");
        wys("- (2) Gra w Kolko i Krzyzyk -");
        wys("- (3) Gra w Warcaby -");
        wys("- (4) Ogolne informacje -");
        wys("- (X) Powrot do MENU -");
        std::cout << "Wybierz opcje: ";
        std::getline(std::cin >> std::ws, tryb);
        if (tryb.size() == 1 && (tryb[0] == '1' || tryb[0] == '2' || tryb[0] == '3' || tryb[0] == '4' || tryb[0] == 'X' || tryb[0] == 'x'))
        {

            switch (tryb[0])
            {
            case '1':
                system("cls");
                pomoc_SVG();
                system("cls");
                break;

            case '2':
                system("cls");
                pomoc_XO();
                system("cls");
                break;

            case '3':
                system("cls");
                pomoc_Warcaby();
                system("cls");
                break;

            case '4':
                system("cls");
                pomoc_ogolna();
                system("cls");
                break;

            case 'X':
            case 'x':
                return;

            default:
                system("cls");
                std::cout << "Nieprawidlowa opcja. Sprobuj ponownie." << std::endl;
                break;
            }
        }
        else
        {
            system("cls");
            std::cout << "Nieprawidlowa opcja. Sprobuj ponownie." << std::endl;
        }
    }
}

//===================================================================================================================================================================

std::string wybor_koloru()
{
    std::string nrkoloru;
    std::string kolor;
    std::cout << "(1) czerwony" << std::endl;
    std::cout << "(2) niebieski" << std::endl;
    std::cout << "(3) zielony" << std::endl;
    std::cout << "(4) czarny" << std::endl;
    std::cout << "(5) secret" << std::endl;
    while (true)
    {
        std::getline(std::cin >> std::ws, nrkoloru);
        if (nrkoloru.size() == 1 && (nrkoloru[0] >= '1' && nrkoloru[0] <= '5'))
        {
            switch (nrkoloru[0])
            {
            case '1':
                kolor = "red";
                break;
            case '2':
                kolor = "blue";
                break;
            case '3':
                kolor = "green";
                break;
            case '4':
                kolor = "black";
                break;
            case '5':
            {
                std::vector<std::string> sekretnykolor =
                    {
                        "purple",
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
                int losowa = rand() % sekretnykolor.size();
                kolor = sekretnykolor[losowa];
                break;
            }
            default:
                std::cout << "Nieprawidlowa opcja. Sprobuj ponownie." << std::endl;
                continue;
            }
            return kolor;
        }
        else
        {
            std::cout << "Nieprawidlowa opcja. Sprobuj ponownie." << std::endl;
            continue;
        }
    }
    return kolor;
}

//===================================================================================================================================================================

void pomoc_SVG()
{
    system("cls");
    wys("### INSTRUKCJA DO SVG ###");
    std::cout << std::endl;

    wys("# SVG PODSTAWOWE #");
    std::cout << std::endl;
    wys("Program prosi o nazwe pliku i tworzy puste SVG z naglowkiem i <svg>.");
    wys("Na koncu plik jest zamykany </svg> i pyta uzytkownika czy ma otworzyc plik w przegladarce.");
    std::cout << std::endl;

    wys("# SVG ZAAWANSOWANE #");
    std::cout << std::endl;
    wys("Program tworzy SVG i rysuje trzy elementy: kolo, prostokat i linie.");
    wys("Dla kazdej figury trzeba podac parametry (np. wspolrzedne, rozmiar, kolor).");
    wys("Figury sa rysowane na polu 1500x1500");
    wys("Trzeba pamietac ze podawane wspolrzedne sa liczone od lewego gornego rogu pola");
    wys("Jesli elementy nachodza na siebie, program poprosi o ponowne podanie danych.");
    std::cout << std::endl;

    wys("# NAZWY PLIKOW #");
    std::cout << std::endl;
    wys("Nazwy moga miec spacje, ale lepiej dawac proste nazwy typu rysunek.svg.");
    wys("Plik zapisuje sie w folderze, w ktorym jest program");
    std::cout << std::endl;

    wys("# WAZNE #");
    std::cout << std::endl;
    wys("Jesli przegladarka nie pokazuje zmian, odswiez strone (F5).");
    std::cout << std::endl;
    std::cout << std::endl;
    pauza();
}

void pomoc_XO()
{
    wys("### INSTRUKCJA DO GRY KOLKO I KRZYZYK ###");
    std::cout << std::endl;
    wys("- Gra toczy sie na planszy 3x3 pola.");
    wys("- Gracze lub gracz i komputer, na zmiane wybieraja pola na planszy, aby postawic swoj znak (Kolo lub Krzyzyk).");
    wys("- Celem gry jest ustawienie trzech swoich znakow w linii poziomej, pionowej lub ukosnej.");
    wys("- Gracz ktoremu uplynie czas, przegrywa.");
    wys("- Aby wybrac pole, nalezy wpisac liczbe od 1 do 9, odpowiadajaca niezajetemu polu na planszy.");
    wys("- Gracz O zawsze zaczyna jako pierwszy.");
    std::cout << std::endl;
    wys("Po lewej stronie znajduje sie numeracja pol:");
    std::cout << std::endl;
    wys("1 | 2 | 3");
    wys("---+---+---");
    wys("4 | 5 | 6");
    wys("---+---+---");
    wys("7 | 8 | 9");
    std::cout << std::endl;
    wys("Pod nia znajduje sie informacja, ktory gracz wykonuje ruch.");
    wys("Cyfra w polu oznacza ze jest ono wolne.");
    wys("Gdy gracz wybierze pole, numer zniknie, co oznacza ze pole jest juz zajete.");
    std::cout << std::endl;
    wys("Na srodku widoczna jest aktualna plansza gry:");
    std::cout << std::endl;
    wys("   |   |   ");
    wys("---+---+---");
    wys("   |   |   ");
    wys("---+---+---");
    wys("   |   |   ");
    std::cout << std::endl;
    wys("Po prawej stronie wyswietla sie ile czasu zostalo danemu graczowi.");
    wys("Podstawowy czas dla kazdego z graczy wynosi on 30s.");
    wys("W ustawieniach gry, jest mozliwosc zmiany czasu,");
    wys("oraz jego calkowite wylaczenie.");
    std::cout << std::endl;
    wys("Czas gracza O: 0:30");
    wys("Czas gracza X: 0:30");
    std::cout << std::endl;
    wys("W przypadku trybu Gracz VS PC, czas wyswietla sie tylko dla gracza.");
    std::cout << std::endl;
    wys("# PLIK SVG DO GRY #");
    std::cout << std::endl;
    wys("W trakcie gry generowany jest plik SVG,");
    wys("ktory wizualizuje aktualny stan planszy gry w kolko i krzyzyk.");
    wys("Plik ten jest nadpisywany przy kazdym ruchu gracza i nalezy odswierzyc, aby zobaczyć zmiany.");
    wys("Jezeli chcesz zobaczyc plik SVG, znajdziesz go w folderze z programem pod nazwa 'XO.svg'.");
    wys("W ustawieniach gry jest mozliwosc wylączania wizualizacji graficznej.");
    wys("A takze wlaczyc tryb odswierzania automatycznego, ktory otwiera");
    wys("nowa karte z aktualnym stanem gry.");
    std::cout << std::endl;
    wys("MILEJ ZABAWY!!!");
    std::cout << std::endl
              << std::endl;
    pauza();
}

void pomoc_Warcaby()
{
    system("cls");
    wys("### INSTRUKCJA DO GRY WARCABY ###");
    std::cout << std::endl;

    wys("# PODSTAWY #");
    std::cout << std::endl;
    wys("Gra to odmiana warcab Checkers");
    wys(" czyli angilska/amerykanska wersja ");
    wys("Gra toczy sie na planszy 8x8");
    wys("Gracze wykonuja ruchy na zmiane");
    wys("Gracz O zawsze zaczyna jako pierwszy");
    std::cout << std::endl;

    wys("# JAK WYGLADA PLANSZA #");
    std::cout << std::endl;
    wys("Pola z gwiazdka * (czarne) to pola gry na ktorych mozna stawiac pionki");
    wys("Puste pola (biale) to pola gry na ktorych nie mozna stawiac pionkow ");
    wys("O (bialy) oraz @ (czarny) to zwykle pionki graczy");
    wys("% (bialy) oraz & (czarny) to damki graczy");
    std::cout << std::endl;

    wys("# JAK WYKONAC RUCH #");
    std::cout << std::endl;
    wys("Podajesz pole startowe i pole docelowe w formacie typu a3 lub h6");
    wys("Litera to kolumna od a do h");
    wys("Cyfra to wiersz od 1 do 8");
    std::cout << std::endl;

    wys("# ZASADY RUCHU #");
    std::cout << std::endl;
    wys("Zwykly pionek porusza sie o jedno pole po skosie do przodu");
    wys("Damka porusza sie o jedno pole po skosie w kazda strone");
    std::cout << std::endl;

    wys("# BICIE #");
    std::cout << std::endl;
    wys("Jesli masz mozliwosc bicia to musisz bic");
    wys("Bicie polega na przeskoku o dwa pola po skosie nad pionkiem przeciwnika");
    wys("Po biciu mozesz miec kolejne bicie i wtedy kontynuujesz w tej samej turze");
    std::cout << std::endl;

    wys("# DAMKA #");
    std::cout << std::endl;
    wys("Pionek O zostaje damka (%) na gornej krawedzi planszy");
    wys("Pionek @ zostaje damka (&) na dolnej krawedzi planszy");
    std::cout << std::endl;

    wys("# ZAPIS W TRAKCIE GRY #");
    std::cout << std::endl;
    wys("Gdy program pyta o pole mozesz wpisac X");
    wys("Wtedy otworzy sie menu zapisu i wybierasz od slot 1 do 4");
    wys("Jesli slot jest zajety program zapyta czy nadpisac");
    wys("P oznacza powrot do gry");
    wys("X w menu zapisu oznacza powrot do menu");
    std::cout << std::endl;

    wys("# SVG DO WARCABOW #");
    std::cout << std::endl;
    wys("W trakcie gry moze byc generowany plik SVG");
    wys("Plik pokazuje aktualny stan planszy w trybie graficznym");
    wys("Jesli przegladarka nie pokazuje zmian odswiez strone (F5)");
    wys("Plik znajduje sie w folderze z programem");
    std::cout << std::endl;

    wys("MILEJ ZABAWY!!!");
    std::cout << std::endl
              << std::endl;
    pauza();
}

void pomoc_ogolna()
{
    system("cls");
    wys("### POMOC OGOLNA ###");
    std::cout << std::endl;

    wys("# MENU I STEROWANIE #");
    std::cout << std::endl;
    wys("W menu wpisujesz jedna litere lub cyfre zgodnie z opisem na ekranie");
    wys("W wielu miejscach wielkosc liter nie ma znaczenia");
    wys("Jesli wpiszesz cos zle, program poprosi o ponowne wpisanie");
    std::cout << std::endl;

    wys("# PLIKI I ZAPIS #");
    std::cout << std::endl;
    wys("Pliki zapisu i pliki SVG zapisuja sie w folderze z programem");
    wys("Plik z reprezentacja graficzna do XO nazywa sie XO.svg");
    wys("Zapis w slotach to pliki typu war_slot1.txt war_slot2.txt itd");
    wys("Jesli plik jest uszkodzony program potraktuje slot jako pusty");
    std::cout << std::endl;

    wys("# TRYB GRAFICZNY SVG #");
    std::cout << std::endl;
    wys("SVG to plik ktory otwierasz w przegladarce i widzisz rysunek gry");
    wys("Program moze nadpisywac ten sam plik po kazdym ruchu");
    wys("Jesli nie widac zmian odswiez karte w przegladarce (F5)");
    std::cout << std::endl;

    wys("# ODSWIEZANIE #");
    std::cout << std::endl;
    wys("Opcja odswiezania automatycznego otwieraa plik SVG po kazdym ruchu");
    wys("Jesli to przeszkadza mozna to wylaczyc w ustawieniach danej gry");
    std::cout << std::endl;

    pauza();
}
