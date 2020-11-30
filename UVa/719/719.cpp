#include <bits/stdc++.h>
 
using namespace std;

int main(){
	int casos;
	map <string, int> mapa;
	string temp, s;
	vector <string> vec;
	cin >> casos;

	while(casos--){
		cin >> s;
		s += s;
		for(int i = 0; i < s.size(); i++){
			temp = s.substr(i, s.size() - i);
			vec.push_back(temp);
			mapa[temp] = i;
		}
		sort(vec.begin(), vec.end());
		for(int i = 0; i < vec.size(); i++){
			if(vec[i].size() >= s.size() / 2){
				cout << mapa[vec[i]] + 1 << endl;
				break;
			}
		}
		vec.clear();
		mapa.clear();
	}

	return 0;
}
