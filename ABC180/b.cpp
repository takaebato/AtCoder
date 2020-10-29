#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	int x[N];
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	ll m = 0;
	ll tmp = 0;
	ll c = 0;
	
	for (int i = 0; i < N; i++) {
		m += abs(x[i]);
		tmp += ll(x[i]) * x[i];
		c = c > abs(x[i]) ? c: abs(x[i]);
	}
	cout << m << endl;
	printf("%.10f\n", sqrt(tmp));
	cout << c << endl;
}