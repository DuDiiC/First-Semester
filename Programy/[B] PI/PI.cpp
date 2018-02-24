#include <iostream>
#include <math.h>
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
    int m, n;
    int ilePar = 0, ileParWzgledniePierwszych = 0;
    cin >> m >> n;
    for(int i = m; i < n; i++){
        for(int j = i + 1; j < n; j++){
            ilePar++;
            if(NWD(i, j) == 1) {
                ileParWzgledniePierwszych++;
            }
        }
    }
    double q = (double)ileParWzgledniePierwszych/ilePar;
    cout << sqrt(6/q) << endl;
}
