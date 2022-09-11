#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> grafo(2002);
vector <vector<int>> nodos;
int visitados[2002];
int numSCC = 0, t = 0;
int low[2002];
bool enPila[2002];
stack <int> pila;

void tarjanAux(int nodo){
	low[nodo] = visitados[nodo] = ++t;
	pila.push(nodo);
	enPila[nodo] = true;

	for(int i = 0; i < grafo[nodo].size(); i++){
		int aux = grafo[nodo][i];
		if(visitados[aux] == -1){
			tarjanAux(aux);
			low[nodo] = min(low[nodo], low[aux]);
		}
		else if(enPila[aux])
			low[nodo] = min(low[nodo], visitados[aux]);
	}

	if(low[nodo] == visitados[nodo]){
		nodos.push_back(vector<int>());
		numSCC++;
		while(pila.top() != nodo){
			enPila[pila.top()] = false;
			nodos[numSCC - 1].push_back(pila.top());
			pila.pop();
		}
		enPila[pila.top()] = false;
		nodos[numSCC - 1].push_back(pila.top());
		pila.pop();
	}

}

void tarjan(int n){
	for(int i = 0; i < n; i++){
		visitados[i] = low[i] = -1;
		enPila[i] = false;
	}

	for(int i = 0; i < n; i++){
		if(visitados[i] == -1)
			tarjanAux(i);
	}
}

int main(){

	return 0;
}