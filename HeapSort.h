#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED

#include <iostream>
#include <stdlib.h>

using namespace std;

class HeapSort
{
    public:
        int numComparacoes = 0;
        int numCopias = 0;
        void heapSort(int arr[], int n);

    private:
        void heapify(int arr[], int n, int i);
};

#endif // HEAPSORT_H_INCLUDED
