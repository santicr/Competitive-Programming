#include <iostream>
#include <cstdio>

using namespace std;

void swap(int *xp, int *yp){ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

void bubbleSort(int arr[], int n){ 
   int i, j; 
   for (i = 0; i < n-1; i++)   
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 

void printArray(int arr[], int n){
	for(int i = 0; i < n; i++){
		cout << arr[i] << endl;
	}
}

int main(){
	int arr[] = {5,4,3,2,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << n << " -> tamaño " << endl;
	bubbleSort(arr, n);
	printArray(arr, n);

	return 0;
}