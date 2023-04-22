#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using ll = long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vector<T>>;
template <class T, class U>
using P = pair<T, U>;
#define pb push_back
#define eb emplace_back
#define em emplace
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n + 1); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

const int MOD = 1e9 + 7;
vector<long long> fact, fact_inv, inv;

void init_nCk(int SIZE) {
    fact.resize(SIZE + 5);
    fact_inv.resize(SIZE + 5);
    inv.resize(SIZE + 5);
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;

    for (int i = 2; i < SIZE + 5; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }
}

long long nCk(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fact[n] * (fact_inv[k] * fact_inv[n - k] % MOD) % MOD;
}

int main() {
    int X, Y;
    cin >> X >> Y;

    int stepX = (2 * X - Y) / 3;
    int stepY = (2 * Y - X) / 3;

    if ((X + Y) % 3 != 0 || stepX < 0 || stepY < 0) {
        cout << 0 << endl;
        return 0;
    }
    init_nCk(stepX + stepY);
    cout << nCk(stepX + stepY, stepX) << endl;
}
