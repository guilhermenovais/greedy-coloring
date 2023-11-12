#include "../include/lista.hpp"
#include "../include/vertice.hpp"

Lista::Lista(int capacidadeInicial) {
    capacidade = capacidadeInicial;
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
    if(tamanho == capacidade)
        redimensiona();
    tamanho++;
    for(int i = tamanho; i > 0; i--)
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
    if(tamanho == capacidade)
        redimensiona();
    if((pos > tamanho) || (pos < 0))
        throw "ERRO: Posicao Invalida!";
    tamanho++;
    for(int i = tamanho; i > pos; i--)
        array[i] = array[i-1];
    array[pos] = item;};

Vertice* Lista::removeInicio() {
    if(tamanho == 0)
        throw "ERRO: Lista vazia!";
    Vertice* aux = array[0];
    for(int i = 0; i < tamanho; i++)
        array[i] = array[i+1];
    tamanho--;
    return aux;
}

Vertice* Lista::removeFinal() {
    if(tamanho == 0)
        throw "ERRO: Lista vazia!";
    tamanho--;
    Vertice* aux = array[tamanho];
    return aux;
}

Vertice* Lista::removePosicao(int pos) {
    if((pos > tamanho) || (pos < 0))
        throw "ERRO: Posicao Invalida!";
    Vertice* aux = array[pos];
    for(int i = pos; i < tamanho; i++)
        array[i] = array[i+1];
    tamanho--;
    return aux;
}

Vertice* Lista::pesquisa(int chave) {
    if(tamanho == 0)
        throw "ERRO: Lista vazia!";
    Vertice* aux = nullptr; // indica pesquisa sem sucesso
    for(int i=0; i < tamanho; i++)
        if(array[i]->getChave() == chave) {
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
    for(int i = 0; i < tamanho; ++i) {
        novoArray[i] = array[i];
    }

    if(array != nullptr)
        delete[] array;

    array = novoArray;
    capacidade = novaCapacidade;
}

void Lista::setCapacidade(int novaCapacidade) {
    if(array != nullptr)
        delete[] array;
    array = new Vertice*[novaCapacidade];
    capacidade = novaCapacidade;
    tamanho = 0;
}