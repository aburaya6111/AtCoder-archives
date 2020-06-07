#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
using namespace std;

void Main() {
    vector<int> inputVec(5);

    REP(i, 5) {
        cin >> inputVec[i];
    }

    string result = "NO";
    REP(i, 4) {
        if (inputVec[i] == inputVec[i + 1]) {
            result = "YES";
            break;
        }
    }

    cout << result << endl;
}

int main() {
    Main();
}
