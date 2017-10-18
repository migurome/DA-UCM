/**
* Grupo DA09, Miguel Romero
*/

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
using namespace std;


/**
* @brief Dados dos numeros enteros les asigna un valor leyendo desde la entrada standard
* @param pajaro_1 Primero de los enteros a leer
* @param pajaro_2 Segundo de los enteros a leer
*/
void leerDatos(int &pajaro_1, int &pajaro_2) {

	cin >> pajaro_1 >> pajaro_2;
}

/**
* @brief Se generan dos colas de prioridad, menores (ordenada de mayor a menor) y mayores (ordenada de menor a mayor)
* se incluye también un numero entero, cabeza, el cual es el pajaro que ocupa en el momento actual dirije la formacion
* Cada vez que se une una pareja, en función de las edades de estos nuevos pájaros, se añaden a la cola de máximos o 
* a la de mínimos y si fuera necesario se modifica el pájaro del medio con el que pase a tener la edad del medio.
* @return booleano false si no hay mas casos que procesar, true en caso contrario
* Coste: Es de O(n log(n)), para cada pareja n que se añade, cuesta log(n) añadir o quitar miembros.
*/
bool resuelveCaso() {

	PriorityQueue<int, std::less<int>> mayores;
	PriorityQueue<int, std::greater<int>> menores;
	
	int cabeza, num_casos, elem1, elem2;

	cin >> cabeza >> num_casos;

	if (num_casos != 0) {

		for (int i = 0; i < num_casos; i++) {

			leerDatos(elem1, elem2);

			if (elem1 < cabeza  && elem2 > cabeza) {
				menores.push(elem1);
				mayores.push(elem2);
			}
			else if (elem1 > cabeza && elem2 < cabeza) { 
				menores.push(elem2);
				mayores.push(elem1);
			}
			else if (elem1 > cabeza && elem2 > cabeza) {
				menores.push(cabeza);
				mayores.push(elem1);
				mayores.push(elem2);

				cabeza = mayores.top();
				mayores.pop();
			}
			else { 
				mayores.push(cabeza);
				menores.push(elem1);
				menores.push(elem2);

				cabeza = menores.top();
				menores.pop();
			}

			cout << cabeza << " ";
		}
		cout << endl;
		return true;
	}
	else
		return false;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}