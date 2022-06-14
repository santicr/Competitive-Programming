#include <bits/stdc++.h>

using namespace std;

int bin_lower(vector <int> vec, int x){
	int low = 0, high = vec.size();
	while(low + 1< high){
		int mid = (low + high) / 2;
		if(vec[mid] > x)
			high = mid;
		else
			low = mid;
	}
	return low;
}

int main(){
	int n, val, idx, ii, ij, mAns;

	while(cin >> n){
		vector <int> vec;
		mAns = INT_MAX;

		for(int i = 0; i < n; i++){
			cin >> val;
			vec.push_back(val);
		}
		cin >> val;

		sort(vec.begin(), vec.end());

		for(int i = 0; i < n; i++){
			if(val >= vec[i]){
				idx = bin_lower(vec, val - vec[i]);
				if(vec[idx] + vec[i] == val && idx != i && abs(vec[idx] - vec[i]) < mAns){
					if(idx <= i){
						ii = idx;
						ij = i;
					}
					else{
						ii = i;
						ij = idx;
					}
					mAns = abs(vec[idx] - vec[i]);
				}

			}
		}

		printf("Peter should buy books whose prices are %d and %d.\n", vec[ii], vec[ij]);
		printf("\n");
	}


	return 0;
}