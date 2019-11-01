#include <iostream>
#include <vector>

using namespace std;

struct punto{
	int x, y;
} typedef P;

int main(){
	int n, m, x_sol, y_sol, x_lead, y_lead;
	vector <int> numeros;
	vector <P> puntos;

	while(scanf("%d %d", &n, &m) != EOF){
		int ys, xs, ;
		if(n == 0 && m == 0)
			break;
		
		for(int i = 0; i < 2 * n; i++)
			scanf("%d", &numeros[i]);
		
		for(int i = 0; i < 2 * n; i++){
			if(i % 2 == 0 || i == 0)
				
		}



		scanf("%d %d %d %d", &x_sol, &y_sol, &x_lead, &y_lead);

		for(int i = 0; i < puntos.size(); i++)
			cout << puntos[i].x << " -> " << puntos[i].y << endl;

	}

	return 0;
}