#include <bits/stdc++.h>

using namespace std;

int prices[1005], weights[1005], mWeights[1005];
map <pair <int, int>, int> memo;

int dp(int n, int m){
	int ans;
	pair <int, int> p = make_pair(n, m);

	if(memo.find(p) != memo.end())
		ans = memo[p];
	else{
		if(n == 0)
			ans = 0;
		else if(m == 0)
			ans = 0;
		else if(n > 0 and m >= weights[n - 1])
			ans = max(dp(n - 1, m), dp(n - 1, m - weights[n - 1]) + prices[n - 1]);
		else if(n > 0 and m < weights[n - 1])
			ans = dp(n - 1, m);
		memo[p] = ans;
	}

	return ans;
}

int main(){
	int cases, n, g, ans;
	cin >> cases;

	while(cases--){
		ans = 0;
		cin >> n;

		for(int i = 0; i < n; i++)
			cin >> prices[i] >> weights[i];
		
		cin >> g;
		for(int i = 0; i < g; i++){
			cin >> mWeights[i];
			ans += dp(n, mWeights[i]);
		}

		cout << ans << endl;
		memo = map <pair <int, int>, int> ();
	}

	return 0;
}