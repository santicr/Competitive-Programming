#include <bits/stdc++.h>

using namespace std;

vector <string> mat;

int n, m;

int solve(int a, int b){
	queue <pair<int,int>> cola;
	map <pair<int, int>, int> visitados;
	padres[{a, b}] = 1;
	cola.push({a, b});
	visitados[{a, b}] = 1;
	int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
	int dy[] = {1, 1, 0, -1, -1, 1, -1, 0};


	while(!cola.empty()){
		int nx, ny;
		int x = cola.front().first;
		int y = cola.front().second;
		char c = mat[x][y];

		for(int i = 0; i < 8; i++){
			nx = dx[i] + x;
			ny = dy[i] + y;
			if(0 <= nx && nx < n && 0 <= ny && ny < m && visitados[{nx, ny}] != 1){
				if(mat[nx][ny] == c + 1){
					cola.push({nx, ny});
					visitados[{nx, ny}] = 1;
				}
			}
		}

		cola.pop();
	}

	return ans;
}

int main(){
	string fila;

	while(cin >> n){
		cin >> m;
		for(int i = 0; i < n; i++){
			cin >> fila;
			mat.push_back(fila);
		}

		cout << solve(0, 0) << endl;
	}


	return 0;
}