#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	char c;
	int size;
	cin >> s;

	size = s.size();
	sort(s.begin(), s.end());

	cout << s << endl;

	for(int i = 0; i < size; i++){
		if((s[i] == '1' && s[i + 1] == '0' && i < size - 1)){
			c = s[i];
			s[i] = s[i + 1];
			s[i + 1] = c;
		}
		if((s[i] == '2' && s[i + 1] == '1' && i < size - 1)){
			c = s[i];
			s[i] = s[i + 1];
			s[i + 1] = c;
		}
	}

	cout << s << endl;


	return 0;
}