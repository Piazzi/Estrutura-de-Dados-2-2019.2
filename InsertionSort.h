#include <iostream>
#include <stdlib.h>

using namespace std;

class InsertionSort
{
    public:
        int numComparacoes = 0;
        int numCopias = 0;
        void insertionSortHibrido(int vet[], int inicio, int fim);
        void insertionSort(int vet[], int TAM);
};
