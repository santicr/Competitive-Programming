#include <bits/stdc++.h>

using namespace std;

int n, distMax, nodoMax;
vector<vector<int> > adj(5002);
int grado[50000];
int nivel[50000];
set<int> nodosCentro;
set <int> nodosRes;

void dfsAux(int v, int padre, int dist){
  int w, i;
  dist++;

  if(dist > distMax){
    distMax = dist;
    nodoMax = v;
    nodosRes.clear();
    nodosRes.insert(v);
  }
  else if(dist == distMax){
      nodosRes.insert(v);
  }
  
  for(i = 0; i < adj[v].size(); ++i){
    w = adj[v][i];
    if(w != padre)
      dfsAux(w, v, dist);
  }
}

int diametro(int nodo){
  distMax = 0;
  nodoMax = -1;

  dfsAux(nodo, -1, -1);
  dfsAux(nodoMax, -1, -1);
  dfsAux(nodoMax, -1, -1);
  
  return distMax;
}

int radio(int nodo){
  int diam = diametro(nodo);
  return (diam + 1) / 2;
}

void centro(){
  int i, v, nivelMax = 0, radio;
  queue<int> cola;

  for(i = 0; i < n; ++i){
    nivel[i] = 0;
    grado[i] = adj[i].size();
  }

  for(i = 0; i < n; ++i)
    if(grado[i] == 1)
        cola.push(i);

  while(!cola.empty()){
    v = cola.front();
    cola.pop();

    for(i = 0; i < adj[v].size(); ++i){
      grado[adj[v][i]]--;
      if(grado[adj[v][i]] == 1){
	cola.push(adj[v][i]);
	nivel[adj[v][i]] = nivel[v] + 1;
	nivelMax = max(nivelMax, nivel[adj[v][i]]);
      }
    }
  }

  for(i = 0; i < n; ++i)
    if(nivel[i] == nivelMax)
      nodosCentro.insert(i);

  radio = (nodosCentro.size() >= 2) ? nivelMax + 1 : nivelMax;
}

int main(){
    int conex, aux1, indice = 0;
    while(cin >> n){
        int res = -1, res2 = INT_MAX;
        set <int> :: iterator it;

        for(int i = 0; i < n; i++){
            cin >> conex;
            for(int j = 0; j < conex; j++){
                cin >> aux1;
                adj[indice].push_back(aux1 - 1);
            }

            indice++;
        }

        centro();
        cout << "Best Roots  :";

        for(it = nodosCentro.begin(); it != nodosCentro.end(); it++)
            cout << " " << *it + 1;
            
        cout << endl;
        cout << "Worst Roots :";
        diametro(0);

        for(it = nodosRes.begin(); it != nodosRes.end(); it++)
            cout << " " << *it + 1;
        
        cout << endl;

        for(int i = 0; i < n; i++)
            adj[i] = vector <int> ();

        nodosRes.clear();
        nodosCentro.clear();
        indice = 0;
    }

    return 0;
}