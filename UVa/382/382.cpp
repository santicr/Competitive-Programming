/* Nivel 1 */
#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	printf("PERFECTION OUTPUT\n");

	while(N != 0){
		int temp = 0;
		vector <int> vec;

		for(int i = 1; i < N; i++){
			if(N % i == 0)
				vec.push_back(i);
		}

		for(int i = 0; i < vec.size(); i++)
			temp += vec[i];

		if(temp == N)
			printf("%5d  PERFECT\n", N);

		else if(temp > N)
			printf("%5d  ABUNDANT\n", N);

		else
			printf("%5d  DEFICIENT\n", N);

		scanf("%d", &N);
	}

	printf("END OF OUTPUT\n");
	return 0;
}