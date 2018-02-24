#include <iostream>
#include <string>
using namespace std;

string odwroc(string liczba) {
    //if(liczba.size()%2 == 0){
        for(int i = 0; i <= liczba.size()/2 - 1; ++i) {
            char pomoc = liczba[i];
            liczba[i] = liczba[liczba.size() - 1 - i];
            liczba[liczba.size() - 1 - i] = pomoc;
        }
        return liczba;
    //}
}

string dodawanieDwochStringow(string liczba1, string liczba2) {
    string suma = "";
    int cyfraPrzenoszona = 0, sumaCyfr, dlugoscWiekszejLiczby,
        i = liczba1.size(), j = liczba2.size();
        dlugoscWiekszejLiczby = i;
        if(j < i) dlugoscWiekszejLiczby = j;
        //sumowanie cyfr od konca
        for(int m = 0; m < dlugoscWiekszejLiczby; ++m) {
            --i;
            --j;
            sumaCyfr = (int)(liczba1[i]) + (int)(liczba2[j]) + cyfraPrzenoszona - 96;
            cyfraPrzenoszona = sumaCyfr/10;
            suma = (char)((sumaCyfr%10) + 48) + suma;
        }
        while(i > 0) {
            --i;
            sumaCyfr = liczba1[i] + cyfraPrzenoszona - 48;
            cyfraPrzenoszona = sumaCyfr/10;
            suma = (char)((sumaCyfr%10) + 48) + suma;

        }
        while(j > 0) {
            --j;
            sumaCyfr =liczba2[j] + cyfraPrzenoszona - 48;
            cyfraPrzenoszona = sumaCyfr/10;
            suma = (char)((sumaCyfr%10) + 48) + suma;

        }
        if(cyfraPrzenoszona) suma = (char)(cyfraPrzenoszona + 48) + suma;
        if(suma == "") suma = "0";

        return suma;
}

bool czyPalindrom(string liczba) {
    bool palindrom = true;
    for(int i = 0; i <= liczba.size()/2; ++i) {
        if(liczba[i] != liczba[liczba.size() - 1 - i]) {
            palindrom = false;
            break;
        }
    }
    return palindrom;
}

int main() {
    int ile; cin >> ile;
    for(int i = 0; i < ile; ++i) {
        string liczba;
        cin >> liczba;
        int licznikOperacji = 0;
        while(true){
            if(czyPalindrom(liczba)) break;
            string odwrocony = odwroc(liczba);
            liczba = dodawanieDwochStringow(liczba, odwrocony);
            ++licznikOperacji;
        }

        cout << licznikOperacji << " " << liczba << endl;
    }
}
