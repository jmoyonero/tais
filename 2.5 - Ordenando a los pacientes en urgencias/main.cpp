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

struct patient {
    string name; // Nombre del paciente.
    int gravity; // Gravedad de urgencia.
    int order; // Orden de entrada para usarlo en caso de igualdad de gravedad.
};


bool operator<(patient const &a, patient const &b) {
    return b.gravity > a.gravity || (a.gravity == b.gravity && b.order < a.order);
}

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>


bool resuelveCaso() {
    // leer los datos de la entrada

    int nEvents;

    cin >> nEvents;

    if (nEvents == 0) {
        return false;
    }

    priority_queue<patient> queue;

    string eventType;

    for (int i = 1; i <= nEvents; i++) {
        cin >> eventType;
        if (eventType == "I") {
            int gravity;
            string name;
            cin >> name >> gravity;
            queue.emplace(name, gravity, i);
        } else if (eventType == "A") {
            patient p = queue.top();
            cout << p.name << "\n";
            queue.pop();
        } else {
            cout << "Tipo de evento inválido: " << eventType << "\n";
        }
    }

    cout << "---\n";
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    /*
     * Definimos una estructura para representar al paciente (patient) con un comparador personalizado en el que
     * compararamos la gravedad y el orden de entrada.
     * Creamos una cola de prioridad de elementos tipo patient y sacamos el elemento más prioritario cada vez que
     * recibimos un evento tipo A.
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
