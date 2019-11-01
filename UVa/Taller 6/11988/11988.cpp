#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <list>

using namespace std;

/* La complejidad de este ejercicio es de O(n^2), es aceptado debido a que no sobrepasa los límites
	de UVa en donde su complejidad es hasta 10^9*/

int main(){
	char Cad[100003] = "";
	while(scanf("%s", Cad) != EOF){
		string Cadena = Cad;
		list <char> Resultado;
		stack <char> Pila;
		int Caso = 1, aux = Caso;

		for(int i = 0; i < Cadena.size(); i++){
			if(Cadena[i] == '['){
				Caso = 2;
				while(!Pila.empty()){
					Resultado.push_front(Pila.top());
					Pila.pop();
				}
			}
			else if(Cadena[i] == ']'){
				Caso = 1;
				while(!Pila.empty()){
					Resultado.push_front(Pila.top());
					Pila.pop();
				}
			}
			else if(Caso == 1){
				Resultado.push_back(Cadena[i]);
			}
			else if(Caso == 2)
				Pila.push(Cadena[i]);
		}
		while(!Pila.empty()){
			Resultado.push_front(Pila.top());
			Pila.pop();
		}
		for(list<char>::iterator it = Resultado.begin(); it != Resultado.end(); ++it){
			cout << *it;
		}

		cout << endl;
	}

	return 0;
}