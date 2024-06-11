#include <iostream>
#include <thread>
#include <chrono>
#include <random>

using namespace std;

class Proceso {
public:
    Proceso(int id) : id(id) {}

    void ejecutar() {
        // Generador de números aleatorios
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist_time(100, 1000); // Rango en milisegundos
        uniform_int_distribution<> dist_count(1, 10);    // Número de veces para mostrar el mensaje

        int demora = dist_time(gen);
        int veces = dist_count(gen);

        for (int i = 1; i <= veces; i++) {
            cout << "Soy el proceso " << id << "\n";
            this_thread::sleep_for(chrono::milliseconds(demora));
        }
    }

private:
    int id;
};

int main() {
    const int numProcesses = 15;
    vector<thread> threads;
    vector<Proceso> procesos;

    // Crear instancias de Proceso y hilos
    for (int i = 0; i < numProcesses; i++) {
        procesos.emplace_back(i + 1);
    }

    // Ejecutar la función en hilos
    for (int i = 0; i < numProcesses; i++) {
        threads.emplace_back(&Proceso::ejecutar, &procesos[i]);
    }

    // Esperar a que todos los hilos terminen
    for (auto& th : threads) {
        th.join();
    }

    cout << "Fin \n";
    return 0;
}
