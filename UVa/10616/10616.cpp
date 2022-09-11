#include <bits/stdc++.h>

using namespace std;

int numeros[205] = {0}, d;
map <tuple <int, int, int>, int> memo;

int solve(int n, int m, int acum){
	int ans, r1, r2;
	tuple <int, int, int> t = make_tuple(n, m, acum);

	if(memo.find(t) != memo.end())
		ans = memo[t];

	else{	
		if(m == 0 and acum % d == 0)
			ans = 1;
		else if(m == 0 and acum % d != 0)
			ans = 0;
		else if(n == 0 and m > 0)
			ans = 0;
		else if(n > 0 and m > 0){
			r1 = solve(n - 1, m - 1, acum + (numeros[n - 1]) % d);
			r2 = solve(n - 1, m, acum);
			ans = r1 + r2;
		}
		memo[t] = ans;
	}

	return ans;
}

int main(){
	int n, q, num, m, index = 0;
	cin >> n >> q;

	while(n != 0 and q != 0){
		printf("SET %d:\n", ++index);

		for(int i = 0; i < n; i++)
			cin >> numeros[i];

		for(int i = 0; i < q; i++){
			memo = map <tuple <int, int, int>, int> ();
			cin >> d >> m;
			printf("QUERY %d: %d\n", i + 1, solve(n, m, 0));
		}

		cin >> n >> q;
	}


	return 0;
}