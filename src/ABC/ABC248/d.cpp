#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

template <typename T>
vector<ll> dat(pow(10, 10), 0);
int cnt = 0;

int query_sub(int a, int b, int k, int l, int r, int x) {
    // k:現在見ているノードの位置  [l,r):dat[k]が表している区間
    if (r <= a || b <= l) {  // 範囲外なら考えない
        return 0;
    } else if (a <= l && r <= b) {  // 範囲内なので自身の値を返す
        if (dat[k] == x) cnt++;
        return dat[k];
    } else {  // 一部区間が被る時
        int vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
}

int query(int a, int b, int n, int x) { return query_sub(a, b, 0, 0, n, x); }

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    int Q;
    cin >> Q;
    rep(i, Q) {
        int l, r, x;
        cin >> l >> r >> x;
        cnt = 0;
        query(l, r, N, x);
        cout << cnt << endl;
    }
}
