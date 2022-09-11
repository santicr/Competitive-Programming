#include <iostream>
#include <string>

using namespace std;

struct carro{
	string nombre;
	int min;
	int max;
};

typedef struct carro Carro;

int main(){
	int casos;
	cin >> casos;
	for(int i = 0; i < casos; i++){
		int base_datos, precio, longitud = 0, indice = 0;
		cin >> base_datos;
		Carro arreglo[10003];

		while(base_datos--){
			string nom;
			char nombre[21];
			int minimo, maximo;
			scanf("%s %d %d", nombre, &minimo, &maximo);
			nom = nombre;
			arreglo[indice].nombre = nom;
			arreglo[indice].min = minimo;
			arreglo[indice].max = maximo;
			indice++;
			longitud++;
		}

		cin >> precio;
		
		while(precio--){
			int valor, verificacion = 0, no_es = 0;
			string res;
			cin >> valor;
			for(int j = 0; j < longitud; j++){
				if(valor >= arreglo[j].min && valor <= arreglo[j].max){
					res = arreglo[j].nombre;
					verificacion++;
				}
			}
			if(verificacion == 1)
				cout << res << endl;
			else
				cout << "UNDETERMINED" << endl;
		}
		if(i != casos-1)
			cout << endl;
	}

	return 0;
}