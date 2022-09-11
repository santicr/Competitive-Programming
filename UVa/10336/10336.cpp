#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> p;
vector <string> mat;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int visited[1001][1001];
int n, m;
map <char, int> mapa;

struct par{
	char c;
	int num;
};

bool comp(par a, par b){
	if(a.num != b.num)
		return a.num > b.num;
	return a.c < b.c;
}

void bfs(p nodo){
	char c = mat[nodo.first][nodo.second];
	mapa[c]++;
	queue <p> q;
	q.push(nodo);
	int x, y;
	p u, v;
	visited[nodo.first][nodo.second] = 1;

	while(!q.empty()){
		u = q.front();

		for(int i = 0; i < 4; i++){
			x = u.first + dx[i];
			y = u.second + dy[i];
			v = {x, y};

			if(x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && c == mat[x][y]){
				visited[x][y] = 1;
				q.push(v);
			}
		}

		q.pop();
	}
}

int main(){
	int cases, idx = 0;
	map <char, int> :: iterator it;
	string str;
	cin >> cases;

	while(idx < cases){
		cin >> n >> m;

		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				visited[i][j] = 0;

		for(int i = 0; i < n; i++){
			cin >> str;
			mat.push_back(str);
		}

		printf("World #%d\n", idx + 1);

		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(!visited[i][j])
					bfs({i, j});

		vector <par> vec;
		par temp;

		for(it = mapa.begin(); it != mapa.end(); it++){
			temp.c = it -> first;
			temp.num = it -> second;
			vec.push_back(temp);
		}

		sort(vec.begin(), vec.end(), comp);

		for(int i = 0; i < vec.size(); i++)
			cout << vec[i].c << ": " << vec[i].num << endl;

		mapa = map <char, int> ();
		mat = vector <string> ();
		idx++;
	}

	return 0;
}