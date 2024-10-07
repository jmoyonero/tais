using namespace std;

/*@ <authors>
 *
 * Jonathan Paul Moyonero Espinoza (TAIS068)
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {
    // leer los datos de la entrada

    int numElems, elem;

    cin >> numElems;

    if (numElems == 0) {
        return false;
    }

    priority_queue<long, vector<long>, greater<> > queue;

    for (int i = 0; i < numElems; i++) {
        cin >> elem;
        queue.push(elem);
    }

    // resolver el caso posiblemente llamando a otras funciones

    long cost = 0;

    while (queue.size() > 1) {
        long aux = queue.top();
        queue.pop();
        aux += queue.top();
        queue.pop();
        cost += aux;
        queue.push(aux);
    }

    cout << cost << endl;

    // escribir la solución
    /*
     * Creamos una cola de prioridad de mínimos para ir sumando los dos valores más prioritarios después de quitarlos,
     * y luego introducirlos en la cola para que se tengan en cuenta en la siguiente suma. Por otro lado, el costo lo
     * acumulamos en una variable siempre y cuando la cola tenga más de un elemento (queda pendiente alguna suma).
     *
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
