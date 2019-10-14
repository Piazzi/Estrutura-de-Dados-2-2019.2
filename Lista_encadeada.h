#ifndef LISTA_ENCADEADA_H_INCLUDED
#define LISTA_ENCADEADA_H_INCLUDED
#include "Lista_encadeada.h"
#include "No.h"

class ListaEncadeada{
public:
    ListaEncadeada();
    ~ListaEncadeada();
    void insereInicio(GameReview gr);
    void insere(GameReview gr);
    void imprimir();
    int numcomparacoes=0;
private:
    No* primeiro;
};

#endif // LISTA_ENCADEADA_H_INCLUDED
