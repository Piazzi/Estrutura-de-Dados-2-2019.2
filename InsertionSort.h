#include <iostream>
#include <stdlib.h>

#include "GameReview.h"

using namespace std;

class InsertionSort
{
    public:
        int numComparacoes = 0;
        int numCopias = 0;
        void insertionSortHibrido(int vet[], int inicio, int fim);
        void insertionSort(int vet[], int TAM);

        void insertionSortHibrido(GameReview vet[], int inicio, int fim);
        void insertionSort(GameReview vet[], int TAM);
	//TODO: funcao parece não estar funcionando
};
