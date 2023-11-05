#include "../include/lista_encadeada.hpp"
#include "../include/tipo_celula.hpp"

ListaEncadeada::ListaEncadeada() {
    tamanho = 0;
    primeiro = new TipoCelula();
    ultimo = primeiro;
}

ListaEncadeada::~ListaEncadeada() {
    Limpa();
    delete primeiro;
}

TipoCelula* ListaEncadeada::Posiciona(int pos, bool antes=false) {
    TipoCelula *p; 
    int i;
    if((pos > tamanho) || (pos <= 0))
        throw "ERRO: Posicao Invalida!";
    p = primeiro;
    for(i=1; i<pos; i++){
        p = p->prox;
    }
    if(!antes)
        p = p->prox;
    return p;
}

Vertice* ListaEncadeada::GetItem(int pos) {
    TipoCelula* p;
    p = Posiciona(pos);
    return p->item;
}

void ListaEncadeada::SetItem(Vertice* item, int pos) {
    TipoCelula* p;
    p = Posiciona(pos);
    p->item = item;
}

void ListaEncadeada::InsereInicio(Vertice* item) {
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->item = item;
    nova->prox = primeiro->prox;
    primeiro->prox = nova;
    tamanho++;
    if(nova->prox == nullptr)
        ultimo = nova;
};

void ListaEncadeada::InsereFinal(Vertice* item) {
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->item = item;
    ultimo->prox = nova;
    ultimo = nova;
    tamanho++;
}

void ListaEncadeada::InserePosicao(Vertice* item, int pos) { 
    TipoCelula *p, *nova;
    p = Posiciona(pos,true); // posiciona na célula anterior
    nova = new TipoCelula();
    nova->item = item;
    nova->prox = p->prox;
    p->prox = nova;
    tamanho++;
    if(nova->prox == nullptr)
        ultimo = nova;
};

Vertice* ListaEncadeada::RemoveInicio() {
    Vertice* aux;
    TipoCelula *p;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    p = primeiro->prox;
    primeiro->prox = p->prox;
    tamanho--;
    if(primeiro->prox == nullptr)
        ultimo = primeiro;
    aux = p->item;
    delete p;
    return aux;
}

Vertice* ListaEncadeada::RemoveFinal() {
    Vertice* aux;
    TipoCelula *p;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    // posiciona p na celula anterior à última
    p = Posiciona(tamanho, true);
    p->prox = nullptr;
    tamanho--;
    aux = ultimo->item;
    delete ultimo;
    ultimo = p;
    return aux;
}

Vertice* ListaEncadeada::RemovePosicao(int pos) {
    Vertice* aux;
    TipoCelula *p, *q;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    // posiciona p na celula anterior à pos
    p = Posiciona(pos, true);
    q = p->prox;
    p->prox = q->prox;
    tamanho--;
    aux = q->item;
    delete q;
    if(p->prox == nullptr)
        ultimo = p;
    return aux;
}

Vertice* ListaEncadeada::Pesquisa(int c) {
    Vertice* aux = nullptr;
    TipoCelula *p;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    p = primeiro->prox;
    while (p!= nullptr) {
        if (p->item->GetChave() == c) {
            aux = p->item;
            break;
        }
        p = p->prox;
    }
    return aux;
};

void ListaEncadeada::Limpa() {
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

int ListaEncadeada::GetTamanho() {
    return tamanho;
}

bool ListaEncadeada::Vazia() {
    return tamanho == 0;
}