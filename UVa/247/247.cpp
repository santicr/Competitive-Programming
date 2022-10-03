#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> grafo;
vector <vector<int>> nodos;
int visitados[26];
int numSCC = 0, t = 0;
int low[26];
bool enPila[26];
stack <int> pila;
int n, m;

map <string, int> mapa;
map <int, string> mapa2;

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
	string u, v;
	int it = 0, cases = 1;

	cin >> n >> m;

	while(n != 0 && m != 0){
		grafo = vector <vector<int>> (n);

		while(m--){
			cin >> u >> v;

			if(mapa.find(u) == mapa.end()){
				mapa[u] = it++;
				mapa2[it - 1] = u;
			}
			if(mapa.find(v) == mapa.end()){
				mapa[v] = it++;
				mapa2[it - 1] = v;
			}

			grafo[mapa[u]].push_back(mapa[v]);
		}

		tarjan(n);

		if(!(cases - 1))
			printf("Calling circles for data set %d:\n", cases++);
		else
			printf("\nCalling circles for data set %d:\n", cases++);

		for(int i = 0; i < numSCC; i++){
			for(int j = 0; j < nodos[i].size(); j++){
				if(!j)
					cout << mapa2[nodos[i][j]];
				else
					cout << ", " << mapa2[nodos[i][j]];
			}
			cout << endl;
		}

		cin >> n >> m;

		mapa.clear();
		mapa2.clear();
		t = 0;
		numSCC = 0;
		nodos.clear();
		pila = stack <int>();
		it = 0;

	}

	return 0;
}