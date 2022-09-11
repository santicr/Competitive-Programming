#include <iostream>
#include <list>

using namespace std;

struct pareja{
	int dato;
	int veces;
};

typedef struct pareja Pareja;

list <Pareja> countingPair(list <int> lista){
	list <Pareja> res;
	for(auto it = lista.begin(); it != lista.end(); it++){
		bool verificar = false;
		Pareja temp;
		temp.dato = *it;
		temp.veces = 1;
		for(auto itt = res.begin(); itt != res.end(); itt++){
			if(itt -> dato == temp.dato){
				itt -> veces++;
				verificar = true;
			}
		}
		if(verificar == false)
			res.push_back(temp);
	}

	return res;
}

void printList(list <Pareja> l){
	for(auto it = l.begin(); it != l.end(); it++){
		cout << it -> dato << " -> " << it -> veces << endl;	
	}
}

int main(){
	list <int> lista = {2, 4, 2, 3, 1, 2, 5, 6, 7, 1, 2, 5};
	list <Pareja> l = countingPair(lista);
	printList(l);
	return 0;
}