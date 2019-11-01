#include <iostream>

using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int * bubbleSort(int arr[], int tam){
	for(int i = 0; i < tam; i++){
		for(int j = 0; j < tam - i - 1; j++){
			if(arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
	return arr;
}

int main(){
	int arr[6] = {1, 3, 2, 4, 5, 6};
	int *arr2 = (int*)malloc(6 * sizeof(int));
	arr2 = bubbleSort(arr, 6);
	for(int i = 0; i < 6; i++)
		cout << *arr2 + i << " ";
	cout << endl;
	return 0;
}