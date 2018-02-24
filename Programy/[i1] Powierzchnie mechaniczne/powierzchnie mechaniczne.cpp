#include <iostream>

using namespace std;

int main() {
    int N;
    while(cin >> N){
        if(N == 0) break;

        string wiersze[N];
        string zmienna;
        getline(cin, zmienna);
        //wczytanie danych
        for(int i = 0; i < N; ++i) {
            getline(cin, wiersze[i]);
        }
        //zliczenie przestrzeni
        int przestrzenieWiersza[N];
        for(int i = 0; i < N; ++i) {
            przestrzenieWiersza[i] = 0;
        }
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < 25; ++j) {
                if(wiersze[i][j] == ' ') przestrzenieWiersza[i]++;
            }
        }
        //wybranie najmniejszej przestrzeni
        int najmniejsza = przestrzenieWiersza[0];
        for(int i = 1; i < N; ++i) {
            if(przestrzenieWiersza[i] < najmniejsza) najmniejsza = przestrzenieWiersza[i];
        }
        //sumowanie przestrzeni
        int sumaPrzestrzeni = 0;
        for(int i = 0; i < N; ++i) {
            sumaPrzestrzeni += (przestrzenieWiersza[i] - najmniejsza);
        }

        cout << sumaPrzestrzeni << endl;
    }
}
