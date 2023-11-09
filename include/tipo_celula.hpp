#ifndef TIPO_CELULA_HPP
#define TIPO_CELULA_HPP

#include "vertice.hpp"

class TipoCelula {
    public:
        TipoCelula();
        TipoCelula* getProx();
        TipoCelula* getAnterior();
        Vertice* getItem();
    private:
        Vertice* item;
        TipoCelula* prox;
        TipoCelula* anterior;
        friend class ListaEncadeada;
        friend class Sorting;
};

#endif // TIPO_CELULA_HPP