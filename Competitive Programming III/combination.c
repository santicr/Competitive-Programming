#include <stdio.h>
#include <stdlib.h>

int main(){
	int array[10], size, cont = 0;
	scanf("%d", &size);
	while(size != 0){
		for(int i = 0; i < size; i++)
			scanf("%d", &array[i]);

		for(int i = 0; i < size - 1; i++)
			for(int j = 0; j < size; j++){
				cont++;
				printf("%d %d\n", array[i], array[j]);
			}

		printf("%d\n", cont);
		scanf("%d", &size);
	}

	return 0;
}