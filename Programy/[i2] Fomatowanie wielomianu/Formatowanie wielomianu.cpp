#include <iostream>
using namespace std;

void czyUjemna(int &liczba) {
    if(liczba < 0) {
        cout << " - ";
        liczba = -liczba;
    } else {
        cout << " + ";
    }
}

void czyJeden(int liczba, int potega) {
    if(liczba == 1) {
        cout << "x^" << potega;
    } else if(liczba == -1) {
        cout << "-x^" << potega;
    } else {
        cout << liczba << "x^" << potega;
    }
}

int main() {
    int wielomian[9];


    while(cin >> wielomian[8]) {
        bool pierwszyZnak = true;
        bool wszystkieZerowe = true;
        bool niezerowy[9];
        //wczytywanie x^8
        if(wielomian[8] != 0) {
                niezerowy[8] = true;
                wszystkieZerowe = false;
            } else niezerowy[8] = false;
        //wczytywanie wielomianu
        for(int i = 7; i >= 0; --i) {
            cin >> wielomian[i];
            if(wielomian[i] != 0) {
                niezerowy[i] = true;
                wszystkieZerowe = false;
            } else niezerowy[i] = false;
        }
        if(wszystkieZerowe) {
            cout << 0 << endl;
            continue;
        }
        //wypisywanie od x^8 do x^2
        for(int i = 8; i > 1; --i) {
            if(niezerowy[i]){
                if(pierwszyZnak){
                    pierwszyZnak = false;
                    czyJeden(wielomian[i], i);
                } else {
                    czyUjemna(wielomian[i]);
                    czyJeden(wielomian[i], i);
                }
            }
        }
        //wypisanie x
        if(niezerowy[1]){
            if(pierwszyZnak){
                pierwszyZnak = false;
                if(wielomian[1] == 1) {
                    cout << "x";
                } else if(wielomian[1] == -1) {
                    cout << "-x";
                } else {
                    cout << wielomian[1] << "x";
                }
            } else {
                czyUjemna(wielomian[1]);
                if(wielomian[1] == 1) {
                    cout << "x";
                } else {
                    cout << wielomian[1] << "x";
                }
            }
        }
        //wypisanie wyrazu wolnego
        if(niezerowy[0]){
            if(pierwszyZnak){
                pierwszyZnak = false;
                cout << wielomian[0];
            } else {
                czyUjemna(wielomian[0]);
                cout << wielomian[0];
            }
        }
        cout << endl;
    }
}
