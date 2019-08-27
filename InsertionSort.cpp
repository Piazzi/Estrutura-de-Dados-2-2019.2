#include "InsertionSort.h";

void InsertionSort::insertionSort(int vet[], int TAM)
{
    for (int i = 1; i <= TAM; i++)
    {
        int valorAtual = vet[i];

        for (int j = i - 1; j != 0 && vet[j - 1] > vet[j]; j--)
        {
            swap(vet[j], vet[j - 1]);
            numCopias+=3;
        }
        numComparacoes++;
    }
}

void InsertionSort::insertionSortHibrido(int arr[], int inicio, int fim)
{
    int i, j;
	int chave;

	for (i = inicio + 1; i < fim; i++)
	{
		chave = arr[i];
        numCopias++;

		j = i - 1;

		while (j >= 0 && (arr[j] > chave))
		{
			arr[j + 1] = arr[j];
            numCopias++;
			j--;
		}
		arr[j + 1] = chave;
        numCopias++;
	}
}
