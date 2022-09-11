#include <bits/stdc++.h>

using namespace std;

int b[101];
int w[10001];
int memo[101][10201], memo2[101][10201];
int n, c;

int solve1(int n, int m){
	int ans;
	if(memo[n][m] != -1)
		ans = memo[n][m];
	else{
		if(n == 0)
			ans = 0;
		else if(n != 0 && m + w[n - 1] <= 2000 && m + w[n - 1] <= c)
			ans = max(solve1(n - 1, m + w[n - 1]) + b[n - 1], solve1(n - 1, m));
		else if(n != 0 && m + w[n - 1] > 2000 && m + w[n - 1] <= c + 200)
			ans = max(solve1(n - 1, m + w[n - 1]) + b[n - 1], solve1(n - 1, m));
		else
			ans = solve1(n - 1, m);
		memo[n][m] = ans;
	}
	return ans;
}

int solve2(int in, int m){
	int ans;
	if(memo2[in][m] != -1)
		ans = memo2[in][m];
	else{
		if(in == n)
			ans = 0;
		else if(in != n && m + w[in] <= 2000 && m + w[in] <= c)
			ans = max(solve2(in + 1, m + w[in]) + b[in], solve2(in + 1, m));
		else if(in != n && m + w[in] > 2000 && m + w[in] <= c + 200)
			ans = max(solve2(in + 1, m + w[in]) + b[in], solve2(in + 1, m));
		else
			ans = solve2(in + 1, m);
		memo2[in][m] = ans;
	}
	return ans;
}

int main(){
	while(cin >> c){
		cin >> n;

		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= c + 200; j++){
				memo[i][j] = -1;
				memo2[i][j] = -1;
			}
		}

		for(int i = 0; i < n; i++)
			cin >> w[i] >> b[i];

		cout << max(solve1(n, 0), solve2(0, 0)) << endl;

	}

	return 0;
}