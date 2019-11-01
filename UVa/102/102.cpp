/* Nivel 0 */
#include <iostream>
#include <vector>

using namespace std;

int main(){
	int b1, g1, c1, b2, g2, c2, b3, g3, c3;
	while(scanf("%d %d %d %d %d %d %d %d %d",&b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3) != EOF){
		vector <char> vec4 = {'B', 'G', 'C'};
		int pos1 = 0, pos2 = 0, pos3 = 0, min = 0, res = 0;
		res += g1 + c1 + b2 + g2 + b3 + c3;
		pos1 = 0;
		pos2 = 2;
		pos3 = 1;
		min = res;
		res = 0;
		res += g1 + c1 + b2 + c2 + b3 + g3;
		if(res < min){
			pos1 = 0;
			pos2 = 1;
			pos3 = 2;
			min = res;
		}
		res = 0;
		res += b1 + g1 + g2 + c2 + b3 + c3;
		if(res < min){
			pos1 = 2;
			pos2 = 0;
			pos3 = 1;
			min = res;
		}
		res = 0;
		res += b1 + g1 + b2 + c2 + g3 + c3;
		if(res < min){
			pos1 = 2;
			pos2 = 1;
			pos3 = 0;
			min = res;
		}
		res = 0;
		res += b1 + c1 + g2 + c2 + b3 + g3;
		if(res < min){
			pos1 = 1;
			pos2 = 0;
			pos3 = 2;
			min = res;
		}
		res = 0;
		res += b1 + c1 + b2 + g2 + g3 + c3;
		if(res < min){
			pos1 = 1;
			pos2 = 2;
			pos3 = 0;
			min = res;
		}
		cout << vec4[pos1] << vec4[pos2] << vec4[pos3] << " " << min << endl;
	}
	return 0;
}