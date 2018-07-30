/*#include <iostream>
using namespace std;
 NIEOPTYMALNY
int main() {
    int n, k;
    while(cin >> n >> k){
        int papierosyDoSpalenia = n;
        int spalonePapierosy = 0;
        int iloscNiedopalkow = 0;
        for(int i = 1; i <= papierosyDoSpalenia; i++) { //spalanie jednego papierosa
            spalonePapierosy++;
            iloscNiedopalkow++;
            if(iloscNiedopalkow == k) {
                papierosyDoSpalenia++;
                iloscNiedopalkow = 0;
            }
        }
        cout << spalonePapierosy << endl;
    }
}*/
#include <iostream>
using namespace std;
int main() {
    int n, k;
    while(cin >> n >> k){
        int iloscSpalonychPapierosow = n;
        int niedopalki = 0;
        while (n) {
            niedopalki += n;
            n = niedopalki / k;
            niedopalki %= k;
            iloscSpalonychPapierosow += n;
        }
        cout << iloscSpalonychPapierosow << endl;
    }
}
