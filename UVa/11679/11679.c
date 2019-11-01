#include <stdio.h>
#include <stdlib.h>

int main(){
	int B, N;
	scanf("%d %d", &B, &N);
	while(B != 0 && N != 0){
		int reser[22], D, C, V, entro = 0, i;

		for(i = 0; i < B; i++)
			scanf("%d", &reser[i]);

		for(i = 0; i < N; i++){
			scanf("%d %d %d", &D, &C, &V);
			reser[D - 1] -= V;
			reser[C - 1] += V;
		}

		for(i = 0; i < B; i++){
			if(reser[i] < 0){
				printf("N\n");
				entro = 1;
				break;
			}
		}

		if(entro == 0)
			printf("S\n");

		scanf("%d %d", &B, &N);


	}

	return 0;
}