#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int potegaDwojki(int potega);
bool dzieleniePrzezPotegiDwojki(string mojaLiczba, int potega);
bool dzieleniePrzez3(string mojaLiczba);
bool dzieleniePrzez5(string mojaLiczba);
bool dzieleniePrzez6(string mojaLiczba);
bool dzieleniePrzez7(string mojaLiczba);
bool dzieleniePrzez9(string mojaLiczba);
bool dzieleniePrzez10(string mojaLiczba);
bool dzieleniePrzez11(string mojaLiczba);
bool dzieleniePrzez12(string mojaLiczba);
bool dzieleniePrzez13(string mojaLiczba);
bool dzieleniePrzez14(string mojaLiczba);
bool dzieleniePrzez15(string mojaLiczba);
bool dzieleniePrzez17(string mojaLiczba);
void sprawdzenieDzielenia(string mojaLiczba);
string dodawanieDwochStringow(string liczba1, string liczba2);

int main(){
    string liczba;
    while(cin >> liczba) {
        sprawdzenieDzielenia(liczba);
    }
}

bool dzieleniePrzezPotegiDwojki(string mojaLiczba, int potega) {
    string ostatnieCyfry;
    int liczbaInt;
    if(mojaLiczba.size() > potega) {
        ostatnieCyfry = mojaLiczba.substr(mojaLiczba.size() - (potega + 1), potega + 1);
        liczbaInt = strtol(ostatnieCyfry.c_str(), NULL, 10);
    } else {
        liczbaInt = strtol(mojaLiczba.c_str(), NULL, 10);
    }
    if(liczbaInt%potegaDwojki(potega) == 0) return true;
    else                                    return false;
}

bool dzieleniePrzez3(string mojaLiczba){
    int cyfryLiczby[mojaLiczba.size()];
    int sumaCyfr = 0;
    string cyfra;
    for(int i = 0; i < mojaLiczba.size(); ++i) {
        cyfra = mojaLiczba[i];
        cyfryLiczby[i] = strtol(cyfra.c_str(), NULL, 10);
        sumaCyfr += cyfryLiczby[i];
    }
    if(sumaCyfr%3 == 0) return true;
    else                return false;
}

bool dzieleniePrzez5(string mojaLiczba){
    if((mojaLiczba[mojaLiczba.size() - 1] == '5') ||
       (mojaLiczba[mojaLiczba.size() - 1] == '0')) return true;
    else                                           return false;
}

bool dzieleniePrzez6(string mojaLiczba){
    if(dzieleniePrzezPotegiDwojki(mojaLiczba, 1) && dzieleniePrzez3(mojaLiczba))    return true;
    else                                                                            return false;
}

bool dzieleniePrzez7(string mojaLiczba){
    int liczbaInt;
    if(mojaLiczba.size() < 4) {
        liczbaInt = strtol(mojaLiczba.c_str(), NULL, 10);
    } else{
        string ostatniaCyfra;
        int ostatniaLiczba;
        for(int i = mojaLiczba.size() - 1; ; --i){
            if(mojaLiczba.size() < 4) break;
            ostatniaCyfra = mojaLiczba[mojaLiczba.size()-1];
            ostatniaLiczba = (strtol(ostatniaCyfra.c_str(), NULL, 10)) * 5;
            ostringstream ss;
            ss << ostatniaLiczba;
            string ostatniaLiczbaString = ss.str();
            mojaLiczba = mojaLiczba.erase(mojaLiczba.size() - 1, 1);
            mojaLiczba = dodawanieDwochStringow(mojaLiczba, ostatniaLiczbaString);
        }
        liczbaInt = strtol(mojaLiczba.c_str(), NULL, 10);
    }
    if(liczbaInt%7 == 0) return true;
    else                  return false;
}

bool dzieleniePrzez9(string mojaLiczba){
    int cyfryLiczby[mojaLiczba.size()];
    int sumaCyfr = 0;
    string cyfra;
    for(int i = 0; i < mojaLiczba.size(); ++i) {
        cyfra = mojaLiczba[i];
        cyfryLiczby[i] = strtol(cyfra.c_str(), NULL, 10);
        sumaCyfr += cyfryLiczby[i];
    }
    if(sumaCyfr%9 == 0) return true;
    else                return false;
}

bool dzieleniePrzez10(string mojaLiczba){
    if(mojaLiczba[mojaLiczba.size() - 1] == '0') return true;
    else                                         return false;
}

bool dzieleniePrzez11(string mojaLiczba){
    int sumaParzysta = 0, sumaNieparzysta = 0, cyfraInt;
    string jednaCyfra;
    for(int i = mojaLiczba.size() - 1; i >= 0; --i) {
        jednaCyfra = mojaLiczba[i];
        cyfraInt = strtol(jednaCyfra.c_str(), NULL, 10);
        if(i%2 == 0){
            sumaParzysta += cyfraInt;
        } else if(i%2 == 1){
            sumaNieparzysta += cyfraInt;
        }
    }
    if((sumaParzysta - sumaNieparzysta)%11 == 0) return true;
    else                                         return false;
}

bool dzieleniePrzez12(string mojaLiczba){
    if(dzieleniePrzez3(mojaLiczba) && dzieleniePrzezPotegiDwojki(mojaLiczba, 2)) return true;
    else                                                           return false;
}

