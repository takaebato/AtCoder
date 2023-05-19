#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define rep2(i, n) for (int i = 2; i < (int)(n); i++)

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    vector<int> B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    vector<int> diff1(N, 0);
    vector<int> diff2(N, 0);
    vector<int> diff3(N, 0);
    vector<int> diff4(N, 0);
    rep1(i, N) diff1[i] = abs(A[i - 1] - A[i]);
    rep1(i, N) diff2[i] = abs(B[i - 1] - A[i]);
    rep1(i, N) diff3[i] = abs(A[i - 1] - B[i]);
    rep1(i, N) diff4[i] = abs(B[i - 1] - B[i]);

    if (N == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    if (N == 2) {
        if (diff1[1] > K && diff2[1] > K && diff3[1] > K && diff4[1] > K) {
            cout << "No" << endl;
            return 0;
        } else {
            cout << "Yes" << endl;
            return 0;
        }
    }

    bool isA = false;
    bool isB = false;
    rep2(i, N) {
        if (diff1[i - 1] <= K || diff2[i - 1] <= K) {
            isA = true;
        } else {
            isA = false;
        }
        if (diff3[i - 1] <= K || diff4[i - 1] <= K) {
            isB = true;
        } else {
            isB = false;
        }

        if (isA && isB) {
            if (diff1[i] > K && diff2[i] > K && diff3[i] > K && diff4[i] > K) {
                cout << "No" << endl;
                return 0;
            }
        } else if (isA) {
            if (diff1[i] > K && diff3[i] > K) {
                cout << "No" << endl;
                return 0;
            }
        } else if (isB) {
            if (diff2[i] > K && diff4[i] > K) {
                cout << "No" << endl;
                return 0;
            }
        } else {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
