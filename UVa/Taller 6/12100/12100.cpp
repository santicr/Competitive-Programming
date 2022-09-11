#include <iostream>
#include <string>
#include <queue>
#include <map>


using namespace std;

struct mapa{
	int llave;
	int valor;
};

typedef struct mapa Mapa;

int main(){
	int casos;
	cin >> casos;
	while(casos--){
		int impresiones, pos, indice = 0;
		queue <Mapa> cola;
		priority_queue <int> temp;
		scanf("%d %d", &impresiones, &pos);

		while(impresiones--){
			int prioridad;
			Mapa aux;
			cin >> prioridad;
			aux.llave = indice;
			aux.valor = prioridad;
			indice++;
			cola.push(aux);
			temp.push(prioridad);
		}

		int indice2 = 0, contador = 0;

		while(!temp.empty()){
			if(pos == cola.front().llave && temp.top() <= cola.front().valor){
				cout << contador + 1 << endl;
				break;
			}
			else if(temp.top() > cola.front().valor){
				cola.push(cola.front());
				cola.pop();
			}
			else if(temp.top() == cola.front().valor && cola.front().llave != pos){
				temp.pop();
				cola.pop();
				contador++;
			}

		}
	}

	return 0;
}