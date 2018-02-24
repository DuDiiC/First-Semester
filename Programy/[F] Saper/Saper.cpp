#include <iostream>
using namespace std;

int main() {
    int ileTestow = 1;
    int kolumny, wiersze;
    while(true) {
        cin >> kolumny >> wiersze;
        if(kolumny == 0 || wiersze == 0) break;
        else {
            char pole[kolumny+2][wiersze+2];
            for(int i = 0; i < kolumny+2; i++){
                for(int j = 0; j < wiersze+2; j++) {
                    pole[i][j] = 0;
                }
            }
            for(int i = 1; i < kolumny+1; i++){
                for(int j = 1; j < wiersze+1; j++){
                    cin >> pole[i][j];
                    if(pole[i][j] != '*') {
                        pole[i][j] = '0';
                    }
                }
            }
            for(int i = 1; i < kolumny+1; i++){
                for(int j = 1; j < wiersze+1; j++){
                    if(pole[i][j] == '*'){
                        if(pole[i-1][j-1] != '*') pole[i-1][j-1]++;
                        if(pole[i][j-1] != '*') pole[i][j-1]++;
                        if(pole[i+1][j-1] != '*') pole[i+1][j-1]++;
                        if(pole[i-1][j] != '*') pole[i-1][j]++;
                        if(pole[i+1][j] != '*') pole[i+1][j]++;
                        if(pole[i-1][j+1] != '*') pole[i-1][j+1]++;
                        if(pole[i][j+1] != '*') pole[i][j+1]++;
                        if(pole[i+1][j+1] != '*') pole[i+1][j+1]++;
                    }
                }
            }
            cout << endl << "Field #" << ileTestow << ":" << endl;
            for(int i = 1; i < kolumny+1; i++){
                for(int j = 1; j < wiersze+1; j++){
                    cout << pole[i][j];
                }
                cout << endl;
            }
            ileTestow++;
        }
    }
}
