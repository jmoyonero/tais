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

struct cash {
    int number; // número de caja
    int busyTime; // tiempo ocupado de la caja
};


bool operator<(cash const &a, cash const &b) {
    return b.busyTime < a.busyTime || (a.busyTime == b.busyTime && b.number < a.number);
}

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>


bool resuelveCaso() {
    // leer los datos de la entrada

    int nCash, nClient;

    cin >> nCash >> nClient;

    if (nCash == 0 && nClient == 0) {
        return false;
    }

    int time;

    priority_queue<cash> queue;

    for (int i = 1; i <= nCash; i++) {
        queue.emplace(i, 0);
    }

    for (int i = 1; i <= nClient; i++) {
        cin >> time;
        auto current = queue.top();
        queue.pop();
        current.busyTime += time;
        queue.emplace(current.number, current.busyTime);
    }

    // resolver el caso posiblemente llamando a otras funciones

    cout << queue.top().number << "\n";

    // escribir la solución
    /*
     * Definimos una estructura para representar la caja (cash) con un comparador personalizado en el que compararamos el menor
     * tiempo ocupado, el cual es la suma del tiempo que tardará en atender a todos los clientes.
     * Creamos una cola de prioridad de elementos tipo cash y sacamos el elemento más prioritario para luego
     * incrementarle su timepo ocupado y volver a introducirlo en la cola.
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
