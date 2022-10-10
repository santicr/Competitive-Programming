#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> adj;
int cases, n, u, m, v;

int bfs(int start, int end){
	vector <int> vis(n, 0);
	queue <int> q;
	int ans = 0;

	q.push(start);
	vis[start] = 0;

	while(!q.empty()){
		u = q.front();
		if(u == end)
			return vis[u] - 1;

		for(int i = 0; i < adj[u].size(); i++){
			v = adj[u][i];
			if(!vis[v]){
				q.push(v);
				vis[v] = vis[u] + 1;
			}	
		}
		q.pop();
	}

	return -1;
}

int main(){
	cin >> cases;

	while(cases--){
		cin >> n;

		adj = vector<vector<int>>(n);

		for(int i = 0; i < n; i++){
			cin >> u >> m;

			while(m--){
				cin >> v;
				adj[u].push_back(v);
			}
		}

		cin >> u >> v;
		cout << u << " " << v << " " << bfs(u, v) << endl;
		if(cases)
			cout << endl;
	}

	return 0;
}