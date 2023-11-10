#ifndef LISTA_ENCADEADA_HPP
#define LISTA_ENCADEADA_HPP

#include "tipo_celula.hpp"

// Forward declaration de Vertice
class Vertice;

class ListaEncadeada {
    public:
        int getTamanho();
        bool vazia();
        ListaEncadeada();
        ~ListaEncadeada();
        Vertice* getItem(int pos);
        void setItem(Vertice* item, int pos);
        void insereInicio(Vertice* item);
        void insereFinal(Vertice* item);
        void inserePosicao(Vertice* item, int pos);
        Vertice* removeInicio();
        Vertice* removeFinal();
        Vertice* removePosicao(int pos);
        Vertice* pesquisa(int c);
        void limpa();
        TipoCelula* getPrimeiraCelula();
        TipoCelula* getCelula(int pos);
    private:
        int tamanho;
        TipoCelula* primeiro;
        TipoCelula* ultimo;
        TipoCelula* posiciona(int pos, bool antes);
};

#endif // LISTA_ENCADEADA_HPP