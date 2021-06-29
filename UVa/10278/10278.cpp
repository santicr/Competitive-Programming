#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<pair<int, int> > > grafo(50000);
vector<int> padres(50000);
vector<int> distancias(50000);

void inicializar(int nodo){
	for(int i = 0; i < n; i++){
		padres[i] = -1;
		distancias[i] = INT_MAX;
	}

	distancias[nodo] = 0;
}

void dijkstra(int nodo){
	int peso, costo, val;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > cola;
	inicializar(nodo);
	cola.push(make_pair(0, nodo));

	while(!cola.empty()){
		costo = cola.top().first;
		val = cola.top().second;
		cola.pop();

		if(costo == distancias[val]){
			for(int i = 0; i < grafo[val].size(); i++){
				int aux = grafo[val][i].first;
				peso = grafo[val][i].second;
				if(distancias[val] != INT_MAX && distancias[val] + peso < distancias[aux]){
					distancias[aux] = distancias[val] + peso;
					padres[aux] = val;
					cola.push(make_pair(distancias[aux], aux));
				}
			}
		}
	}
}

int main(){
	int cases, fstations;
	cin >> cases;

	while(cases--){
		cin >> 
	}

	return 0;
}