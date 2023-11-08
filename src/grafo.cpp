#include "../include/grafo.hpp"

Grafo::Grafo(int qtdVertices) {
    vertices = new ListaEncadeada();
    for(int i = 0; i < qtdVertices; i++) {
        Vertice* novoVertice = new Vertice(i, 0, new ListaEncadeada());
        vertices->insereFinal(novoVertice);
    }
}

Grafo::~Grafo() {
    delete vertices;
}

void Grafo::addVertice(int rotulo, std::string strAdjacentes) {
    Vertice* vertice = vertices->getItem(rotulo);
    std::istringstream streamAdjacente(strAdjacentes);
    std::string strQtdAdjacentes, strRotuloVertice;
    streamAdjacente >> strQtdAdjacentes;
    for(int i = 0; i < std::stoi(strQtdAdjacentes); i++) {
        streamAdjacente >> strRotuloVertice;
        Vertice* verticeAdjacente = vertices->getItem(std::stoi(strRotuloVertice));
        vertice->getAdjacentes()->insereFinal(verticeAdjacente);
    }
}