#include <bits/stdc++.h>

using namespace std;

int n, m, e;
vector<vector<pair<int, int> > > adj;
vector<int> padres(20002);
vector<int> d(20002);

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
	int cases, s, m, t, u, v, w;

	cin >> cases;

	for(int i = 0; i < cases; i++){
		cin >> n >> m >> s >> t;

		adj = vector<vector<pair<int, int> > >(n + 1);

		while(m--){
			cin >> u >> v >> w;
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}

		dijkstra(s);

		if(d[t] != INT_MAX)
			cout << "Case #" << i + 1 << ": " << d[t] << endl;
		else
			cout << "Case #" << i + 1 << ": " << "unreachable" << endl;

	}

	return 0;
}