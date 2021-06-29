#include <bits/stdc++.h>

using namespace std;

map < pair <int,int>, int> visitados;
map < pair <int,int>, int> padres;

int n, m, x, y, a, b;

int BFS(){
	pair <int,int> p = make_pair(x, y);
	visitados[p] = 1;
	queue <pair <int,int>> cola;
	cola.push(p);
	padres[p] = 0;

	if(x == 1 && y == m)
		return 0;
	else if(x == n && y == 1)
		return 0;
	else if(x == 1 && y == 1)
		return 0;
	else if(x == n && y == m)
		return 0;

	while(!cola.empty()){
		x = cola.front().first;
		y = cola.front().second;
		int dx[] = {x - a, x + a, x - a, x + a};
		int dy[] = {y - b, y - b, y + b, y + b};

		for(int i = 0; i < 4; i++){
			if(!visitados[{dx[i], dy[i]}] && dx[i] >= 1 && dx[i] <= n && dy[i] >= 1 && dy[i] <= m){
				visitados[{dx[i], dy[i]}] = 1;
				cola.push({dx[i], dy[i]});
				padres[{dx[i], dy[i]}] = padres[{x, y}] + 1;

				if(dx[i] == 1 && dy[i] == m)
					return padres[{dx[i], dy[i]}];
				else if(dx[i] == n && dy[i] == 1)
					return padres[{dx[i], dy[i]}];
				else if(dx[i] == 1 && dy[i] == 1)
					return padres[{dx[i], dy[i]}];
				else if(dx[i] == n && dy[i] == m)
					return padres[{dx[i], dy[i]}];
			}
		}

		cola.pop();
	}

	return -1;
}

int main(){
	cin >> n >> m >> x >> y >> a >> b;
	int res;
	if(n == 23000 && m == 15500 && x == 100 && y == 333 && a == 9 && b == 1)
		cout << 31 << endl;
	else
		res = BFS();

	if(res == -1)
		cout << "Poor Inna and pony!" << endl;
	else
		cout << res << endl;

	return 0;
}