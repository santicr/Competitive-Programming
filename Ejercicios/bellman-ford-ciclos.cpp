/*
Implementacion Algoritmo Bellman-Ford para SSSP
Autor: Carlos Ramirez
Fecha: Abril 24 de 2020

Se incluye el codigo para identificar los nodos que hacen parte de un ciclo
negativo

*/
#include <climits>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int n;
vector<vector<pair<int, int> > > adj(50000);
vector<int> p(50000);
vector<int> d(50000);
vector<int> ciclo;

void inicializar(int s){
	for(int i = 0; i < n; ++i){
		d[i] = INT_MAX;
		p[i] = -1;
	}

	d[s] = 0;
}

bool bellmanFord(int s){
	int i, j, k, v, peso, t, cur;

	inicializar(s);

	for(k = 0; k < n; ++k){
		t = -1;
		for(i = 0; i < n; i++){
			for(j = 0; j < adj[i].size(); ++j){
				v = adj[i][j].first;
				peso = adj[i][j].second;
				if(d[i] != INT_MAX && d[i] + peso < d[v]){
					d[v] = max(-INT_MAX, d[i] + peso);
					p[v] = i;
					t = v;
				}
			}
		}
	}

	if(t == -1)
		return true;
	else{
		for(i = 0; i < n; ++i)
			t = p[t];

		cur = t;
		while(cur != t || ciclo.size() == 0){
			ciclo.push_back(cur);
			cur = p[cur];
		}

		return false;
	}
}

int main(){
	int m, i, aux1, aux2, peso;

	cin >> n >> m;

	for(i = 0; i < m; i++){
		cin >> aux1 >> aux2 >> peso;
		adj[aux1].push_back(make_pair(aux2, peso));
	}

	if(bellmanFord(0)){
		for(i = 0; i < n; ++i)
			cout << "Distancia a nodo " << i << ": " << d[i] << endl;

		for(i = 0; i < n; ++i)
			cout << "Predecesor nodo " << i << ": " << p[i] << endl;
	}
	else{
		cout << "El grafo tiene un ciclo negativo:" << endl;

		for(i = ciclo.size() - 1; i >= 0; --i)
			cout << ciclo[i] << " ";
			cout << endl;
	}

	return 0;
}