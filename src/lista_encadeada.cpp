#include "../include/lista_encadeada.hpp"
#include "../include/vertice.hpp"

ListaEncadeada::ListaEncadeada() {
    tamanho = 0;
    primeiro = new TipoCelula();
    ultimo = primeiro;
}

ListaEncadeada::~ListaEncadeada() {
    limpa();
    delete primeiro;
}

TipoCelula* ListaEncadeada::posiciona(int pos, bool antes=false) {
    TipoCelula *p; 
    int i;
    if((pos > tamanho) || (pos < 0))
        throw "ERRO: Posicao Invalida!";
    p = primeiro;
    for(i=0; i<pos; i++){
        p = p->prox;
    }
    if(!antes)
        p = p->prox;
    return p;
}

Vertice* ListaEncadeada::getItem(int pos) {
    TipoCelula* p;
    p = posiciona(pos);
    return p->item;
}

void ListaEncadeada::setItem(Vertice* item, int pos) {
    TipoCelula* p;
    p = posiciona(pos);
    p->item = item;
}

void ListaEncadeada::insereInicio(Vertice* item) {
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->item = item;
    nova->prox = primeiro->prox;
    nova->prox->anterior = nova;
    primeiro->prox = nova;
    nova->anterior = primeiro;
    tamanho++;
    if(nova->prox == nullptr)
        ultimo = nova;
};

void ListaEncadeada::insereFinal(Vertice* item) {
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->item = item;
    ultimo->prox = nova;
    nova->anterior = ultimo;
    ultimo = nova;
    tamanho++;
}

void ListaEncadeada::inserePosicao(Vertice* item, int pos) { 
    TipoCelula *p, *nova;
    p = posiciona(pos,true); // posiciona na célula anterior
    nova = new TipoCelula();
    nova->item = item;
    nova->prox = p->prox;
    nova->prox->anterior  = nova;
    p->prox = nova;
    nova->anterior = p;
    tamanho++;
    if(nova->prox == nullptr)
        ultimo = nova;
};

Vertice* ListaEncadeada::removeInicio() {
    Vertice* aux;
    TipoCelula *p;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    p = primeiro->prox;
    primeiro->prox = p->prox;
    primeiro->prox->anterior = primeiro;
    tamanho--;
    if(primeiro->prox == nullptr)
        ultimo = primeiro;
    aux = p->item;
    delete p;
    return aux;
}

Vertice* ListaEncadeada::removeFinal() {
    Vertice* aux;
    TipoCelula *p;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    // posiciona p na celula anterior à última
    p = posiciona(tamanho, true);
    p->prox = nullptr;
    tamanho--;
    aux = ultimo->item;
    delete ultimo;
    ultimo = p;
    return aux;
}

Vertice* ListaEncadeada::removePosicao(int pos) {
    Vertice* aux;
    TipoCelula *p, *q;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    // posiciona p na celula anterior à pos
    p = posiciona(pos, true);
    q = p->prox;
    p->prox = q->prox;
    p->prox->anterior = p;
    tamanho--;
    aux = q->item;
    delete q;
    if(p->prox == nullptr)
        ultimo = p;
    return aux;
}

Vertice* ListaEncadeada::pesquisa(int c) {
    Vertice* aux = nullptr;
    TipoCelula *p;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    p = primeiro->prox;
    while (p!= nullptr) {
        if (p->item->getChave() == c) {
            aux = p->item;
            break;
        }
        p = p->prox;
    }
    return aux;
};

void ListaEncadeada::limpa() {
    TipoCelula *p;
    p = primeiro->prox;
    while (p!=nullptr) {
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
    tamanho = 0;
};

int ListaEncadeada::getTamanho() {
    return tamanho;
}

bool ListaEncadeada::vazia() {
    return tamanho == 0;
}

TipoCelula* ListaEncadeada::getPrimeiraCelula() {
    return primeiro;
}

TipoCelula* ListaEncadeada::getCelula(int pos) {
    TipoCelula* p;
    p = posiciona(pos);
    return p;
}

TipoCelula* ListaEncadeada::getUltimaCelula() {
    return ultimo;
}