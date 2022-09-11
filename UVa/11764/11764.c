#include <stdlib.h>
#include <stdio.h>

int main(){
	int casos, i;
	scanf("%d", &casos);
	for(i = 0; i < casos; i++){
		int paredes, indice = 0, j, altos = 0, bajos = 0;
		int saltos[50];
		scanf("%d", &paredes);

		while(paredes--){
			int salto;
			scanf("%d", &salto);
			saltos[indice] = salto;
			indice++;
		}

		for(j = 0; j < indice; j++){
			if(j == indice - 1)
				break;
			else if(saltos[j] < saltos[j + 1])
				altos++;
			else if(saltos[j] > saltos[j + 1])
				bajos++;
		}
		printf("Case %d: %d %d\n", i + 1, altos, bajos);
	}

	return 0;
}