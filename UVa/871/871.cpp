#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> p;
vector <string> mat;
int visited[26][26];
int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
int n, m;

int bfs(p nodo){
	queue <p> q;
	int x, y, ans = 1;
	p v, u;
	q.push(nodo);
	visited[nodo.first][nodo.second] = 1;

	while(!q.empty()){
		u = q.front();

		for(int i = 0; i < 8; i++){
			x = dx[i] + u.first;
			y = dy[i] + u.second;
			v = {x, y};

			if(x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && mat[x][y] == '1'){
				visited[x][y] = 1;
				q.push(v);
				ans++;
			}
		}

		q.pop();
	}

	return ans;
}

int main(){
	int cases, nMax;
	string str;
	cin >> cases;
	scanf("\n");

	while(cases--){
		mat = vector <string> ();
		nMax = 0;

		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				visited[i][j] = 0;

		while(getline(cin, str)){
			if(str == "")
				break;
			mat.push_back(str);
		}

		n = mat.size();
		m = mat[0].size();

		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(mat[i][j] == '1' && !visited[i][j])
					nMax = max(nMax, bfs({i, j}));

		printf("%d\n", nMax);
		if(cases)
			printf("\n");
		scanf("\n");
	}

	return 0;
}