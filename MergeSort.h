#ifndef MERGESORT_H_INCLUDED
#define MERGESORT_H_INCLUDED

#include <iostream>
#include <stdlib.h>

#include "GameReview.h"
using namespace std;

class MergeSort
{
    public:
        int numComparacoes = 0;
        int numCopias = 0;

        void mergeSort(int vet[], int indiceEsq, int indiceDir);
        void mergeSort(GameReview vet[], int indiceEsq, int indiceDir);

    private:
        void Intercalacao(int vet[], int indiceEsq, int indiceMed, int indiceDir);
        void Intercalacao(GameReview vet[], int indiceEsq, int indiceMed, int indiceDir);
};

#endif // MERGESORT_H_INCLUDED
