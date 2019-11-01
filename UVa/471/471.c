#include <stdlib.h>
#include <stdio.h>

typedef long long int lli;

int verificar(lli n){
	int arr[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int res = 1, i;
	while(n){
		arr[n % 10]++;
		n /= 10;
	}

	for(i = 0; i < 10; i++)
		res = (arr[i] >= 2) ? res = 0 : res;

	return res;
}

int main(){
	int casos;
	scanf("%d", &casos);
	while(casos--){
		lli entero, i, res = 1;
		scanf("%lld", &entero);
		for(i = 1; res < 9876543210; i++){
			res = entero * i;
			if(verificar(res) && verificar(i))
				printf("%lld / %lld = %lld\n", res, i, entero);
			if(res > 9876543210)
				break;
		}
		if(casos != 0)
			printf("\n");
	}	
	return 0;
}