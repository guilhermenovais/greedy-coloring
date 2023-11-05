#ifndef TIPO_CELULA_HPP
#define TIPO_CELULA_HPP

#include "vertice.hpp"

class TipoCelula {
    public:
        TipoCelula();
    private:
        Vertice* item;
        TipoCelula* prox;
        friend class ListaEncadeada;
};

#endif // TIPO_CELULA_HPP