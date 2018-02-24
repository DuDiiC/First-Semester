#include <iostream>
using namespace std;

int potega2(int potega) {
    int iloczyn = 1;
    for(int i = 0; i < potega; ++i) {
        iloczyn *= 2;
    }
    return iloczyn;
}

int zamiana(char znak) {
    switch(znak){
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
    }
}

int main() {
    string liczba2;
    while(cin >> liczba2) {
        if(liczba2 == "0") break;
        unsigned int suma = 0;
        for(int i = 0; i < liczba2.size(); ++i) {
            suma = suma + ((potega2(liczba2.size()-i) - 1) * zamiana(liczba2[i]));
        }
        cout << suma << endl;
    }
}
