#include <bits/stdc++.h>

using namespace std;

int n, m, rows, r, cs, c, xi, yi, xf, yf;

vector <vector<int>> mat;

typedef pair <int, int> P;

int bfs(P start, P end){
	vector <vector<int>> vis(n, vector<int>(m, 0));
	queue <P> q;
	int nx, ny, x = start.first, y = start.second;
	int dx[] = {1, 0, 0, -1};
	int dy[] = {0, 1, -1, 0};

	q.push(start);
	vis[x][y] = 0;

	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++){
			nx = x + dx[i];
			ny = y + dy[i];

			if(nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny]){
				q.push({nx, ny});
				mat[nx][ny] = 0;
				vis[nx][ny] = vis[x][y] + 1;
			}
		}
	}

	return vis[end.first][end.second];
}

int main(){
	cin >> n >> m;

	while(n || m){
		cin >> rows;

		mat = vector<vector<int>>(n, vector<int>(m, 1));

		while(rows--){
			cin >> r >> cs;

			while(cs--){
				cin >> c;
				mat[r][c] = 0;
			}
		}

		cin >> xi >> yi >> xf >> yf;

		cout << bfs({xi, yi}, {xf, yf}) << endl;

		cin >> n >> m;
	}

	return 0;
}