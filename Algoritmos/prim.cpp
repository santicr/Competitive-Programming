#include <bits/stdc++.h>

using namespace std;

int n, total = 0;
vector<vector<pair<int, int> > > adj(250001);
vector<int> d(250001);
vector<int> p(250001);

void prim(int s){
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > cola;
	vector<bool> visitado(n, false);
	int i, u, v, peso, pesoAux;

	for(i = 0; i < n; ++i){
		d[i] = INT_MAX;
		p[i] = -1;
	}

	total = 0;
	d[s] = 0;
	cola.push(make_pair(0, s));

	while(!cola.empty()){
		u = cola.top().second;
		peso = cola.top().first;
		visitado[u] = true;
		cola.pop();

		if(peso == d[u]){
			total += peso;
			for(i = 0; i < adj[u].size(); ++i){
				v = adj[u][i].first;
				pesoAux = adj[u][i].second;

				if(!visitado[v] && pesoAux < d[v]){
					p[v] = u;
					d[v] = pesoAux;
					cola.push(make_pair(d[v], v));
				}
			}
		}
	}
}