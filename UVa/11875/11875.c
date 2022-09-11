#include <stdlib.h>
#include <stdio.h>

int main(){
	int casos;
	scanf("%d", &casos);
	for(int i = 0; i < casos; i++){
		int lett, indice = 0;
		scanf("%d", &lett);
		int arreglo[11];
		for(int j = 0; j < lett; j++){
			int n;
			scanf("%d", &n);
			arreglo[indice] = n;
			indice++;
		}
		int pos = lett / 2;
		printf("Case %d: %d\n", i + 1, arreglo[pos]);
	}
	return 0;
}