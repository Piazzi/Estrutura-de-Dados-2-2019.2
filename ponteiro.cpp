#include "ponteiro.h"

using namespace std;

ponteiro::ponteiro(){
}

ponteiro::~ponteiro(){
}

GameReview ponteiro::getGameReview()
{
    return gr;
}

ponteiro* ponteiro::getProx()
{
    return prox;
}

void ponteiro::setChave(GameReview obj)
{
    gr=obj;
}

void ponteiro::setProx(ponteiro* novo)
{
    prox = novo;
}

int ponteiro::getEnde()
{
    return endereco;
}

void ponteiro::setEnde(int val)
{
    endereco = val;
}
