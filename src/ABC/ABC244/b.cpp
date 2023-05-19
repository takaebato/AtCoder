#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

int main() {
    int n;
    string t;
    cin >> n >> t;

    char dir = 'E';
    int x = 0;
    int y = 0;

    rep(i, n) {
        if (t[i] == 'R') {
            switch (dir) {
                case 'E':
                    dir = 'S';
                    break;
                case 'S':
                    dir = 'W';
                    break;
                case 'W':
                    dir = 'N';
                    break;
                case 'N':
                    dir = 'E';
                    break;
            }
        } else if (t[i] == 'S') {
            switch (dir) {
                case 'E':
                    x++;
                    break;
                case 'S':
                    y--;
                    break;
                case 'W':
                    x--;
                    break;
                case 'N':
                    y++;
                    break;
            }
        }
    }
    cout << x << " " << y << endl;
}
