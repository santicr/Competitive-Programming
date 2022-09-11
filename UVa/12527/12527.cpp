/* Nivel 3 */
#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N, M;
	while(scanf("%d %d", &N, &M) != EOF){
		int res = M - N + 1;
		vector <int> vec;
		for(int i = N; i <= M; i++){
			if(N >= 10 && N < 100){
				for(int j = 0; j < 2; j++){
					vec.push_back(N % 10);
					N /= 10;
				}
				for(int j = 0; j < vec.size(); j++){
					int temp = vec[j];
					for(int k = j + 1; k++ < vec.size(); k++){
						if(vec[k] == temp){
							res -= 1;
							break;
						}
					}
				}
			}
			if(N >= 100 && N < 1000){
				for(int j = 0; j < 3; j++){
					vec.push_back(N % 10);
					N /= 10;
				}
				for(int j = 0; j < vec.size(); j++){
					int temp = vec[j];
					for(int k = j + 1; k++ < vec.size(); k++){
						if(vec[k] == temp){
							res -= 1;
							break;
						}
					}
				}
			}
			if(N >= 1000){
				for(int j = 0; j < 4; j++){
					vec.push_back(N % 10);
					N /= 10;
				}
				for(int j = 0; j < vec.size(); j++){
					int temp = vec[j];
					for(int k = j + 1; k++ < vec.size(); k++){
						if(vec[k] == temp){
							res -= 1;
							break;
						}
					}
				}
			}
		}
		cout << res << endl;

	}
	return 0;
}