/*
Implementacion Algoritmo Bellman-Ford para SSSP
Autor: Carlos Ramirez
Fecha: Abril 24 de 2020

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

void inicializar(int s){
	for(int i = 0; i < n; ++i){
		d[i] = INT_MAX;
		p[i] = -1;
	}

	d[s] = 0;
}

bool bellmanFord(int s){
	int i, j, k, v, peso;
	bool flag;

	inicializar(s);

	for(k = 0; k < n - 1; ++k){
		flag = false;
		for(i = 0; i < n; i++){
			for(j = 0; j < adj[i].size(); ++j){
				v = adj[i][j].first;
				peso = adj[i][j].second;
				if(d[i] != INT_MAX && d[i] + peso < d[v]){
					d[v] = d[i] + peso;
					p[v] = i;
					flag = true;
				}
			}
		}
		if(!flag)
			break;
	}

	for(i = 0; i < n; i++){
		for(j = 0; j < adj[i].size(); ++j){
			v = adj[i][j].first;
			peso = adj[i][j].second;
			if(d[i] != INT_MAX && d[i] + peso < d[v])
				return false;
		}
	}

	return true;
}

int main(){

	return 0;
}