#ifndef SORTING_HPP
#define SORTING_HPP

#include "tipo_celula.hpp"
#include "vertice.hpp"
#include "lista_encadeada.hpp"

class Sorting {
    public:
        static void bubbleSort(ListaEncadeada* lista);
        static void selectionSort(ListaEncadeada* lista);
        static void insertionSort(ListaEncadeada* lista);
        static void quicksort(TipoCelula* Esq, TipoCelula* Dir);
        static void mergesort(ListaEncadeada* lista);
        static void heapsort(ListaEncadeada* lista);
        static void customSort(ListaEncadeada* lista);
    private:
        static void trocaCelulas(TipoCelula* celula1, TipoCelula* celula2);
        static TipoCelula* getMeio(TipoCelula* Esq, TipoCelula* Dir);
        static TipoCelula* qsParticao(TipoCelula* Esq, TipoCelula* Dir);
};

#endif // SORTING_HPP