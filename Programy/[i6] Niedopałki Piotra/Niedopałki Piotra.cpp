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
}
JAKIŒ B£¥D KTOREGO NIE MOGE ZNALEZC
int main() {
    int n, k;
    while(cin >> n >> k) {
            int iloscSpalonychPapierosow = n;
            int iloscDodatkowychNiedopalkow = 0;
            while((int)n/k != 0) {
                int iloscPapierosowZNiedopalkow = n / k;
                if(n == k  && iloscDodatkowychNiedopalkow + 1 == k){
                    n += iloscPapierosowZNiedopalkow;
                }
                iloscDodatkowychNiedopalkow += (n%k);
                if(iloscDodatkowychNiedopalkow == k) {
                    iloscPapierosowZNiedopalkow++;
                    iloscDodatkowychNiedopalkow = 0;
                } else if(iloscDodatkowychNiedopalkow > k) {
                    iloscPapierosowZNiedopalkow++;
                    iloscDodatkowychNiedopalkow -= k;
                }
                iloscSpalonychPapierosow += iloscPapierosowZNiedopalkow;
                n = iloscPapierosowZNiedopalkow;
            }
        cout << iloscSpalonychPapierosow << endl;
    }
}
*/
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
