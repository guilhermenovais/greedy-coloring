#ifndef VERTICE_HPP
#define VERTICE_HPP

// Forward declaration de Lista
class Lista;

class Vertice {
    public:
        Vertice(int rotulo = 0, int cor = 0, Lista* adjacentes = nullptr);
        ~Vertice();
        int getChave();
        int getCor();
        void setCor(int cor);
        Lista* getAdjacentes();
        bool satisfazGuloso();
    private:
        Lista* adjacentes;
        int rotulo;
        int cor;
};

#endif // VERTICE_HPP