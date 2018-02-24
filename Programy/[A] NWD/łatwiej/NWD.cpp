#include <iostream>
using namespace std;

int NWD(int x, int y) {
        if(x<y) {
            int zmienna = x;
            x = y;
            y = zmienna;
        }
        while(y != 0) {
            int zmienna = x % y;
            x = y;
            y = zmienna;
        }

        return x;
}

int main() {

}
