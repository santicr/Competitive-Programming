#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> p;
vector <string> mat;
int visited[102][102];
int dx[] = {0, 1, -1, 0, -1, 1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, 1, -1};
int n, m;

void bfs(p nodo){
	int x, y;
	queue <p> q;
	q.push(nodo);
	visited[nodo.first][nodo.second] = 1;
	p u, v;

	while(!q.empty()){
		u = q.front();

		for(int i = 0; i < 8; i++){
			x = u.first + dx[i];
			y = u.second + dy[i];
			v = {x, y};

			if(x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && mat[x][y] == '@'){
				visited[x][y] = 1;
				q.push(v);
			}
		}

		q.pop();
	}
}

int main(){
	int ans;
	string str;

	cin >> n;

	while(n != 0){
		cin >> m;

		mat = vector <string> ();
		ans = 0;
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				visited[i][j] = 0;

		for(int i = 0; i < n; i++){
			cin >> str;
			mat.push_back(str);
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(mat[i][j] == '@' && !visited[i][j]){
					ans++;
					bfs({i, j});
				}
			}
		}

		cout << ans << endl;
		
		cin >> n;	
	}



	return 0;
}