#include "../include/grafo.hpp"

Grafo::Grafo(int qtdVertices) {
    vertices = new Lista(qtdVertices);

    // Inicializa lista com vértices de cor e lista de adjacentes nulos
    for(int i = 0; i < qtdVertices; i++) {
        Vertice* novoVertice = new Vertice(i, 0, new Lista(0));
        vertices->insereFinal(novoVertice);
    }
}

Grafo::~Grafo() {
    // Exclui todos os vértices e apaga a lista
    int tamanho = vertices->getTamanho();
    for(int i = 0; i < tamanho; i++)
        delete vertices->getItem(i);
    delete vertices;
}

void Grafo::addVertice(int rotulo, std::string strAdjacentes) {
    // Cria o vetor de vértices adjacentes associado ao vértice
    Vertice* vertice = vertices->getItem(rotulo);
    std::istringstream streamAdjacente(strAdjacentes);
    std::string strQtdAdjacentes, strRotuloVertice;
    streamAdjacente >> strQtdAdjacentes;
    int qtdAdjacentes = std::stoi(strQtdAdjacentes);
    vertices->getItem(rotulo)->getAdjacentes()->setCapacidade(qtdAdjacentes);
    for(int i = 0; i < qtdAdjacentes; i++) {
        streamAdjacente >> strRotuloVertice;
        Vertice* verticeAdjacente = vertices->getItem(std::stoi(strRotuloVertice));
        vertice->getAdjacentes()->insereFinal(verticeAdjacente);
    }
}

void Grafo::colore(std::string strCores) {
    // Armazena as cores de cara vértice
    std::istringstream streamCores(strCores);
    std::string strCor;
    for(int i = 0; i < vertices->getTamanho(); i++) {
        streamCores >> strCor;
        vertices->getItem(i)->setCor(std::stoi(strCor));
    }
}

bool Grafo::eGuloso() {
    // Verifica se todos os vértices satisfazem a condição para ser guloso
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
            Sorting::quicksort(0, vertices->getTamanho() - 1, vertices);
            break;
        case 'm':
            Sorting::mergesort(0, vertices->getTamanho() - 1, vertices);
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