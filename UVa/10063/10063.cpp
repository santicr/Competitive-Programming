#include <bits/stdc++.h>

using namespace std;

string str;
vector <vector <int>> sols;
int n;

void solve(vector <int> sol, int idx, int it){
	if(sol.size() == n)
		sols.push_back(sol);
	else{
		int index = 0, i = idx;
		vector <int> sc;
		for(; i < it + idx; i++){
			sc = sol;
			sc.insert(sc.begin() + index++, idx);
			solve(sc, idx + 1, it + 1);
		}
	}
}

int main(){
	int cases = 0;
	while(cin >> str){
		if(cases++)
			printf("\n");
		sols = vector <vector <int>>();
		n = str.size();
		solve({0}, 1, 2);
		string temp;

		for(int i = 0; i < sols.size(); i++){
			temp = "";
			for(int j = 0; j < n; j++)
				temp.push_back(str[sols[i][j]]);
			cout << temp << endl;
		}
	}

	return 0;
}