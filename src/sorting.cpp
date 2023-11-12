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

void Sorting::quicksort(int esquerda, int direita, Lista* lista) {
    int i, j;
    qsParticao(esquerda, direita, &i, &j, lista);
    if (esquerda < j) quicksort(esquerda, j, lista);
    if (i < direita) quicksort(i, direita, lista);
}

void Sorting::qsParticao(int esquerda, int direita, int *i, int *j, Lista* lista) {
    *i = esquerda;
    *j = direita;
    Vertice* pivo = lista->getItem((*i + *j)/2);
    do {
        /* Procura um elemento que tenha a cor menor que a do pivô
        ou que tenha a mesma cor mas tenha chave menor */
        while(
            pivo->getCor() > lista->getItem(*i)->getCor() ||
            (pivo->getCor() == lista->getItem(*i)->getCor() &&
            pivo->getChave() > lista->getItem(*i)->getChave())
        ) (*i)++;

        /* Procura um elemento que tenha a cor maior que a do pivô
        ou que tenha a mesma cor mas tenha chave maior */
        while(
            pivo->getCor() < lista->getItem(*j)->getCor() ||
            (pivo->getCor() == lista->getItem(*j)->getCor() &&
            pivo->getChave() < lista->getItem(*j)->getChave())
        ) (*j)--;

        // Troca os dois elementos
        if (*i <= *j) {
            troca(*i, *j, lista);
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void Sorting::mergesort(int esquerda, int direita, Lista* lista) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        mergesort(esquerda, meio, lista);
        mergesort(meio + 1, direita, lista);

        merge(esquerda, direita, lista);
    }
}

void Sorting::merge(int esquerda, int direita, Lista* lista) {
    int meio = esquerda + (direita - esquerda) / 2;
    int tamanhoEsq = meio - esquerda + 1;
    int tamanhoDir = direita - meio;

    Lista* listaEsq = new Lista(tamanhoEsq);
    Lista* listaDir = new Lista(tamanhoDir);

    // Copia os itens para suas respectivas listas
    for (int i = 0; i < tamanhoEsq; i++)
        listaEsq->insereFinal(lista->getItem(esquerda + i));
    for (int j = 0; j < tamanhoDir; j++)
        listaDir->insereFinal(lista->getItem(meio + 1 + j));

    int i = 0;
    int j = 0;
    int k = esquerda;

    // Guarda os items das duas listas na lista principal do menor para o maior
    while (i < tamanhoEsq && j < tamanhoDir) {
        if (listaEsq->getItem(i)->getCor() <= listaDir->getItem(j)->getCor()) {
            lista->setItem(listaEsq->getItem(i), k);
            i++;
        } else {
            lista->setItem(listaDir->getItem(j), k);
            j++;
        }
        k++;
    }

    // Guarda os itens que sobraram nas listas
    while (i < tamanhoEsq) {
        lista->setItem(listaEsq->getItem(i), k);
        i++;
        k++;
    }
    while (j < tamanhoDir) {
        lista->setItem(listaDir->getItem(j), k);
        j++;
        k++;
    }

    delete listaEsq;
    delete listaDir;
}

void Sorting::heapsort(Lista *lista) {
    int tamanho = lista->getTamanho();

    hsConstroiMax(lista);

    for (int indice = tamanho - 1; indice > 0; indice--) {
        // Move a raiz atual para o final
        troca(0, indice, lista);

        // Chama hsAjustaMax no heap reduzido
        hsAjustaMax(lista, indice, 0);
    }
}

void Sorting::hsConstroiMax(Lista* lista) {
    int tamanho = lista->getTamanho();

    // Constrói o heap (reorganiza a lista)
    for(int indice = tamanho / 2 - 1; indice >= 0; indice--)
        hsAjustaMax(lista, tamanho, indice);
}

void Sorting::hsAjustaMax(Lista* lista, int tamanho, int indiceRaiz) {
    int indiceMaior = indiceRaiz;
    int indiceFilhoEsquerda = 2 * indiceRaiz + 1;
    int indiceFilhoDireita = 2 * indiceRaiz + 2;

    /* Caso a cor do filho à esquerda seja maior ou as cores sejam iguais mas o filho à esquerda tenha
    chave maior*/
    if (indiceFilhoEsquerda < tamanho && lista->getItem(indiceFilhoEsquerda)->getCor() > lista->getItem(indiceMaior)->getCor())
        indiceMaior = indiceFilhoEsquerda;
    else if (indiceFilhoEsquerda < tamanho && lista->getItem(indiceFilhoEsquerda)->getCor() == lista->getItem(indiceMaior)->getCor() &&
            lista->getItem(indiceFilhoEsquerda)->getChave() > lista->getItem(indiceMaior)->getChave())
        indiceMaior = indiceFilhoEsquerda;

    /* Caso a cor do filho à direita seja maior ou as cores sejam iguais mas o filho à direita tenha
    chave maior*/
    if (indiceFilhoDireita < tamanho && lista->getItem(indiceFilhoDireita)->getCor() > lista->getItem(indiceMaior)->getCor())
        indiceMaior = indiceFilhoDireita;
    else if (indiceFilhoDireita < tamanho && lista->getItem(indiceFilhoDireita)->getCor() == lista->getItem(indiceMaior)->getCor() &&
            lista->getItem(indiceFilhoDireita)->getChave() > lista->getItem(indiceMaior)->getChave())
        indiceMaior = indiceFilhoDireita;

    if (indiceMaior != indiceRaiz) {
        troca(indiceRaiz, indiceMaior, lista);

        hsAjustaMax(lista, tamanho, indiceMaior);
    }
}

void Sorting::customSort(Lista *lista) {
    int maximo = rsEncontraMax(lista);

    // Ordena a lista dígito a dígito
    for (int exp = 1; maximo / exp > 0; exp *= 10)
        rsOrdenaPorDigito(lista, exp);
}

int Sorting::rsEncontraMax(Lista* lista) {
    int maximo = lista->getItem(0)->getCor();
    int tamanho = lista->getTamanho();
    for (int i = 1; i < tamanho; i++) {
        if(lista->getItem(i)->getCor() > maximo) {
            maximo = lista->getItem(i)->getCor();
        }
    }
    return maximo;
}

void Sorting::rsOrdenaPorDigito(Lista* lista, int exp) {
    const int tamanho = lista->getTamanho();
    const int base = 10;

    // Cria e inicializa lista onde será armazenado o resultado
    Lista* resultado = new Lista(tamanho);
    for(int i = 0; i < tamanho; i++)
        resultado->insereFinal(lista->getItem(i));
    
    // Cria e inicializa arra de contagem de dígitos
    int contagemDigitos[base];
    for(int i = 0; i < base; i++)
        contagemDigitos[i] = 0;

    // Faz a contagem das ocorrências de cada dígito
    for(int i = 0; i < tamanho; i++)
        contagemDigitos[(lista->getItem(i)->getCor() / exp) % base]++;

    // Acumula a contagem
    for(int i = 1; i < base; i++)
        contagemDigitos[i] += contagemDigitos[i - 1];

    // Cria a lista ordenada
    for(int i = tamanho - 1; i >= 0; i--) {
        resultado->setItem(lista->getItem(i), contagemDigitos[(lista->getItem(i)->getCor() / exp) % base] - 1);
        contagemDigitos[(lista->getItem(i)->getCor() / exp) % base]--;
    }

    // Copia a lista ordenada para a lista principal
    for(int i = 0; i < tamanho; i++)
        lista->setItem(resultado->getItem(i), i);

    delete resultado;
}

void Sorting::troca(int indice1, int indice2, Lista* lista) {
    Vertice* aux = lista->getItem(indice1);
    lista->setItem(lista->getItem(indice2), indice1);
    lista->setItem(aux, indice2);
}