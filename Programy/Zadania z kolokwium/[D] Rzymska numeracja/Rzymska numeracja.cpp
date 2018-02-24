#include <iostream>
using namespace std;

int main() {
    int liczba;
    while(cin >> liczba) {
        if(liczba == 0) break;
        int ileI = 0, ileV = 0, ileX = 0, ileL = 0, ileC = 0;
        for(int i = 1; i <= liczba; ++i) {
            if(i < 100) {
                if(i%10 == 1) ++ileI;
                if(i%10 == 2) ileI += 2;
                if(i%10 == 3) ileI += 3;
                if(i%10 == 4) { ++ileI; ++ileV;}
                if(i%10 == 5) ++ileV;
                if(i%10 == 6) { ++ileI; ++ileV;}
                if(i%10 == 7) { ileI += 2; ++ileV;}
                if(i%10 == 8) { ileI += 3; ++ileV;}
                if(i%10 == 9) { ++ileI; ++ileX;}
                if(i/10 == 1) ++ileX;
                if(i/10 == 2) ileX += 2;
                if(i/10 == 3) ileX += 3;
                if(i/10 == 4) { ++ileX; ++ileL;}
                if(i/10 == 5) ++ileL;
                if(i/10 == 6) { ++ileX; ++ileL;}
                if(i/10 == 7) { ileX += 2; ++ileL;}
                if(i/10 == 8) { ileX += 3; ++ileL;}
                if(i/10 == 9) { ++ileX; ++ileC;}
            }
            else ++ileC;
        }
        cout << liczba << ": " << ileI << " i, " << ileV << " v, " << ileX << " x, " << ileL << " l, " << ileC << " c" << endl;
    }
}
