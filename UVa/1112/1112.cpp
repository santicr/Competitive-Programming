#include <bits/stdc++.h>

using namespace std;

int n, m, e;
vector<vector<pair<int, int> > > adj;
vector<int> padres(101);
vector<int> d(101);

void inicializar(int nodo){
	for(int i = 0; i < n; i++){
		padres[i] = -1;
		d[i] = INT_MAX;
	}

	d[nodo] = 0;
}

void dijkstra(int nodo){
	int w, cost, u;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
	inicializar(nodo);
	q.push(make_pair(0, nodo));

	while(!q.empty()){
		cost = q.top().first;
		u = q.top().second;
		q.pop();

		if(cost == d[u]){
			for(int i = 0; i < adj[u].size(); i++){
				int aux = adj[u][i].first;
				w = adj[u][i].second;
				if(d[u] != INT_MAX && d[u] + w < d[aux]){
					d[aux] = d[u] + w;
					padres[aux] = u;
					q.push(make_pair(d[aux], aux));
				}
			}
		}
	}
}

int main(){
	int cases, time, u, v, w, ans;

	cin >> cases;

	while(cases--){
		ans = 0;

		cin >> n >> e >> time >> m;

		adj = vector<vector<pair<int, int> > >(n + 1);

		while(m--){
			cin >> u >> v >> w;
			adj[v - 1].push_back({u - 1, w});
		}

		dijkstra(e - 1);

		for(int i = 0; i < n; i++)
			if(d[i] <= time)
				ans++;

		cout << ans << endl;

		if(cases)
			cout << endl;

	}

	return 0;
}