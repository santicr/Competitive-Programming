#include <bits/stdc++.h>

using namespace std;

int n, m, query;
map <int, pair<int, int>> mapa;
vector <vector<int>> vis1, vis2;
bool k;

void bfsQueen(){
	int dx[] = {1, 0, 0, -1};
	int dy[] = {0, 1, -1, 0};
	int x, y, nx, ny, it;
	queue <pair <pair<int, int>, int>> q;
	vis1 = vector <vector<int>> (8, vector <int>(8, 0));
	vis1[mapa[m].first][mapa[m].second] = 1;

	for(int i = 0; i < 4; i++){
		nx = dx[i] + mapa[m].first;
		ny = dy[i] + mapa[m].second;

		if(nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && !(nx == mapa[n].first && ny == mapa[n].second)){
			q.push({{nx, ny}, i});
			vis1[nx][ny] = 1;
		}
	}

	while(!q.empty()){
		x = q.front().first.first;
		y = q.front().first.second;
		it = q.front().second;

		nx = x + dx[it];
		ny = dy[it] + y;

		if(nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && vis1[nx][ny] == 0 && !(nx == mapa[n].first && ny == mapa[n].second)){
			q.push({{nx, ny}, it});
			vis1[nx][ny] = 1;
		}

		q.pop();
	}
}

void bfsKing(){
	int dx[] = {1, 0, 0, -1};
	int dy[] = {0, 1, -1, 0};
	int x, y, nx, ny, it;
	queue <pair <pair<int, int>, int>> q;
	vis2 = vector <vector<int>> (8, vector <int>(8, 0));
	vis2[mapa[n].first][mapa[n].second] = 1;

	for(int i = 0; i < 4; i++){
		nx = dx[i] + mapa[n].first;
		ny = dy[i] + mapa[n].second;

		if(nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && !(nx == mapa[m].first && ny == mapa[m].second))
			vis2[nx][ny] = 1;
	}
}

int main(){
	int idx = 0, x, y;
	string ans;

	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			mapa[idx++] = {i, j};
	
	while(cin >> n){
		cin >> m >> query;
		ans = "";

		if(n == m)
			ans = "Illegal state\n";
		else if(n != m){
			bfsKing();
			bfsQueen();
			x = mapa[query].first;
			y = mapa[query].second;

			if(!vis1[x][y] || query == m)
				ans = "Illegal move\n";

			else if(vis1[x][y] == vis2[x][y] == 1)
				ans = "Move not allowed\n";

			else if(vis1[x][y] && !vis2[x][y]){
				k = false;
				ans = "Stop\n";
				m = query;
				vis2[mapa[n].first][mapa[n].second] = 0;
				bfsQueen();

				for(int i = 0; i < 8; i++)
					for(int j = 0; j < 8; j++)
						if(vis2[i][j] && !vis1[i][j])
							k = true;
					
				if(k)
					ans = "Continue\n";
			}
		}

		cout << ans;
	}

	return 0;
}