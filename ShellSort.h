#ifndef SHELLSORT_H_INCLUDED
#define SHELLSORT_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <chrono>

#include "GameReview.h"

using namespace std;

class ShellSort
{
    public:
        int numComparacoes = 0;
        int numCopias = 0;
        void shellSort(int vet[], int tam);
        void shellSort(GameReview vet[], int tam);
};


#endif // SHELLSORT_H_INCLUDED
