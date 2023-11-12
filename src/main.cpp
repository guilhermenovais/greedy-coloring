#include <iostream>
#include <sstream>
#include <string>
#include "../include/grafo.hpp"

int main(void) {
    // Obtém os parâmetros para a execução do programa
    std::string linha;
    std::getline(std::cin, linha);
    std::istringstream stream(linha);
    std::string qtdVertices, tipoOrdenacao;
    stream >> tipoOrdenacao;
    stream >> qtdVertices;

    // Inicializa o grafo com os vértices
    Grafo grafo = Grafo(std::stoi(qtdVertices));

    // Define os vértices adjacentes de cada vértice
    int rotulo = 0;
    while(rotulo < std::stoi(qtdVertices)) {
        std::getline(std::cin, linha);
        grafo.addVertice(rotulo, linha);
        rotulo++;
    }

    // Define as cores de cada vértice
    std::getline(std::cin, linha);
    grafo.colore(linha);

    // Ordena a lista de vértices usando o método de ordenação selecionado
    grafo.ordena(tipoOrdenacao[0]);

    // Verifica se a coloração pode ser obtida usando um algoritmo guloso
    bool eGuloso = grafo.eGuloso();

    // Imprime o resultado
    std::cout << eGuloso;
    if(eGuloso) {
        grafo.imprimeVertices();
    }
    return 0;
}