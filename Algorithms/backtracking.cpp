#include <bits/stdc++.h>

using namespace std;

void backtracking(int n, int acum, vector <int> vec, int i){
	if(acum == n){
		cout << i << endl;
		return;
	}
	else if(i == vec.size()){
		cout << i << endl;
		return;
	}
	else if(acum > n){
		cout << vec[i] << endl;
		return;
	}

	backtracking(n, acum, vec, i + 1);
	backtracking(n, acum + vec[i], vec, i + 1);

}

int main(){
	vector <int> vec;
	int n;
	cin >> n;

	int i = 0;
	while(i <= n)
		vec.push_back(++i);

	backtracking(4, 0, vec, 0);

	return 0;
}