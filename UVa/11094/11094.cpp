#include <bits/stdc++.h>

using namespace std;

int n, m, x, y;
vector <string> graph;
int visited[100][100];

int main(){
	string str;

	while(cin >> n){
		cin >> m;

		for(int i = 0; i < n; i++){
			cin >> str;
			graph.push_back(str);
		}

		cin >> x >> y;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				visited[i][j] = 0;
			}
		}

		graph = vector <string> ();
	}

	return 0;
}