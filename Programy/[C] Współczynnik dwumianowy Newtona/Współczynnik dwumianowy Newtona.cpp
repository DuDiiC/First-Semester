#include <iostream>
using namespace std;

int NWD(int x, int y) {
    if(x<y) {
        int zmienna = x;
        x = y;
        y = zmienna;
    }
    while(y != 0) {
        int zmienna = x % y;
        x = y;
        y = zmienna;
    }

    return x;
}


int main() {
    int n, k;
    cin >> n >> k;
    do {
        long long wynik;
        long long licznik = 1, mianownik = 1;
        for(int i = k + 1, j = 1; (i <= n) && (j <= n - k); i++, j++){
            licznik *= i;
            mianownik *= j;
            if(NWD(licznik, mianownik) > 1) {
                for(int m = 2; m <= 33; m++) {
                    if((licznik%m == 0) && (mianownik%m == 0)) {
                        licznik = licznik/m;
                        mianownik = mianownik/m;
                    }
                }
            }
        }
        wynik = licznik/mianownik;
        cout << wynik << endl;
        cin >> n >> k;
    } while(n != 0 && k != 0);
    cout << 1 << endl;
}
