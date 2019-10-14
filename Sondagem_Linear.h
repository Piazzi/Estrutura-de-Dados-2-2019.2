#ifndef SONDAGEM_LINEAR_H_INCLUDED
#define SONDAGEM_LINEAR_H_INCLUDED
#include "GameReview.h"
class Sondagem_Linear
{
    public:
        Sondagem_Linear(int tam);
        ~Sondagem_Linear();
        void insere_sond_linear(GameReview vetor[]);
        void imprimir();
        int numcomparacoes=0;
        float memoriagasta=0;
    private:
        int func_sond_linear(int valor);
        int tamanho;
        GameReview *tabela;
};

#endif // SONDAGEM_LINEAR_H_INCLUDED
