#pragma region Macros

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;
using vvi = vector<vi>;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

// debug methods
// usage: debug(x,y);
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0, a1, a2, a3, a4, x, ...) x
#define debug_1(x1) cout << #x1 << ": " << x1 << endl
#define debug_2(x1, x2) cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << endl
#define debug_3(x1, x2, x3) cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " << x3 << endl
#define debug_4(x1, x2, x3, x4) cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " << x3 << ", " #x4 << ": " << x4 << endl
#define debug_5(x1, x2, x3, x4, x5) cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " << x3 << ", " #x4 << ": " << x4 << ", " #x5 << ": " << x5 << endl
#ifdef _DEBUG
#define debug(...)                                                        \
    CHOOSE((__VA_ARGS__, debug_5, debug_4, debug_3, debug_2, debug_1, ~)) \
    (__VA_ARGS__)
#else
#define debug(...)
#endif

#pragma endregion

// 以下に、24時間表記の時計構造体 Clock を定義する
struct Clock {
    int hour;    //時間を表す (0~23の値をとる)
    int minute;  //分を表す   (0~59の値をとる)
    int second;  //秒を表す   (0~59の値をとる)

    /* data */

    void set(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }

    string to_str() {
        ostringstream ss;
        ss << std::setw(2) << std::setfill('0') << hour << ":";
        ss << std::setw(2) << std::setfill('0') << minute << ":";
        ss << std::setw(2) << std::setfill('0') << second;
        string str(ss.str());

        return str;
    }

    void shift(int diff_second) {
        if (diff_second < 0) {
            diff_second += 86400;
        }

        int sec = hour * 3600 + minute * 60 + second;

        sec += diff_second;

        hour = (sec % (24 * 60 * 60)) / 3600;
        minute = (sec % (60 * 60)) / 60;
        second = sec % 60;
    }
};

// -------------------
// ここから先は変更しない
// -------------------

void Main() {
    // 入力を受け取る
    int hour, minute, second;
    cin >> hour >> minute >> second;
    int diff_second;
    cin >> diff_second;

    // Clock構造体のオブジェクトを宣言
    Clock clock;

    // set関数を呼び出して時刻を設定する
    clock.set(hour, minute, second);

    // 時刻を出力
    cout << clock.to_str() << endl;

    // 時計を進める(戻す)
    clock.shift(diff_second);

    // 変更後の時刻を出力
    cout << clock.to_str() << endl;
}

#pragma region main
main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Main();
    cout << flush;
}
#pragma endregion
