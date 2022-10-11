#include <bits/stdc++.h>

using namespace std;

int cases, n, m, temp, node_min;
map <int, int> important;
vector <vector<int>> adj;
float min_el, ans;

float bfs(int node){
	queue <int> q;
	vector <int> vis(n, -1);
	int u, v;
	float suma = 0, prom = 1;

	q.push(node);
	vis[node] = 0;

	while(!q.empty()){
		u = q.front();
		q.pop();

		for(int i = 0; i < adj[u].size(); i++){
			v = adj[u][i];
			if(vis[v] == -1){
				vis[v] = vis[u] + 1;
				q.push(v);
				prom = important[v] > 1 ? prom + 1: prom;
				suma = important[v] > 1 ? suma + vis[v]: suma;
			}
		}
	}

	return suma / prom;
}

int main(){
	cin >> cases;

	while(cases--){
		cin >> n >> m;

		adj = vector<vector<int>>(n, vector<int>( ));
		important = map <int, int>();

		for(int i = 0; i < m; i++){
			vector <int> nodes;

			while(cin >> temp && temp)
				nodes.push_back(temp);

			for(int i = 1; i < nodes.size(); i++){
				adj[nodes[i - 1] - 1].push_back(nodes[i] - 1);
				adj[nodes[i] - 1].push_back(nodes[i - 1] - 1);
				important[nodes[i - 1] - 1]++;
				if(i == nodes.size() - 1)
					important[nodes[i] - 1]++;
			}
		}
		
		min_el = FLT_MAX;
		node_min = -1;

		for(auto it = important.begin(); it != important.end(); it++){
			int k = it -> first;
			int v = important[k];
			if(v > 1){
				ans = bfs(k);
				if(ans < min_el){
					node_min = k + 1;
					min_el = ans;
				}
			}
		}

		printf("Krochanska is in: %d\n", node_min);
	}

	return 0;
}