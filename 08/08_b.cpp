/**
* Grupo DA09, Miguel Romero
*/

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
using namespace std;

struct tInstrumento {

	int max;
	int npartituras;
	int musicos;

};

class compare {
public:
	bool operator()(tInstrumento instrumento1, tInstrumento instrumento2) {
		return instrumento1.max > instrumento2.max;
	}
};

bool leerDatos(PriorityQueue<tInstrumento, compare> &cola, int &npartituras) {

	int ncasos, elem, i = 0;
	tInstrumento instrumento;


	if (!cin.eof()) {

		cin >> npartituras >> ncasos;

		npartituras -= ncasos;

		do {
			cin >> elem;
			instrumento.max = elem;
			instrumento.musicos = elem;
			instrumento.npartituras = 1;
			cola.push(instrumento);
			i++;
		} while (i < ncasos);

		return true;
	}
	else
		return false;

}

bool resuelveCaso() {

	PriorityQueue<tInstrumento, compare> cola;
	int partituras;
	tInstrumento auxiliar;

	if(leerDatos(cola, partituras)){

		for (int i = 0; i < partituras; i++) {

			auxiliar= cola.top();
			auxiliar.npartituras++;
			auxiliar.max = (auxiliar.musicos / auxiliar.npartituras) + (auxiliar.musicos % auxiliar.npartituras);
			cola.pop();
			cola.push(auxiliar);
		}

		cout << cola.top().max << endl;

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