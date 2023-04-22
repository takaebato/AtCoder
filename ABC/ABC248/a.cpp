#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    string S;
    cin >> S;
    vector<int> a(10, 0);
    rep(i, S.size()) a[int(S[i] - '0')] = 1;
    rep(i, 10) {
        if (a[i] == 0) cout << i << endl;
    }
}
