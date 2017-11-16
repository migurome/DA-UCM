/*
* Grupo DA09, Miguel Romero
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <queue> 

using namespace std;

/**
* @brief Comparador
*/

class compare {
public:
	bool operator()(long int elem_1, long int elem_2) {
		return elem_1 > elem_2;
	}
};

/**
* @brief dada una cola de prioridad la rellena.
* @param cola , cola de prioridad a rellenar
* @return true si se ha podido rellenar la cola, false en caso contrario
*/

bool leerDatos(priority_queue<long int, vector<long int>, compare> &cola) {

	int num_elem;
	long int elemento;

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
* Complejidad Cada operación de pop tiene un coste de O(log n) y lo mismo para instertar, por lo
* por lo tanto el coste es de 3 O(log n)
*/

void resuelve() {

	priority_queue<long int, vector<long int>, compare> cola;

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