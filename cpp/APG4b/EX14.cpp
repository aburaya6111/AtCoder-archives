#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int result = max(max(A, B), C) - min(min(A, B), C);

    cout << result << endl;
}
