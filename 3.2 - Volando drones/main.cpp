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

    int nDrones = 0, nBigBattery = 0, nSmallBattery = 0;

    cin >> nDrones >> nBigBattery >> nSmallBattery;

    if (nDrones == 0 && nBigBattery == 0 && nSmallBattery == 0) {
        return false;
    }

    priority_queue<int, vector<int>, less<> > bigBatteryQueue;
    priority_queue<int, vector<int>, less<> > smallBatteryQueue;


    int charge = 0;

    for (int i = 0; i < nBigBattery; i++) {
        cin >> charge;
        bigBatteryQueue.push(charge);
    }

    for (int i = 0; i < nSmallBattery; i++) {
        cin >> charge;
        smallBatteryQueue.push(charge);
    }

    vector<int> usedSmallBatteries;
    vector<int> usedBigBatteries;

    while (!bigBatteryQueue.empty() && !smallBatteryQueue.empty()) {
        int time = 0;
        for (int i = 0; i < nDrones && !bigBatteryQueue.empty() && !smallBatteryQueue.empty(); i++) {
            int bigBattery = bigBatteryQueue.top();
            bigBatteryQueue.pop();

            int smallBattery = smallBatteryQueue.top();
            smallBatteryQueue.pop();

            time += min(bigBattery, smallBattery);

            if (bigBattery > smallBattery) {
                usedBigBatteries.push_back(bigBattery - smallBattery);
            } else if (smallBattery > bigBattery) {
                usedSmallBatteries.push_back(smallBattery - bigBattery);
            }
        }

        for (int usedSmallBattery: usedSmallBatteries) {
            smallBatteryQueue.push(usedSmallBattery);
        }

        for (int usedBigBattery: usedBigBatteries) {
            bigBatteryQueue.push(usedBigBattery);
        }

        usedBigBatteries.clear();
        usedSmallBatteries.clear();

        cout << time << " ";
    }

    cout << "\n";


    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    /*
     * Delaramos 2 colas de prioridad de máximos para almacenar las pilas, luego iteramos siempre que ambas colas tengan
     * elementos. Dentro de esta iteración añadimos otra iteración de n veces como drones tengamos siempre y cuando ambas
     * colas sigan teniendo elementos. Cada vez que utilizamos alguna pila y le sobre batería, las almacenamos en 2 vectores
     * de ayuda para luego volverlas a insertar a sus respectivas colas.
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
