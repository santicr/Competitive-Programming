/*
Diametro arbol n-ario representacion listas de adyacencia
Autor: Carlos Ramirez
Fecha: Abril 18 de 2020

Este algoritmo requiere que se conozca cual es la raiz del arbol.

*/

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int n;
vector<vector<int> > adj(50000);
vector<int> alturas(50000);

int diametroAux(int v, int padre){
  int i, maxDiam, nodo, alt1, alt2;
  maxDiam = alt1 = alt2 = 0;

  for(i = 0; i < adj[v].size(); ++i){
    nodo = adj[v][i];
    if(nodo != padre){
      maxDiam = max(maxDiam, diametroAux(nodo, v));
      alturas[v] = max(alturas[v], alturas[nodo] + 1);

      if(alturas[nodo] + 1 > alt1){
	alt2 = alt1;
	alt1 = alturas[nodo] + 1;
      }
      else if(alturas[nodo] + 1 > alt2)
	alt2 = alturas[nodo] + 1;
    }
  }

  return max(alt1 + alt2, maxDiam);
}

int diametro(){
  //se escoge arbitrariamente iniciar en el nodo 0
  //el resultado seria el mismo asi se inicie en un nodo diferente
  return diametroAux(0, -1);
}

int main(){
  int m, i, aux1, aux2, diam;

  cin >> n >> m;

  for(i = 0; i < m; i++){
    cin >> aux1 >> aux2;
    adj[aux1].push_back(aux2);
  }

  diam = diametro();
  cout << "El diametro del arbol es " << diam << endl;
  cout << "La altura del arbol es " << alturas[0] << endl;
   
  return 0;
}
