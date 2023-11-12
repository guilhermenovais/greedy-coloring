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

    // Inicializa o array com as cores que devem estar ligadas ao vértice
    int coresMenores[cor - 1];
    for(int i = 0; i < cor - 1; i++) {
        coresMenores[i] = i + 1;
    }

    int coresFaltantes = cor - 1;

    if(coresFaltantes == 0)
        return true;
    
    int qtdAdjacentes = adjacentes->getTamanho();
    for(int i = 0; i < qtdAdjacentes; i++) {
        int corAdjacente = adjacentes->getItem(i)->getCor();
        if(corAdjacente < cor && coresMenores[corAdjacente - 1] != 0) {
            // Zera posição da cor ao encontrá-la
            coresMenores[corAdjacente - 1] = 0;
            // Decrementa a variável de cores faltantes
            coresFaltantes--;
            // Verifica se já achou todas as cores
            if(coresFaltantes <= 0)
                return true;
        }
    }

    return false;
}