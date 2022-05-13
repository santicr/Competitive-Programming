/*
Diametro arbol n-ario representacion listas de adyacencia
Autor: Carlos Ramirez
Fecha: Abril 18 de 2020

Algoritmo que hace dos DFS

*/

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int n, distMax, nodoMax;
vector<vector<int> > adj(50000);

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

  //se escoge arbitrariamente iniciar en el nodo 0
  //el resultado seria el mismo asi se inicie en un nodo diferente
  dfsAux(0, -1, -1);
  dfsAux(nodoMax, -1, -1);
  
  return distMax;
}

int main(){
  int m, i, aux1, aux2, diam;

  cin >> n >> m;

  for(i = 0; i < m; i++){
    cin >> aux1 >> aux2;
    adj[aux1 - 1].push_back(aux2 - 1);
    adj[aux2 - 1].push_back(aux1 - 1);
  }

  diam = diametro();
  cout << "El diametro del arbol es " << diam << endl;
  
  return 0;
}
