#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string wyraz;
    while(cin >> wyraz && wyraz != "#") {
        bool zmienna = next_permutation(wyraz.begin(), wyraz.end());
        if(zmienna) cout << wyraz << endl;
        else cout << "No Successor" << endl;
    }
}
