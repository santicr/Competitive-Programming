#include <bits/stdc++.h>

using namespace std;

int monedas[105] = {0}, acum = 0;
int memo[105] = {-1};

void inicializar(){
	int acum = 0;
	for(int i = 0; i < 105; i++)
		memo[i] = -1;
}

int solve(int m){
	int ans, p1, p2, res1, res2, p3, p4;

	if(memo[m] != -1)
		ans = memo[m];
	else{
		if(m == 0)
			ans = 0;
		else if(m > 0){
			p1 = solve(m - 1) + monedas[m - 1];
			p2 = solve(m - 1);
			
		}
	}

	return ans;
}

int main(){
	int n, m, val;
	cin >> n;
	while(n--){
		cin >> m;
		inicializar();

		for(int i = 0; i < m; i++){
			cin >> monedas[i];
			acum += monedas[i];
		}

		cout << solve(m) << endl;;
	}


	return 0;
}