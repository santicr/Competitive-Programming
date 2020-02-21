#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;
	map <string, int> mapa;
	while(getline(cin, str)){

		for(int i = 0; i < str.size(); i++){
			str[i] = tolower(str[i]);
		}
		
		string temp = "";
		for(int i = 0; i < str.size(); i++){
			if(str[i] >= 'a' && str[i] <= 'z')
				temp += str[i];
			else{
				if(temp.size() >= 1)
					mapa[temp] = 1;
				temp = "";
			}
		}
		if(temp.size() >= 1)
			mapa[temp] = 1;
		temp = "";
	}
	for(auto it = mapa.begin(); it != mapa.end(); it++){
			cout << it -> first << endl;
		}


	return 0;
}