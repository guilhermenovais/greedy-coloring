#ifndef LISTA_HPP
#define LISTA_HPP

// Forward declaration de Vertice
class Vertice;

class Lista {
    public:
        int getTamanho();
        bool vazia();
        Lista(int capacidadeInicial);
        ~Lista();
        Vertice* getItem(int pos);
        void setItem(Vertice* item, int pos);
        void insereInicio(Vertice* item);
        void insereFinal(Vertice* item);
        void inserePosicao(Vertice* item, int pos);
        Vertice* removeInicio();
        Vertice* removeFinal();
        Vertice* removePosicao(int pos);
        Vertice* pesquisa(int chave);
        void limpa();
        void setCapacidade(int novaCapacidade);
    private:
        Vertice** array;
        int capacidade;
        int tamanho;
        void redimensiona();      
};

#endif // LISTA_HPP