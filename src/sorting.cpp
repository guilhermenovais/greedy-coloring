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

void Sorting::quicksort(int esq, int direita, Lista* lista) {
    int i, j;
    qsParticao(esq, direita, &i, &j, lista);
    if (esq < j) quicksort(esq, j, lista);
    if (i < direita) quicksort(i, direita, lista);
}

void Sorting::qsParticao(int esq, int direita, int *i, int *j, Lista* lista) {
    *i = esq;
    *j = direita;
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

void Sorting::mergesort(int esquerda, int direitaeita, Lista* lista) {
    if (esquerda < direitaeita) {
        int meio = esquerda + (direitaeita - esquerda) / 2;

        mergesort(esquerda, meio, lista);
        mergesort(meio + 1, direitaeita, lista);

        merge(esquerda, direitaeita, lista);
    }
}

void Sorting::merge(int esquerda, int direitaeita, Lista* lista) {
    int meio = esquerda + (direitaeita - esquerda) / 2;
    int n1 = meio - esquerda + 1;
    int n2 = direitaeita - meio;

    Lista* L = new Lista(n1);
    Lista* R = new Lista(n2);

    for (int i = 0; i < n1; i++)
        L->insereFinal(lista->getItem(esquerda + i));
    for (int j = 0; j < n2; j++)
        R->insereFinal(lista->getItem(meio + 1 + j));

    int i = 0;
    int j = 0;
    int k = esquerda;

    while (i < n1 && j < n2) {
        if (L->getItem(i)->getCor() <= R->getItem(j)->getCor()) {
            lista->setItem(L->getItem(i), k);
            i++;
        } else {
            lista->setItem(R->getItem(j), k);
            j++;
        }
        k++;
    }

    while (i < n1) {
        lista->setItem(L->getItem(i), k);
        i++;
        k++;
    }

    while (j < n2) {
        lista->setItem(R->getItem(j), k);
        j++;
        k++;
    }

    delete L;
    delete R;
}

void Sorting::heapsort(Lista *lista) {
    int tamanho = lista->getTamanho();

    for (int i = tamanho / 2 - 1; i >= 0; i--)
        hsAjustaMax(lista, tamanho, i);

    for (int i = tamanho - 1; i > 0; i--) {
        troca(0, i, lista);
        hsAjustaMax(lista, tamanho, i);
        hsAjustaMax(lista, i, 0);
    }
}

void Sorting::hsAjustaMax(Lista* lista, int tamanho, int indice) {
    int indiceMaior = indice;
    int filhoEsquerda = 2 * indice + 1;
    int filhoDireita = 2 * indice + 2;

    if (filhoEsquerda < tamanho && lista->getItem(filhoEsquerda) > lista->getItem(indiceMaior))
        indiceMaior = filhoEsquerda;

    if (filhoDireita < tamanho && lista->getItem(filhoDireita) > lista->getItem(indiceMaior))
        indiceMaior = filhoDireita;

    if (indiceMaior != indice) {
        troca(indice, indiceMaior, lista);
        hsAjustaMax(lista, tamanho, indiceMaior);
    }
}

void Sorting::customSort(Lista *lista) {
    
}

void Sorting::troca(int indice1, int indice2, Lista* lista) {
    Vertice* aux = lista->getItem(indice1);
    lista->setItem(lista->getItem(indice2), indice1);
    lista->setItem(aux, indice2);
}