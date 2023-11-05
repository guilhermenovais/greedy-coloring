#ifndef LISTA_ENCADEADA_HPP
#define LISTA_ENCADEADA_HPP



#include "tipo_celula.hpp"

// Forward declaration de Vertice
class Vertice;

class ListaEncadeada {
    public:
        int GetTamanho();
        bool Vazia();
        ListaEncadeada();
        ~ListaEncadeada();
        Vertice* GetItem(int pos);
        void SetItem(Vertice* item, int pos);
        void InsereInicio(Vertice* item);
        void InsereFinal(Vertice* item);
        void InserePosicao(Vertice* item, int pos);
        Vertice* RemoveInicio();
        Vertice* RemoveFinal();
        Vertice* RemovePosicao(int pos);
        Vertice* Pesquisa(int c);
        void Limpa();
    private:
        int tamanho;
        TipoCelula* primeiro;
        TipoCelula* ultimo;
        TipoCelula* Posiciona(int pos, bool antes);
};

#endif // LISTA_ENCADEADA_HPP