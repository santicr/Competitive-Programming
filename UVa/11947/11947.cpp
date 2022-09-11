#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int N, indice = 1;
	bool bisiesto = false;
	vector <int> dias = {0,31,59,90,120,151,181,212,243,273,304,334,365};
	vector <int> signos = {21,50,51,79,80,110,111,141,142,172,173,
							203,204,233,234,266,267,296,297,326,327,356,357,
							385};
	vector <int> d_bisiesto = {0,31,60,91,121,152,182,213,244,274,305,335,366};
	vector <int> s_bisiesto = {21,50,51,80,81,111,112,142,143,173,174,
							204,205,234,235,267,268,297,298,327,328,357,356
							,386};
	vector <string> sig = {"aquarius","pisces","aries","taurus","gemini",
							"cancer","leo","virgo","libra","scorpio",
							"sagittarius","capricorn"};
	cin >> N;
	while(N--){
		string fecha;
		cin >> fecha;
		int mes = atoi(fecha.substr(0,2).c_str()); 
		int dia = atoi(fecha.substr(2,2).c_str());
		int ano = atoi(fecha.substr(4,4).c_str());
		int d;
		if(ano % 4 == 0 && ((ano % 100 != 0) || (ano % 400 == 0)))
			bisiesto = true;
		if(bisiesto == true)
			d = d_bisiesto[mes - 1] + dia + 280;
		else
			d = dias[mes - 1] + dia + 280;
		if(d > 365 && bisiesto == false){
			d -= 365;
			ano++;
			if(ano % 4 == 0 && ((ano % 100 != 0) || (ano % 400 == 0)))
				bisiesto = true;
			if(bisiesto == false){
				for(int i = 1; i < dias.size(); i++){
					if(d >= dias[i] && d <= dias[i + 1]){
						string temp;
						for(int j = 0; j < signos.size(); j += 2){
							if(d >= signos[j] && d <= signos[j + 1]){
								temp = sig[j / 2];
								break;
							}
							else if(d <= 21){
								temp = "aquarius";
								break;
							}
						}
						printf("%d %02d/%02d/%d %s\n", indice, i, d, ano, 
							temp.c_str());
						break;
					}
				}
			}
			else if(bisiesto == true){
				int tt = d;
				for(int i = 1; i < d_bisiesto.size(); i++){
					if(d <= d_bisiesto[i]){
						d -= d_bisiesto[i - 1];
						string temp;
						if(d > 357){
							temp = sig[11];
						}
						else{	
							for(int j = 0; j < signos.size(); j += 2){
								if(d >= signos[j] && d <= signos[j + 1]){
									temp = sig[j / 2];
									break;
								}
								else if(d <= 21){
									temp = "aquarius";
									break;
								}
							}
						}
						printf("%d %02d/%02d/%d %s\n", indice, i, d, ano, 
							temp.c_str());
						break;
					}
				}
			}
		}
		else if(d <= 365 && bisiesto == false){
			int tt = d;
			for(int i = 1; i < dias.size(); i++){
				if(d <= dias[i]){
					d -= dias[i - 1];
					string temp;
					if(d > 356){
						temp = sig[11];
					}
					else{	
						for(int j = 0; j < signos.size(); j += 2){
							if(tt >= signos[j] && tt <= signos[j + 1]){
								temp = sig[j / 2];
								break;
							}
						}
					}
					printf("%d %02d/%02d/%d %s\n", indice, i, d, ano, 
						temp.c_str());
					break;
				}
			}
		}
		else if(d > 366 && bisiesto == true){
			d -= 366;
			ano++;
			string temp;
			for(int i = 0; i < dias.size(); i++){
				if(d <= dias[i]){
					d -= dias[i - 1];
					for(int j = 0; j < signos.size(); j++){
						if(d >= signos[j] && d <= signos[j + 1]){
							temp = sig[j / 2];
							break;
						}
						else if(d <= 21){
							temp = "aquarius";
							break;
						}
					}
					printf("%d %02d/%02d/%d %s\n", indice, d, i, ano, 
						temp.c_str());
					break;
				}
			}
		}
		else{
			int tt = d;
			for(int i = 1; i < d_bisiesto.size(); i++){
				if(d <= d_bisiesto[i]){
					d -= d_bisiesto[i - 1];
					string temp;
					if(d > 357){
						temp = sig[11];
					}
					else{	
						for(int j = 0; j < s_bisiesto.size(); j += 2){
							if(tt >= s_bisiesto[j] && tt <= s_bisiesto[j + 1]){
								temp = sig[j / 2];
								break;
							}
						}
					}
					printf("%d %02d/%02d/%d %s\n", indice, i, d, ano, 
						temp.c_str());
					break;
				}
			}
		}
		indice++;
	}
	return 0;
}