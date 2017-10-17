#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
using namespace std;

typedef struct {
	int id;
	int periodo;
	int prioridad;
}tUsuario;

class compare {
public:
	bool operator()(tUsuario usuario1, tUsuario usuario2) {
		if (usuario1.prioridad == usuario2.prioridad)
			return usuario1.id < usuario2.id;
		else
			return usuario1.prioridad < usuario2.prioridad;
	}
};

void leerDatos(PriorityQueue<tUsuario, compare> &colap, int n) {
	tUsuario usuario;

	for (int i = 0; i < n; i++) {
		cin >> usuario.id;
		cin >> usuario.periodo;
		usuario.prioridad = usuario.periodo;
		colap.push(usuario);
	}
}

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