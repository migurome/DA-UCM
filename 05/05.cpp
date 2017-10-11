#include <algorithm>
#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

using namespace std;

 bool leerDatos(PriorityQueue<long int> & cola) {

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


void resuelve() {
	
	PriorityQueue<long int> cola;
	long int gorras, ganador = 0;

	while (leerDatos(cola)) {
		gorras = 0;
		while (cola.size() > 1) {

			gorras += cola.top();
			ganador = cola.top();
			cola.pop();
			
			if(!cola.empty()){
				gorras += cola.top();
				ganador += cola.top();
				cola.pop();
				if(cola.size() >= 1 )
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