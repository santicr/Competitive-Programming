#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <list>

using namespace std;

struct pareja{
	int pos1, pos2;
};

typedef struct pareja Pareja;

struct punto{
	int x, y;
};

typedef struct punto Punto;

double distancia(Punto a, Punto b){
	double res = sqrt(pow((a.x - b.x),2) + pow((a.y - b.y),2));
	return res;
}

int main(){
	int este = 1;
	while(este){
		int N;
		vector <Punto> vector; //Guardamos los puntos
		list <Pareja> lista; //Guardamos las posiciones en que deben hacer match
		cin >> N;
		if(N == 0)
			break;

		for(int i = 0; i < 2*N; i++){
			char temp[25] = "";
			int x, y;
			Punto p;
			scanf("%s %d %d", temp, &x, &y);
			p.x = x;
			p.y = y;
			vector.push_back(p);
		}

		for(int i = 0; i < vector.size(); i++){
			
		}

	}

	return 0;
}