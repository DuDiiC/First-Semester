#include <iostream>

using namespace std;

void zamien(long &a, long &b) {
    a = a - b;
    b = b + a;
    a = b - a;
}

int main()
{
    int iloscPowtorzen;
    cin >> iloscPowtorzen;
    for(int i = 0; i < iloscPowtorzen; i++) {
        long a, b;
        cin >> a >> b;
        if(a > b) {
            zamien(a, b);
        }
        while(a != 0) {
            b = b % a;
            if(a > b) {
                zamien(a, b);
            }
        }
        cout << b << endl;
    }
    return 0;
}
