#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
using namespace std;

// 参照渡しを用いて、呼び出し側の変数の値を変更する
void saiten(vector<vector<int>> &vvci, int &cc, int &wc) {
    // 呼び出し側のAの各マスを正しい値に修正する
    // Aのうち、正しい値の書かれたマスの個数を correct_count に入れる
    // Aのうち、誤った値の書かれたマスの個数を wrong_count に入れる

    // ここにプログラムを追記

    REP(i, 9) {
        REP(j, 9) {
            if (vvci[i][j] == (i + 1) * (j + 1)) {
                cc++;
            } else {
                vvci[i][j] = (i + 1) * (j + 1);
                wc++;
            }
        }
    }
}

void Main() {
    // A君の回答を受け取る
    vector<vector<int>> A(9, vector<int>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> A.at(i).at(j);
        }
    }

    int correct_count = 0;  // ここに正しい値のマスの個数を入れる
    int wrong_count = 0;    // ここに誤った値のマスの個数を入れる

    // A, correct_count, wrong_countを参照渡し
    saiten(A, correct_count, wrong_count);

    // 正しく修正した表を出力
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << A.at(i).at(j);
            if (j < 8)
                cout << " ";
            else
                cout << endl;
        }
    }
    // 正しいマスの個数を出力
    cout << correct_count << endl;
    // 誤っているマスの個数を出力
    cout << wrong_count << endl;
}

int main() {
    cin.tie(0);
    Main();
}
