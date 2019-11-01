#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int comparar(vector <string> c_grande, vector <string> c_peque, int m, int n){
	int i, j, k, l, res = 0;
	for(i = 0; i < m; i++){
		for(j = 0; j < m; j++){
			int cont = 0;
			if(c_peque[0][0] == c_grande[i][j] && j <= m - n && i <= m - n){
				int indice1 = 0;
				for(k = i; k < n + i; k++, indice1++){
					int indice2 = 0;
					for(l = j; l < n + j; l++, indice2++){
						if(c_peque[indice1][indice2] == c_grande[k][l])
							cont++;
					}
				}
			}
			if(cont == n * n)
				res++;
		}
	}

	return res;
}

vector <string> voltear(vector <string> c_peque, int n){
	vector <string> res;
	int indice1 = 0, i, j;

	for(i = 0; i < n; i++){
		string temp;
		for(j = n - 1; j >= 0; j--)
			temp.push_back(c_peque[j][i]);
		res.push_back(temp);
	}

	return res;
}

int main(){
	int m, n, i, j;
	scanf("%d %d", &m, &n);
	while(m != 0 && n != 0){
		vector <string> c_grande;
		vector <string> c_peque;
		int arr[4] = {0, 0, 0, 0}, indice1 = 0, indice2 = 0;

		for(i = 0; i < m; i++){
			string temp;
			cin >> temp;
			c_grande.push_back(temp);
		}

		for(i = 0; i < n; i++){
			string temp;
			cin >> temp;
			c_peque.push_back(temp);
		}

		for(i = 0; i < 4; i++){
			if(comparar(c_grande, c_peque, m, n) > 0)
				arr[i] += comparar(c_grande, c_peque, m, n);
			c_peque = voltear(c_peque, n);
		}
		cout << arr[0];
		for(i = 1; i < 4; i++)
			cout << " " << arr[i];

		cout << endl;

		scanf("%d %d", &m, &n);
	}
	return 0;
}