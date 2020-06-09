#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
using namespace std;

int array_sum(vector<int> &data, int i) {
    if (i == 0) {
        return 0;
    }
    return array_sum(data, i - 1) + data[i - 1];
}

int sum_range(int a, int b) {
    if (a == b) {
        return a;
    }
    return sum_range(a, b - 1) + b;
}

void Main() {
    vector<int> a = {0, 3, 9, 1, 5};
    cout << array_sum(a, a.size()) << endl;
    cout << sum_range(1, 50) << endl;
}

int main() {
    cin.tie(0);
    Main();
}
