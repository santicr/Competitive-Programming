#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(vector <string> matrix){
	int j;
	for(j = 0; j < matrix.size(); j++)
		cout << matrix[j] << endl;
}

void row(string *a, string *b){
	string temp = *a;
	*a = *b;
	*b = temp;
}

vector <string> col(vector <string> matrix, int col1, int col2){
	int i, j;
	vector <string> res = matrix;
	for(i = 0; i < matrix.size(); i++){
		for(j = 0; j < matrix.size(); j++)
			res[i][col1 - 1] = matrix[i][col2 - 1];
	}
	for(i = 0; i < matrix.size(); i++){
		for(j = 0; j < matrix.size(); j++)
			res[i][col2 - 1] = matrix[i][col1 - 1];
	}

	return res;
}

vector <string> inc(vector <string> matrix){
	int i, j;
	vector <string> res = matrix;
	for(i = 0; i < res.size(); i++){
		int temp;
		for(j = 0; j < res.size(); j++){
			temp = res[i][j] - 48;
			temp++;
			if(temp == 10)
				temp = 0;
			res[i][j] = temp + 48;
		}
	}
	return res;
}

vector <string> dec(vector <string> matrix){
	int i, j;
	vector <string> res = matrix;
	for(i = 0; i < res.size(); i++){
		int temp;
		for(j = 0; j < res.size(); j++){
			temp = res[i][j] - 48;
			temp--;
			if(temp == -1)
				temp = 9;
			res[i][j] = temp + 48;
		}
	}
	return res;
}

vector <string> transpose(vector <string> matrix){
	int i, j;
	vector <string> res = matrix;
	for(i = 0; i < matrix.size(); i++){
		for(j = 0; j < matrix.size(); j++)
			res[i][j] = matrix[j][i];
	}

	return res;
}

int main(){
	int cases, i, j, k;
	cin >> cases;
	for(i = 0; i < cases; i++){
		int size, operations, a, b;
		vector <string> matrix;
		string rows, operation;
		cin >> size;
		for(j = 0; j < size; j++){
			cin >> rows;
			matrix.push_back(rows);
		}
		cin >> operations;
		for(j = 0; j < operations; j++){
			cin >> operation;
			if(operation == "row"){
				scanf("%d %d", &a, &b);
				row(&matrix[a - 1], &matrix[b - 1]);
			}
			if(operation == "col"){
				scanf("%d %d", &a, &b);
				matrix = col(matrix, a, b);
			}
			if(operation == "inc")
				matrix = inc(matrix);

			if(operation == "dec")
				matrix = dec(matrix);

			if(operation == "transpose")
				matrix = transpose(matrix);
		}

		cout << "Case #" << i + 1 << endl;
		
		print(matrix);

		if(i != cases - 2)
			cout << endl;
		if(i == cases - 2)
			cout << endl;
	}
	return 0;
}