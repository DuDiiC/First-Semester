#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
using namespace std;

int i, j, k;
//FUNKCJA ZMIENIA KODOWANIE Z OEM-852 NA WINDOWS-1250
//ZAMIENIA FORMATOWANIE SYSTEMOWE NA KONSOLOWE
char *tr(char *str)
{
    static char buff[256];
    char cp[]="\245\206\251\210\344\242\230\276\253\244\217\250\235\343\340\227\275\215¹æê³ñóœ¿Ÿ¥ÆÊ£ÑÓŒ¯";
    if(strlen(str)>=sizeof(buff)) return str;
    char *bf=buff;
    while(*str)
    {
        char *pos=strchr(cp+18,*str);
        *(bf++)=pos?*(pos-18):*str;
        ++str;
    }
    *bf=0;
    return buff;
}
//FUNKCJA ZMIENIA KODOWANIE WINDOWS-1250 NA OEM-852
//ZAMIENIA FORMATOWANIE KONSOLOWE NA SYSTEMOWE
char *rt(char *str)
{
    static char buff[256];
    char cp[]="¹æê³ñóœ¿Ÿ¥ÆÊ£ÑÓŒ¯\245\206\251\210\344\242\230\276\253\244\217\250\235\343\340\227\275\215";
    if(strlen(str)>=sizeof(buff)) return str;
    char *bf=buff;
    while(*str)
    {
        char *pos=strchr(cp+18,*str);
        *(bf++)=pos?*(pos-18):*str;
        ++str;
    }
    *bf=0;
    return buff;
}
//DZIALA JAK POWTARZA SIE LITERA W SLOWIE KODOWYM
bool czyJuzBylo(char *wsk, char znak, int i, int j) {
    for(k = 0; k < i+(i+1)*j; ++k) {
        if(*wsk == znak) {
            cout << "to juz bylo! " << znak << endl;
            wsk -= k;
            return true;
        }
        ++wsk;
    }
    wsk -= k;
    return false;
}
//POMAGA UZUPELNIC TABLICE SZYFRU
bool czyJuzBylo(string szyfrowe, char znak) {
    for(k = 0; k < szyfrowe.size(); ++k) {
        if(szyfrowe[k] == znak) return true;
    }
    return false;
}
//FUNKCJA SZYFRUJACA
string zakoduj(string slowoZakodowane, char tablicaDoSzyfru[6][6]) {
    int wiersz1, wiersz2, kolumna1, kolumna2;
    int rozmiar = slowoZakodowane.size();
    //POPISANIE ZEBY BYLO MOZNA POLACZYC W PARY
    if(rozmiar%2 == 1) {
        slowoZakodowane += "x";
        ++rozmiar;
    }
    for(i = 0; i < rozmiar-1; i += 2) { //PETLA DLA KAZDEJ DWOJKI
        bool wyjscie = false;
        for(j = 0; j < 6; ++j) { //ZNALEZIENIE PIERWSZEJ Z PARY W TABLICY
            for(k = 0; k < 6; ++k) {
                if(slowoZakodowane[i] == tablicaDoSzyfru[j][k]) {
                    wiersz1 = j;
                    kolumna1 = k;
                    wyjscie = true;
                    break;
                }
            }
            if(wyjscie == true) break;
        }
        wyjscie = false;
        for(j = 0; j < 6; ++j) { //ZNALEZIENIE DRUGIEJ Z PARY W TABLICY
            for(k = 0; k < 6; ++k) {
                if(slowoZakodowane[i+1] == tablicaDoSzyfru[j][k]) {
                    wiersz2 = j;
                    kolumna2 = k;
                    wyjscie = true;
                    break;
                }
            }
            if(wyjscie == true) break;
        }
        //SZYFROWANIE
        if(wiersz1 == wiersz2 && kolumna1 == kolumna2) {
        } else if(wiersz1 == wiersz2) {
            if(kolumna1 == 0) kolumna1 = 5;
            else --kolumna1;
            if(kolumna2 == 0) kolumna2 = 5;
            else --kolumna2;
        } else if(kolumna1 == kolumna2) {
            if(wiersz1 == 0) wiersz1 = 5;
            else --wiersz1;
            if(wiersz2 == 0) wiersz2 = 5;
            else --wiersz2;
        } else {
            swap(kolumna1, kolumna2);
        }
        slowoZakodowane[i] = tablicaDoSzyfru[wiersz1][kolumna1];
        slowoZakodowane[i+1] = tablicaDoSzyfru[wiersz2][kolumna2];
    }
    return slowoZakodowane;
}

