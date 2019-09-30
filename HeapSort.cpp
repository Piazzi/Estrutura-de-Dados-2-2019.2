#include "HeapSort.h";

/**
 * Função de heapsort que ordena um dado array
 *
 * @param int arr[]
 * @param int n
 * @return void
*/
void HeapSort::heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        numCopias+=3;

        heapify(arr, i, 0);
    }
}

/**
 * Função de heapsort que ordena um dado array
 *
 * @param GameReview arr[]
 * @param int n
 * @return void
*/
void HeapSort::heapSort(GameReview arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        numCopias+=3;

        heapify(arr, i, 0);
    }
}

/**
 * Função heapify que transforma um array em uma heap
 *
 * @param int arr[]
 * @param int n
 * @param int i
 * @return void
*/
void HeapSort::heapify(int arr[], int n, int i)
{
    int maior = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    numComparacoes++;
    if (l < n && arr[l] > arr[maior])
        maior = l;

    numComparacoes++;
    if (r < n && arr[r] > arr[maior])
        maior = r;

    if (maior != i)
    {
        swap(arr[i], arr[maior]);
        numCopias+=3;

        heapify(arr, n, maior);
    }
}

/**
 * Função heapify que transforma um array em uma heap
 *
 * @param GameReview arr[]
 * @param int n
 * @param int i
 * @return void
*/
void HeapSort::heapify(GameReview arr[], int n, int i)
{
    int maior = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    numComparacoes++;
    if (l < n && arr[l].GetInternalId() > arr[maior].GetInternalId())
        maior = l;

    numComparacoes++;
    if (r < n && arr[r].GetInternalId() > arr[maior].GetInternalId())
        maior = r;

    if (maior != i)
    {
        swap(arr[i], arr[maior]);
        numCopias+=3;

        heapify(arr, n, maior);
    }
}

