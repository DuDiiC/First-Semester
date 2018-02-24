#include <iostream>
using namespace std;
 int main() {
    int k; cin >> k;
    for(int i = 0; i < k; ++i) {
        int liczba;
        cin >> liczba;
        if(liczba == 0) {
            cout << liczba << " - liczba deficytowa" << endl;
            continue;
        }
        int suma = 0;
        //sprawdzenie czy cos jest dzielnikiem
        for(int i = 1; i < liczba/2 + 1; ++i) {
            //dodanie tego dzielnika do sumy
            if(liczba % i == 0) {
                suma += i;
            }
        }
        //sprawdzenie i wydrukowanie wyniku
        if(suma == liczba) {
            cout << liczba << " - liczba doskonala" << endl;
        } else if(suma > liczba) {
            cout << liczba << " - liczba deficytowa" << endl;
        } else if(suma < liczba) {
            cout << liczba << " - liczba nadmiarowa" << endl;
        }
    }
 }
