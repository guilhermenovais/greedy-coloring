#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "lista_encadeada.hpp"
#include "vertice.hpp"
#include <sstream>
#include <string>
#include "sorting.hpp"
#include <iostream>

class Grafo {
    public:
        Grafo(int qtdVertices);
        ~Grafo();
        bool eGuloso();
        void addVertice(int rotulo, std::string strAdjacentes);
        void colore(std::string strCores);
        void ordena(char tipoOrdenacao);
        void imprimeVertices();
    private:
        ListaEncadeada* vertices;
};

#endif // GRAFO_HPP