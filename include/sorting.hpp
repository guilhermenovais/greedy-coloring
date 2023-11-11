#ifndef SORTING_HPP
#define SORTING_HPP

#include "vertice.hpp"
#include "lista.hpp"

class Sorting {
    public:
        static void bubbleSort(Lista* lista);
        static void selectionSort(Lista* lista);
        static void insertionSort(Lista* lista);
        static void quicksort(int esq, int dir, Lista* lista);
        static void mergesort(int esquerda, int direita, Lista* lista);
        static void heapsort(Lista* lista);
        static void customSort(Lista* lista);
    private:
        static void troca(int indice1, int indice2, Lista* lista);
        static void qsParticao(int esq, int dir, int *i, int *j, Lista* lista);
        static void merge(int esquerda, int direita, Lista* lista);
        static void hsAjustaMax(Lista* lista, int tamanho, int indice);
};

#endif // SORTING_HPP