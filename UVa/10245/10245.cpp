#include <iostream>
#include <math.h>

using namespace std;

typedef float T;

struct Pair{
	 double x, y;
};

 double distance( double x1,  double y1,  double x2,  double y2){
	 double res = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
	return sqrt(res);
}

int main(){
	int points;
	cin >> points;
	while(points != 0){
		Pair array[40001];

		for(int i = 0; i < points; i++){
			Pair temp;
			cin >> array[i].x >> array[i].y;
		}

		 double res = 99999;

		for(int i = 0; i < points; i++)
			for(int j = i + 1; j < points; j++)
				if(distance(array[i].x, array[i].y, array[j].x, array[j].y) < res)
					res = distance(array[i].x, array[i].y, array[j].x, array[j].y);

		if(res >= 10000)
			printf("INFINITY\n");
		else
			printf("%.4lf\n", res);

		cin >> points;
	}


	return 0;
}