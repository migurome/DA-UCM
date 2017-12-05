/**
* Grupo DA09, Miguel Romero
* Solucion: Las peliculas se ordenan en una cola de prioridad en función de su hora de finalización.
* Para cada pelicula hora de finalización de la película sumando el comienzo más la duración más los 10 min de descanso.
* Siempre se toma la primera película como vista y a partir de ahí se mira si da tiempo a ver la siguiente 
* película por orden de finalización o ya estará empezada cuando salga de la actual, y no se puede ver
* hasta llegar a la última película.
* Coste: el algoritmo será lineal en el número de películas O(n)
*/

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

	struct tPelicula{
		int hora;
		int duracion;
		int fin;
	};

	class compare {
	public:
		bool operator()(tPelicula a, tPelicula b) {
			return a.fin > b.fin;
		}
	};

	bool resolverCaso() {

		int npeliculas;
		cin >> npeliculas;

		if (npeliculas == 0)
			return true;

		int horas, minutos, duracion;
		char puntos;

		priority_queue<tPelicula, vector<tPelicula>, compare> peliculas;
		tPelicula aux;

		for (int i = 0; i < npeliculas; i++){
			cin >> horas;
			cin >> puntos;
			cin >> minutos;

			aux.hora = horas * 60 + minutos;

			cin >> duracion;
			
			aux.duracion = duracion;
			aux.fin = aux.hora + duracion + 10;

			peliculas.push(aux);
		}

		int num_peliculas = 1;
		int ocupado_hasta = peliculas.top().fin;

		while(!peliculas.empty()) {

			if (peliculas.top().hora >= ocupado_hasta) {
				num_peliculas++;
				ocupado_hasta = peliculas.top().fin;
			}

			peliculas.pop();
		}

		cout << num_peliculas << endl;

		return false;
	}
};

int main() {

	Ejercicio ej("casos.txt");
	ej.ejecutar();
	return 0;
}