/*  Zad. Slaby przywodca ciagu
 *  Maciej Dudek
 */

#include <iostream>
using namespace std;

int i, j;

int main() {
    //definiujemy i inicjalizujemy potrzebne zmienne
    int n, k;
    cout << "Podaj rozmiar tablicy: ";
    cin >> n;
    cout << "Podaj wartosc parametru k: ";
    cin >> k;
    int tab[n];
    cout << "Podaj wartosci elementow tablicy: ";
    for(i = 0; i < n; ++i) cin >> tab[i];
    //zmienna ile przechowuje wiadomosc na temat tego ile razy musi dana liczba
    //wystapic w tablicy, aby byc slabym przywodca
    int ile = n/k + 1;
    //zmienna maks przechowuje ilosc potencjalnych slabych przywodcow
    int maksPrzywodcow = n/ile;
    //tablica przywodcy[] przechowuje liczby mogace byc slabymi przywodcami,
    //a tablica licznikPrzywodcy[] ilosc ich wystapien w tablicy
    int przywodcy[maksPrzywodcow];
    int licznikPrzywodcy[maksPrzywodcow];
    //wstepnie trzeba wyzerowac liczniki dla wszystkich potencjalnych przywodcow
    for(i = 0; i < maksPrzywodcow; ++i) licznikPrzywodcy[i] = 0;

    for(i = 0; i < n; ++i) { //petla zewnetrzna iteruje po elementach wyjsciowej tablicy
        for(j = 0; j < maksPrzywodcow; ++j) { //petla wewnetrzna iteruje po ilosci potencjalnych slabych przywodcow
            if(licznikPrzywodcy[j] == 0) {
                //w przypadku gdy jakis licznik jest pusty, tj. dla danego j nie ma wskazanego potencjalnego przywodcy,
                //ustalamy i-ty element tab jako przywodce i zwiekszamy o 1 ilosc wystapien
                przywodcy[j] = tab[i];
                ++licznikPrzywodcy[j];
                break;
            } else if(przywodcy[j] == tab[i]) {
                //w przypadku gdy natrafimy na liczbe, ktora jest juz potencjalnym przywodca, po prostu zwiekszamy ilosc
                //wystapien w petli
                ++licznikPrzywodcy[j];
                break;
            } else if(j == maksPrzywodcow - 1) {
                //w innym przypadku niz dwa pozostale mamy sytuacje, gdy jakby "pozbywamy sie" wszystkich rozniacych sie
                //potencjalnych przywodcow, w mysl zasady, ze usuniecie maks roznych elementow nie zmienia ilosci przywodcow
                for(j = 0; j < maksPrzywodcow; ++j) {
                    --licznikPrzywodcy[j];
                }
                //oczywiscie w tym momencie zmniejszamy tez ilosc potrzebnych wystapien slabych przywodcow w tablicy o 1
                --ile;
            }
        }
    }
    //teraz wypisanie wszystkich potencjalnych przywodcow, ktorzy wystapili w tablicy tyle razy, ile potrzeba, zeby
    //byc slabym przywodca
    cout << "Slabi przywodcy to: ";
    for(i = 0; i < maksPrzywodcow; ++i) {
        if(licznikPrzywodcy[i] >= ile) cout << przywodcy[i] << " ";
    }
    cout << endl;
}
