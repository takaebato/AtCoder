#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = j; i < (int)(n); i++)

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    vector<bool> dp(N, false), ep(N, false);
    dp[0] = ep[0] = true;
    repg(i, 1, N) {
        if (dp[i - 1]) {
            if (abs(A[i - 1] - A[i]) <= K) dp[i] = true;
            if (abs(A[i - 1] - B[i]) <= K) ep[i] = true;
        }
        if (ep[i - 1]) {
            if (abs(B[i - 1] - A[i]) <= K) dp[i] = true;
            if (abs(B[i - 1] - B[i]) <= K) ep[i] = true;
        }
    }
    if (dp[N - 1] || ep[N - 1]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
