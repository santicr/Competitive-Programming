//Accepted
#include <bits/stdc++.h>

using namespace std;

int main(){
	string s, ans;
	cin >> s;
	int size = s.size();
	ans = s;

	for(int i = size - 2; i >= 0; i--)
		ans.push_back(s[i]);
	
	cout << ans << endl;
	
	return 0;
}