#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int casos, i;
	scanf("%d", &casos);
	for(i = 0; i < casos; i++){
		int j, indice = 0, mayor = 0, k;
		int arreglo_int[11];
		char arreglo_char[11][105];

		for(j = 0; j < 10; j++){
			char cadena[105];
			int relevancia;
			scanf("%s %d", cadena, &relevancia);
			int longitud = strlen(cadena);
			arreglo_int[indice] = relevancia;
			for(k = 0; k < longitud; k++){
				arreglo_char[j][k] = cadena[k];
				//printf("%c\n", arreglo_char[j][k]);
			}
			indice++;
			memset(cadena, 0, sizeof cadena);
		}

		for(j = 0; j < 10; j++){
			if(mayor < arreglo_int[j])
				mayor = arreglo_int[j];
		}
		printf("Case #%d:\n", i+1);

		for(j = 0; j < 10; j++){
			if(arreglo_int[j] == mayor){
				printf("%s", arreglo_char[j]);
				printf("\n");
			}
		}

	}


	return 0;
}