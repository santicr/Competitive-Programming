#include <bits/stdc++.h>

using namespace std;

int cases, n, acum = 0, ans = 0, obj;
vector <int> vec(101);
int memo[101][50001];

int solve(int n, int m){
	int ans;
	if(memo[n][m] != -1)
		ans = memo[n][m];
	else{
		if(n == 0)
			ans = m;
		else if(n != 0 && m + vec[n - 1] <= obj)
			ans = max(solve(n - 1, m + vec[n - 1]), solve(n - 1, m));
		else if(n != 0 && m + vec[n - 1] > obj)
			ans = solve(n - 1, m);
		memo[n][m] = ans;
	}

	return ans;
}

int main(){
	cin >> cases;

	while(cases--){
		cin >> n;

		for(int i = 0; i < n; i++){
			cin >> vec[i];
			acum += vec[i];
		}

		for(int i = 0; i < n + 1; i++)
			for(int j = 0; j < acum + 1; j++)
				memo[i][j] = -1;

		obj = acum / 2;
		ans = solve(n, 0);
		printf("%d\n", acum - ans * 2);
		acum = 0;
	}

	return 0;
}