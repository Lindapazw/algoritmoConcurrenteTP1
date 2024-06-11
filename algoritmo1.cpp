#include <iostream>
#include <thread>
#include <string>
#include <chrono>

using namespace std;

void misaludo(string m, int demora, int veces) {
    for (int i = 1; i <= veces; i++) {
        cout << m << "\n";
        this_thread::sleep_for(chrono::milliseconds(demora));
    }
}

int main() {
    thread th1(misaludo, "Soy A", 100, 10);
    thread th2(misaludo, "\tSoy B", 150, 15);
    thread th3(misaludo, "\t\tSoy C", 300, 5);

    th1.join();
    th2.join();
    th3.join();

    cout << "Fin \n";
    return 0;
}
