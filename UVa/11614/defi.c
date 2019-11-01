#include <stdio.h>
#include <stdlib.h>

int main(){
	int casos;
	scanf("%d", &casos);
	while(casos--){
		long long int n;
		long long int indice = 0, sumatoria = 0;
		scanf("%lld", &n);
		if(n == 0)
			printf("%d -> %d\n", 0, 0);
		for(long long int i = 1; i < n; i++){
			sumatoria = sumatoria + i;
			if(n < sumatoria)
				break;
			else
				indice++;
		}
		if(n == 1)
			printf("%d -> %d\n", 1, 1);
		else if(indice > 0)
			printf("%lld -> %lld\n", indice, n);
	}
	return 0;
}