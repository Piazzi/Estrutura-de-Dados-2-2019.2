#ifndef HASH_COALESC_H_INCLUDED
#define HASH_COALESC_H_INCLUDED
#include "ponteiro.h"

class Hash_coalesc{
    public:
        Hash_coalesc(int tam);
        ~Hash_coalesc();
        void insere_hashCoalescido(GameReview vetor[]);
        void imprimir();
        int numcomparacoes=0;
        float memoriagasta=0;
    private:
        int func_hashCoalescido(int valor);
        int tamanho;
        ponteiro ** tabela;
};

#endif // HASH_COALESC_H_INCLUDED
