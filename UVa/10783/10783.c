#include <stdio.h>

int main(){
	int cases, i, j, num1, num2;
	scanf("%d", &cases);
	for(i = 0; i < cases; i++){
		int res = 0;
		scanf("%d", &num1);
		scanf("%d", &num2);
		
		for(j = num1; j <= num2; j++)
			res = (j % 2 != 0) ? res += j : res;

		printf("Case %d: %d\n", i + 1, res);
	}

	return 0;
}