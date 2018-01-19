/*
* Grupo DA09, Miguel Romero
* Solucion:
* Coste:
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

	struct tTrabajo { 
		long int inicio; 
		long int fin; 
	};

	class compare {
	public:
		bool operator()(tTrabajo a, tTrabajo b) {
			return a.inicio > b.inicio;
		}
	};


	bool resolverCaso() {

		int Ci, Fi, ntrabajos;
		tTrabajo entrada;
		priority_queue<tTrabajo, vector<tTrabajo>, compare> lista;

		cin >> Ci >> Fi >> ntrabajos;

		if (ntrabajos == 0 && Ci == 0 && Fi == 0)
			return true;

		for (int i = 0; i < ntrabajos; i++) {
			cin >> entrada.inicio;
			cin >> entrada.fin;

			lista.push(entrada);
		}

		/*Cojo la primera conferencia*/

		bool rango = true;
		int minT = Ci, maxT = Ci;
		tTrabajo aux;
		queue<tTrabajo> other;

		if(lista.top().inicio <= Ci){
			while (!lista.empty() && rango && lista.top().inicio <= minT) {
				
				while (lista.top().inicio <= minT) {
					if (lista.top().fin > maxT) {
						maxT = lista.top().fin;
						aux = lista.top();
					}

					lista.pop();
				}
				other.push(aux);
				minT = maxT;
				if (maxT >= Fi)
					rango = false;
			}
		}else{
			cout << "Imposible" << endl;
		}

		if(!other.empty() && !rango)
			cout << other.size() << endl;
		else
			cout << "Imposible" << endl;


		return false;
	}
};

int main() {

	Ejercicio ej("casos.txt");
	ej.ejecutar();
	return 0;
}