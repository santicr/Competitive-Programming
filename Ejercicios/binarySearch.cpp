#include <iostream>
#include <vector>

using namespace std;

int bin_lower(vector <int> vec, int x){
	int low = 0, high = vec.size();
	while(low + 1 < high){
		int mid = (low + high) / 2;
		if(vec[mid] > x)
			high = mid;
		else
			low = mid;
	}
	return low;
}

int bin_upper(vector <int> vec, int x){
	int low = -1, high = vec.size() - 1;
	while(low + 1 < high){
		int mid = (high + low) / 2;
		if(vec[mid] >= x)
			high = mid;
		else
			low = mid;
	}
	return high;
}

int main(){

	vector <int> vec = {1, 2, 3, 5, 6, 7, 9};

	cout << bin_lower(vec, 8) << endl;

	cout << bin_upper(vec, 8) << endl;

	return 0;
}