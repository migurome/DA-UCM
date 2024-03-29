﻿/**
* Grupo DA09, Miguel Romero
* Solucion: Los datos tanto para atacantes como para defensores se introducen en una cola de prioridad
* ordenada de mayor a menor. En cada iteración se comprueba si el valor de los defensores es mayor que 
* la de los atacantes, en tal caso se eliminan ambos elementos de sus respectivas colas, en caso contrario
* únicamente se elimina el dato de la cola de atacantes y se dá por perdida la bartalla. La suma total de 
* victorias se acumula en una variable local.
* Coste: la inclusion de las dos colas es de O(log n) y la de extracción de datos es también de O (log n)
* por lo que en el caso peor, el cual supone que para todos los casos el numero de defensores es mayor que el 
* que el de atacantes es de 4 O (log n)
*/

#include <iostream>
#include <fstream>
#include <queue>
#include "JudgeSolver.h"

using namespace std;

class Ejercicio : public JudgeSolver
{
public:

	/**
	* @brief Constructor
	* Constructor. Crea un objeto encargado de solucionar el problema de calcular el maximo tamanio de una componente conexa
	* Este problema realiza la lectura con el patrón cantidad.
	* Cuando se ejecuta en local desde el fichero "nombreFich".
	*/

	Ejercicio() : JudgeSolver(JudgeSolver::CENTINELA) {}

	/**
	* @brief Constructor
	* Constructor. Crea un objeto encargado de solucionar el problema de calcular el maximo tamanio de una componente conexa
	* Este problema realiza la lectura con el patrón cantidad.
	* Cuando se ejecuta en local desde el fichero "nombreFich".
	* @param nombFich nombre de archivo de casos de prueba
	*/

	Ejercicio(string nombreFich) : JudgeSolver(JudgeSolver::CENTINELA, nombreFich) {}

	/**
	* @brief Metodo encargado de averiguar el numero de componentes conexas
	* Se realiza la lectura de los datos desde "std::cin" y se muestra el resultado a trav�s del "std::cout".
	* @return false ya que no se controla si ha habido un error o no
	*/

	struct myclass {
		bool operator() (int i, int j) { return (i>j); }
	} myobject;

	bool resolverCaso() {


		int nelementos, elemento, victorias = 0;
		cin >> nelementos;

		priority_queue<int> atacantes;
		priority_queue<int> defensores;

		if (cin.fail())  // hemos terminado de procesar todos los casos
			return true;

		for (int i = 0; i < nelementos; i++) {
			cin >> elemento;
			atacantes.push(elemento);
		}

		for (int i = 0; i < nelementos; i++) {
			cin >> elemento;
			defensores.push(elemento);
		}

		for (int i = 0; i < nelementos; i++) {

			if (atacantes.top() <= defensores.top()){
				defensores.pop();
				victorias++;
			}

			atacantes.pop();
		
		}

		cout << victorias << endl;

		return false;
	}
};

int main() {

	Ejercicio ej("casos.txt");
	ej.ejecutar();
	return 0;
}