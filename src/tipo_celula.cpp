#include "../include/tipo_celula.hpp"

TipoCelula::TipoCelula() {
    item = nullptr;
    prox = nullptr;
}

TipoCelula* TipoCelula::getProx() {
    return prox;
}

Vertice* TipoCelula::getItem() {
    return item;
}