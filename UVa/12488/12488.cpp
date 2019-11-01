#include <iostream>
#include <vector>

using namespace std; 

void func(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int funcion(vector <int> vec1, vector <int> vec2){
	int res1 = 0, res2 = 0, i, j, n = 1;
	vector <int> vec3 = vec1, vec4 = vec2;

	for(i = 0; i < vec1.size(); i++){
		if(vec1[i] != vec2[i]){
			for(j = 0; j < vec1.size(); j++){
				if(i < j && vec1[j] == vec2[i]){
					func(&vec1[j], &vec1[j - 1]);
					res1++;
					j = 0;
				}
				if(i > j && vec1[j] == vec2[i]){
					func(&vec1[j], &vec1[j + 1]);
					res1++;
					j = 0;
				}
			}
			i = 0;
		}
	}

	return res1;
}

int main(){
	int n, i, num;
	while(cin >> n){
		vector <int> vec1, vec2;
		for(i = 0; i < n; i++){
			cin >> num;
			vec1.push_back(num);

		}

		for(i = 0; i < n; i++){
			cin >> num;
			vec2.push_back(num);
		}

		printf("%d\n", funcion(vec1, vec2));

	}


	return 0;
}