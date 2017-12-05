#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

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

	struct tConferencia { long int inicio; long int fin; };

	class compare {
	public:
		bool operator()(tConferencia a, tConferencia b) {
			return a.inicio >= b.inicio;
		}
	};

	bool resolverCaso() {

		int nconferecias;
		priority_queue<tConferencia, vector<tConferencia>, compare> conferencias;
		priority_queue<tConferencia, vector<tConferencia>, compare> salas;
		tConferencia aux;

		cin >> nconferecias;

		if (nconferecias == 0)
			return true;

		for (int i = 0; i < nconferecias; i++) {
			cin >> aux.inicio;
			cin >> aux.fin;

			conferencias.push(aux);
		}

		/*Cojo la primera conferencia*/

		salas.push(conferencias.top());
		conferencias.pop();


		while (!conferencias.empty()) {

			if (salas.top().fin <= conferencias.top().inicio) {
				salas.pop();
			}

			salas.push(conferencias.top());
			conferencias.pop();
		}

		cout << salas.size() << endl;

		return false;
	}
};

int main() {

	Ejercicio ej("casos.txt");
	ej.ejecutar();
	return 0;
}