#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	int casos;
	scanf("%d", &casos);
	while(casos--){
		int i = 0, indice = 0, res = 0, j, temp;
		char arreglo[17];

		for(i = 0; i < 4; i++){
			char x[5];
			scanf("%s", x);
			for(j = 0; j < 4; j++){
				arreglo[indice] = x[j];
				indice++;
			}
		}

		for(i = 0; i < 16; i++){
			if(i % 2 == 0){
				temp = arreglo[i] - '0';
				temp *= 2;
				while(temp){
					res += temp % 10;
					temp /= 10;
				}
			}
			else{
				temp = arreglo[i] - '0';
				res += temp;
			}
		}
		
		if(res % 10 != 0)
			printf("Invalid\n");
		else
			printf("Valid\n");

	}

	return 0;
}