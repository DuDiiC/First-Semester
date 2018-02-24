#include <iostream>
using namespace std;

long long NWD(long long x, long long y) {
    if(x == 0) return y;
    else {
        cout << y << " = " << y/x << " * " << x << " + " << y%x  << endl;
        NWD(y%x, x);
    }
}

int main() {
    long long x, y;
    cin >> x >> y;
    NWD(x, y);
}
