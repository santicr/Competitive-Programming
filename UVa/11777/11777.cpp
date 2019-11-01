#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int cases, i; 
	float term1, term2, final, attendance, test1, test2, test3;
	cin >> cases;
	for(i = 0; i < cases; i++){
		vector <float> vec;

		scanf("%f %f %f %f %f %f %f", &term1, &term2, &final, &attendance, 
				&test1, &test2, &test3);
		double res = term1 + term2 + final + attendance;

		vec.push_back(test1);
		vec.push_back(test2);
		vec.push_back(test3);
		sort(vec.begin(), vec.end());

		res += ((vec[1] + vec[2]) / 2);

		if(res >= 90)
			printf("Case %d: A\n", i + 1);
		else if(res >= 80 && res < 90)
			printf("Case %d: B\n", i + 1);
		else if(res >= 70 && res < 80)
			printf("Case %d: C\n", i + 1);
		else if(res >= 60 && res < 70)
			printf("Case %d: D\n", i + 1);
		else
			printf("Case %d: F\n", i + 1);
	}

	return 0;
}
