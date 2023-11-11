#ifndef SORTING_HPP
#define SORTING_HPP

#include "vertice.hpp"
#include "lista.hpp"

class Sorting {
    public:
        static void bubbleSort(Lista* lista);
        static void selectionSort(Lista* lista);
        static void insertionSort(Lista* lista);
        static void quicksort(Lista*);
        static void mergesort(Lista* lista);
        static void heapsort(Lista* lista);
        static void customSort(Lista* lista);
};

#endif // SORTING_HPP