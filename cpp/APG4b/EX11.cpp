#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
using namespace std;

int main() {
    int N, A;
    cin >> N >> A;

    string op;
    int B;

    string result;
    REP(i, N) {
        cin >> op >> B;

        if (op == "+") {
            result = to_string(A = A + B);
        }

        if (op == "-") {
            result = to_string(A = A - B);
        }

        if (op == "*") {
            result = to_string(A = A * B);
        }
        if (op == "/") {
            if (B == 0) {
                cout << "error" << endl;
                return 0;
            } else {
                result = to_string(A = A / B);
            }
        }

        cout << to_string(i + 1) << ":" << result << "\n";
    }
}
