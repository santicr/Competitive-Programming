#include <bits/stdc++.h>

using namespace std;

int r, c, q, r1, c1;
vector <string> mat;

int bfs(pair <int, int> exit, vector <vector<int>> &visitados){
	queue <pair <int,int >> cola;
	cola.push(exit);
	visitados[exit.first][exit.second] = 0;

	while(!cola.empty()){
		pair <int, int> u = cola.front(), v;
		cola.pop();
		int x, y;
		int dx[] = {-1, 1, 0, 0};
		int dy[] = {0, 0, -1, 1};

		for(int i = 0; i < 4; i++){
			x = dx[i] + u.first;
			y = dy[i] + u.second;
			v = make_pair(x, y);
			if(x >= 0 && x < r && y >= 0 && y < c && visitados[x][y] == -1 && mat[x][y] == '.'){
				visitados[x][y] = visitados[u.first][u.second] + 1;
				cola.push(v);
			}
		}
	}
}

int main(){
	bool flag = false;
	pair <int, int> exit;
	string row;
	cin >> r >> c;

	for(int i = 0; i < r; i++){
		cin >> row;
		
		if(!flag){
			for(int j = 0; j < c; j++){
				if(row[j] == 'E'){
					exit = make_pair(i, j);
					flag = true;
				}
			}
		}

		mat.push_back(row);
	}

	vector <vector <int>> visitados(r, vector <int> (c, -1));
	bfs(exit, visitados);

	cin >> q;

	while(q--){
		cin >> r1 >> c1;
		r1--, c1--;
		if(visitados[r1][c1] == -1 && mat[r1][c1] == '.')
			cout << '?' << '\n';
		else{
			int pasos = INT_MAX;
			if(mat[r1][c1] == '#')
				cout << 'W' << '\n';
			else if(mat[r1][c1] == 'X')
				cout << 'X' << '\n';
			else if(mat[r1][c1] == 'E')
				cout << 'E' << '\n';
			else{
				int izq = abs((r1) - exit.first) + abs((c1 - 1) - exit.second);
				int abajo = abs((r1 + 1) - exit.first) + abs(c1 - exit.second);
				int der = abs((r1) - exit.first) + abs((c1 + 1) - exit.second);
				int arriba = abs((r1 - 1) - exit.first) + abs(c1 - exit.second);
				char m = 't';

				if(c1 - 1 >= 0 && (mat[r1][c1 - 1] == '.' || mat[r1][c1 - 1] == 'E')
					&& visitados[r1][c1 - 1] < pasos){
					pasos = visitados[r1][c1 - 1];
					m = 'L';
				}
				if(r1 + 1 < r && (mat[r1 + 1][c1] == '.' || mat[r1 + 1][c1] == 'E')
					&& visitados[r1 + 1][c1] < pasos){
					pasos = visitados[r1 + 1][c1];
					m = 'D';
				}
				if(c1 + 1 < c && (mat[r1][c1 + 1] == '.' || mat[r1][c1 + 1] == 'E')
					&& visitados[r1][c1 + 1] < pasos){
					pasos = visitados[r1][c1 + 1];
					m = 'R';
				}
				if(r1 - 1 >= 0 && (mat[r1 - 1][c1] == '.' || mat[r1 - 1][c1] == 'E')
					&& visitados[r1 - 1][c1] < pasos){
					pasos = visitados[r1 - 1][c1];
					m = 'U';
				}
				cout << m << endl;
			}
		}
	}

	return 0;
}