#include "../include/sorting.hpp"

void Sorting::bubbleSort(ListaEncadeada *lista) {
    int n = lista->getTamanho();
    for(int i = 0; i < n - 1; i++) {
        TipoCelula* celula = lista->getPrimeiraCelula()->prox;
        for(int j = 1; j < n - i; j++) {
            if(celula->prox->item->getCor() < celula->item->getCor()) {
                TipoCelula* aux = celula->prox;
                trocaCelulas(celula, celula->prox);
                celula = aux;
            }
            celula = celula->prox;
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

void Sorting::trocaCelulas(TipoCelula* celula1, TipoCelula* celula2) {
    // Caso a célula 2 esteja imediatamente a frente da célula 1
    if(celula1->prox == celula2) {
        if(celula2->prox != nullptr)
            celula2->prox->anterior = celula1;
        celula1->prox = celula2->prox;
        if(celula1->anterior != nullptr)
            celula1->anterior->prox = celula2;
        celula2->anterior = celula1->anterior;
        celula2->prox = celula1;
        celula1->anterior = celula2;
        // Caso a célula 1 esteja imediatamente a frente da célula 2
    } else if(celula1->anterior == celula2) {
        if(celula1->prox != nullptr)
            celula1->prox->anterior = celula2;
        celula2->prox = celula1->prox;
        if(celula2->anterior != nullptr)
            celula2->anterior->prox = celula1;
        celula1->anterior = celula2->anterior;
        celula1->prox = celula2;
        celula2->anterior = celula1;
    } else {
        if(celula1->anterior != nullptr)
            celula1->anterior->prox = celula2;
        celula2->anterior = celula1->anterior;
        if(celula2->anterior != nullptr)
            celula2->anterior->prox = celula1;
        if(celula1->prox != nullptr)
            celula1->prox->anterior = celula2;
        if(celula2->prox != nullptr)
            celula2->prox->anterior = celula1;

        TipoCelula* aux;

        aux = celula1->anterior;
        celula1->anterior = celula2->anterior;
        celula2->anterior = aux;

        aux = celula1->prox;
        celula1->prox = celula2->prox;
        celula2->prox = aux;
    }
}