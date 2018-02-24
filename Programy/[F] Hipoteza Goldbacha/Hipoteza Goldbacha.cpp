#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int liczba;
    while(true) {
        cin >> liczba;
        if(liczba == 0) break;
        //sito
        bool wszystkieLiczby[liczba] = {false, false};
        for(int i = 2; i <= liczba; ++i) {
            wszystkieLiczby[i] = true;
        }
        for(int i = 2; i <= sqrt(liczba); ++i) {
            if(wszystkieLiczby[i]) {
                for(int j = i*i; j <= liczba; j += i) {
                    wszystkieLiczby[j] = false;
                }
            }
        }
        //tablica liczb pierwszych
        int liczbyPierwsze[liczba/2];
        int ileLiczbPierwszych = 0;
        for(int i = 0; i < liczba; ++i) {
            if(wszystkieLiczby[i]) {
                liczbyPierwsze[ileLiczbPierwszych] = i;
                ileLiczbPierwszych++;
            }
        }
        //sprawdzamy sumy par liczb
        int ilePar = 0;
        for(int i = 0; i < ileLiczbPierwszych; ++i) {
            for(int j = i; j < ileLiczbPierwszych; ++j) {
                if(liczbyPierwsze[i] + liczbyPierwsze[j] == liczba) {
                    ilePar++;
                }
            }
        }
        cout << ilePar << endl;
    }
}
