#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> grafo(2002);
int visitados[2002];
int low[2002];
int padre[2002];
int t = 0;
set <int> nodos;

void tarjanAux(int nodo){
	int numHijos = 0;
	low[nodo] = visitados[nodo] = ++t;

	for(int i = 0; i < grafo[nodo].size(); i++){
		int aux = grafo[nodo][i];
		if(visitados[aux] == -1){
			numHijos++;
			padre[aux] = nodo;
			tarjanAux(aux);
			low[nodo] = min(low[nodo], low[aux]);
			if(padre[nodo] != -1 && low[aux] >= visitados[nodo])
				nodos.insert(nodo);
			else if(aux != padre[nodo])
				low[v] = low[v] < visitados[w] ? low[v] : visitados[w];
		}
	}

	if(padre[nodo] == -1 && numHijos > 1)
		nodos.insert(nodo);
}

void apTarjan(int n){
	for(int i = 0; i < n; i++)
		visitados[i] = low[i] = padre[i] = -1;

	for(int i = 0; i < n; i++)
		if(visitados[i] == -1)
			tarjanAux(i);
}

int main(){


	return 0;
}