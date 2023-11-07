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
    for(int i = 0; i < strAdjacentes.length(); i++) {
        if(strAdjacentes[i] != ' ') {
            std::string strNum = "";
            strNum.push_back(strAdjacentes[i]);
            while(i + 1 < strAdjacentes.length() && strAdjacentes[i + 1] != ' ') {
                i++;
                strNum.push_back(strAdjacentes[i]);
            }
            Vertice* verticeAdjacente = vertices->getItem(std::stoi(strNum));
            vertice->getAdjacentes()->insereFinal(verticeAdjacente);
        }
    }
}