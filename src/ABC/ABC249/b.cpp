#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repi(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

int main() {
    string s;
    cin >> s;
    set<char> a;
    bool large = false;
    bool small = false;
    rep(i, s.size()) {
        if (islower(s[i])) small = true;
        if (isupper(s[i])) large = true;
        a.insert(s[i]);
    };
    if (small && large && a.size() == s.size()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
