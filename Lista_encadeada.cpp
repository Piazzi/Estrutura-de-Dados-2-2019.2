#include <iostream>
#include "Lista_encadeada.h"

using namespace std;

ListaEncadeada::ListaEncadeada(){
    primeiro = NULL;
};
ListaEncadeada::~ListaEncadeada(){
    No *p = primeiro;
    while(p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }
}
void ListaEncadeada::insereInicio(GameReview gr){
    No* p = new No();
    p->setInfoGameReview(gr);
    p->setProx(NULL);
    primeiro = p;
}
void ListaEncadeada::insere(GameReview gr){
    numcomparacoes++;
    if(primeiro==NULL)
    {
        insereInicio(gr);
    }
    else{
        No* no = primeiro;
        while(no->getProx() != NULL){
            no = no->getProx();
            numcomparacoes++;
        }
        numcomparacoes++;
        No* u = new No;
        u->setInfoGameReview(gr);
        u->setProx(NULL);
        no->setProx(u);
    }
}
void ListaEncadeada::imprimir(){
    if(primeiro == NULL)
    {
        cout << "NULL";
    }
    else
    {
        No* aux = primeiro;
        while(aux->getProx() != NULL)
        {
            GameReview gr1=aux->getInfoGameReview();
            cout << "[" << gr1.GetIndex() << "]->";
            aux = aux->getProx();
        }
        GameReview gr2=aux->getInfoGameReview();
        cout << "[" << gr2.GetIndex() << "]";
    }
}
