#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

#include <iostream>
#include <stdlib.h>

#include "GameReview.h"

using namespace std;

class QuickSort
{
    public:
        int numComparacoes = 0;
        int numCopias = 0;

        void inicializa();
        void quickSort(int arr[], int inicio, int fim);
        void quickSort(GameReview arr[], int inicio, int fim);
        void quickSortMediana(int arr[], int inicio, int fim, int k);
        void quickSortMediana(GameReview arr[], int inicio, int fim, int k);
        int mediana(int arr[], int inicio, int fim, int k);
        int mediana(GameReview arr[], int inicio, int fim, int k);
        void quickSortInsercao(int arr[], int inicio, int fim, int m);
        void quickSortInsercao(GameReview arr[], int inicio, int fim, int m);


    private:
        int particionar(int arr[], int inicio, int fim);
        int particionar(GameReview arr[], int inicio, int fim);
        int particionarMediana(int arr[], int inicio, int fim, int mediana);
        int particionarMediana(GameReview arr[], int inicio, int fim, int mediana);
        int particionarInsercao(int arr[], int inicio, int fim);
        int particionarInsercao(GameReview arr[], int inicio, int fim);
};

#endif
