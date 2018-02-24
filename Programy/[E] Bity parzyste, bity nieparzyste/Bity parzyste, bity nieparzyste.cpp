#include <iostream>
using namespace std;

int main() {
    int liczba;
    while(cin >> liczba) {
        if(liczba == 0) break;
        else {
            int maskaParzysta = 1, maskaNieparzysta = 2;
            //maska parzysta
            for(int i = 0; i < 17; i++) {
                maskaParzysta = maskaParzysta << 2;
                maskaParzysta = maskaParzysta | 1;
            }
            //maska nieparzysta
            for(int i = 0; i < 17; i++) {
                maskaNieparzysta = maskaNieparzysta << 2;
                maskaNieparzysta = maskaNieparzysta | 2;
            }
            int czescParzysta = maskaParzysta & liczba;
            int czescNieparzysta = maskaNieparzysta & liczba;

            cout << czescParzysta << " " << czescNieparzysta << endl;
        }
    }
}
