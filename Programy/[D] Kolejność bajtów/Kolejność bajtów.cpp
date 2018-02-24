#include <iostream>
using namespace std;

int main() {
    int liczba;
    cin >> liczba;
    int a, b, c ,d, przesuwana = 255;

    a = liczba & przesuwana;
    przesuwana = przesuwana << 8;
    b = liczba & przesuwana;
    przesuwana = przesuwana << 8;
    c = liczba & przesuwana;
    przesuwana = przesuwana << 8;
    d = liczba & przesuwana;

    a = a << 8;
    a = a | (b>>8);
    a = a << 8;
    a = a | (c>>16);
    a = a << 8;
    a = a | (d>>24);

    cout << a << endl;
}

/* WERSJA CZYTELNIEJSZA DLA MNIE
#include <iostream>
using namespace std;

int main() {
    int liczba;
    cin >> liczba;
    int a, b, c, d, przesuwana = 255;

    a = liczba & przesuwana;
    przesuwana = przesuwana << 8;
    b = liczba & przesuwana;
    przesuwana = przesuwana << 8;
    c = liczba & przesuwana;
    przesuwana = przesuwana << 8;
    d = liczba & przesuwana;

    d = d >> 24;
    c = c >> 8;
    b = b << 8;
    a = a << 24;

    int przesunieta = a | b | c | d;
    cout << przesunieta << endl;
}
*/
