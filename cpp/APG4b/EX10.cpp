#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    cout << "A:";
    REP(i, A) {
        cout << "]";
    }
    cout << endl;
    cout << "B:";
    REP(i, B) {
        cout << "]";
    }
    cout << endl;

}
