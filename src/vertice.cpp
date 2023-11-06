#include "../include/vertice.hpp"
#include "../include/lista_encadeada.hpp"

Vertice::Vertice(int rotulo, int cor, ListaEncadeada* adjacentes) {
    this->rotulo = rotulo;
    this->cor = cor;
    this->adjacentes = adjacentes;
}

Vertice::~Vertice() {
    delete adjacentes;
}

int Vertice::getChave() {
    return rotulo;
}

int Vertice::getCor() {
    return cor;
}

void Vertice::setCor(int cor) {
    this->cor = cor;
}

ListaEncadeada* Vertice::getAdjacentes() {
    return adjacentes;
}