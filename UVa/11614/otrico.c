#include <stdio.h>
#include <stdlib.h>

int main(){
	int casos;
	scanf("%d", &casos);
	while(casos--){
		long long int n, res = 0, indice = 1, i = 2, cont = 0;
		scanf("%lld", &n);
		while(n > 0){
			res = res + (indice * i);
			if(n < res)
				break;
			indice++;
			i++;
			cont++;
		}
		printf("%lld\n", cont);
	}

	return 0;
}