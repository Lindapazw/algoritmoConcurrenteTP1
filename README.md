# INDIVIDUAL

## 01 Objetivo

El objetivo principal de esta actividad consiste en aplicar los conocimientos adquiridos en el módulo uno de la asignatura. Específicamente se abordará el concepto de concurrencia mediante algoritmos básicos en lenguaje de C++. La actividad debe ser llevada a cabo en forma individual.

En concreto los objetivos de esta práctica son:

- Crear y manipular programas concurrentes en C++.
- Implementar programas concurrentes que requieran cierta sincronización.
- Adquirir conocimiento empírico del funcionamiento de threads en C++.

## 02 Situación problemática

A continuación se presenta un caso. Lee con atención el mismo, teniendo presente cada uno de los contenidos que hemos desarrollado en el módulo, ya que luego tendrás que resolver una actividad retomándolos. Haz clic sobre el siguiente enlace para descargar el enunciado:

[Clic aquí](https://siglo21.instructure.com/courses/34593/assignments/394491)

## 03 Consignas de la actividad

### Consigna 1

Basado en la situación problemática, se debe analizar el comportamiento de los algoritmos presentados, estudiando sus particularidades desde el punto de vista de la implementación. Para llevar a cabo esta tarea es necesario ejecutar los algoritmos y luego de realizar diversas ejecuciones, documentar y explicar el comportamiento de tales programas.

Se valorará la claridad del código y debidamente comentado. Adicionalmente se considera mayor puntaje si se incluye tratamiento correcto de errores, es decir, en caso de producirse errores deberá informarse al usuario del tipo de error ocurrido. Breve informe que incluye el trabajo teórico realizado y la resolución/análisis de los ejercicios planteados.

---

## Algoritmo 1

```cpp
#include <iostream>
#include <thread>
#include <string>
#include <chrono>

using namespace std;

void misaludo (string m, int demora, int veces) {
    for (int i = 1; i <= veces; i++) {
        cout << m << "\n";
        this_thread::sleep_for(chrono::milliseconds(demora));
    }
}

int main() {
    thread th_1(misaludo, "Soy A", 100, 10);
    thread th_2(misaludo, "\tSoy B", 150, 15);
    thread th_3(misaludo, "\t\tSoy C", 300, 5);
    th_1.join();
    th_2.join();
    th_3.join();
    cout << "Fin \n";
    return 0;
}
```

## Algoritmo 2

```cpp
#include <iostream>
#include <thread>
#include <string>
#include <chrono>

using namespace std;

void misaludo (string m, int demora, int veces) {
    for (int i = 1; i <= veces; i++) {
        cout << m << "\n";
        this_thread::sleep_for(chrono::milliseconds(demora));
    }
}

int main() {
    thread P[3];
    P[0] = thread(misaludo, "Soy 1", 100, 10);
    P[1] = thread(misaludo, "\tSoy 2", 150, 15);
    P[2] = thread(misaludo, "\t\tSoy 3", 300, 5);
    P[0].join();
    P[1].join();
    P[2].join();
    cout << "Fin \n";
    return 0;
}
```


