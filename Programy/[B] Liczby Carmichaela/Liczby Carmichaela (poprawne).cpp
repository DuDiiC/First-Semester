#include <iostream>
using namespace std;

int main() {
    int liczba;
    int liczbyCarmichaela[15] = {561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973};
    while(cin >> liczba) {
        if(liczba == 0) break;
        int i;
        bool czyCarmichaela = false;
        for(i = 0; i < 15; ++i) {
            if(liczba == liczbyCarmichaela[i]) {
                czyCarmichaela = true;
                break;
            }
        }
        if(czyCarmichaela) {
            cout << "The number " << liczba << " is a Carmichael number." << endl;
        } else {
            cout << liczba << " is normal." << endl;
        }
    }
}
