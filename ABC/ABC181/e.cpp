#include <bits/stdc++.h>
using ll = long long;
using rep(i,n) = for(int i = 0; i < (n); ++i)
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	int h[N], w[M];
	rep(i,N) cin >> h[i]
	rep(i,M) cin >> w[i]

	for(int i = 1; i < N - 1; i += 2){
		if(i == 1) lsum[i] = h[i] - h[i - 1];
		lsum[i] = lsum[i - 2] + h[i] - h[i - 1];
	}
	for(int i = N - 2; i > 0; i -= 2){
		if(i == N - 2) rsum[i] = h[i + 1] - h[i];
		rsum[i] = rsum[i + 2] + h[i + 1] - h[i];
	}
	
	return 0;
}