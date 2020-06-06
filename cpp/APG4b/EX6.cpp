#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    string op;
    cin >> A >> op >> B;

    if (op == "+") {
        cout << A + B << endl;
        return 0;
    }
    if (op == "-") {
        cout << A - B << endl;
        return 0;
    }

    if (op == "*") {
        cout << A * B << endl;
        return 0;
    }

    if (op == "/") {
        if (B == 0) {
            cout << "error" << endl;
            return 0;
        }
        cout << A / B << endl;
        return 0;
    }
    cout << "error" << endl;
}