#include <iostream>

using namespace std;

struct wezel {
    wezel *nast;
    char dane;
};

struct stos {
    wezel *wierzch;
};

void inicjuj(stos &s) {
    s.wierzch = NULL;
}

bool pusty(stos &s) {
    if(s.wierzch == NULL) return true;
    else return false;
}

void odloz(stos &s, char nowy) {
    wezel* r = new wezel;
    r->dane = nowy;
    r->nast = s.wierzch;
    s.wierzch = r;
}

void zdejmij(stos &s) {
    wezel* r = s.wierzch;
    if(!pusty(s)) {
        r = s.wierzch->nast;
    }
    delete s.wierzch;
    s.wierzch = r;
}

char obejrzyj_wierzch(stos s) {
    if(!pusty(s)) return s.wierzch->dane;
    else return '\0';
}

void zniszcz(stos &s) {
    wezel* r = s.wierzch;
    while(r != NULL) {
        r = r->nast;
        delete s.wierzch;
        s.wierzch = r;
    }
}

int main() {
    cout << "Tworzymy stos..." << endl;
    stos Stos;
    inicjuj(Stos);
    cout << "Stworzony!" << endl;
    odloz(Stos, 'y');
    cout << "Dodalem na stos nowy element - " << obejrzyj_wierzch(Stos) << endl;
    odloz(Stos, 'r');
    cout << "Dodalem na stos nowy element - " << obejrzyj_wierzch(Stos) << endl;
    odloz(Stos, 'j');
    cout << "Dodalem na stos nowy element - " << obejrzyj_wierzch(Stos) << endl;
    zdejmij(Stos);
    cout << "Zdjalem ze stosu, teraz na wierzchu jest - " << obejrzyj_wierzch(Stos) << endl;
    zniszcz(Stos);
    if(pusty(Stos)) {
        cout << "Stos jest pusty, usunalem cala jego zawartosc." << endl;
    } else cout << "Cos poszlo nie tak, stos caly czas istnieje." << endl;
}
