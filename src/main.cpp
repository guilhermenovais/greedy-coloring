#include <iostream>
#include <sstream>
#include <string>
#include "../include/grafo.hpp"

int main(void) {
    std::string linha;
    std::getline(std::cin, linha);
    std::istringstream stream(linha);
    std::string qtdVertices, tipoOrdenacao;
    stream >> tipoOrdenacao;
    stream >> qtdVertices;

    Grafo grafo = Grafo(std::stoi(qtdVertices));

    int rotulo = 0;
    while(rotulo < std::stoi(qtdVertices)) {
        std::getline(std::cin, linha);
        grafo.addVertice(rotulo, linha);
        rotulo++;
    }

    std::getline(std::cin, linha);
    grafo.colore(linha);

    std::cout << grafo.eGuloso();
    return 0;
}