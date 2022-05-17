#include <bits/stdc++.h>

using namespace std;

int n;
vector <string> vec;
vector <string> sols;
map <string, int> vsols;

bool c(string a, string b){
	int as = a.size(), bs = b.size();
	if(as != bs)
		return as < bs;
	return a < b;
}

bool cond(int x, int y, vector <pair<int,int>> sol){
	bool ans = false;
	int m = sol.size();

	if(vec[x][y] > vec[sol[m - 1].first][sol[m - 1].second])
		ans = true;
	return ans;
}

void bt(map <pair<int,int>, int> vis, vector <pair<int,int>> sol){
	if(sol.empty()){
		map <pair<int,int>, int> vc;
		vector <pair<int,int>> sc;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				vc = vis;
				sc = sol;
				vc[{i, j}] = 1;
				sc.push_back({i, j});
				bt(vc, sc);
			}
		}
	}
	else{
		int dx[] = {1, 1,  1, 0,  0, -1, -1, -1};
		int dy[] = {0, 1, -1, 1, -1, -1, 1,  0};
		string sb;
		int m = sol.size(), nx, ny;

		for(int i = 0; i < m; i++)
			sb.push_back(vec[sol[i].first][sol[i].second]);

		if(m >= 3 && (vsols.find(sb) == vsols.end())){
			sols.push_back(sb);
			vsols[sb] = 1;
		}

		vector <pair<int,int>> sc;
		map <pair<int,int>, int> vc;

		for(int i = 0; i < 8; i++){
			nx = dx[i] + sol[m - 1].first;
			ny = dy[i] + sol[m - 1].second;

			if(nx >= 0 && nx < n && ny >= 0 && ny < n && cond(nx, ny, sol) && (vis.find({nx, ny}) == vis.end() || vis[{nx, ny}] == 0)){
				vc = vis;
				sc = sol;
				sc.push_back({nx, ny});
				vc[{nx, ny}] = 1;
				bt(vc, sc);
			}
		}
	}
}

int main(){
	int cases, i;
	string str;

	cin >> cases;

	for(i = 0; i < cases; i++){
		if(i != 0)
			printf("\n");
		cin >> n;
		vec = vector <string> ();
		sols = vector <string> ();
		vsols = map <string, int>();

		for(int j = 0; j < n; j++){
			cin >> str;
			vec.push_back(str);
		}

		bt(map <pair<int,int>, int>(), vector <pair<int,int>> ());

		sort(sols.begin(), sols.end(), c);
		for(int i = 0; i < sols.size(); i++){
			cout << sols[i] << endl;
		}

	}

	return 0;
}