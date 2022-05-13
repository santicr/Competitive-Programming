#include <stdio.h>
#include <stdlib.h>

int array[10];

int fact(int n){
	if(n <= 1)
		array[n] = 1;
	else if(array[n] == 0)
		array[n] = n * fact(n - 1);
	return array[n];
}

int main(){
	array[0] = 1;
	int i, n;
	scanf("%d", &n);
	printf("%d\n", fact(n));
	for(i = 0; i < 10; i++)
		printf("%d\n", array[i]);

	return 0;
}