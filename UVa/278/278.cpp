#include <bits/stdc++.h>

using namespace std;

int cases;
float n, m, ans;
char c;

int main(){
	cin >> cases;

	while(cases--){

		cin >> c >> n >> m;

		if(c == 'r')
			ans = min(n, m);
		else if(c == 'k')
			ans = ceil((n * m) / 2);
		else if(c == 'Q')
			ans = min(n, m);
		else
			ans = ceil(n / 2) * ceil(m / 2);

		cout << ans << endl;

	}

	return 0;
}