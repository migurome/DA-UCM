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