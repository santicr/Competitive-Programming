#include <stdio.h>
#include <stdlib.h>

void swap(long long int *a, long long int *b){
	long long int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	long long int size, i, j, array[500004];
	scanf("%lld", &size);
	while(size != 0){
		long long int res = 0;

		for(i = 0; i < size; i++)
			scanf("%lld", &array[i]);

		for(i = 0; i < size; i++){
			for(j = 0; j < size - i - 1; j++){
				if(array[j] > array[j + 1]){
					swap(&array[j], &array[j + 1]);
					res++;
				}
			}
		}

		printf("%lld\n", res);


		scanf("%lld", &size);
	}


	return 0;
}