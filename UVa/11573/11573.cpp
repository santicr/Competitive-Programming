#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> mat;

int n, m, q, xi, xf, yi, yf;

typedef pair <int, int> P;

vector<vector<int>> d;

void inicializar(P nodo){
	d = vector <vector<int>>(n, vector<int>(m, INT_MAX));
	d[nodo.first][nodo.second] = 0;
}

int dijkstra(P nodo, P fin){
	int cost, x, y, nx, ny;
	priority_queue<pair<int, P>, vector<pair<int, P>>, greater< pair<int, P>> > q;
	int dx[] = {1, 0, 0, -1, 1, -1, 1, -1};
	int dy[] = {0, 1, -1, 0, 1, -1, -1, 1};
	map <int, int> mapa = {{7, 5}, {0, 3}, {1, 7}, {2, 1}, {3, 4}, {4, 0}, {5, 6}, {6, 2}};

	inicializar(nodo);
	q.push({0, nodo});

	while(!q.empty()){
		cost = q.top().first;
		x = q.top().second.first;
		y = q.top().second.second;
		q.pop();

		if(x == fin.first && y == fin.second)
			return d[x][y];

		if(cost == d[x][y]){
			nx = dx[mapa[mat[x][y]]] + x;
			ny = dy[mapa[mat[x][y]]] + y;

			if(nx >= 0 && ny >= 0 && nx < n && ny < m && d[x][y] < d[nx][ny]){
				q.push({d[x][y], {nx, ny}});
				d[nx][ny] = d[x][y];
			}

			for(int i = 0; i < 8; i++){
				nx = dx[i] + x;
				ny = dy[i] + y;

				if(nx >= 0 && nx < n && ny >= 0 && ny < m && d[x][y] + 1 < d[nx][ny]){
					d[nx][ny] = d[x][y] + 1;
					q.push({d[nx][ny], {nx, ny}});
				}
			}
		}
	}

	return d[fin.first][fin.second];
}

int main(){
	while(cin >> n){
		mat = vector<vector<int>>();
		string str;

		cin >> m;

		for(int i = 0; i < n; i++){
			vector <int> row;

			cin >> str;

			for(int i = 0; i < m; i++)
				row.push_back(str[i] - '0');

			mat.push_back(row);
		}

		cin >> q;

		while(q--){
			cin >> xi >> yi;
			cin >> xf >> yf;

			cout << dijkstra({xi - 1, yi - 1}, {xf - 1, yf - 1}) << endl;
		}
	}

	return 0;
}