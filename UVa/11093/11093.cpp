#include <bits/stdc++.h>
//Author: Santiago Caicedo Rojas
//Github: https://github.com/santicr
//UVa profile: https://uhunt.onlinejudge.org/id/1033486

using namespace std;

int petrol[100003];
int needed[100003];
int n, res = -1;

bool solve(){
	int pe = 0, ne = 0;
	bool ans;

	for(int i = 0; i < n; i++){
		pe += petrol[i];
		ne += needed[i];
	}
	if(ne > pe)
		return false;

	int act = 0, i = 0;
	res = 0;
	while(i < n){
		act += petrol[i];
		act -= needed[i];
		i++;
		if(act < 0){
			act = 0;
			res = i + 1;
		}
	}


	return true;
}

int main(){
	int cases;
	bool ans;
	cin >> cases;

	for(int i = 0; i < cases; i++){
		cin >> n;

		for(int j = 0; j < n; j++)
			cin >> petrol[j];

		for(int j = 0; j < n; j++)
			cin >> needed[j];

		bool ans = solve();
		if(!ans)
			printf("Case %d: Not possible\n", i + 1);
		else
			printf("Case %d: Possible from station %d\n", i + 1, res);
		res = -1;
	}

	return 0;
}