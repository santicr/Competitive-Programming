#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> P;

int n, m, i, j;
vector <string> mat;
vector <vector<int>> vis1;
char l;

int bfs(P node, int option){
	int dx[] = {0, 1, -1, 0};
	int dy[] = {1, 0, 0, -1};
	int x, y, nx, ny;
	queue <P> q;
	int ans = 1;

	q.push(node);
	vis1[node.first][node.second] = 1;

	if(option)
		l = mat[node.first][node.second];

	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;

		for(int i = 0; i < 4; i++){
			nx = dx[i] + x;
			ny = dy[i] + y;

			if(nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == l && vis1[nx][ny] == 0){
				vis1[nx][ny] = 1;
				q.push({nx, ny});
				ans++;
			}

			if(y == 0){
				nx = x;
				ny = m - 1;
				if(nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == l && vis1[nx][ny] == 0){
					vis1[nx][ny] = 1;
					q.push({nx, ny});
					ans++;
				}
			}
			if(y == m - 1){
				nx = x;
				ny = 0;
				if(nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == l && vis1[nx][ny] == 0){
					vis1[nx][ny] = 1;
					q.push({nx, ny});
					ans++;
				}
			}
		}

		q.pop();
	}
	if(option)
		return -1;

	return ans;

}

int main(){
	string str;
	int res;

	while(cin >> n){
		cin >> m;
		
		vis1 = vector <vector<int>> (n, vector<int>(m, 0));
		mat = vector <string> ();
		res = 0;

		for(i = 0; i < n; i++){
			cin >> str;
			mat.push_back(str);
		}

		cin >> i >> j;

		bfs({i, j}, 1);

		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				if(!vis1[i][j] && mat[i][j] == l)
					res = max(res, bfs({i, j}, 0));

		cout << res << endl;

	}

	return 0;
}