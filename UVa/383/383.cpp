#include <bits/stdc++.h>

using namespace std;

int cases, n, m, q, i, j, cost, ans;
string u, v;
map <string, vector<string>> adj;

int bfs(string start, string end){
	queue <string> q;
	map <string, int> vis;

	q.push(start);
	vis[start] = 1;

	while(!q.empty()){
		u = q.front();
		q.pop();

		for(j = 0; j < adj[u].size(); j++){
			v = adj[u][j];
			if(!vis[v]){
				vis[v] = vis[u] + 1;
				q.push(v);
			}
		}
	}

	return vis[end] - 1;
}

int main(){
	cin >> cases;

	cout << "SHIPPING ROUTES OUTPUT" << endl << endl;

	for(i = 0; i < cases; i++){
		adj = {};

		cin >> n >> m >> q;

		for(j = 0; j < n; j++){
			cin >> u;
			adj[u] = vector<string>();
		}

		for(j = 0; j < m; j++){
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		cout << "DATA SET  " << i + 1 << endl << endl;

		while(q--){
			cin >> cost >> u >> v;
			ans = bfs(u, v);
			if(ans == -1)
				cout << "NO SHIPMENT POSSIBLE" << endl;
			else
				cout << "$" << ans * cost * 100 << endl;
		}

		cout << endl;
	}

	cout << "END OF OUTPUT" << endl;

	return 0;
}