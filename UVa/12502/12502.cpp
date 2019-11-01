#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int cases, res2;
	scanf("%d", &cases);
	while(cases--){
		double a, b, paid, res;
		scanf("%lf %lf %lf", &a, &b, &paid);
		res = (paid / ((a + b) / 3)) * (a - ((a + b) / 3));
		res = ceil(10000 * res)/10000;
		res2 = res;
		if(res2 < 0)
			printf("0\n");
		else
			printf("%d\n", res2);
	}

	return 0;
}