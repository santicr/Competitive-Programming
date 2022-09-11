/* Nivel 1 */
#include <stdio.h>
#include <stdlib.h>

int main(){
	int casos;
	scanf("%d", &casos);
	while(casos--){
		int primero, segundo;
		scanf("%d %d", &primero, &segundo);
		if(primero > segundo)
			printf(">\n");
		else if(segundo > primero)
			printf("<\n");
		else
			printf("=\n");
	}


	return 0;
}