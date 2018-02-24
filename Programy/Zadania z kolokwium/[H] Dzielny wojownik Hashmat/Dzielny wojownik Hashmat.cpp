#include <iostream>
using namespace std;

int main() {
    long pierwsza, druga;
    while(cin >> pierwsza >> druga) {
        long roznica = pierwsza - druga;
        if(roznica >= 0) cout << roznica << endl;
        else cout << -roznica << endl;
    }
}
