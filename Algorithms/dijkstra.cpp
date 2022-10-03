#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<pair<int, int> > > adj(50000);
vector<int> padres(50000);
vector<int> d(50000);

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