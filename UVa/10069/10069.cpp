#include <bits/stdc++.h>

using namespace std;
string str1, str2;
map <pair<int,int>, long long int> mapa;
int n, m;

long long int solve(int index1, int index2){
	long long int ans = 0;
	pair <int,int> p = make_pair(index1, index2);
	if(mapa.find(p) != mapa.end())
		ans = mapa[p];
	else{
		if(index1 < n && index2 < m){
			if(str1[index1] == str2[index2] && index2 == m - 1)
				ans = 1 + solve(index1 + 1, index2);
			else if(str1[index1] == str2[index2] && index1 == n - 1)
				ans = 0;
			else if(str1[index1] == str2[index2])
				ans = solve(index1 + 1, index2 + 1) + solve(index1 + 1, index2);
			else if(str1[index1] != str2[index2])
				ans = solve(index1 + 1, index2);
		}
		else
			ans = 0;
		mapa[p] = ans;
	}
	return ans;
}

int main(){
	int cases;
	cin >> cases;

	while(cases--){
		cin >> str1 >> str2;
		n = str1.size(), m = str2.size();
		mapa = map <pair <int, int>, long long int> ();
		cout << solve(0, 0) << endl;
	}

	return 0;
}