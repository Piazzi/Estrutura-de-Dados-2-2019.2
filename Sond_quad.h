#ifndef SOND_QUAD_H_INCLUDED
#define SOND_QUAD_H_INCLUDED
#include "GameReview.h"
class Sond_quad {
public:
    Sond_quad(int tam);
    ~Sond_quad();
    void inserir_func_quadratica(GameReview vetor[]);
    void imprimir();
    int numcomparacoes=0;
    float memoriagasta=0;
private:
    int func_calc_hashing(int valor);
    int tamanho;
    GameReview *tabela;

};

#endif // SOND_QUAD_H_INCLUDED
