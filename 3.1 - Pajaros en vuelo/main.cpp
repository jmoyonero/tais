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

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>


bool resuelveCaso() {
    // leer los datos de la entrada

    int firstBirt, nBirds;

    cin >> firstBirt >> nBirds;

    if (firstBirt == 0 && nBirds == 0)
        return false;

    priority_queue<int, vector<int>, less<> > maxQueue;
    priority_queue<int, vector<int>, greater<> > minQueue;

    minQueue.push(firstBirt);

    int birdA, birdB;

    for (int i = 0; i < nBirds; i++) {
        cin >> birdA >> birdB;

        if (!maxQueue.empty() && birdA < maxQueue.top() && birdB < maxQueue.top()) {
            maxQueue.push(birdA);
            maxQueue.push(birdB);
            minQueue.push(maxQueue.top());
            maxQueue.pop();
        } else {
            minQueue.push(birdA);
            minQueue.push(birdB);
            maxQueue.push(minQueue.top());
            minQueue.pop();
        }

        cout << minQueue.top() << " ";
    }

    cout << "\n";


    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    /*
     * Delaramos 2 colas de prioridad, una de máximos (aves jóvenes) y otra de mínimos (aves adultas) para almacenar las
     * edades de las aves. La diferencia del tamaño de estas colas es siempre de 1 siendo la cola de mínimos la más grande.
     * La idea es insertar cada par de aves en la cola de mínimos para luego sacar la más prioritaria y añadirla a la
     * cola de máximos. Salvo el escenario en el que el par de aves a entrar sean menores al elemento más prioritario de
     * la cola de máximos, en este caso hacemos lo contrario. Con esto, el elemento más prioritario de la cola de mínimos
     * es la ave que debe encabezar la bandada.
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
