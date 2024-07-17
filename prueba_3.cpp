#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

// Función para intercambiar dos elementos
void intercambiar(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Función para particionar el array
int particionar(std::vector<int>& arreglo, int bajo, int alto) {
    int pivote = arreglo[alto]; // El pivote es el último elemento
    int i = (bajo - 1); // Índice del elemento más pequeño

    for (int j = bajo; j <= alto - 1; j++) {
        if (arreglo[j] < pivote) { // Si el elemento actual es menor que el pivote
            i++; // Incrementa el índice del elemento más pequeño
            intercambiar(arreglo[i], arreglo[j]);
        }
    }
    intercambiar(arreglo[i + 1], arreglo[alto]);
    return (i + 1);
}

// Función de QuickSort
void ordenRapido(std::vector<int>& arreglo, int bajo, int alto) {
    if (bajo < alto) {
        int indiceParticion = particionar(arreglo, bajo, alto); // Índice de partición

        // Ordena recursivamente los elementos antes y después de la partición
        ordenRapido(arreglo, bajo, indiceParticion - 1);
        ordenRapido(arreglo, indiceParticion + 1, alto);
    }
}

// Función para imprimir un array
void imprimirArreglo(const std::vector<int>& arreglo) {
    for (size_t i = 0; i < arreglo.size(); i++)
        std::cout << arreglo[i] << " ";
    std::cout << std::endl;
}

// Función para calcular el uso de memoria de un vector
size_t calcularMemoria(const std::vector<int>& arreglo) {
    return arreglo.size() * sizeof(int);
}

// Función principal
int main() {
    // Crear tres conjuntos de datos de diferentes tamaños
    std::vector<int> conjuntoPequeno(100);
    std::vector<int> conjuntoMediano(300);
    std::vector<int> conjuntoGrande(500);

    // Llenar los conjuntos con números aleatorios
    std::srand(std::time(nullptr)); // Inicializar la semilla aleatoria
    for (size_t i = 0; i < conjuntoPequeno.size(); i++) conjuntoPequeno[i] = std::rand() % 1000;
    for (size_t i = 0; i < conjuntoMediano.size(); i++) conjuntoMediano[i] = std::rand() % 1000;
    for (size_t i = 0; i < conjuntoGrande.size(); i++) conjuntoGrande[i] = std::rand() % 1000;

    // Ordenar los conjuntos usando QuickSort y medir el tiempo de ejecución y el uso de memoria
    auto inicio = std::chrono::high_resolution_clock::now();
    ordenRapido(conjuntoPequeno, 0, conjuntoPequeno.size() - 1);
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;
    std::cout << "Tiempo de ejecucion para conjunto pequeno: " << duracion.count() << " segundos" << std::endl;
    std::cout << "Memoria usada por conjunto pequeno: " << calcularMemoria(conjuntoPequeno) << " bytes" << std::endl;

    inicio = std::chrono::high_resolution_clock::now();
    ordenRapido(conjuntoMediano, 0, conjuntoMediano.size() - 1);
    fin = std::chrono::high_resolution_clock::now();
    duracion = fin - inicio;
    std::cout << "Tiempo de ejecucion para conjunto mediano: " << duracion.count() << " segundos" << std::endl;
    std::cout << "Memoria usada por conjunto mediano: " << calcularMemoria(conjuntoMediano) << " bytes" << std::endl;

    inicio = std::chrono::high_resolution_clock::now();
    ordenRapido(conjuntoGrande, 0, conjuntoGrande.size() - 1);
    fin = std::chrono::high_resolution_clock::now();
    duracion = fin - inicio;
    std::cout << "Tiempo de ejecucion para conjunto grande: " << duracion.count() << " segundos" << std::endl;
    std::cout << "Memoria usada por conjunto grande: " << calcularMemoria(conjuntoGrande) << " bytes" << std::endl;

    return 0;
}
