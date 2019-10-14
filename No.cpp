#include <iostream>
#include "No.h"

using namespace std;

No::No() {};
No::~No() {};
GameReview No::getInfoGameReview()
{
    return gr;
}
No* No::getProx()
{
    return Prox;
}
void No::setInfoGameReview(GameReview obj)
{
    gr=obj;
}
void No::setProx(No* novo)
{
    Prox = novo;
}
