/*  Zad. Liczba inwersji w dwoch posortowanych tablicach
 *  Maciej Dudek
 */

#include <iostream>
using namespace std;

int i, j;

//funkcja sortujaca zadane tablice
void quickSort(int tab[], int s, int k) {
    int pktPodzialu, sortownik;
    if(s < k) {
        pktPodzialu = s;
        sortownik = tab[pktPodzialu];
        for(i = s+1; i<=k; ++i) {
            if(tab[i]<sortownik) {
                ++pktPodzialu;
                swap(tab[pktPodzialu], tab[i]);
            }
        }
        swap(tab[s], tab[pktPodzialu]);
        quickSort(tab, s, pktPodzialu-1);
        quickSort(tab, pktPodzialu+1, k);
    }
}

int main() {
    //definiujemy i inicjalizujemy potrzebne zmienne
    int rozA, rozB, liczbaInwersji = 0;
    cout << "Podaj rozmiar tablicy A: ";
    cin >> rozA;
    cout << "Podaj rozmiar tablicy B: ";
    cin >> rozB;
    int tabA[rozA], tabB[rozB];
    cout << "Podaj wartoœci elementow tablicy A: ";
    for(i = 0; i < rozA; ++i) cin >> tabA[i];
    cout << "Podaj wartosci elementow tablicy B: ";
    for(i = 0; i < rozB; ++i) cin >> tabB[i];
    //sortowanie podanych tablic
    quickSort(tabA, 0, rozA-1);
    quickSort(tabB, 0, rozB-1);
    //ustawienie iteratorow petli na koncu obu tablic
    i = rozA-1;
    j = rozB-1;
    //warunkiem wejscia do petli jest wyrazenie, ktore informuje, ze nie przeszlismy
    //jeszcze calej tablicy, ani pierwszej, ani drugiej
    while(i >= 0 && j >= 0) {
        //w momencie gdy zawartosc i-tego elementu tabA jest wieksza od zawartosci j-tego elementu tabB
        // nalezy dokonac inwersji - dokonuje od razu inwersji dla wszystkich mniejszych elementow tabB,
        //wiedzac, ze jest ona posortowana rosnaco
        if(tabA[i] > tabB[j]) {
            liczbaInwersji += (j+1);
            --i;
        //w przeciwnym wypadku zblizam sie do poczatku tabB i sprawdzam coraz to mniejsze elementy tablicy
        } else --j;
    }
    cout << "Liczba inwersji miedzy elementami posortowanych tablic A oraz B wynosi: "
         << liczbaInwersji << endl;
}
