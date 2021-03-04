#include <bits/stdc++.h>

using namespace std;

void resp(long long int n){
	long long int res = 0;
	while(n){
		res += n * (n + 1) / 2;
		n--;
	}
	
	cout << res << endl;
}

int main(){
	long long int t, n;
	cin >> t;
	
	while(t--){
		cin >> n;
		resp(n);
	}
	
	return 0;
}
