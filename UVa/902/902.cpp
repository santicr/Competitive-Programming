#include <bits/stdc++.h>

using namespace std;

typedef pair <int, string> P;

int main(){
	int n;
	string str, temp, res;

	while(cin >> n){
		map <string, int> mapa;
		int mEl = -1;

		cin >> str;

		for(int i = 0; i < str.size(); i++){
			temp = str.substr(i, n);
			mapa[temp]++;
		}

		auto it = mapa.begin();

		for(; it != mapa.end(); it++){
			if(mEl < it -> second){
				res = it -> first;
				mEl = it -> second;
			}
		}

		cout << res << endl;
	}


	return 0;
}