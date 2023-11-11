#include "../include/grafo.hpp"

Grafo::Grafo(int qtdVertices) {
    vertices = new Lista();
    for(int i = 0; i < qtdVertices; i++) {
        Vertice* novoVertice = new Vertice(i, 0, new Lista());
        vertices->insereFinal(novoVertice);
    }
}

Grafo::~Grafo() {
    int tamanho = vertices->getTamanho();
    for(int i = 0; i < tamanho; i++)
        delete vertices->getItem(i);
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

void Grafo::colore(std::string strCores) {
    std::istringstream streamCores(strCores);
    std::string strCor;
    for(int i = 0; i < vertices->getTamanho(); i++) {
        streamCores >> strCor;
        vertices->getItem(i)->setCor(std::stoi(strCor));
    }
}

bool Grafo::eGuloso() {
    int tamanho = vertices->getTamanho();
    for(int i = 0; i < tamanho; i++) {
        bool satisfaz = vertices->getItem(i)->satisfazGuloso();
        if(!satisfaz) return false;
    }
    return true;
}

void Grafo::ordena(char tipoOrdenacao) {
    switch (tipoOrdenacao) {
        case 'b':
            Sorting::bubbleSort(vertices);
            break;
        case 's':
            Sorting::selectionSort(vertices);
            break;
        case 'i':
            Sorting::insertionSort(vertices);
            break;
        case 'q':
            Sorting::quicksort(vertices);
            break;
        case 'm':
            Sorting::mergesort(vertices);
            break;
        case 'p':
            Sorting::heapsort(vertices);
            break;
        case 'y':
            Sorting::customSort(vertices);
            break;
    }
}

void Grafo::imprimeVertices() {
    int tamanho = vertices->getTamanho();
    for(int i = 0; i < tamanho; i++)
        std::cout << ' ' << vertices->getItem(i)->getChave();
}