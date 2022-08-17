#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> adj(1001);
vector <int> ans;
int cases, n, m, p1, p2;

void bfs(){
	int vis[1001] = {0};
	int u, v;
	int padres[1001] = {0};
	queue <int> q;

	vis[0] = 1;
	q.push(0);

	while(!q.empty()){
		u = q.front();

		for(int i = 0; i < adj[u].size(); i++){
			v = adj[u][i];

			if(!vis[v]){
				vis[v] = 1;
				q.push(v);
				padres[v] = padres[u] + 1;
			}
		}

		q.pop();
	}

	for(int i = 1; i < n; i++)
		ans.push_back(padres[i]);
}

int main(){

	cin >> cases;

	for(int i = 0; i < cases; i++){
		adj = vector <vector <int>> (1000);
		ans = vector <int> ();
		cin >> n >> m;

		while(m--){
			cin >> p1 >> p2;
			adj[p1].push_back(p2);
			adj[p2].push_back(p1);
		}

		bfs();

		if(i)
			printf("\n");
		
		for(int i = 0; i < n - 1; i++)
			cout << ans[i] << '\n';

	}

	return 0;
}