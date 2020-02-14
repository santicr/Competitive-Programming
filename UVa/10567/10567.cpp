#include <iostream>
#include <string>
#include <map>

using namespace std;

int bin_lower(string str, char x){
	int low = 0, high = str.size();
	while(low + 1 < high){
		int mid = (low + high) / 2;
		if(str[mid] > x)
			high = mid;
		else
			low = mid;
	}
	return low;
}

int main(){
	string key;
	int queries;

	cin >> key;
	cin >> queries;

	while(queries--){
		string str;
		int indice = 0, index1, index2;
		bool paso = true;

		cin >> str;

		for(int i = 0; i < str.size(); i++){
			for(int j = indice; j < key.size(); j++){
				if(str[i] == key[j] && i == 0){
					index2 = j;
					index1 = j;
					indice = j + 1;
					break;
				}
				else if(str[i] == key[j] && i == str.size() - 1){
					indice = j + 1;
					index2 = j; 
					break;
				}
				else if(str[i] == key[j]){
					indice = j + 1;
					break;
				}
				else if(str[i] != key[j] && j == key.size() - 1){
					printf("Not matched\n");
					paso = false;
					break;
				}
			}
			if(indice >= key.size() && i < str.size() - 1){
				printf("Not matched\n");
				paso = false;
				break;
			}
			if(!paso)
				break;
		}

		if(paso)
			printf("Matched %d %d\n", index1, index2);

	}

	return 0;
}