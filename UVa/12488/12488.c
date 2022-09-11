#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int funcion(int * arr, int n, int * arr2){
	int i, res = 0, j, aux = n, temp;
	for(i = n - 1; i >= 0; i--){
		if(arr[i] != arr2[i]){
			for(j = 0; j < n; j++){
				if(arr2[j] == arr[i])
					temp = j;
			}
			for(j = i; j > temp; j--){
				swap(&arr[j], &arr[j - 1]);
				res++;
			}
			printf("\n");
			for(j = 0; j < n; j++)
				printf("%d ", arr[j]);
			printf("\n");
		}
	}

	return res;
}

int main(){
	int N, i;
	while(scanf("%d", &N) != EOF){
		int* arreglo_ini = (int*)malloc(N * sizeof(int));
		int* arreglo_fin = (int*)malloc(N * sizeof(int));

		for(i = 0; i < N; i++)
			scanf("%d", &arreglo_ini[i]);

		for(i = 0; i < N; i++)
			scanf("%d", &arreglo_fin[i]);

		printf("%d\n", funcion(arreglo_ini, N, arreglo_fin));


	}


	return 0;
}