#include <iostream>
using namespace std;

struct wezel {
    wezel *nast;
    char dane;
};

struct kolejka {
    wezel *przod;
    wezel *tyl;
};

void inicjuj(kolejka &k) {
    k.przod = NULL;
}

void ustaw(kolejka &k, char nowy) {
    wezel *w = new wezel;
    w->dane = nowy;
    w->nast = NULL;
    if(k.przod == NULL) k.przod = w;
    else k.tyl->nast = w;
    k.tyl = w;
}

bool pusty(kolejka k) {
    return k.przod==NULL;
}

void wyjdz(kolejka k) {
    wezel* r = k.przod;
    if(!pusty(k)) {
        if(k.przod != k.tyl) {
            k.przod = k.przod->nast;
        }
        delete r;
    }
}

char przod(kolejka k) {
    if(!pusty(k)) {
        return k.przod->dane;
    } else return '\0';
}

void zniszcz(kolejka &k) {
    wezel* r = k.przod;
    while(k.przod != NULL) {
        r = r->nast;
        delete k.przod;
        k.przod = r;
    }
    k.tyl = k.przod;
}

int main() {
    kolejka Kolejka;
    inicjuj(Kolejka);
    if(pusty(Kolejka)) {
        cout << "Jestem tutaj! Taka pusta!" << endl;
    }
    ustaw(Kolejka, 'h');
    if(pusty(Kolejka)) {
        cout << "Nadal pusta" << endl;
    } else cout << "Mam element! Jest nim - " << przod(Kolejka) << endl;

}
