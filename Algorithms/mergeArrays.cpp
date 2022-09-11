#include <iostream>
#include <cstdio>
using namespace std;

void introducir(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;	
}

void mergeArrays(int arreglo3[], int arreglo1[], int arreglo2[], int tam1, int tam2){
	int i = 0, j = 0, k = 0; //i -> arr1, j -> arr2, k -> arr3
	if(tam1 > tam2){
		while(i < tam1){
			if(j == tam2)
				break;
			if(arreglo1[i] < arreglo2[i]){
				introducir(&arreglo3[k], &arreglo1[i]);
				k++;
				i++;
			}
			else if(arreglo1[i] >= arreglo2[j]){
				introducir(&arreglo3[k], &arreglo2[j]);
				j++;
				k++;
			}
		}
	}
	else{
		while(j < tam2){
			if(i == tam1)
				break;
			else if(arreglo2[j] < arreglo1[i]){
				introducir(&arreglo3[k], &arreglo2[j]);
				k++;
				j++;
			}
			else if(arreglo2[j] >= arreglo1[i]){
				introducir(&arreglo3[k], &arreglo1[i]);
				i++;
				k++;
			}
		}
	}
	while(i < tam1 || j < tam2){
		if(i == tam1){
			introducir(&arreglo3[k], &arreglo2[j]);
			j++;
			k++;
		}
		else{
			introducir(&arreglo3[k], &arreglo1[i]);
			i++;
			k++;
		}

	}
}

void printArray(int arr[], int n){
	for(int i = 0; i < n; i++){
		cout << arr[i] << " -> " << i << endl;
	}
}

int main(){
	int arreglo1[] = {1,2,3};
	int arreglo2[] = {1,2,3,4};
	int tam1 = sizeof(arreglo1)/sizeof(arreglo1[0]);
	int tam2 = sizeof(arreglo2)/sizeof(arreglo2[0]);
	int tam3 = tam1 + tam2;
	int arreglo3[tam3];
	cout << tam3 << " -> tam3" << endl;
	mergeArrays(arreglo3, arreglo1, arreglo2, tam1, tam2);
	printArray(arreglo3, tam3);
	return 0;
}