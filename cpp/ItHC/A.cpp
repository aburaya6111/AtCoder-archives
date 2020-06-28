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
template <class T>
ostream &operator<<(ostream &out, vector<T> const &v) {
    for (auto &&a : v) out << a << " ";
    out << endl;
    return out;
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
    int D;
    cin >> D;

    vector<pair<int, int>> c;
    REP(i, 26) {
        int aaaa;
        cin >> aaaa;
        c.push_back({aaaa, i + 1});
    }
    sort(ALL(c), greater<pair<int, int>>());
    vector<vector<pair<int, int>>> s(D, vector<pair<int, int>>());
    int buff;
    REP(i, D) {
        REP(j, 26) {
            cin >> buff;
            s[i].push_back({buff, j + 1});
        }
    }
    int count = 0;
    REP(i, D) {
        set<int> set26;
        REP(j, 26) {
            set26.insert(j + 1);
        }
        while (!set26.empty()) {
            vector<pair<int, int>> sss = s[count];
            sort(ALL(sss), greater<pair<int, int>>());
            int a = 1;
            REP(k, 26) {
                if (rand() % 10 < 1) {
                    a = 0;
                    REP(l, 10) {
                        if (set26.count(c[l].second)) {
                            a = c[l].second;
                            debug("aaaaa", a);
                            break;
                        }
                    }
                    if (a == 0) {
                        a = 1;
                    } else {
                        break;
                    }
                }
                if (set26.count(sss[k].second)) {
                    a = sss[k].second;
                    debug(sss[k].second);
                    break;
                }
            }

            cout << a << "\n";
            set26.erase(a);
            debug(a);
            count++;
            if (count >= D) {
                return;
            }
        }
    }
}

#pragma region main
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Main();
    cout << flush;
}
#pragma endregion
