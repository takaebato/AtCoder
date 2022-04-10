#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = j; i < (int)(n); i++)

int main() {
    int Q;
    cin >> Q;
    vector<vector<int>> q(Q, vector<int>(3));
    rep(i, Q) {
        cin >> q[i][0];
        if (q[i][0] == 1) {
            cin >> q[i][1];
        } else {
            cin >> q[i][1] >> q[i][2];
        }
    }
    priority_queue<int> que;
    vector<int> ans(0);
    rep(i, Q) {
        if (q[0] == 1) {
            que.push(q[i][1])
        } else if (q[0] == 2) {
            ans.push_back()
        }
    }
}
