#include <bits/stdc++.h>

using namespace std;

int main(){
	int cases, n, d;
	string str;

	cin >> cases;

	for(int i = 0; i < cases; i++){
		cin >> n;
		map <string, int> mapa;
		string ans;

		while(n--){
			cin >> str >> d;
			mapa[str] = d;
		}

		cin >> d >> str;

		if(mapa.find(str) != mapa.end() && mapa[str] <= d)
			ans = "Yesss\n";
		else if(mapa.find(str) != mapa.end() && mapa[str] <= d + 5)
			ans = "Late\n";
		else
			ans = "Do your own homework!\n";
		
		cout << "Case " << i + 1 << ": " << ans;
	}


	return 0;
}