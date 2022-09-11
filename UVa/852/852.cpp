#include <bits/stdc++.h>

using namespace std;

vector <string> graph;
int visited[1000][1000];
int white = 0, black = 0, b_points = 0, w_points = 0;

void count(string str){
	for(int i = 0; i < str.size(); i++){
		white = (str[i] == 'O') ? white += 1 : white;
		black = (str[i] == 'X') ? black += 1 : black;
	}
}

void BFS(int x, int y){
	queue < pair <int , int> > cola;
	int dx[] = {0, 0, 1, -1};
	int dy[] = {-1, 1, 0, 0};
	int nx, ny, w = 0, b = 0;
	pair <int, int> p;
	cola.push(make_pair(x, y));
	visited[x][y] = 1;
	vector < pair <int, int>> all;

	while(!cola.empty()){
		p = cola.front();
		cola.pop();
		all.push_back(p);

		for(int i = 0; i < 4; i++){
			nx = p.first + dx[i];
			ny = p.second + dy[i];

			if(0 <= nx && nx < graph.size() && 0 <= ny && ny < 9){
				if(graph[nx][ny] == 'X')
					b++;
				else if(graph[nx][ny] == 'O')
					w++;
				else if(graph[nx][ny] == '.' && !visited[nx][ny]){
					visited[nx][ny] = 1;
					cola.push(make_pair(nx, ny));
				}
			}
		}
	}

	if(b > 0 && w == 0)
		for(int i = 0; i < all.size(); i++)
			b_points++;
	
	else if(w > 0 && b == 0)
		for(int i = 0; i < all.size(); i++)
			w_points++;

}

int main(){
	int lines, index;
	string str;

	cin >> lines;
	
	while(lines--){
		index = 0;

		while(index < 9){
			cin >> str;
			graph.push_back(str);
			count(str);
			index++;
		}

		for(int i = 0; i < 1000; i++){
			for(int j = 0; j < 1000; j++){
				visited[i][j] = 0;
			}
		}

		for(int i = 0; i < graph.size(); i++){
			for(int j = 0; j < 9; j++){
				if(graph[i][j] == '.' && !visited[i][j])
					BFS(i, j);
			}
		}

		cout << "Black " << b_points + black << " White " << w_points + white << '\n';

		black = 0;
		white = 0;
		b_points = 0;
		w_points = 0;
		graph.clear();
	}

	return 0;
}