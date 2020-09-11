#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e14;
using Graph = vector<vector<int>>;

signed main() {
    int N, K;
    cin >> N >> K;

    vector<int> plus;
    vector<int> minus;
    int kake = 1;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        if (A > 0)
            plus.push_back(A);
        else
            minus.push_back(A);
        kake *= A;
        kake %= MOD;
    }

    if (N == K) {
        kake %= MOD;
        if (kake < 0) kake += MOD;
        cout << kake << endl;
        return 0;
    }

    sort(plus.rbegin(), plus.rend());

    int ans = 1;
    //正の数が1つもなかったら
    int m = (int)minus.size();
    if (plus.size() == 0) {
        if (K % 2 == 1) {
            sort(minus.rbegin(), minus.rend());
            for (int i = 0; i < K; i++) {
                ans *= minus[i];
                ans %= MOD;
            }
        } else {
            sort(minus.begin(), minus.end());
            for (int i = 0; i < min(K, m); i++) {
                ans *= minus[i];
                ans %= MOD;
            }
            if (minus.size() < K) {
                cout << 0 << endl;
                return 0;
            }
        }
    } else {  //正の数が一つ以上あったら
        sort(minus.begin(), minus.end());
        int cnt = 0;
        int pnow = 0;
        int mnow = 0;
        if (K % 2 == 1) {
            ans *= plus[0];
            ans %= MOD;
            pnow++;
            cnt++;
        }
        while (cnt < K) {
            int pkouho = -1;
            int mkouho = -1;
            if (pnow + 1 < K) {
                pkouho = plus[pnow] * plus[pnow + 1];
                pkouho %= MOD;
            }
            if (mnow + 1 < K) {
                mkouho = minus[mnow] * minus[mnow + 1];
                mkouho %= MOD;
            }
            if (pkouho > mkouho) {
                ans *= pkouho;
                ans %= MOD;
                pnow += 2;
            } else {
                ans *= mkouho;
                ans %= MOD;
                mnow += 2;
            }
            cnt += 2;
        }
    }

    if (ans < 0) {
        ans %= MOD;
        ans += MOD;
    }

    cout << ans << endl;
}
