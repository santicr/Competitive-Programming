#include <stdio.h>
#include <stdlib.h>

int main(){
	int size, array[19], i, j, indice = 0;
	while(scanf("%d", &size) != EOF){
		for(i = 0; i < size; i++)
			scanf("%d", &array[i]);

		long long int mult = 1, flag = 0;
		for(i = 0; i < size; i++){
			mult *= array[i];
			for(j = i + 1; j < size; j++){
				mult *= array[j];
				if(mult > flag)
					flag = mult;
			}
			mult = 1;
		}
		for(i = 0; i < size; i++)
			flag = (array[i] > flag) ? flag = array[i] : flag;

		indice++;

		printf("Case #%d: The maximum product is %lld.\n", indice, flag);
		printf("\n");
	}
	return 0;
}