#include <iostream>
#include <string>
using namespace std;

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

        //brak implementacji ucinania zer na pocz¹tku

        return suma;
}

int main() {
    string string1, suma;
    cin >> string1;
    if(string1 == "0") {
        return 0;
    }
    suma = string1;
    while(true){
        cin >> string1;
        if(string1 == "0") break;
        suma = dodawanieDwochStringow(string1, suma);
    }
    cout << suma << endl;
}
