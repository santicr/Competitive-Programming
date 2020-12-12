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
			cout << vec[i] << " " << mapa[vec[i]] << endl;
		}
	}

	return 0;
}
