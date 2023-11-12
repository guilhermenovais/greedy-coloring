#include "../include/vertice.hpp"
#include "../include/lista.hpp"

Vertice::Vertice(int rotulo, int cor, Lista* adjacentes) {
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

Lista* Vertice::getAdjacentes() {
    return adjacentes;
}

bool Vertice::satisfazGuloso() {
    if(cor == 0)
        throw "A cor ainda não foi definida";
    int coresMenores[cor - 1];
    for(int i = 0; i < cor - 1; i++) {
        coresMenores[i] = i + 1;
    }
    int qtdAdjacentes = adjacentes->getTamanho();
    for(int i = 0; i < qtdAdjacentes; i++) {
        int corAdjacente = adjacentes->getItem(i)->getCor();
        if(corAdjacente < cor) {
            // Zera posição da cor ao encontrá-la
            coresMenores[corAdjacente - 1] = 0;
        }
    }

    // Verifica se alguma cor menor não foi encontrada
    for(int i = 0; i < cor - 1; i++) {
        if(coresMenores[i] != 0)
            return false;
    }

    // Retorna true caso todas tenha sido encontradas;
    return true;
}