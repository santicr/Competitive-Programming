#include <iostream>

using namespace std;

struct Nodo{
	int dato;
	struct Nodo * izquierda;
	struct Nodo * derecha;
};

typedef struct Nodo Nodo;

Nodo * nuevoNodo(int valor){
	Nodo * temp = (Nodo*)malloc(sizeof(Nodo));
	temp -> dato = valor;
	temp -> derecha = NULL;
	temp -> izquierda = NULL;
	return temp;
}

void insertar(int valor, Nodo ** cabeza){
	
}

int main(){
	Nodo * cabeza;
	cabeza = nuevoNodo(8);
	cout << cabeza -> dato << endl;
	return 0;
}