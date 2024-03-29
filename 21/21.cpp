/**
* Grupo DA09, Miguel Romero
* Solucion: Los pasajeros se guardan en un vector, seguidamente este se ordena mediante sort de mayor a menor
* Se dispone de dos iteradores imax e imin, los cuales se sitúan al principio y final del vector respectivamente-
* En cada iteración se intenta colocar a los pasajeros de los extremos del vector, el de mayor peso con el de menor
* peso, para equilibrar el peso total del telesilla.
* Coste: El coste de ordenar el vector es de O(n), y el de recorrerlo de extremo a extremo es también de O(n), por lo que 
* el coste total del algoritmo es de 2 O(n) 
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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


		int peso_max, nusuarios, elemento, nviajes = 0;
		cin >> peso_max >> nusuarios;


		vector<int> usuarios;

		if (cin.fail())  // hemos terminado de procesar todos los casos
			return true;

		for (int i = 0; i < nusuarios; i++) {
			cin >> elemento;
			usuarios.push_back(elemento);
		}

		sort(usuarios.begin(), usuarios.end(), myobject);


		int imax = 0, imin = nusuarios - 1;

		while (imax <= imin) {
			if (!((usuarios[imax] + usuarios[imin]) > peso_max))
				imin--;
			nviajes++;
			imax++;
		}

		cout << nviajes << endl;

		return false;
	}
};

int main() {

	Ejercicio ej("casos.txt");
	ej.ejecutar();
	return 0;
}