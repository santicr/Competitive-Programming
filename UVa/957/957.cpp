#include <iostream>
#include <vector>

using namespace std;

int bin_lower(vector <int> vec, int x, int size, int index){
	int low = index, high = size;
	while(low + 1 < high){
		int mid = (low + high) / 2;
		if(vec[mid] > x)
			high = mid;
		else
			low = mid;
	}
	return low;
}

int main(){
	int period, popes;

	while(cin >> period){
		cin >> popes;
		vector <int> vec;
		int res = 0, temp, temp_first = 0, temp_last = 0;

		for(int i = 0; i < popes; i++){
			cin >> temp;
			vec.push_back(temp);
		}

		for(int i = 0; i < vec.size(); i++){
			int temp = bin_lower(vec, vec[i] + period - 1, vec.size(), i);
			temp += 1;
			temp -= i;
			if(temp > res){
				temp_first = i;
				temp_last = bin_lower(vec, vec[i] + period - 1, vec.size(), i);
				res = temp;
			}
		}

		printf("%d %d %d\n", res, vec[temp_first], vec[temp_last]);
	
	}

	return 0;
}