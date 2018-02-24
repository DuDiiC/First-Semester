#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void zamianaNa_16(int n) {
    if(n > 0) {
        zamianaNa_16(n / 16);
        if(n % 16 > 9) {
            switch(n % 16) {
                case 10:
                    cout<<"A"; break;
                case 11:
                    cout<<"B"; break;
                case 12:
                    cout<<"C"; break;
                case 13:
                    cout<<"D"; break;
                case 14:
                    cout<<"E"; break;
                case 15:
                    cout<<"F"; break;
            }
        } else cout << n % 16;
    }
}

int stringNaInt(char znak) {
    switch(znak) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case 'A': return 10;
        case 'a': return 10;
        case 'B': return 11;
        case 'b': return 11;
        case 'C': return 12;
        case 'c': return 12;
        case 'D': return 13;
        case 'd': return 13;
        case 'E': return 14;
        case 'e': return 14;
        case 'F': return 15;
        case 'f': return 15;
    }
}

int potega(int podstawa, int wykladnik) {
    int wynik = 1;
    if(wykladnik>0){
        for(int i = 0; i < wykladnik; i++) {
        wynik *= podstawa;
        }
    }
    return wynik;
}

void zamianaNa_10(int n, int tablica[]) {
    int suma = 0;
    int j = n;
    for(int i = 0; i < n; i++, j--){
        suma += tablica[i]*potega(16, (j - 1));
    }
    cout << suma << endl;
}

int main() {
    string liczba;
    while(cin >> liczba) {
        if(liczba == "-1") break;
        //liczba szesnastkowa
        if(liczba[0] == '0' && liczba[1] == 'x') {
            liczba = liczba.erase(0, 2);
            int dlugoscLiczby = liczba.length();
            int tablicaSzesnastkowa[dlugoscLiczby];
            for(int i = 0; i < dlugoscLiczby; i++) {
                tablicaSzesnastkowa[i] = stringNaInt(liczba[i]);
            }
            zamianaNa_10(dlugoscLiczby, tablicaSzesnastkowa);
        }
        //liczba dziesiêtna
        else {
            int liczbaNasza = atoi(liczba.c_str()); //zamiana stringa na liczbe
            if(liczbaNasza == 0) {
                cout << "0x0" << endl;
            } else {
                cout << "0x";
                zamianaNa_16(liczbaNasza);
                cout << endl;
            }
        }
    }
}
