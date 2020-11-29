/*
Diametro arbol binario divide y venceras representacion con estructuras nodo
Autor: Carlos Ramirez
Fecha: Abril 18 de 2020

 */

#include <vector>
#include <iostream>

using namespace std;

struct Nodo{
  int info;
  struct Nodo *izq, *der;

  Nodo(int d){
    info = d;
    izq = NULL;
    der = NULL;
  }
  
  Nodo(int d, Nodo *n1, Nodo *n2){
    info = d;
    izq = n1;
    der = n2;
  }
};

int diametroAux(Nodo* v, int &altura){
  int altIzq = 0, altDer = 0, diamIzq = 0, diamDer = 0;
  
  //caso hoja
  if(v == NULL){
    altura = 0;
    return 0;
  }

  diamIzq = diametroAux(v->izq, altIzq);
  diamDer = diametroAux(v->der, altDer);
  altura = max(altIzq, altDer) + 1;

  return max(altIzq + altDer, max(diamIzq, diamDer));
}

int diametro(Nodo* v){
  int altura = 0;
  return diametroAux(v, altura);
}

int main(){ 
  Nodo* arbol1 = new Nodo(1, new Nodo(2, new Nodo(4, new Nodo(6),
					            NULL),
				        new Nodo(5, NULL,
					            new Nodo(7))),
			      new Nodo(3, new Nodo(8),
				          NULL));

  Nodo* arbol2 = new Nodo(1, new Nodo(2, new Nodo(4, new Nodo(6),
						     new Nodo(8, new Nodo(9),
							         new Nodo(10))),
				        new Nodo(5, NULL,
					            new Nodo(7))),
			    new Nodo(3));

  int diam = diametro(arbol1);
  cout << "El diametro del arbol es " << diam << endl;
  diam = diametro(arbol2);
  cout << "El diametro del arbol es " << diam << endl;
  
  return 0;
}
