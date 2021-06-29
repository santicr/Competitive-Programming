#include <bits/stdc++.h>

using namespace std;

int n, capacity = 0, capMax;
vector<vector<pair<int, int> > > grafo(50000);
vector<int> padres(502);
vector<int> distancias(502);
map <int, int> mapa;
int picks[502], deli[502], visitados[502];

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

int BFS(int nodo){
	int res = 0, nres = -1, nres2 = -1;
	bool flag = false;
	visitados[nodo] = 1;
	queue <int> cola;
	cola.push(nodo);

	while(!cola.empty()){
		int min1 = INT_MAX, min2 = INT_MAX;
		dijkstra(cola.front());

		for(int i = 0; i < n; i++){
			if(!visitados[i] && picks[i] && capacity < capMax){
				if(distancias[i] < min1){
					min1 = distancias[i];
					nres = i;
					flag = true;
				}
			}
		}

		for(int i = 0; i < n; i++){
			if(!visitados[i] && deli[i] && visitados[mapa[i]]){
				if(distancias[i] < min2){
					min2 = distancias[i];
					nres2 = i;
					flag = true;
				}
			}
		}

		if(flag){
			if(min1 < min2){
				visitados[nres] = 1;
				res += min1;
				flag = false;
				cola.push(nres);
				capacity++;
			}
			else{
				visitados[nres2] = 1;
				res += min2;
				flag = false;
				cola.push(nres2);
				capacity--;
			}
		}

		cola.pop();
	}

	return res;
}

int main(){

	int edges, order, c1, c2, w, start, pick, del;

	cin >> n >> edges >> order;

	while(!(n == 0 && edges == 0 && order == 0)){
		for(int i = 0; i < n; i++){
			visitados[i] = 0;
			deli[i] = 0;
			picks[i] = 0;
			grafo[i] = vector <pair<int,int>>();
		}

		for(int i = 0; i < edges; i++){
			cin >> c1 >> c2 >> w;
			grafo[c1 - 1].push_back(make_pair(c2 - 1, w));
			grafo[c2 - 1].push_back(make_pair(c1 - 1, w));
		}

		cin >> capMax >> start;

		for(int i = 0; i < order; i++){
			cin >> pick >> del;
			mapa[del - 1] = pick - 1;
			picks[pick - 1] = 1;
			deli[del - 1] = 1;
		}

		cout << BFS(start - 1) << endl;
		mapa.clear();
		capacity = 0;

		cin >> n >> edges >> order;

	}


	return 0;
}