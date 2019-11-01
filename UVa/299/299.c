#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int cases, array[52], i, j;
	scanf("%d", &cases);
	while(cases--){
		int size, res = 0;
		scanf("%d", &size);
		for(i = 0; i < size; i++)
			scanf("%d", &array[i]);
		for(i = 0; i < size; i++){
			for(j = 0; j < size - i - 1; j++){
				if(array[j] > array[j + 1]){
					swap(&array[j], &array[j + 1]);
					res++;
				}
			}
		}
		printf("Optimal train swapping takes %d swaps.\n", res);
	}

	return 0;
}