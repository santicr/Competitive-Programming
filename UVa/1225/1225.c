#include <stdio.h>

int main(){
	int cases, i, number;
	scanf("%d", &cases);
	while(cases--){
		int array[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, temp, flag = 0;
		scanf("%d", &number);
		for(i = 0; i <= number; i++){
			temp = i;
			while(temp){
				array[temp % 10]++;
				temp /= 10;
			}
		}
		for(i = 0; i < 10; i++){
			if(flag)
				printf(" %d", array[i]);
			else{
				flag++;
				printf("%d", array[i]);
			}
		}
		printf("\n");
	}

	return 0;
}