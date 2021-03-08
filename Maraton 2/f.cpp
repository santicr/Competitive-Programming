#include <bits/stdc++.h>

using namespace std;

int visited[1000][1000];
int counter[1000][1000];

int find(string str){
	for(int i = 0; i < str.size(); i++)
		if(str[i] == '@')
			return i;
	
	return -1;
}

void BFS(int x, int y){
	queue <pair <int, int>> q;
	int dx[] = {0, 0, 1, -1};
	int dy[] = {-1, 1, 0, 0};
	pair <int, int> p;

	q.push(make_pair(x, y));
	visited[x][y] = 1;
	counter[x][y] = 0;

	while(!q.empty()){
		p = q.front();

		for(int i = 0; i < 4; i++){
			
		}
	}

}

int main(){
	int cases;

	cin >> cases;

	while(cases--){
		int col, row, x, y;
		vector <string> graph;
		string str;

		cin >> col >> row;
		
		for(int i = 0; i < row; i++){
			cin >> str;
			graph.push_back(str);
			x = i;
			y = find(str);
		}


	}

	return 0;
}