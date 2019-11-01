#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int number, i, j, array[1003];
	while(scanf("%d", &number) != EOF){
		int res = 0;

		for(i = 0; i < number; i++)
			scanf("%d", &array[i]);

		for(i = 0; i < number; i++){
			for(j = 0; j < number - i - 1; j++){
				if(array[j] > array[j + 1]){
					swap(&array[j], &array[j + 1]);
					res++;
				}
			}
		}

		printf("Minimum exchange operations : %d\n", res);
	}

	return 0;
}