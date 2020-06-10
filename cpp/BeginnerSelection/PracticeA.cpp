#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
using namespace std;

void Main() {
    vector<int> input(3);

    REP(i, 3) {
        cin >> input[i];
    }
    string inputStr;
    cin >> inputStr;

    int sum = 0;
    REP(i, 3) {
        sum += input[i];
    }
    cout << sum << " " << inputStr << endl;
}

int main() {
    cin.tie(0);
    Main();
}
