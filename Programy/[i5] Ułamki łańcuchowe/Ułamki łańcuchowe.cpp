#include <iostream>
using namespace std;

int main() {
    int licznik, mianownik;
    while(cin >> licznik >> mianownik) {
        if(licznik == 0) {
            cout << "[0]" << endl;
            continue;
        }
        if(mianownik == 1) {
            cout << "[" << licznik << "]" << endl;
            continue;
        }
        if(licznik%mianownik == 0){
            cout << "[" << licznik/mianownik << "]" << endl;
            continue;
        }

        cout << "[";
        if(licznik >= mianownik) {
            cout << licznik/mianownik << ";";
        } else cout << 0 << ";";
        do {
            licznik = licznik%mianownik;
            int zmienna = licznik;
            licznik = mianownik;
            mianownik = zmienna;
            cout << licznik/mianownik;
            if(licznik%mianownik == 0) break;
            if(mianownik != 1) cout << ",";
        } while(mianownik != 1);
        cout << "]" << endl;
    }
}