int main() {
    cout << "Podaj slowo kodowe, uzyte do wczesniejszego zakodowania: " << endl;
    string slowoKodowe;
    cin >> slowoKodowe;
    char slowoKodoweChar[slowoKodowe.size()+1];
    copy(slowoKodowe.begin(), slowoKodowe.end(), slowoKodoweChar);
    slowoKodoweChar[slowoKodowe.size()] = '\0';
    slowoKodowe = rt(slowoKodoweChar);
    //PRZYGOTOWANIE TABLICY
        char tablicaRobocza[6][6] = {'a', '¹', 'b', 'c', 'æ', 'd', 'e', 'ê', 'f', 'g', 'h', 'i', 'j', 'k', 'l', '³', 'm', 'n',
                                     'ñ', 'o', 'ó', 'p', 'q', 'r', 's', 'œ', 't', 'u', 'w', 'v', 'x', 'y', 'z', 'Ÿ', '¿', ' '};
        char tablicaDoSzyfru[6][6];
        for(i = 0; i < 6; ++i) {
            for(j = 0; j < 6; ++j) {
                tablicaDoSzyfru[i][j] = 0;
            }
        }
        char *wskDoTablicySzyfru = &tablicaDoSzyfru[0][0], *wskDoTablicySzyfru2 = &tablicaDoSzyfru[0][0];
        int licznik = 0;
        i = 0; j = 0;
        //WPISANIE SLOWA KODOWEGO NA POCZATEK TABLICY
        while(licznik < slowoKodowe.size()) {
            if(j == 6) {
                j = 0;
                ++i;
            }
            if(i == 6) break;
            if(czyJuzBylo(wskDoTablicySzyfru, slowoKodowe[licznik], i, j) == false) {
                tablicaDoSzyfru[i][j] = slowoKodowe[licznik];
                ++j;
            }
            ++licznik;
        }
        wskDoTablicySzyfru = &tablicaDoSzyfru[i][j];
        i = 0; j = 0;
        //WPISANIE RESZTY ZNAKOW DO TABLICY
        while(true) {
            if(j == 6) {
                j = 0;
                ++i;
            }
            if(i == 6) break;
            if(!czyJuzBylo(slowoKodowe, tablicaRobocza[i][j])) {
                *wskDoTablicySzyfru = tablicaRobocza[i][j];
                ++wskDoTablicySzyfru;
            }
            ++j;
        }
    ///////////////////////
    cout << "Wybierz czy podasz sciezke do pliku (wpisz 1) czy podasz slowo do odkodowania w konsoli (wpisz 2): " << endl;
    int wybor;
    cin >> wybor;
    cin.sync();
    string slowoDoZakodowania, slowoZakodowane;
    switch(wybor) {
        case 1: {
            string sciezkaDoPliku;
            getline(cin, sciezkaDoPliku);
            string sciezkaDoPlikuZakodowanego = sciezkaDoPliku;
            sciezkaDoPlikuZakodowanego = sciezkaDoPlikuZakodowanego.erase(sciezkaDoPlikuZakodowanego.length()-4, sciezkaDoPlikuZakodowanego.length());
            sciezkaDoPlikuZakodowanego += ".out.txt";
            ifstream plikZeSlowem(sciezkaDoPliku.c_str());
            getline(plikZeSlowem, slowoDoZakodowania);
            slowoZakodowane = slowoDoZakodowania;
            slowoZakodowane = zakoduj(slowoDoZakodowania, tablicaDoSzyfru);
            ofstream plikZZakodowanymSlowem(sciezkaDoPlikuZakodowanego.c_str());
            plikZZakodowanymSlowem << slowoZakodowane;
            break;
        }
        case 2: {
            getline(cin, slowoDoZakodowania);
            cin.sync();
            //ZAMIANA NA KODOWANIE SYSTEMOWE
            char slowoDoZakodowaniaChar[slowoDoZakodowania.size()+1];
            copy(slowoDoZakodowania.begin(), slowoDoZakodowania.end(), slowoDoZakodowaniaChar);
            slowoDoZakodowaniaChar[slowoDoZakodowania.size()] = '\0';
            slowoDoZakodowania = rt(slowoDoZakodowaniaChar);
            slowoZakodowane = slowoDoZakodowania;
            slowoZakodowane = zakoduj(slowoDoZakodowania, tablicaDoSzyfru);
            ofstream plikZZakodowanymSlowem("wyjscie.out.txt");
            plikZZakodowanymSlowem << slowoZakodowane;
        }
    }

    //ZAMIANA NA KODOWANIE KONSOLI
    char slowoZakodowaneChar[slowoZakodowane.size()+1];
    copy(slowoZakodowane.begin(), slowoZakodowane.end(), slowoZakodowaneChar);
    slowoZakodowaneChar[slowoZakodowane.size()]='\0';
    slowoZakodowane = tr(slowoZakodowaneChar);
    cout << slowoZakodowane << endl;
}
//PROGRAM MA PROBLEM GDY W PLIKU ZNAJDUJE SIE SLOWO Z POLSKIMI ZNAKAMI (znak polski traktuje jako jakby dwie litery)
