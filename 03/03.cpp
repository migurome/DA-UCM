/*
* Grupo DA09, Miguel Romero
* Solución: una función recursiva que recorre el árbol comprobando que está ordenadoy que está balanceado
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include "TreeMap_AVL.h"

using namespace std;

/**
* Rellena un arbol AVL
* @param arbol Arbol que queremos rellenar
* @param k1 primer pibote desde el que queremos leer
* @param k2 segundo pibote hasta el que queremos leer
* @return valor booleano, false si se han podido leer datos y true en caso contrario
*/


bool leerDatos(map<int,int> & arbol, int nvalores, int &k1, int &k2) {
		
	if (nvalores == 0)
		return true;

	int dato;
	
	for (int i = 0; i < nvalores; i++) {
		cin >> dato;
		arbol.insert(dato);
	}


	cin >> k1;
	cin >> k2;

	return false;
}

/**
* @bvrief Se crea un iterador y se situa en k1, mostramos por pantalla los elementos contenidos entre k1 y k2 
* @param arbol
* @param k1
* @param k2
* El coste es de O(n) siendo n el numero de elementos que componen el árbol
*/


void procesarCaso(const map<int, int> & arbol, int k1, int k2) {
			
	
	map<int, int>::const_iterator it = arbol.begin();

	while (it != arbol.end() && (*it).clave < k1)
		++it;

	while (it != arbol.end() && (*it).clave <= k2) { // imprimir elementos entre k1 y k2 y cuando sean mayores que k2 se corta
		cout << (*it).clave;
		++it;
		if (it != arbol.end() && (*it).clave <= k2) // imprimir espacio en todos menos en el ultimo
			cout << " ";
	}

	cout << endl;
}

/**
* @brief Se realiza la lectura del arbol y de los parámetros k1 y k2, finalmente se invoca a la función procesarCaso para que 
* muestre el resultado
* @return finLectura valor ofrecido por la funcion procesarCaso
*/


bool analizarCaso() {

	int valores, k1, k2;
	map<int, int> arbol;
	bool finLectura = false;

	cin >> valores;

	finLectura = leerDatos(arbol, valores, k1, k2);

	if (!finLectura)
		procesarCaso(arbol, k1, k2);
	
	return finLectura;
}

int main(int argc, char** args) {

	bool fin;

	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	do {
		fin = analizarCaso();
	} while (!fin);

	
	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif

	return 0;
}