#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "lista_encadeada.hpp"
#include "vertice.hpp"
#include <sstream>
#include <string>

class Grafo {
    public:
        Grafo(int qtdVertices);
        ~Grafo();
        bool eGuloso();
        void addVertice(int rotulo, std::string strAdjacentes);
        void colore(std::string strCores);
    private:
        void ordena(char tipoOrdenacao);
        ListaEncadeada* vertices;
};

#endif // GRAFO_HPP