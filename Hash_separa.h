#ifndef HASH_SEPARA_H_INCLUDED
#define HASH_SEPARA_H_INCLUDED
#include "Lista_encadeada.h"

class Hash_separa
{
    public:
        Hash_separa(int tamanho);
        ~Hash_separa();
        int func_hash_separado(int valor);
        void insere_hash_separado (GameReview vetor[]);
        void imprimir();
        int numcomparacoes=0;
        float memoriagasta=0;
    private:
        int tam;
        ListaEncadeada ** tabela;
};


#endif // HASH_SEPARA_H_INCLUDED
