#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	pair <int, int> p;
	p.first = 0;
	p.second = 0;
	string str, s1, s2;
	int res = 0;

	cin >> n;

	for(int i = 0; i < n + 1; i++){
		cin >> str;

		int size = str.size();

		for(int j = 1; j < size; j++){
			if(str[j] == '.'){
				s1 = str.substr(1, j);
				s2 = str.substr(j + 1, size - 1);
				break;
			}
		}

		p.first += stoi(s1);
		p.second += stoi(s2);
		cout << p.first << " " << p.second << endl;

		if(p.second != 0 && i != 0)
			res++;

	}

	cout << res << endl;


	return 0;
}