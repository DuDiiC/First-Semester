#include <iostream>
using namespace std;

int N, j;

void ktoraPotega(long long wysokoscProta, long long pracujaceKoty);

long long int lacznaWysokoscKotow(long long int wysokoscProta, long long int pracujaceKoty);

long long int kotyNiepracujace(long long int wysokoscProta, long long int pracujaceKoty);

int main() {
    long long int wysokoscProta, pracujaceKoty;

    while(cin >> wysokoscProta >> pracujaceKoty && wysokoscProta != 0 && pracujaceKoty != 0) {
        if(wysokoscProta == 1) {
            cout << 0 << " " << wysokoscProta << endl;
            continue;
        } else if(pracujaceKoty == 0) {
            cout << 1 << " " << wysokoscProta << endl;
            continue;
        } else {
            ktoraPotega(wysokoscProta, pracujaceKoty);
            if(pracujaceKoty != N | pracujaceKoty == 1) {
                cout << kotyNiepracujace(wysokoscProta, pracujaceKoty) << " " << lacznaWysokoscKotow(wysokoscProta, pracujaceKoty) + pracujaceKoty << endl;
            } else {
                cout << 1 << " " << wysokoscProta + pracujaceKoty << endl;
            }
        }
    }
}

void ktoraPotega(long long wysokoscProta, long long pracujaceKoty) {
    long long int mianownik, ile;
    N = 1;
    j = 1;
    if(pracujaceKoty != 1) {
        ++N;
        for(N; N <= pracujaceKoty; ++N) {
            ile = N;
            while(ile < pracujaceKoty) {
                ile *= N;
                ++j;
            }
            if(ile == pracujaceKoty) {
                mianownik = N + 1;
                for(int i = 1; i < j; ++i) { mianownik *= (N + 1); }
                if(wysokoscProta%mianownik == 0) break;
                else j = 1;
            } else j = 1;
        }
    }
}

long long int lacznaWysokoscKotow(long long int wysokoscProta, long long int pracujaceKoty){
    long long int wysokoscWszystkichKotow, mianownik = N + 1, podst = N + 1, wysokosc;
    if(N > 1) {
        for(int i = 2; i < j; ++i) { mianownik *= podst; }
    } else {
        wysokosc = wysokoscProta;
        while(wysokosc != 1) {
            mianownik *= podst;
            wysokosc /= 2;
        }
    }
    wysokoscWszystkichKotow = mianownik * podst;
    wysokoscWszystkichKotow -= pracujaceKoty;
    wysokoscWszystkichKotow *= wysokoscProta;
    wysokoscWszystkichKotow /= mianownik;
    if(N == 1) --wysokoscWszystkichKotow;
    return wysokoscWszystkichKotow;
}

long long int kotyNiepracujace(long long int wysokoscProta, long long int pracujaceKoty) {
    long long liczbaNiepracujacychKotow;
    if(pracujaceKoty == 1) {
        liczbaNiepracujacychKotow = 0;
        while(wysokoscProta != 1) {
            ++liczbaNiepracujacychKotow;
            wysokoscProta /= 2;
        }
    } else {
        liczbaNiepracujacychKotow = pracujaceKoty;
        liczbaNiepracujacychKotow = 1 - liczbaNiepracujacychKotow;
        liczbaNiepracujacychKotow /= (1 - N);
    }
    return liczbaNiepracujacychKotow;
}
