/**
* Grupo DA09, Miguel Romero
* Desarrollo utilizando las bibliotecas standard de c++
*/

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

struct tInstrumento {

	int max;
	int npartituras;
	int musicos;

};

class compare {
public:
	bool operator()(tInstrumento instrumento1, tInstrumento instrumento2) {
		return instrumento1.max < instrumento2.max;
	}
};

bool leerDatos(priority_queue<tInstrumento, vector<tInstrumento>, compare> &cola, int &npartituras) {

	int ncasos, elem, i = 0;
	bool finLeer = !cin.fail();
	tInstrumento instrumento;

	cin >> npartituras >> ncasos;

	npartituras -= ncasos;

	if (!cin.fail()) {

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

	priority_queue<tInstrumento, vector<tInstrumento>, compare> cola;

	int partituras;
	tInstrumento auxiliar;


	if (leerDatos(cola, partituras)) {

		for (int i = 0; i < partituras; i++) {

			auxiliar = cola.top();
			
			auxiliar.npartituras++;

			if (auxiliar.musicos % auxiliar.npartituras == 0)
				auxiliar.max = (auxiliar.musicos / auxiliar.npartituras);
			else
				auxiliar.max = (auxiliar.musicos / auxiliar.npartituras) + 1;

			cola.pop();
			cola.push(auxiliar);
		}

		if(cola.top().musicos != 0)
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