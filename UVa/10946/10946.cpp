#include <bits/stdc++.h>

using namespace std;

struct P{
	char c;
	int num = 0;
};

int n, m;
vector <string> graph;
int visited[1000][1000];
vector <P> ans;

P BFS(int x1, int y1){
	queue <pair <int, int>> q;
	q.push(make_pair(x1, y1));
	visited[x1][y1] = 1;
	pair <int, int> f;
	int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
	int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
	int x, y;
	char c = graph[x1][y1];
	int res = 1;
	P ans;

	while(!q.empty()){
		f = q.front();
		q.pop();

		for(int i = 0; i < 4; i++){
			x = dx[i] + f.first;
			y = dy[i] + f.second;

			if(0 <= x && x < n && 0 <= y && y < m){
				if(graph[x][y] == c && !visited[x][y]){
					q.push(make_pair(x, y));
					res++;
					visited[x][y] = 1;
				}
			}

		}
	}

	ans.num = res;
	ans.c = c;

	return ans;
}

bool func(P p1, P p2){
	if(p1.num != p2.num)
		return p1.num > p2.num;
	return p1.c < p2.c;
}

int main(){
	string str;
	int index = 1;

	while(cin >> n){
		cin >> m;

		if(n == 0 && m == 0)
			break;

		cout << "Problem " << index++ << ":" << endl;

		for(int i = 0; i < n; i++){
			cin >> str;
			graph.push_back(str);
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				visited[i][j] = 0;
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(!visited[i][j] && graph[i][j] != '.')
					ans.push_back(BFS(i, j));
			}
		}

		sort(ans.begin(), ans.end(), func);

		for(int i = 0; i < ans.size(); i++)
			cout << ans[i].c << " " << ans[i].num << endl;

		graph = vector <string> ();
		ans = vector <P> ();

	}

	return 0;
}