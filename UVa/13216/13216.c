/* Nivel 0 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
	int casos;
	scanf("%d", &casos);
	while(casos--){
		char n[10000] = "";
		long long int res = 1;
		int arreglo[5] = {76, 16, 56, 96, 36};
		scanf("%s", n);
		if(strlen(n) == 1){
			int i, otro = n[0] - '0';
			for(i = 0; i < otro; i++){
				res *= 66;
			}
			printf("%lld\n", res % 100);
		}
		else{
			int ultima_pos = strlen(n) - 1;
			int num = n[ultima_pos] - '0';
			if(num >= 5){
				int pos = num - 5;
				printf("%d\n", arreglo[pos]);
			}
			else
				printf("%d\n", arreglo[num]);
		}

	}	

	return 0;
}