bool dzieleniePrzez13(string mojaLiczba){
    int liczbaInt;
    if(mojaLiczba.size() < 4) {
        liczbaInt = strtol(mojaLiczba.c_str(), NULL, 10);
    } else{
        string ostatniaCyfra;
        int ostatniaLiczba;
        for(int i = mojaLiczba.size() - 1; ; --i){
            if(mojaLiczba.size() < 4) break;
            ostatniaCyfra = mojaLiczba[mojaLiczba.size()-1];
            ostatniaLiczba = (strtol(ostatniaCyfra.c_str(), NULL, 10)) * 4;
            ostringstream ss;
            ss << ostatniaLiczba;
            string ostatniaLiczbaString = ss.str();
            mojaLiczba = mojaLiczba.erase(mojaLiczba.size() - 1, 1);
            mojaLiczba = dodawanieDwochStringow(mojaLiczba, ostatniaLiczbaString);
        }
        liczbaInt = strtol(mojaLiczba.c_str(), NULL, 10);
    }
    if(liczbaInt%13 == 0) return true;
    else                  return false;
}

bool dzieleniePrzez14(string mojaLiczba){
    if(dzieleniePrzezPotegiDwojki(mojaLiczba, 1) && dzieleniePrzez7(mojaLiczba)) return true;
    else                                                           return false;
}

bool dzieleniePrzez15(string mojaLiczba){
    if(dzieleniePrzez3(mojaLiczba) && dzieleniePrzez5(mojaLiczba)) return true;
    else                                                           return false;
}

bool dzieleniePrzez17(string mojaLiczba){
    int liczbaInt;
    if(mojaLiczba.size() < 4) {
        liczbaInt = strtol(mojaLiczba.c_str(), NULL, 10);
    } else{
        string ostatniaCyfra;
        int ostatniaLiczba;
        for(int i = mojaLiczba.size() - 1; ; --i){
            if(mojaLiczba.size() < 4) break;
            ostatniaCyfra = mojaLiczba[mojaLiczba.size()-1];
            ostatniaLiczba = (strtol(ostatniaCyfra.c_str(), NULL, 10)) * 12;
            ostringstream ss;
            ss << ostatniaLiczba;
            string ostatniaLiczbaString = ss.str();
            mojaLiczba = mojaLiczba.erase(mojaLiczba.size() - 1, 1);
            mojaLiczba = dodawanieDwochStringow(mojaLiczba, ostatniaLiczbaString);
        }
        liczbaInt = strtol(mojaLiczba.c_str(), NULL, 10);
    }
    if(liczbaInt%17 == 0) return true;
    else                  return false;
}

void sprawdzenieDzielenia(string mojaLiczba) {
    bool podzielnaPrzezCokolwiek = false;
    string wyrazenie = "Liczba jest podzielna przez: \n";
    if(dzieleniePrzezPotegiDwojki(mojaLiczba, 1))  { wyrazenie = wyrazenie + "2 "; podzielnaPrzezCokolwiek = true; }
    if(dzieleniePrzez3(mojaLiczba)) { wyrazenie = wyrazenie + "3 "; podzielnaPrzezCokolwiek = true; }
    if(dzieleniePrzezPotegiDwojki(mojaLiczba, 2)) { wyrazenie = wyrazenie + "4 "; podzielnaPrzezCokolwiek = true; }
    if(dzieleniePrzez5(mojaLiczba)) { wyrazenie = wyrazenie + "5 "; podzielnaPrzezCokolwiek = true; }
    if(dzieleniePrzez6(mojaLiczba)) { wyrazenie = wyrazenie + "6 "; podzielnaPrzezCokolwiek = true; }
    if(dzieleniePrzez7(mojaLiczba)) { wyrazenie = wyrazenie + "7 "; podzielnaPrzezCokolwiek = true; }
    if(dzieleniePrzezPotegiDwojki(mojaLiczba, 3)) { wyrazenie = wyrazenie + "8 "; podzielnaPrzezCokolwiek = true; }
    if(dzieleniePrzez9(mojaLiczba)) { wyrazenie = wyrazenie + "9 "; podzielnaPrzezCokolwiek = true; }
    if(dzieleniePrzez10(mojaLiczba)) { wyrazenie = wyrazenie + "10 "; podzielnaPrzezCokolwiek = true; }
    if(dzieleniePrzez11(mojaLiczba)) { wyrazenie = wyrazenie + "11 "; podzielnaPrzezCokolwiek = true; }
    if(dzieleniePrzez12(mojaLiczba)) { wyrazenie = wyrazenie + "12 "; podzielnaPrzezCokolwiek = true; }
    if(dzieleniePrzez13(mojaLiczba)) { wyrazenie = wyrazenie + "13 "; podzielnaPrzezCokolwiek = true; }
    if(dzieleniePrzez14(mojaLiczba)) { wyrazenie = wyrazenie + "14 "; podzielnaPrzezCokolwiek = true; }
    if(dzieleniePrzez15(mojaLiczba)) { wyrazenie = wyrazenie + "15 "; podzielnaPrzezCokolwiek = true; }
    if(dzieleniePrzezPotegiDwojki(mojaLiczba, 4)) { wyrazenie = wyrazenie + "16 "; podzielnaPrzezCokolwiek = true; }
    if(dzieleniePrzez17(mojaLiczba)) { wyrazenie = wyrazenie + "17 "; podzielnaPrzezCokolwiek = true; }

    if(podzielnaPrzezCokolwiek) {
        cout << wyrazenie << endl;
    } else {
        cout << "Liczba nie jest podzielna przez zadna liczbe z zakresu 2-17." << endl;
    }
}

int potegaDwojki(int potega) {
    int wynik = 1;
    for(int i = 0; i < potega; ++i) {
    wynik *= 2;
    }
    return wynik;
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
