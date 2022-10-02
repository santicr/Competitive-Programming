#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<pair<int, int> > > adj(50000);
vector<int> p(50000);
vector<int> d(50000);

void init(int nodo){
	for(int i = 0; i < n; i++){
		p[i] = -1;
		d[i] = INT_MAX;
	}

	d[nodo] = 0;
}

void dijkstra(int nodo){
	int w, cost, u, v;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
	init(nodo);
	q.push(make_pair(0, nodo));

	while(!q.empty()){
		cost = q.top().first;
		u = q.top().second;

		if(cost == d[u]){
			for(int i = 0; i < adj[u].size(); i++){
				v = adj[u][i].first;
				w = adj[u][i].second;

				if(d[u] != INT_MAX && d[u] + peso < d[v]){
					d[v] = d[u] + peso;
					p[v] = u;
					q.push(make_pair(d[v], v));
				}
			}
		}

		q.pop();
	}
}

int main(){
	int cases, a, b, c, d;
	cin >> cases;

	while(cases--){
		cin >> a >> b >> c >> d;
		

	}

	return 0;
}