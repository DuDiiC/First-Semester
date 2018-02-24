#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;

    while(x != 0) {
        bool pierwsza = true;
        for(int i = 2; i <= (x / 2) + 1; i++) {
            if(x % i == 0 && x != 2) {
                cout << "dzielnikiem " << x << " jest " << i << "." << endl;
                pierwsza = false;
                break;
            }
        }
        if(pierwsza) {
            cout << x << " to liczba pierwsza." << endl;
        }

        cin >> x;
    }
}
