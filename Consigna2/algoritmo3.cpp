#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <vector>

using namespace std;

void misaludo(int id) {
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

int main() {
    const int numProcesses = 15;
    vector<thread> threads;

    for (int i = 0; i < numProcesses; i++) {
        threads.emplace_back(misaludo, i + 1);
    }

    for (auto& th : threads) {
        th.join();
    }

    cout << "Fin \n";
    return 0;
}
