#include <bits/stdc++.h>

using namespace std;

int visited[1000][1000];
vector <string> graph;
int n, fight_pos = 0;
vector <pair <int, int>> sectors;

pair <int, int> BFSaux(int x, int y, int num){
	pair <int, int> ans;
	ans = make_pair(0, 0);
	int bc = 0, pc = 0;
	bc = num == 1 ? bc += 1 : bc;
	pc = num == 2 ? pc += 1 : pc;
	queue <pair <int, int>> q;
	pair <int, int> p;
	int nx, ny;
	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};

	q.push(make_pair(x, y));
	visited[x][y] = 1;

	while(!q.empty()){
		p = q.front();
		q.pop();

		for(int i = 0; i < 4; i++){
			nx = dx[i] + p.first;
			ny = dy[i] + p.second;

			if(0 <= nx && nx < n && 0 <= ny && ny < n){
				if(graph[nx][ny] == 'B' && !visited[nx][ny]){
					visited[nx][ny] = 1;
					bc++;
					q.push(make_pair(nx, ny));
				}
				
				else if(graph[nx][ny] == 'P' && !visited[nx][ny]){
					visited[nx][ny] = 1;
					pc++;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	if(pc > 0 && bc > 0)
		fight_pos += 2;
	if(pc > 0)
		ans.first = 1;
	if(bc > 0)
		ans.second = 1;

	return ans;

}

pair <int, int> BFS(int x, int y){
	queue <pair <int, int>> q;
	pair <int, int> p, r, temp;
	r = make_pair(0, 0);
	int nx, ny;
	int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
	int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

	q.push(make_pair(x, y));
	visited[x][y] = 1;

	while(!q.empty()){
		p = q.front();
		q.pop();

		for(int i = 0; i < 8; i++){
			nx = dx[i] + p.first;
			ny = dy[i] + p.second;

			if(0 <= nx && nx < n && 0 <= ny && ny < n){
				if(graph[nx][ny] == '*' && !visited[nx][ny]){
					visited[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
				else if((graph[nx][ny] == 'B' || graph[nx][ny] == 'P') && !visited[nx][ny]){
					if(graph[nx][ny] == 'B'){
						temp = BFSaux(nx, ny, 1);
						r.first += temp.first;
						r.second += temp.second;
					}
					else{
						temp = BFSaux(nx, ny, 2);
						r.first += temp.first;
						r.second += temp.second;
					}
				}
			}
		}
	}

	return r;
}

int main(){
	while(cin >> n && n){
		string str;
		int index = 0, nx, ny;
		pair <int, int> temp;
		int dx[] = {0, 0, 1, -1};
		int dy[] = {1, -1, 0, 0};

		for(int i = 0; i < 55; i++){
			for(int j = 0; j < 55; j++){
				visited[i][j] = 0;
			}
		}

		for(int i = 0; i < n; i++){
			cin >> str;
			graph.push_back(str);
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(graph[i][j] == '*' && !visited[i][j]){
					bool nuevo = false;

					for(int k = 0; k < 4; k++){
						nx = dx[k] + i;
						ny = dy[k] + j;

						if(0 <= nx && nx < n && 0 <= ny && ny < n){
							if(graph[nx][ny] == '.')
								nuevo = true;
						}

					}
					if(i == 0 && j == 0)
						nuevo = true;

					if(nuevo)
						sectors.push_back(BFS(i, j));
					else{
						temp = BFS(i, j);
						temp.first += sectors[sectors.size() - 1].first;
						temp.second += sectors[sectors.size() - 1].second;
						sectors[sectors.size() - 1].first = temp.first;
						sectors[sectors.size() - 1].second = temp.second;
					}
				}
			}
		}

		for(int i = 0; i < sectors.size(); i++){
			cout << "Sector #" << i + 1 << ": contain " << sectors[i].second << " freedom fighter group(s) & " << 
			sectors[i].first << " enemy group(s)" << '\n';
		}

		cout << "Total " << fight_pos << " group(s) are in fighting position." << '\n';
		
		fight_pos = 0;
		sectors.clear();
		graph.clear();

		cout << endl;

	}

	return 0;
}