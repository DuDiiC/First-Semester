#include <iostream>
using namespace std;

long long nwd, X = 1, Y, pomoc1, pomoc2;

void NWD(long long x, long long y) {
    if(y == 0) {
        nwd = x;
        pomoc2 = x;
        return;
    } else NWD(y, x%y);

    long long t = Y;
    Y = (X - (x/y) * Y);
    pomoc1 = y;
    X = t;
    pomoc2 = x;
}

int main() {
    long long a, b;
    while(cin >> a >> b) {
        NWD(a, b);
        cout << X << " " << Y << " " << nwd << endl;
        nwd = 0; X = 1; Y = 0; pomoc1 = 0; pomoc2 = 0;
    }
}
