#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll sum = 0;

vector<int> merge(vector<int> vm1, vector<int> vm2){
	vector<int> vm;
	int j = 0;
	int k = 0;
	for(int i = 0; i < (vm1.size() + vm2.size()); i++){
		if(j == vm1.size()){
			vm.push_back(vm2[k]);
			k++;
			continue;
		}else if(k == vm2.size()){
			vm.push_back(vm1[j]);
			j++;
			continue;
		}
		if(vm1[j] > vm2[k]){
			vm.push_back(vm2[k]);
			sum += vm1.size() - j;
			k++;
		}else{
			vm.push_back(vm1[j]);
			j++;
		}
	}
	return vm;
}

vector<int> inv(vector<int> vec){
	if(vec.size() == 1) return vec;
	vector<int> v1, v2;
	for(int i = 0; i < vec.size(); i++){
		if(i < vec.size() / 2){
			v1.push_back(vec[i]);
		}else{
			v2.push_back(vec[i]);
		}
	}
	vector<int> vm1, vm2;
	vm1 = inv(v1);
	vector<int>().swap(v1);
	vm2 = inv(v2);
	vector<int>().swap(v2);
	return merge(vm1, vm2);
}


int main(){
	vector<int> v, vf;
	int temp = 0;
	for(int i = 0; i < 100000; i++){
		cin >> temp;
		v.push_back(temp);
	}
	vf = inv(v);
	for(int i = 0; i < 100000; i++){
		cout << vf[i] <<endl;
	}
	cout << sum <<endl;
}