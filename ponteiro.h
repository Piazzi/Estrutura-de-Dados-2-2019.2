#ifndef PONTEIRO_H_INCLUDED
#define PONTEIRO_H_INCLUDED
#include "GameReview.h"
class ponteiro
{
    public:
        ponteiro();
        ~ponteiro();
        GameReview getGameReview();
        void setChave(GameReview gr);
        ponteiro* getProx();
        void setProx(ponteiro* novo);
        int getEnde();
        void setEnde(int val);
    private:
        ponteiro* prox;
        GameReview gr;
        int endereco;
};

#endif // PONTEIRO_H_INCLUDED
