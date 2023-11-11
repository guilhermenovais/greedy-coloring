#include "../include/sorting.hpp"

void Sorting::bubbleSort(Lista *lista) {
    int tamanho = lista->getTamanho();
    for(int i = 0; i < tamanho - 1; i++)
        for(int j = 1; j < tamanho - i; j++)
            if (lista->getItem(j)->getCor() < lista->getItem(j - 1)->getCor())
                troca(j - 1, j, lista);
}

void Sorting::selectionSort(Lista *lista) {
    int min, tamanho;
    tamanho = lista->getTamanho();
    for (int i = 0; i < tamanho - 1; i++) {
        min = i;
        for (int j = i + 1 ; j < tamanho; j++) {
            if(lista->getItem(j)->getCor() <= lista->getItem(min)->getCor()) {
                if(lista->getItem(j)->getCor() == lista->getItem(min)->getCor()) {
                    // Caso as cores sejam iguais, verifica as chaves
                    if(lista->getItem(j)->getChave() < lista->getItem(min)->getChave())
                        min = j;
                } else
                    min = j;
            }
        }
        troca(i, min, lista);
    }
}

void Sorting::insertionSort(Lista *lista) {
    int tamanho = lista->getTamanho();
    Vertice* aux;
    for (int i = 1; i < tamanho; i++) {
        aux = lista->getItem(i);
        int j = i - 1;
        while (( j >= 0 ) && (aux->getCor() < lista->getItem(j)->getCor())) {
            lista->setItem(lista->getItem(j), j + 1);
            j--;
        }
        lista->setItem(aux, j + 1);
    }
}

void Sorting::quicksort(int esq, int dir, Lista* lista) {
    int i, j;
    qsParticao(esq, dir, &i, &j, lista);
    if (esq < j) quicksort(esq, j, lista);
    if (i < dir) quicksort(i, dir, lista);
}

void Sorting::qsParticao(int esq, int dir, int *i, int *j, Lista* lista) {
    *i = esq;
    *j = dir;
    Vertice* pivo = lista->getItem((*i + *j)/2);
    do {
        while(
            pivo->getCor() > lista->getItem(*i)->getCor() ||
            (pivo->getCor() == lista->getItem(*i)->getCor() &&
               pivo->getChave() > lista->getItem(*i)->getChave())) (*i)++;
        while(pivo->getCor() < lista->getItem(*j)->getCor() ||
            (pivo->getCor() == lista->getItem(*j)->getCor() &&
               pivo->getChave() < lista->getItem(*j)->getChave())) (*j)--;
        if (*i <= *j) {
            troca(*i, *j, lista);
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
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