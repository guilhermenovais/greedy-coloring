#ifndef SORTING_HPP
#define SORTING_HPP

#include "vertice.hpp"
#include "lista_encadeada.hpp"

class Sorting {
    public:
        static void bubbleSort(ListaEncadeada* lista);
        static void selectionSort(ListaEncadeada* lista);
        static void insertionSort(ListaEncadeada* lista);
        static void quicksort(ListaEncadeada* lista);
        static void mergesort(ListaEncadeada* lista);
        static void heapsort(ListaEncadeada* lista);
        static void customSort(ListaEncadeada* lista);
};

#endif // SORTING_HPP