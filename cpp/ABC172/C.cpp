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

void Main() {
    int N, M, K;
    cin >> N >> M >> K;
    queue<int> a;
    queue<int> b;

    int buff;
    REP(i, N) {
        cin >> buff;
        a.push(buff);
    }
    REP(i, M) {
        cin >> buff;
        b.push(buff);
    }

    int k = K;
    int count = 0;
    REP(i, N + M) {
        int buffff;
        int asize = SIZE(a);
        int bsize = SIZE(b);
        int af = a.front();
        int bf = b.front();

        if (asize > 0 && bsize > 0) {
            if (bf > af) {
                buffff = af;
                a.pop();
            } else {
                buffff = bf;
                b.pop();
            }
        } else if (asize > 0) {
            buffff = af;
            a.pop();
        } else if (bsize > 0) {
            buffff = bf;
            b.pop();
        } else {
            cout << count;
            return;
        }
        debug(buffff);

        if (k < buffff) {
            cout << count;
            return;
        }
        k -= buffff;

        count++;
        debug(count, k);
    }
    cout << count;
}

#pragma region main
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Main();
    cout << flush;
}
#pragma endregion
