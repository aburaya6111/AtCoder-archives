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

const string s_int = "int";
const string s_print_int = "print_int";
const string s_vec = "vec";
const string s_print_vec = "print_vec";

map<string, int> intMap;
map<string, vi> viMap;

bool is_number(const std::string &s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int getInt(string s) {
    if (is_number(s)) {
        return stoi(s);
    } else {
        return intMap[s];
    }
}

int ope_int(vector<string> &line, int start) {
    int buff = getInt(line[start]);
    for (int i = start + 1; i < line.size(); i += 2) {
        if (line[i] == "+") {
            buff += getInt(line[i + 1]);

        } else if (line[i] == "-") {
            buff -= getInt(line[i + 1]);
        }
    }

    return buff;
}
void ope_print_int(vector<string> &line) {
    cout << ope_int(line, 1) << "\n";
}

void aaaa() {
}
void minusvi(vi &a, vi b) {
    REP(i, SIZE(a)) {
        a[i] -= b[i];
    }
    return;
}
void plusvi(vi &a, vi b) {
    REP(i, SIZE(a)) {
        a[i] += b[i];
    }
    return;
}

void signsign(vi &a, int sign) {
    REP(i, SIZE(a)) {
        a[i] *= sign;
    }
}

vi ope_vec(vector<string> &line, int start, int sign) {
    vi buff;
    int count = start;
    if (viMap.count(line[start])) {
        buff = viMap[line[start]];
    } else {
        for (int i = start; i < line.size(); i += 2) {
            if (line[i] == "]") {
                count = i;
                break;
            }
            buff.push_back(getInt(line[i + 1]));
        }
    }

    signsign(buff, sign);

    if (line[count + 1] == "+") {
        plusvi(buff, ope_vec(line, count + 2, 1));
    } else if (line[count + 1] == "-") {
        plusvi(buff, ope_vec(line, count + 2, -1));
    }
    return buff;
}
void ope_print_vec(vector<string> &line) {
    vi vec = ope_vec(line, 1, 1);
    cout << "[ ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    }
    cout << "]"
         << "\n";
}

void Main() {
    int N;
    cin >> N;

    vector<vector<string>> input;

    string buff;
    REP(i, N + 1) {
        getline(cin, buff);
        stringstream ss(buff);
        string buff2;
        vector<string> line;
        while (getline(ss, buff2, ' ')) {
            line.push_back(buff2);
        }
        if (line.size() > 0) {
            input.push_back(line);
        }
    }

    for (auto in : input) {
        if (in[0] == s_int) {
            intMap[in[1]] = ope_int(in, 3);
            debug(intMap[in[1]]);
        }
        if (in[0] == s_print_int) {
            ope_print_int(in);
        }
        if (in[0] == s_vec) {
            viMap[in[1]] = ope_vec(in, 3, 1);
            debug(in[1], viMap[in[1]][0], viMap[in[1]][1]);
        }
        if (in[0] == s_print_vec) {
            ope_print_vec(in);
        }
    }
    debug(buff);
}

#pragma region main
main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Main();
    cout << flush;
}
#pragma endregion
