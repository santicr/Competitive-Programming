#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> p;
vector <string> mat;
int n, m;
int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};

bool bfs(p nodo){
	p u = nodo;
	int x, y;
	bool ans = true;

	for(int i = 0; i < 8; i++){
		x = u.first + dx[i];
		y = u.second + dy[i];

		if(x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == '*')
			ans = false;
	}

	return ans;
}

int main(){
	string str;

	cin >> n >> m;

	while(n != 0 && m != 0){
		int ans = 0;
		mat = vector <string> ();

		for(int i = 0; i < n; i++){
			cin >> str;
			mat.push_back(str);
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(mat[i][j] == '*'){
					if(bfs({i, j}))
						ans++;
				}
			}
		}

		printf("%d\n", ans);

		cin >> n >> m;
	}

	return 0;
}