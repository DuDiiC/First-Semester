#include <iostream>
#include <string>
using namespace std;

bool czyLitera(char znak){
    if((znak > 64 && znak < 91) || (znak > 96 && znak < 123)) return true;
    else return false;
}

string konwersjaSlow(string &slowo) {
    if(slowo[0] == 'a' || slowo[0] == 'A' || slowo[0] == 'e' || slowo[0] == 'E' ||
        slowo[0] == 'i' || slowo[0] == 'I' || slowo[0] == 'u' || slowo[0] == 'U' ||
        slowo[0] == 'o' || slowo[0] == 'O') {
        slowo = slowo + "ay";
    } else {
        char poczatek = slowo[0];
        slowo = slowo.substr(1);
        slowo = slowo + poczatek + "ay";
    }
    return slowo;
}

int main() {
    string zdanie, zdanieKoncowe;
    while(getline(cin, zdanie)) {

        zdanieKoncowe = "";
        for(int i = 0; i < zdanie.size();) {
            string slowo = "";
            if(czyLitera(zdanie[i])) {
                while(czyLitera(zdanie[i]) && i < zdanie.size()) {
                    slowo += zdanie[i];
                    ++i;
                }
                slowo = konwersjaSlow(slowo);
                zdanieKoncowe += slowo;
            } else {
                zdanieKoncowe += zdanie[i];
                ++i;
            }
        }
        cout << zdanieKoncowe << endl;
    }
}
