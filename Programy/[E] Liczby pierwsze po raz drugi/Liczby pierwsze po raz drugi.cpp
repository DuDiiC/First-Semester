#include <iostream>

using namespace std;

int main() {
    int maski[8] = {1};
    int zerowania[8] = {254};
    char pelny = 255;
    int bit, bajt;
    int * tabPierwszych = new int[700000];
    int pozycjaPierwszej = 0;
    int znak;
    char liczby[1250000];
    for(int i = 0; i < 1250000; ++i) {
        liczby[i] = 255;
    }

    for(int i = 1; i < 8; ++i){
        maski[i] = maski[i-1] << 1;
    }
    for(int i = 1, potega = 2; i < 8; ++i){
        zerowania[i] = 255 - potega;
        potega *= 2;
    }

    liczby[0] = liczby[0] & zerowania[0];
    liczby[0] = liczby[0] & zerowania[1];
    for(int i = 2; i < 10000000; ++i) {
        bajt = i/8;
        bit = i%8;
        znak = liczby[bajt] & maski[bit];
        if(znak == maski[bit]){
            tabPierwszych[pozycjaPierwszej] = i;
            pozycjaPierwszej++;
            for(int j = 2*i; j < 10000000; j += i) {
                bajt = j/8;
                bit = j%8;
                liczby[bajt] = liczby[bajt] & zerowania[bit];
            }
        }
    }

    int liczba;
    while(true) {
        cin >> liczba;
        if(liczba == 0) break;

        bool czyPierwsza = false;

        for(int i = 0; i < pozycjaPierwszej; ++i) {
            if(liczba == tabPierwszych[i]) {
                czyPierwsza = true;
                cout << liczba << " to liczba pierwsza numer " << i+1 << "." << endl;
            }
        }
        if(czyPierwsza == false) {
            cout << liczba << " nie jest pierwsza." << endl;
        }
    }
}
