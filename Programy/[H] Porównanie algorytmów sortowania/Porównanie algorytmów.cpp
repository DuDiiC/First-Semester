#include <stdio.h>
#include <iostream>

using namespace std;

int bsort(int *tab, int rozm) {
	int licz, pom, t, j;
	int zliczacz = 0;

	licz=rozm-1;
	t=0;

	while(t!=-1) {
		t=-1;

		for(j=0;j<licz;j++){
            zliczacz++;
			if (tab[j]>tab[j+1]) {
				pom=tab[j];
				tab[j]=tab[j+1];
				tab[j+1]=pom;
				t=j;
			}
		}
		licz=t;
	}
	return zliczacz;
}

void dziel(int c, int b, int *tab, int &zliczacz) {
      int x, i, j, pom;

      if(c>=b)
	  return;

      x=tab[c];
      j=b+1;
      i=c-1;

      while(i<j) {
         for(j-=1;tab[j]>x;j--){zliczacz++;};
         zliczacz++;
         for(i+=1;tab[i]<x;i++){zliczacz++;};
         zliczacz++;

	     if(i<j) {
	        pom=tab[i];
	        tab[i]=tab[j];
	        tab[j]=pom;
	     }
      }

      dziel(c,j,tab, zliczacz);
      dziel(j+1,b,tab, zliczacz);
    }

int main() {
    int N; cin >> N;
    int tablica[N], tablica2[N];
    for(int i = 0; i < N; ++i){
        cin >> tablica[i];
        tablica2[i] = tablica[i];
    }
    int dlaB = bsort(tablica, N);
    int zliczacz = 0;
    dziel(0, N-1, tablica2, zliczacz);
    int dlaQ = zliczacz;

    cout << "quick - " << dlaQ << endl;
    cout << "bubble - " << dlaB << endl;
}
