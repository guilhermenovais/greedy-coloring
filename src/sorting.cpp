#include "../include/sorting.hpp"

void Sorting::bubbleSort(Lista *lista) {
    
}

void Sorting::selectionSort(Lista *lista) {
    
}

void Sorting::insertionSort(Lista *lista) {
    
}

void Sorting::quicksort(Lista *lista) {
    
}

void Sorting::mergesort(Lista *lista) {

}

void Sorting::heapsort(Lista *lista) {

}

void Sorting::customSort(Lista *lista) {
    
}

void Sorting::troca(int indice1, int indice2, Lista* lista) {
    Vertice* aux = lista->getItem(indice1);
    lista->setItem(lista->getItem(indice2), indice1);
    lista->setItem(aux, indice2);
}