#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    /*
      n<=10^5, q<=5*10^4
      BF：q*n=10^9.
      探索はそのままで、判定を二分探索で効率化という感じか.
    */
    int N, q;
    cin >> N;
    vector<int> s(N);
    rep(i, N) cin >> s[i];
    sort(s.begin(), s.end());
    cin >> q;
    int cnt = 0;
    int x;
    rep(i, q) {
        cin >> x;
        if (binary_search(s.begin(), s.end(), x)) cnt++;
    }
    cout << cnt << endl;
}
