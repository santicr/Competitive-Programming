#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<pair<int, int> > > grafo(502);
vector<int> distancias(502);
vector<int> distancias2;
vector<int> fstations;

void inicializar(int nodo){
	for(int i = 0; i < n; i++)
		distancias[i] = INT_MAX;
}

void dijkstra(int nodo){
	int peso, costo, val;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > cola;
	distancias[nodo] = 0;
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
					cola.push(make_pair(distancias[aux], aux));
				}
			}
		}
	}
}

int main(){
	int cases, f, fn, u, v, w, mNum, mM;
	vector<int> :: iterator it;
	string str;
	cin >> cases;

	while(cases--){
		vector <int> fs(502, 0);
		fstations = vector <int> ();
		str = "";
		int ans = 1;

		cin >> f >> n;

		for(int i = 0; i < f; i++){
			cin >> fn;
			fstations.push_back(fn - 1);
			fs[fn - 1] = 1;
		}
		cin.ignore();

		while(getline(cin, str)){
			if(str == "") break;
			int flag = 0;
			int index = 0;
			for(int i = 0; i < str.size(); i++){
				if(str[i] == ' '){
					if(flag == 0)
						u = stoi(str.substr(index, i - index));
					else if(flag == 1)
						v = stoi(str.substr(index, i - index));
					index = i + 1;
					flag++;
				}
				if(i == str.size() - 1)
					w = stoi(str.substr(index, (i + 1) - index));
			}
			grafo[u - 1].push_back({v - 1, w});
			grafo[v - 1].push_back({u - 1, w});
		}

		for(int i = 0; i < f; i++){
			if(i == 0)
				inicializar(fstations[i]);
			dijkstra(fstations[i]);
		}

		it = distancias.begin();
		mNum = *max_element(it, it + n);
		distancias2 = distancias;

		for(int i = 0; i < n; i++){
			if(fs[i] != 1){
				distancias2 = distancias;
				dijkstra(i);
				it = distancias.begin();
				mM = *max_element(it, it + n);
				if(mM < mNum){
					ans = i + 1;
					mNum = mM;
				}
			}
			distancias = distancias2;
		}

		for(int i = 0; i < n + 1; i++){
			distancias[i] = INT_MAX;
			grafo[i] = vector <pair <int, int>> ();
		}

		cout << ans << endl;
		if(cases)
			cout << endl;
	}

	return 0;
}