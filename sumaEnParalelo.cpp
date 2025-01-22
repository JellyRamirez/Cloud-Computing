/*
* Description: Code for adding in parallel using omp library.
* Author: Andrea Jelena Ramírez García
* Date: 21/01/2025
*/

#include <iostream>
#include <omp.h>
#include <random>

#define N 2000
#define chunk 200
#define mostrar 20

void imprimeArreglo(float *d);

int main()
{
    std::cout << "Sumando Arreglos en Paralelo: \n";
    float a[N], b[N], c[N];
    int i;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 100);

    for (i = 0; i < N; i++) {
        a[i] = distrib(gen);
        b[i] = distrib(gen);
    }

    int pedazos = chunk;

#pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)

    for (i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }

    std::cout << "Imprimiendo los primeros  " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "\n\n";
    std::cout << "Imprimiendo los primeros  " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "\n\n";
    std::cout << "Imprimiendo los primeros  " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);
    std::cout << "\n\n";
}

void imprimeArreglo(float* d)
{
    for (int x = 0; x < mostrar; x++) {
        if (x == mostrar - 1) {
            std::cout << d[x];
        }
        else {
            std::cout << d[x] << " - ";
        }
    }
        
    std::cout << std::endl;
}

