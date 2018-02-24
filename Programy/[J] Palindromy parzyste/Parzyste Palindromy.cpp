#include <iostream>
#include <string>
using namespace std;

string wyraz;

int naive(int i, int s) {
    int a = s;
    while(i - a - 1 >= 0 && i + a < wyraz.size() && wyraz[i + a] == wyraz[i - a - 1]) ++a;

    return a;
}

int main() {
    while(getline(cin, wyraz)){

        int tab[wyraz.size() - 1];
        int p_s = 0;
        int p_d = 0;
        for(int i = 0; i < wyraz.size(); ++i) {
            int j = (2 * p_s) - i;
            //czy i jest poza parasolem
            if(p_s + p_d <= i) {
                tab[i] = naive(i, 0);
            }
            else {
                //maly parasol konczy sie w tym samym miejscu co duzy
                if(j - tab[j] == p_s - p_d) {
                    tab[i] = naive(i, tab[j]);
                }
                //nie konczy sie
                else {
                    //maly parasol wiekszy niz duzy
                    if(p_s - p_d > j - tab[j]) {
                        tab[i] = j - (p_s - p_d);
                    }
                    //maly parasol mniejszy niz duzy
                    else {
                        tab[i] = tab[j];
                    }
                }
            }

            if(p_s + p_d < i + tab[i]) {
                p_d = tab[i];
                p_s = i;
            }
        }
        //dopisac algorytm dla nieparzystych - kiedyœ...
        int ile_palindromow = 0;
        for(int i = 0; i < wyraz.size(); ++i) {
            ile_palindromow += tab[i];
        }
        cout << ile_palindromow << endl;
        if(p_s + p_d == wyraz.size()) {
                cout << wyraz.size() - 2*p_d << endl;
                if(wyraz.size() - 2*p_d == 0) break;
        }
        else {
            cout << wyraz.size()<< endl;
        }

    }
}
