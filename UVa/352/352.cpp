#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> p;
vector <string> mat;
int n;
int visited[26][26] = {{0}};
int dx[] = {1, 0, -1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
int ans = 0;

void BFS(p nodo){
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

			if(x >= 0 && x < n && y >= 0 && y < n && !visited[x][y] && mat[x][y] == '1'){
				visited[x][y] = 1;
				q.push(v);
			}
		}

		q.pop();
	}
}

int main(){
	int idx = 1;

	while(cin >> n){
		string row;

		for(int i = 0; i < n; i++){
			cin >> row;
			mat.push_back(row);
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(mat[i][j] == '1' and !visited[i][j]){
					BFS({i, j});
					ans++;
				}
			}
		}

		printf("Image number %d contains %d war eagles.\n", idx++, ans);
		
		ans = 0;
		mat = vector <string> ();
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				visited[i][j] = 0;
	}


	return 0;
}