#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> memo(1001);
vector <int> pesos(1001, 0), maximos(1001, 0);

int solve(int n, int m){
	int ans;
	pair <int, int> p = make_pair(n, m);

	if(memo[n][m] != -1)
		ans = memo[n][m];
	else{	
		if(n == 0)
			ans = 0;
		else if(n > 0 and m <= maximos[n - 1])
			ans = max(solve(n - 1, m + pesos[n - 1]) + 1, solve(n - 1, m));
		else if(n > 0 and m > maximos[n - 1])
			ans = solve(n - 1, m);
		memo[n][m] = ans;
	}

	return ans;
}

int main(){
	int n, w, m;
	cin >> n;

	while(n != 0){
		memo = vector <vector<int>> (1001);
		vector <int> temp(6006, -1);

		for(int i = 0; i < n; i++){
			cin >> w >> m;
			pesos[i] = w;
			maximos[i] = m;
			memo[i] = temp;
		}
		memo[n] = temp;

		printf("%d\n", solve(n, 0));

		cin >> n;
	}

	return 0;
}