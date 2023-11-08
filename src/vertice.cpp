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

bool Vertice::satisfazGuloso() {
    if(cor == 0)
        throw "A cor ainda não foi definida";
    int coresMenores[cor - 1];
    for(int i = 0; i < cor - 1; i++) {
        coresMenores[i] = i + 1;
    }
    TipoCelula* celula = adjacentes->getPrimeiraCelula()->getProx();
    while (celula != nullptr) {
        int corAdjacente = celula->getItem()->getCor();
        if(corAdjacente < cor) {
            // zera posição da cor ao encontrá-la
            coresMenores[corAdjacente - 1] = 0;
        }
        celula = celula->getProx();
    }

    // Verifica se alguma cor menor não foi encontrada
    for(int i = 0; i < cor - 1; i++) {
        if(coresMenores[i] != 0)
            return false;
    }

    // Retorna true caso todas tenha sido encontradas;
    return true;
}