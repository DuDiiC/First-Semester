#include <iostream>
#include <string>

using namespace std;

int main() {
    int k, q;
    string S, SS, T;
    cin >> k;
    for(int i = 0; i < k; ++i) {
        cin >> S;
        cin >> q;
        for(int j = 0; j < q; ++j) {
            cin >> T;
            SS = S.substr(0, T.size());
            if(SS == T)  cout << "y" << endl;
            else        cout << "n" << endl;
        }
    }
}
