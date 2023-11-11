#include "../include/lista.hpp"
#include "../include/vertice.hpp"

Lista::Lista() {
    capacidade = 10;
    array = new Vertice*[capacidade];
    tamanho = 0;
}

Lista::~Lista() {
    limpa();
    delete[] array;
}

Vertice* Lista::getItem(int pos) {
    if((pos > tamanho) || (pos < 0))
        throw "ERRO: Posicao Invalida!";
    return array[pos];
}

void Lista::setItem(Vertice* item, int pos) {
    if((pos > tamanho) || (pos < 0))
        throw "ERRO: Posicao Invalida!"; 
    array[pos] = item;
}

void Lista::insereInicio(Vertice* item) {
    int i;
    if(tamanho == capacidade)
        redimensiona();
    tamanho++;
    for(i=tamanho;i>0;i--)
        array[i] = array[i-1];
    array[0] = item;
};

void Lista::insereFinal(Vertice* item) {
    if(tamanho == capacidade)
        redimensiona();
    array[tamanho] = item;
    tamanho++;
}

void Lista::inserePosicao(Vertice* item, int pos) { 
    int i;
    if(tamanho == capacidade)
        redimensiona();
    if((pos > tamanho) || (pos < 0))
        throw "ERRO: Posicao Invalida!";
    tamanho++;
    for(i = tamanho; i > pos; i--)
        array[i] = array[i-1];
    array[pos] = item;};

Vertice* Lista::removeInicio() {
    int i;
    Vertice* aux;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    aux = array[0];
    for(i = 0; i < tamanho; i++)
        array[i] = array[i+1];
    tamanho--;
    return aux;
}

Vertice* Lista::removeFinal() {
    Vertice* aux;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    tamanho--;
    aux = array[tamanho];
    return aux;
}

Vertice* Lista::removePosicao(int pos) {
    int i; 
    Vertice* aux;
    if((pos > tamanho) || (pos < 0))
        throw "ERRO: Posicao Invalida!";
    aux = array[pos];
    for(i = pos; i < tamanho; i++)
        array[i] = array[i+1];
    tamanho--;
    return aux;
}

Vertice* Lista::pesquisa(int c) {
    int i; 
    Vertice* aux;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    aux = nullptr; // indica pesquisa sem sucesso
    for(i=0;i<tamanho;i++)
        if(array[i]->getChave() == c) {
            aux = array[i];
            break;
        }
    return aux;
};

void Lista::limpa() {
    tamanho = 0;
};

int Lista::getTamanho() {
    return tamanho;
}

bool Lista::vazia() {
    return tamanho == 0;
}

void Lista::redimensiona() {
    int novaCapacidade = capacidade * 2;
    Vertice** novoArray = new Vertice*[novaCapacidade];
    for (int i = 0; i < tamanho; ++i) {
        novoArray[i] = array[i];
    }

    delete[] array;

    array = novoArray;
    capacidade = novaCapacidade;
}