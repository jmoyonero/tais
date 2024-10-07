using namespace std;

/*@ <authors>
 *
 * Jonathan Paul Moyonero Espinoza (TAIS068)
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

struct registration {
    int id; // identificador de usuario
    int periodicity; // periodicidad
    int moment; // periodicidad * (número envíos + 1)
};


bool operator<(registration const &a, registration const &b) {
    return b.moment < a.moment || (a.moment == b.moment && b.id < a.id);
}

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>


bool resuelveCaso() {
    // leer los datos de la entrada

    int numElems, id, periodicity, k;

    cin >> numElems;

    if (numElems == 0) {
        return false;
    }

    priority_queue<registration> queue;

    for (int i = 0; i < numElems; i++) {
        cin >> id >> periodicity;
        queue.emplace(id, periodicity, periodicity);
    }

    cin >> k;

    // resolver el caso posiblemente llamando a otras funciones

    for (int i = 0; i < k; i++) {
        registration current = queue.top();
        queue.pop();
        cout << current.id << "\n";
        current.moment += current.periodicity;
        queue.emplace(current.id, current.periodicity, current.moment);
    }

    cout << "---\n";

    // escribir la solución
    /*
     * Definimos una estructura llamada registration con un comparador personalizado en el que compararamos el menor
     * momento, siendo momento el periodo por el número de veces que se ha realizado un envío para este usuario + 1.
     * Creamos una cola de prioridad de elementos tipo registration y sacamos el elemento más prioritario para luego
     * incrementarle su momento y volver a introducirlo en la cola.
     * Esta operación la repetimos k veces.
     */

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    if (!in.is_open())
        std::cout << "Error: no se ha podido abrir el archivo de entrada." << std::endl;
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    std::cout << "Pulsa Intro para salir..." << std::flush;
    std::cin.get();
#endif
    return 0;
}
