/*
Diametro arbol n-ario divide y venceras representacion con estructuras nodo
Autor: Carlos Ramirez
Fecha: Abril 18 de 2020

 */

#include <vector>
#include <iostream>

using namespace std;

struct Nodo{
  int info;
  vector<Nodo*> hijos;
  
  Nodo(int d){
    info = d;
  }

  void agregarHijo(Nodo* n){
    hijos.push_back(n);
  }
};

int diametroAux(Nodo* v, int &altura){
  int i, maxDiam, alt1, alt2;
  maxDiam = alt1 = alt2 = altura = 0;
  Nodo *nodo;
  
  //caso hoja
  if((v->hijos).size() == 0){
    altura = 0;
    return 0;
  }

  for(i = 0; i < (v->hijos).size(); ++i){
    int alt;
    nodo = v->hijos[i];
    maxDiam = max(maxDiam, diametroAux(nodo, alt));
    altura = max(altura, alt + 1);

    if(alt + 1 > alt1){
      alt2 = alt1;
      alt1 = alt + 1;
    }
    else if(alt + 1 > alt2) 
      alt2 = alt + 1;
  }

  return max(alt1 + alt2, maxDiam);
}

int diametro(Nodo* v){
  int altura = 0;
  return diametroAux(v, altura);
}

int main(){ 
  Nodo* arbol1 = new Nodo(1);
  Nodo* arbol2 = new Nodo(2);
  Nodo* arbol3 = new Nodo(3);
  Nodo* arbol4 = new Nodo(4);
  Nodo* arbol5 = new Nodo(5);
  Nodo* arbol6 = new Nodo(6);
  Nodo* arbol7 = new Nodo(7);
  Nodo* arbol8 = new Nodo(8);
  Nodo* arbol9 = new Nodo(9);
  Nodo* arbol10 = new Nodo(10);
  Nodo* arbol11 = new Nodo(11);

  arbol9->agregarHijo(arbol11);
  arbol8->agregarHijo(arbol9);
  arbol8->agregarHijo(arbol10);
  arbol4->agregarHijo(arbol6);
  arbol4->agregarHijo(arbol8);
  arbol5->agregarHijo(arbol7);
  arbol2->agregarHijo(arbol4);
  arbol2->agregarHijo(arbol5);
  arbol1->agregarHijo(arbol2);
  arbol1->agregarHijo(arbol3);
  
  int diam = diametro(arbol1);
  cout << "El diametro del arbol es " << diam << endl;
  
  return 0;
}
