#include <bits/stdc++.h>

using namespace std;

map <int, int> memo;

int solve(int n){
	int ans = 1;

	while(n != 0){
		ans *= n % 10;
		n /= 10;
	}
	if(memo.find(ans) != memo.end())
		ans = memo[ans];
	return ans;
}

int main(){
	int cases, n;
	cin >> cases;

	while(cases--){
		cin >> n;
		int i = 0;

		while(n >= 10){
			n = solve(n);
			i++;
		}

		memo[n] = i;

		cout << i << endl;;
	}


	return 0;
}