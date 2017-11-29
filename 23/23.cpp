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

			if (atacantes.top() > defensores.top()) {

				atacantes.pop();
			}
			else {

				atacantes.pop();
				defensores.pop();
				victorias++;
			}

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