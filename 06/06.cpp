/**
* Grupo DA09,  Miguel Romero
*/

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

using namespace std;

typedef struct {
	int id;
	int periodo;
	int prioridad;
}tUsuario;


/**
* @brief Redefinición del operador < para la comparación en la cola de prioridad de 2 elementos de tipo Dato
* Coste: constante de O(1)
*/

class compare {
public:
	bool operator()(tUsuario usuario1, tUsuario usuario2) {
		if (usuario1.prioridad == usuario2.prioridad)
			return usuario1.id < usuario2.id;
		else
			return usuario1.prioridad < usuario2.prioridad;
	}
};

/**
* @brief Dada una cola de prioridad de tUsuario y un numero n de elementos se incluyen los campos
* id y periodo para cada uno de ellos.
* @param cola Cola de prioridad vacia a rellenar
* @param n Numero total de usuarios que se van a incluir en la cola
*/

void leerDatos(PriorityQueue<tUsuario, compare> &cola, int n) {

	tUsuario usuario;

	for (int i = 0; i < n; i++) {
		cin >> usuario.id;
		cin >> usuario.periodo;
		usuario.prioridad = usuario.periodo;
		cola.push(usuario);
	}
}

/**
* @brief Se crea una cola de prioridad con los elementos que se pasan por entrada, cada tUsuario incluye un campo periodo que mide el avance del
* paquete enviado.
* Una vez rellena la cola se van leyendo uno por uno los elemento de esta, al finalizar se modifica el periodo de este sumando su prioridad y
* la cola reajusta su posición en la misma
* @return booleano false en el caso de que no haya mas elementos para leer true en caso contrario
* Coste: es lineal en el número de mensajes o paquetes a enviar y logarítmico en el número de elementos de la cola, por tanto tiene
* un coste de M log(N) siendo M el número de mensajes y N el número de elementos de la cola
*/

bool resuelveCaso() {

	int n, numEnvio;
	tUsuario usuario;

	cin >> n;
	if (n == 0)
		return false;

	PriorityQueue<tUsuario, compare> cola;

	leerDatos(cola, n);

	cin >> numEnvio;

	for (int i = 0; i < numEnvio; i++) {
		usuario = cola.top();
		cola.pop();
		cout << usuario.id << endl;
		usuario.prioridad += usuario.periodo;
		cola.push(usuario);
	}
	cout << "----" << endl;

	return true;
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