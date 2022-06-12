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
    vec<int> a(N + 1);
    vec<int> b(N + 1);
    a[0] = 1;
    repg(i, 1, N + 1) {
        rep(k, i) {
            if (k == 0 || k == i - 1)
                b[k] = 1;
            else
                b[k] = a[k - 1] + a[k];
        }
        rep(k, i) { cout << b[k] << ' '; }
        cout << endl;
        swap(a, b);
    }
}
