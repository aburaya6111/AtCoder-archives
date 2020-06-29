#pragma region Macros
/**
 * @author uesugi
 * @file AtCoder用テンプレート
 */

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

/**
 * 最大値更新
 * @param T &a 更新対象
 * @param const T &b 判定対象
 * @return 更新有無
 */
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

/**
 * 最小値更新
 * @param T &a 更新対象
 * @param const T &b 判定対象
 * @return 更新有無
 */
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

/**
 * overload
 * 入力を配列に格納
 * 配列の長さ分入力を格納
 * @param std::istream &is 入力ストリーム
 * @param std::vector<T> &vec 格納先配列
 * @return std::istream 
 */
template <typename T>
std::istream &operator>>(std::istream &is, std::vector<T> &vec) {
    for (T &element : vec) {
        is >> element;
    }
    return is;
}

/**
 * overload
 * コンテナの要素を出力する
 * @param std::basic_ostream<Ch, Tr> &os 出力ストリーム
 * @param Container const &x 出力対象コンテナ
 * @return std::basic_ostream<Ch, Tr> 
 */
template <class Ch, class Tr, class Container>
std::basic_ostream<Ch, Tr> &operator<<(std::basic_ostream<Ch, Tr> &os, Container const &x) {
    bool first = true;
    for (auto &y : x) {
        if (first) {
            first = false;
        } else {
            os << " ";
        }
        os << y;
    }
    return os;
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
/**
 * デバッグ用出力メソッド
 * 変数名及び値を出力
 * -D_DEBUG オプション付きビルド時のみ有効
 * @param 可変長引数
 */
#define debug(...)                                                        \
    CHOOSE((__VA_ARGS__, debug_5, debug_4, debug_3, debug_2, debug_1, ~)) \
    (__VA_ARGS__)
#else
#define debug(...)
#endif

#pragma endregion

/**
 * 処理
 * @return void
 */
void Main() {
    int N;
    cin >> N;
}

#pragma region main
/**
 * main
 * 共通処理
 * @return signed
 */
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << std::fixed;
    cout.precision(20);
    Main();
    cout << flush;
}
#pragma endregion
