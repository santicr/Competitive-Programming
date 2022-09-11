#include <stdlib.h>
#include <stdio.h>

typedef long long int lld;

int verificacion(lld n, lld r){
	int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i, verifica = 1, indice = 0, indice2 = 0;

	while(n){
		arr[n % 10]++;
		n /= 10;
		indice2++;
	}

	while(r){
		arr[r % 10]++;
		r /= 10;
		indice++;
	}

	arr[0] = (indice == 4) ? arr[0] += 1 : arr[0];
	arr[0] = (indice2 == 4) ? arr[0] += 1 : arr[0];

	for(i = 0; i < 10; i++)
		verifica = (arr[i] >= 2) ? verifica = 0 : verifica;

	return verifica;

}

int main(){
	lld n, i;
	scanf("%lld", &n);
	while(n != 0){
		lld res, verdad = 0;
		for(i = 1234; i <= 98765; i++){
			res = i * n;
			if(res > 98765)
				break;

			if(verificacion(res, i)){
				verdad = 1;
				printf("%05lld / %05lld = %lld\n", res, i, n);
			}
		}
		if(!verdad)
			printf("There are no solutions for %lld.\n", n);
		scanf("%lld", &n);
		if(n > 0)
			printf("\n");
	}


	return 0;
}