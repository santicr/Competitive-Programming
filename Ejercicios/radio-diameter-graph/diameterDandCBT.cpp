/*
Diametro arbol binario representacion listas de adyacencia
Autor: Carlos Ramirez
Fecha: Abril 18 de 2020

Este algoritmo requiere que se conozca cual es la raiz del arbol y solo
se incluye la arista que conecta un padre con su hijo pero no viceversa

 */

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int n;
vector<vector<int> > adj(50000);
vector<int> alturas(50000);

int diametro(int v){
  int diamIzq, diamDer, nodoIzq, nodoDer, alt1, alt2;
  diamIzq = diamDer = alt1 = alt2 = 0;
  
  //caso hoja
  if(adj[v].size() == 0){
    alturas[v] = 0;
    return 0;
  }

  nodoIzq = adj[v][0];
  diamIzq = diametro(nodoIzq);
  alturas[v] = alturas[nodoIzq] + 1;
  alt1 = alturas[nodoIzq] + 1;
  
  if(adj[v].size() > 1){
    nodoDer = adj[v][1];
    diamDer = diametro(nodoDer);
    alturas[v] = max(alturas[v], alturas[nodoDer] + 1);
    alt2 = alturas[nodoDer] + 1;
  }

  return max(alt1 + alt2, max(diamIzq, diamDer));
}

int main(){
  int m, i, aux1, aux2, diam;

  cin >> n >> m;

  for(i = 0; i < m; i++){
    cin >> aux1 >> aux2;
    adj[aux1].push_back(aux2);
  }

  diam = diametro(0);
  cout << "El diametro del arbol es " << diam << endl;
  cout << "La altura del arbol es " << alturas[0] << endl;
  
  return 0;
}
