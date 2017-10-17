#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
using namespace std;


void leerDatos(int &pajaro_1, int &pajaro_2) {

	cin >> pajaro_1 >> pajaro_2;

}

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