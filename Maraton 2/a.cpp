#include <bits/stdc++.h>

using namespace std;

int main(){
	int cases;
	cin >> cases;
	while(cases--){
		string str;
		int res2 = 0;
		cin >> str;
		for(int i = 0; i < str.size(); i++){
			if(str[i] == '0'){
				int res = 0;
				for(int j = i + 1; j < str.size(); j++){
					if(str[j] == '1')
						break;
					res++;
				}
				if(res > res2)
					res2 = res;
			}
		}
		cout << res2 << endl;
	}

	return 0;
}