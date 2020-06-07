#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
using namespace std;

int main() {
    string str;
    cin >> str;

    int result = 1;
    REP(i, str.size()) {
        if (str.at(i) == '+') {
            result++;
        }
        if (str.at(i) == '-') {
            result--;
        }
    }

    cout << result << endl;
}
