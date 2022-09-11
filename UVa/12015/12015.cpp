#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
	int casos;
	cin >> casos;

	for(int o = 0; o < casos; o++){
		string cadena;
		string arreglo[10];
		string res[10];
		int arreglo2[10];
		int relevancia, indice = 0, mayor = 0, indice2 = 0;

		for(int i = 0; i < 10; i++){
			char temp[102];
			scanf("%s %d", temp, &relevancia);
			cadena = temp;
			arreglo[indice] = cadena;
			arreglo2[indice] = relevancia;
			indice++;
		}

		for(int i = 0; i < 10; i++){
			if(arreglo2[i] >= mayor){
				mayor = arreglo2[i];
			}
		}

		for(int i = 0; i < 10; i++){
			if(arreglo2[i] == mayor){
				res[indice2] = arreglo[i];
				indice2++;
			}
		}

		cout << "Case #" << o+1 << ":" << endl;
		for(int i = 0; i < indice2 + 1; i++){
			cout << res[i];
			if(i != indice2)
				cout << endl;
		}
	}


	return 0;
}