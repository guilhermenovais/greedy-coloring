#include "../include/sorting.hpp"

void Sorting::bubbleSort(ListaEncadeada *lista) {
    int n = lista->getTamanho();
    for(int i = 0; i < n - 1; i++) {
        TipoCelula* anterior = lista->getPrimeiraCelula()->getProx();
        TipoCelula* atual = anterior->getProx();
        for(int j = 1; j < n - i; j++) {
            if(atual->getItem()->getCor() < anterior->getItem()->getCor()) {
                
            }
            anterior = anterior->getProx();
            atual = atual->getProx();
        }
    }
}

void Sorting::selectionSort(ListaEncadeada *lista) {

}

void Sorting::insertionSort(ListaEncadeada *lista) {

}

void Sorting::quicksort(ListaEncadeada *lista) {

}

void Sorting::mergesort(ListaEncadeada *lista) {

}

void Sorting::heapsort(ListaEncadeada *lista) {

}

void Sorting::customSort(ListaEncadeada *lista) {
    
}