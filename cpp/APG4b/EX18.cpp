#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
using namespace std;

void Main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> input(M, vector<int>(2));
    REP(i, M) {
        cin >> input[i][0] >> input[i][1];
    }

    vector<vector<string>> result(N, vector<string>(N, "-"));

    REP(i, M) {
        result[input[i][0]-1][input[i][1]-1] = "o";
        result[input[i][1]-1][input[i][0]-1] = "x";
    }

    REP(i, N) {
        REP(j, N) {
            cout << result[i][j];
            if (j != N-1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

int main() {
    Main();
}
