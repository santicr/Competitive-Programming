#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

struct Numm{

	int numero;
	int veces = 0;

};

bool funcion(Numm a, Numm b){
	if(a.veces < b.veces)
		return a.veces < b.veces;
}

int * frecuencySort(int arr[], int n){
	int* arrf = (int*)malloc(n * sizeof(int));
	Numm numeros[n];

	for(int i = 0; i < n; i++){
		numeros[i].numero = arr[i];
		for(int j = 0; j < n; j++){
			if(arr[j] == numeros[i].numero)
				numeros[i].veces++;
		}
	}

	sort(numeros, numeros + n, funcion);

	for(int i = 0; i < n; i++)
		arrf[i] = numeros[i].numero;
	return arrf;
}

int main(){
	int arr[5] = {2, 1, 1, 1, 2};
	int* arrf2 = frecuencySort(arr, 5);

	for(int i = 0; i < 5; i++)
		printf("%d ", *arrf2 + i);

	printf("\n");
	return 0;
}