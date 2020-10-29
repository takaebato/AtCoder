#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int main()
{
	ll N;
	cin >> N;
	ll sum = 0;
	ll a, b;
	for(ll i = 0; i < N; ++i)
	{
		cin >> a >> b;
		sum += (a + b)*(double)(b - a + 1)/2;
	}
	cout << sum << endl;
}