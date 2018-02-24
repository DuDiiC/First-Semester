#include <iostream>
using namespace std;

int maxSuma;

int main() {
    int N;
    cin >> N;
    int macierz[N+1][N+1];
    //wczytanie danych
    for(int i = 0; i < N + 1; ++i) macierz[i][0] = 0;
    for(int i = 0; i < N + 1; ++i) macierz[0][i] = 0;
    for(int i = 1; i < N+1; ++i) {
        for(int j = 1; j < N+1; ++j) {
            cin >> macierz[i][j];
        }
    }

    //sumy prefixowe
    int sumyPrefix[N+1][N+1];
    for(int i = 0; i < N+1; ++i) { sumyPrefix[i][0] = 0; }
    for(int i = 0; i < N+1; ++i) { sumyPrefix[0][i] = 0; }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            sumyPrefix[i+1][j+1] = sumyPrefix[i][j+1] + sumyPrefix[i+1][j] - sumyPrefix[i][j] + macierz[i+1][j+1];
        }
    }
    /*
    //sprawdzenie
    for(int i = 0; i < N+1; ++i){
        for(int j = 0; j < N+1; ++j) {
            cout.width(3);
            cout << sumyPrefix[i][j];
        }
        cout << endl;
    }
    cout << endl;
    */
    //liczenie
    int maxSuma = 0;
    for(int i = 1; i < N+1; ++i){
        for(int k = i; k < N+1; ++k) {
            for(int j = 1; j < N+1; ++j) {
                for(int l = j; l < N+1; ++l) {
                    int wynik = sumyPrefix[k][l] - sumyPrefix[i-1][l] - sumyPrefix[k][j-1] + sumyPrefix[i-1][j-1];
                    if(wynik>maxSuma) maxSuma = wynik;
                }
            }
        }
    }
    cout << maxSuma << endl;
}
