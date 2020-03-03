 #include <bits/stdc++.h>

using namespace std;

int size1 = 0;
vector <int> vec1;

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

bool backtrack(vector <int> vec, int index, int n, int acum){
	if(acum == n){
		vec1.push_back(acum);
		return true;
	}

	else if(acum > n){
		vec1.push_back(acum);
		return false;
	}

	else if(index == vec.size()){
		vec1.push_back(acum);
		return false;
	}
	return backtrack(vec, index + 1, n, acum + vec[index]) || backtrack(vec, index + 1, n, acum);
}

bool backtrack1(vector <int> vec, int index, int n, int acum, int arr[], int i, int size){
	if(acum == n){
		size1 = size;
		return true;
	}

	else if(acum > n){
		return false;
	}

	else if(index == vec.size()){
		return false;
	}
	
	arr[i] = vec[index];
	return backtrack1(vec, index + 1, n, acum + vec[index], arr, i + 1, size + 1) || backtrack1(vec, index + 1, n, acum, arr, i, size);
}


int main(){
	int number, tracks;
	while(cin >> number){
		cin >> tracks;
		vector <int> vec;
		for(int i = 0; i < tracks; i++){
			int temp;
			cin >> temp;
			vec.push_back(temp);
		}

		int arr[21];

		backtrack(vec, 0, number, 0);

		for(int i = 0; i < vec1.size(); i++)
			cout << vec1[i] << endl;

		sort(vec1.begin(), vec1.end());

		int res1 = bin_lower(vec1, number);

		backtrack1(vec, 0, vec1[res1], 0, arr, 0, 0);

		for(int j = 0; j < size1; j++)
			cout << arr[j] << " ";

		size1 = 0;
		vec1.clear();

		cout << "sum:" << vec1[res1] << endl;
	}


	return 0;
}