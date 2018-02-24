#include <iostream>
using namespace std;

bool pierwsza(int n) {
    if(n < 2) return false;
    for(int i = 2; i*i <= n; ++i) {
        if(n%i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    while(cin >> N && N != 0) {
        int tab1[30];
        for(int i = 0; i < 30; ++i)     { tab1[i] = 0; }
        int licznikLiczb1;
        for(int i = 2; i <= N; ++i) {
            int czynnik = i;
            licznikLiczb1 = 0;
            for(int j = 2; j <= i; ++j) {
                if(czynnik == 1)    { break; }
                while(czynnik%j == 0) {
                    ++tab1[licznikLiczb1];
                    czynnik = czynnik/j;
                }
                if(pierwsza(j)) ++licznikLiczb1;
            }
        }
        cout.width(3);
        cout << N;;
        cout << "! =";
        for(int i = 0; i <= 29; ++i) {
            if(tab1[i] == 0) break;
            if(i == 15) {
                cout << endl;
                cout << "      ";
            }
            cout.width( 3 );
            cout << tab1[i];
        }
        cout << endl;
    }
}
