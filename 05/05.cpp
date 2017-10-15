/*
* Grupo DA09, Miguel Romero
* Solución:
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

using namespace std;

/**
* @brief Lee una cola de prioridad de la entrada estándar
*/

bool leerDatos(PriorityQueue<int> & cola) {

	int num_elem;
	int elemento;

	cin >> num_elem;

	if (num_elem == 0)
		return false;
	if (cola.size() != 0)
		for (int i = 0; i < cola.size(); i++)
			cola.pop();

	for (int i = 0; i < num_elem; i++) {
		cin >> elemento;
		cola.push(elemento);
	}

	return true;
}

/**
* @brief Función principal. Comprobamos que haya mas de elemento en la cola, en caso
* contrario hemos terminado. Extraemos los valores del primer elemento de la cola, este
* indica el numero de seguidores, se acumula el numero de gorras repartidas a cada uno de
* los participantes y por otro lado se calcula el numero de seguidores totales en la
* partida actual, se eliminan los dos equipos de la cola y se calcula el nuevo numero de seguidores
* del ganador, que posteriormente es introducido en la cola.
* Complejidad
*/

void resuelve() {

	PriorityQueue<int> cola;
	long int gorras;
	long int ganador = 0;

	while (leerDatos(cola)) {
		gorras = 0;
		while (cola.size() > 1) {

			gorras += cola.top();
			ganador = cola.top();
			cola.pop();

			if (!cola.empty()) {
				gorras += cola.top();
				ganador += cola.top();
				cola.pop();
				if (cola.size() >= 1)
					cola.push(ganador);
			}
		}

		cout << gorras << endl;
	}

}

int main(int argc, char** args) {

	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif


		resuelve();


	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif

	return 0;
}