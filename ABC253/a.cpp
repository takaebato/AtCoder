#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using ll = long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vector<T>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    vec<int> num(3);
    rep(i, 3) cin >> num[i];
    int b = num[1];
    sort(num.begin(), num.end());
    if (b == num[1])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
