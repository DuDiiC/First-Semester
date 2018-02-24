#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string liczba, cyfraChar;
    while(true) {
        cin >> liczba;
        if(liczba == "0") break;
        int dlugosc = liczba.size();
        int sumaParzysta = 0, sumaNieparzysta = 0;

        for(int i = dlugosc-1; i >= 0; --i) {
            cyfraChar = liczba[i];
            int cyfraInt = strtol(cyfraChar.c_str(), NULL, 10);
            if(i%2 == 0) {
                 sumaParzysta += cyfraInt;
            } else if(i%2 == 1) {
                sumaNieparzysta += cyfraInt;
            }
        }
        if((sumaParzysta-sumaNieparzysta)%11 == 0) {
            cout << liczba << " is a multiple of 11." << endl;
        } else {
            cout << liczba << " is not a multiple of 11." << endl;
        }

    }
}
