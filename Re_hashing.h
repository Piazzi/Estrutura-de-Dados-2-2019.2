#ifndef RE_HASHING_H_INCLUDED
#define RE_HASHING_H_INCLUDED
#include "GameReview.h"
class Re_hashing
{
public:
    Re_hashing(int tam);
    ~Re_hashing();
    void inserir_rehashing(GameReview vetor[]);
    void imprimir();
    int numcomparacoes=0;
    float memoriagasta=0;
private:
    int func_calc_hashing(int valor);
    int func2_calc_hashing(int valor, int cont);
    int calculaProxPrimo(int n);
    int tamanho, tamanho2;
    GameReview *tabela;
};

#endif // RE_HASHING_H_INCLUDED
