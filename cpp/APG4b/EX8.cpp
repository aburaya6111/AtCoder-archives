#include <bits/stdc++.h>
using namespace std;

int main() {
    int p;
    cin >> p;

    string ans;
    if (p == 1) {
        int price, N;
        cin >> price >> N;
        cout << price * N << endl;
    } else {
        int price, N;
        string text;
        cin >> text >> price >> N;
        cout << text << "!" << endl
             << price * N << endl;
    }
}
