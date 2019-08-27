#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

#include <iostream>
#include <stdlib.h>

using namespace std;

class QuickSort
{
    public:
        int numComparacoes = 0;
        int numCopias = 0;

        void inicializa();
        void quickSort(int arr[], int inicio, int fim);
        void quickSortMediana(int arr[], int inicio, int fim, int k);
        int mediana(int arr[], int inicio, int fim, int k);
        void quickSortInsercao(int arr[], int inicio, int fim, int m);


    private:
        int particionar(int arr[], int inicio, int fim);
        int particionarMediana(int arr[], int inicio, int fim, int mediana);
        int particionarInsercao(int arr[], int inicio, int fim);
};

#endif