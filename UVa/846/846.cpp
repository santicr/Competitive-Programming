#include <bits/stdc++.h>

using namespace std;

int main(){
	int cases;
	cin >> cases;
	
	while(cases--){
		long long int x, y;
		cin >> x >> y;
		if(y - x != 0){
			long long int ans = (sqrt(4 * (y - x) - 1));
			cout << ans << endl;
		}
		else
			cout << 0 << endl;
	}

	return 0;
}