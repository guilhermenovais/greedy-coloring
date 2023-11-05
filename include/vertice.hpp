#ifndef VERTICE_HPP
#define VERTICE_HPP

// Forward declaration de ListaEncadeada
class ListaEncadeada;

class Vertice {
    public:
        Vertice(int rotulo, int cor, ListaEncadeada* adjacentes);
        ~Vertice();
        int getChave();
        int getCor();
        ListaEncadeada* getAdjacentes();
    private:
        ListaEncadeada* adjacentes;
        int rotulo;
        int cor;
};

#endif // VERTICE_HPP