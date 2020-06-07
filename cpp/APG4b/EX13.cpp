#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> input(N);
    REP(i, N) {
        cin >> input[i];
    }

    int average = accumulate(input.begin(), input.end(), 0) / N;

    REP(i, N) {
        cout << abs(input[i] - average) << endl;
    }
}
