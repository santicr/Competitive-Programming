#include <stdio.h>

int func(int n){
	int sum = 0;
	while(n){
		sum += ((n % 10) * (n % 10));
		n /= 10;
	}
	return sum;
}

int main(){
	int cases, i, res, number;
	scanf("%d", &cases);
	for(i = 0; i < cases; i++){
		scanf("%d", &number);
		res = func(number);

		while(res != 4 || res != 1){
			if(res == 4)
				break;
			else if(res == 1)
				break;
			res = func(res);
		}

		if(res == 4)
			printf("Case #%d: %d is an Unhappy number.\n", i + 1, number);
		
		else
			printf("Case #%d: %d is a Happy number.\n", i + 1, number);
	}

	return 0;
}