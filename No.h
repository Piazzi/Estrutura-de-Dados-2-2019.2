#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
#include "GameReview.h"
class No
{
public:
    No();
    ~No();
    GameReview getInfoGameReview();
    No* getProx();
    void setInfoGameReview(GameReview obj);
    void setProx(No* novoNo);
private:
    GameReview gr;
    No *Prox;
};


#endif // NO_H_INCLUDED
