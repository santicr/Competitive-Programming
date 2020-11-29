#include <bits/stdc++.h>

using namespace std;

map <char, vector<char>> grafo;
vector <vector<char>> nodos;
map <char, int> visitados;
int numSCC = 0, t = 0;
map <char, int> low;
map <char, bool> enPila;
stack <char> pila;
set <char> tnodos;

void tarjanAux(char nodo){
	low[nodo] = visitados[nodo] = ++t;
	pila.push(nodo);
	enPila[nodo] = true;

	for(int i = 0; i < grafo[nodo].size(); i++){
		char aux = grafo[nodo][i];
		if(visitados[aux] == -1){
			tarjanAux(aux);
			low[nodo] = min(low[nodo], low[aux]);
		}
		else if(enPila[aux])
			low[nodo] = min(low[nodo], visitados[aux]);
	}

	if(low[nodo] == visitados[nodo]){
		nodos.push_back(vector<char>());
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

void tarjan(){
	set <char> :: iterator it = tnodos.begin();
	for(; it != tnodos.end(); it++){
		visitados[*it] = low[*it] = -1;
		enPila[*it] = false;
	}
	it = tnodos.begin();

	for(; it != tnodos.end(); it++){
		if(visitados[*it] == -1)
			tarjanAux(*it);
	}
}