#ifndef VERTICE_HPP
#define VERTICE_HPP

// Forward declaration de ListaEncadeada
class ListaEncadeada;

class Vertice {
    public:
        Vertice();
        int GetChave();
    private:
        ListaEncadeada* adjacentes;
        int rotulo;
        int cor;
};

#endif // VERTICE_HPP