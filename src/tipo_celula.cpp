#include "../include/tipo_celula.hpp"

TipoCelula::TipoCelula() {
    item = nullptr;
    prox = nullptr;
    anterior = nullptr;
}

TipoCelula* TipoCelula::getProx() {
    return prox;
}

TipoCelula* TipoCelula::getAnterior() {
    return anterior;
}

Vertice* TipoCelula::getItem() {
    return item;
}