/*
Radio y centro arbol n-ario representacion listas de adyacencia
Autor: Carlos Ramirez
Fecha: Abril 18 de 2020

*/

#include <vector>
#include <queue>
#include <iostream>
#include <set>

using namespace std;

int n, distMax, nodoMax;
vector<vector<int> > adj(50000);
int grado[50000];
int nivel[50000];
set<int> nodosCentro;

void dfsAux(int v, int padre, int dist){
  int w, i;
  dist++;

  if(dist > distMax){
    distMax = dist;
    nodoMax = v;
  }
  
  for(i = 0; i < adj[v].size(); ++i){
    w = adj[v][i];
    if(w != padre)
      dfsAux(w, v, dist);
  }
}

int diametro(){
  distMax = 0;
  nodoMax = -1;

  //se escoge arbitrariamente iniciar en el nodo 0
  //el resultado seria el mismo asi se inicie en un nodo diferente
  dfsAux(0, -1, -1);
  dfsAux(nodoMax, -1, -1);
  
  return distMax;
}

int radio(){
  int diam = diametro();
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
  cout << "El radio del arbol es " << radio << endl;
}

int main(){
  int m, i, aux1, aux2, rad;

  cin >> n >> m;

  for(i = 0; i < m; i++){
    cin >> aux1 >> aux2;
    adj[aux1 - 1].push_back(aux2 - 1);
    adj[aux2 - 1].push_back(aux1 - 1);
  }

  rad = radio();
  cout << "El radio del arbol es " << rad << endl;

  centro();
  cout << "Nodos en el centro del arbol:";
  for(set<int>::iterator it = nodosCentro.begin(); it != nodosCentro.end(); ++it)
    cout << " " << *it;
  cout << endl;
  
  return 0;
}
