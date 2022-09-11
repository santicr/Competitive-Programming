#include <bits/stdc++.h>

using namespace std;

int cases, nodos, lineas, nodo, n1, n2, impTotal;
vector <vector <int>> adj(10004);
int importantes[10005];
map <int, int> mapa;
vector <int> impor;

void BFS(int val){
	queue <int> cola;
	cola.push(val);
	int visitados[10003] = {0};
	int valores[10004] = {0};
	int padres[10005] = {0};
	visitados[val] = 1;
	int ans = 0, imp = 1;
	padres[val] = -1;
	valores[val] = 0;

	while(!cola.empty()){
		int u, v;
		u = cola.front();

		for(int i = 0; i < adj[u].size(); i++){
			v = adj[u][i];
			if(!visitados[v]){
				visitados[v] = 1;
				padres[v] = u;
				valores[v] = valores[u] + 1;
				imp = importantes[v] > 1 ? imp += 1 : imp;
				if(importantes[v] > 1)
					ans = ans < valores[v] ? ans = valores[v] : ans;
				cola.push(v);
			}
			if(imp == impTotal)
				break;
		}
		if(imp == impTotal)
			break;

		cola.pop();
	}

	mapa[val] = ans;
}

int main(){
	cin >> cases;

	for(int i = 0; i < cases; i++){
		cin >> nodos >> lineas;

		for(int i = 0; i <= nodos + 1; i++){
			importantes[i] = 0;
			adj[i] = vector <int> ();
		}

		impor = vector <int> ();
		mapa.clear();
		impTotal = 0;

		for(int j = 0; j < lineas; j++){
			cin >> nodo;
			while(nodo != 0){
				n1 = nodo;
				importantes[n1]++;
				impTotal = importantes[n1] > 1 ? impTotal += 1: impTotal;
				if(importantes[n1] > 1)
					impor.push_back(n1);
				cin >> nodo;
				n2 = nodo;

				if(n2 != 0){
					adj[n1].push_back(n2);
					adj[n2].push_back(n1);
				}
			}
		}

		int ans = -1, minElement = INT_MAX;

		for(int j = 0; j < impTotal; j++)
			BFS(impor[j]);

		for (auto it = mapa.begin(); it != mapa.end(); it++){
			printf("Primer elemento -> %d, Segundo elemento -> %d\n", it -> first, it -> second);
			if(minElement > it -> second){
				minElement = it -> second;
				ans = it -> first;
			}
		}

		printf("Krochanska is in: %d\n", ans);
	}

	return 0;
}