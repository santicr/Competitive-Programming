#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pd;

int n, m, x, y;
vector <vector<int>> mat(1001, vector <int>(1001));
int distancias[1001][1001];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

struct comp{
	bool operator()(pair<int, pd> a, pair<int, pd> b){
		return a.first > b.first;
	}
};

void dijkstra(){
	pair <int, int> nodo = {0, 0};
	int peso, costo;
	bool f;
	pair <int, int> val, aux;
	priority_queue <pair<int, pd>, vector<pair<int, pd>>, comp> cola;
	distancias[0][0] = mat[0][0];
	cola.push(make_pair(mat[0][0], nodo));

	while(!cola.empty()){
		costo = cola.top().first;
		val = cola.top().second;
		cola.pop();

		if(costo == distancias[val.first][val.second]){
			for(int i = 0; i < 4; i++){
				x = val.first + dx[i];
				y = val.second + dy[i];
				aux = {x, y};
				f = (x >= 0 && x < n && y >= 0 && y < m);
				if(f)
					peso = mat[x][y];
				if(f && distancias[val.first][val.second] != INT_MAX && distancias[val.first][val.second] + peso < distancias[x][y]){
					distancias[x][y] = distancias[val.first][val.second] + peso;
					cola.push(make_pair(distancias[x][y], aux));
				}
			}
		}
	}
}

int main(){
	int cases, i, j, k, l, temp;
	cin >> cases;

	for(i = 0; i < cases; i++){
		cin >> n >> m;

		for(j = 0; j < n; j++){
			for(k = 0; k < m; k++){
				distancias[j][k] = INT_MAX;
				cin >> mat[j][k];
			}
		}

		dijkstra();
		printf("%d\n", distancias[n - 1][m - 1]);
	}

	return 0;
}