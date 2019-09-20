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

void InsertionSort::insertionSort(GameReview vet[], int TAM)
{
	for (int i = 0; i < TAM; i++)
	{
		int valorAtual = vet[i].GetInternalId();

		for (int j = i; j != 0 && vet[j + 1].GetInternalId() > vet[j].GetInternalId(); j--)
		{
			swap(vet[j], vet[j + 1]);
			numCopias += 3;
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

void InsertionSort::insertionSortHibrido(GameReview vet[], int inicio, int fim)
{
	int i, j;
	GameReview chave;

	for (i = inicio + 1; i < fim; i++)
	{
		chave = vet[i];
		numCopias++;

		j = i - 1;

		while (j >= 0 && (vet[j].GetInternalId() > chave.GetInternalId()))
		{
			vet[j + 1] = vet[j];
			numCopias++;
			j--;
		}
		vet[j + 1] = chave;
		numCopias++;
	}
}