#include <bits/stdc++.h>

using namespace std;

int n, m, b, p;
vector <int> banks, police;
vector <vector<pair<int, int> > > adj;
vector <int> padres(1001);
vector <int> d(1001);

void inicializar(int nodo){
	for(int i = 0; i < n; i++){
		padres[i] = -1;
		d[i] = INT_MAX;
	}

	d[nodo] = 0;
}

int dijkstra(int nodo){
	int w, cost, u, v;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
	inicializar(nodo);
	q.push(make_pair(0, nodo));
	int min_val = INT_MAX;

	while(!q.empty()){
		cost = q.top().first;
		u = q.top().second;
		q.pop();

		if(cost == d[u]){
			for(int i = 0; i < adj[u].size(); i++){
				v = adj[u][i].first;
				w = adj[u][i].second;

				if(d[u] != INT_MAX && d[u] + w < d[v]){
					d[v] = d[u] + w;
					padres[v] = u;
					q.push(make_pair(d[v], v));

					if(police[v])
						min_val = min(d[v], min_val);
				}
			}
		}
	}

	return min_val;
}

int main(){
	while(cin >> n){
		int u, v, w, max_dist = -1;
		adj = vector<vector<pair<int, int> > >(n + 1);
		banks = vector <int> (n + 1, 0);
		police = vector <int> (n + 1, 0);
		vector <int> ans(n + 1, 0);
		int pos = 0, res, count = 1;

		cin >> m >> b >> p;

		while(m--){
			cin >> u >> v >> w;
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}

		while(b--){
			cin >> u;
			banks[u] = 1;
		}

		while(p--){
			cin >> u;
			police[u] = 1;
		}

		for(int i = 0; i < n; i++){
			if(banks[i]){
				res = dijkstra(i);
				if(res > max_dist){
					max_dist = res;
					ans[i] = ++pos;
					count = 1;
				}
				else if(res == max_dist){
					ans[i] = pos;
					count++;
				}
			}
		}
		
		if(max_dist == INT_MAX)
			cout << count << " *" << endl;
		else
			cout << count << " " << max_dist << endl;

		int idx = 0;

		for(int i = 0; i < n; i++){
			if(ans[i] == pos && idx)
				cout << " " << i;
			else if(ans[i] == pos && !idx++)
				cout << i;
		}

		cout << endl;

	}

	return 0;
}