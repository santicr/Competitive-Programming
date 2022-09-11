#include <stdio.h>

long long int pot(long long int a, long long int b){
	long long int i, ans = 1;
	for(i = 0; i < b; i++)
		ans *= a;
	return ans;
}

long long int func(long long int n){
	long long int i, res = 0;
	for(i = 1; i <= n; i++)
		res += pot(i, i);
	return res;
}

int main(){
	long long int n;
	scanf("%lld", &n);
	while(n){
		printf("%lld\n", func(n));

		scanf("%lld", &n);
	}

	return 0;
}