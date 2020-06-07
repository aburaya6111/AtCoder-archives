#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
using namespace std;

void Main() {
    int N, S;
    cin >> N >> S;
    vector<int> A(N), P(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    for (int i = 0; i < N; i++) {
        cin >> P.at(i);
    }

    int count = 0;
    REP(i, A.size()) {
        REP(j, P.size()) {
            if (A[i] + P[j] == S) {
                count++;
            }
        }
    }

    cout << count << endl;
}

int main() {
    Main();
}
