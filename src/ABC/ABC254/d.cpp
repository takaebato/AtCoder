#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using ll = long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vector<T>>;
template <class T>
using P = pair<T, T>;
#define push_back = pb;
#define emplace_back = eb;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    int N;
    cin >> N;
    ll cnt = 0;
    for (ll i = 1; i <= N * N; i *= i) {
        for (ll k = 1; k * k <= i; k++) {
            if (i % k == 0)
                if (k <= N && i / k <= N) cnt++;
        }
        i++;
    }
    cout << cnt << endl;
}
