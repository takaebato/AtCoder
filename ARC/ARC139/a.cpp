#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    int N;
    cin >> N;
    vector<bitset<40>> a('1');
    cout << a[0].to_ullong() << endl;

    // rep(i, N) {
    //     int t;
    //     cin >> t;
    //     bitset<40> tmp('1');
    //     a[i] = tmp << t;
    //     if (i == 0) continue;
    //     a[i] = a[i - 1] & (tmp << t);
    // }
    // cout << a[N - 1].to_ullong() << endl;
}
