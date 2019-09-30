#include "MergeSort.h";

/**
 * Utiliza o algortimo de Merge Sort para ordenar um vetor de inteiros
 *
 * @param int vet[]
 * @param int indiceEsq
 * @param int indiceDir
 * @return void
*/
void MergeSort::mergeSort(int vet[], int indiceEsq, int indiceDir)
{
    if (indiceEsq < indiceDir)
    {
        int indiceMed = indiceEsq+(indiceDir-indiceEsq)/2;

        mergeSort(vet, indiceEsq, indiceMed);
        mergeSort(vet, indiceMed+1, indiceDir);

        Intercalacao(vet, indiceEsq, indiceMed, indiceDir);
    }
}

/**
 * Utiliza o algortimo de Merge Sort para ordenar um vetor de inteiros
 *
 * @param GameReview vet[]
 * @param int indiceEsq
 * @param int indiceDir
 * @return void
*/
void MergeSort::mergeSort(GameReview vet[], int indiceEsq, int indiceDir)
{
    if (indiceEsq < indiceDir)
    {
        int indiceMed = indiceEsq+(indiceDir-indiceEsq)/2;

        mergeSort(vet, indiceEsq, indiceMed);
        mergeSort(vet, indiceMed+1, indiceDir);

        Intercalacao(vet, indiceEsq, indiceMed, indiceDir);
    }
}

/**
 * Algortimo de intercala��o para o Merge Sort
 *
 * @param int vet[]
 * @param int indiceEsq
 * @param int indiceMed
 * @param int indiceDir
 * @return void
*/
void MergeSort::Intercalacao(int vet[], int indiceEsq, int indiceMed, int indiceDir)
{
    int i, j, k;
    int tam1 = indiceMed - indiceEsq + 1;
    int tam2 =  indiceDir - indiceMed;

    //int vetEsq[tam1], vetDir[tam2];
	int *vetEsq, *vetDir;
	vetEsq = (int*)malloc(tam1 * sizeof(int));
	vetDir = (int*)malloc(tam2 * sizeof(int));

    for (i = 0; i < tam1; i++)
        vetEsq[i] = vet[indiceEsq + i];
    for (j = 0; j < tam2; j++)
        vetDir[j] = vet[indiceMed + 1+ j];

    i = 0;
    j = 0;
    k = indiceEsq;
    while (i < tam1 && j < tam2)
    {
        numComparacoes++;
        if (vetEsq[i] <= vetDir[j])
        {
            vet[k] = vetEsq[i];
            numCopias++;

            i++;
        }
        else
        {
            vet[k] = vetDir[j];
            numCopias++;

            j++;
        }
        k++;
    }

    while (i < tam1)
    {
        vet[k] = vetEsq[i];
        numCopias++;

        i++;
        k++;
    }

    while (j < tam2)
    {
        vet[k] = vetDir[j];
        numCopias++;

        j++;
        k++;
    }
}

/**
 * Algortimo de intercala��o para o Merge Sort
 *
 * @param GameReview vet[]
 * @param int indiceEsq
 * @param int indiceMed
 * @param int indiceDir
 * @return void
*/
void MergeSort::Intercalacao(GameReview vet[], int indiceEsq, int indiceMed, int indiceDir)
{
    int i, j, k;
    int tam1 = indiceMed - indiceEsq + 1;
    int tam2 =  indiceDir - indiceMed;

    //int vetEsq[tam1], vetDir[tam2];
	GameReview *vetEsq, *vetDir;
	vetEsq = new GameReview[tam1];
	vetDir = new GameReview[tam2];
	//vetEsq = (GameReview*)malloc(tam1 * sizeof(GameReview));
	//vetDir = (GameReview*)malloc(tam2 * sizeof(GameReview));
    for (i = 0; i < tam1; i++)
        vetEsq[i] = vet[indiceEsq + i];
    for (j = 0; j < tam2; j++)
        vetDir[j] = vet[indiceMed + 1+ j];

    i = 0;
    j = 0;
    k = indiceEsq;
    while (i < tam1 && j < tam2)
    {
        numComparacoes++;
        if (vetEsq[i].GetInternalId() <= vetDir[j].GetInternalId())
        {
            vet[k] = vetEsq[i];
            numCopias++;

            i++;
        }
        else
        {
            vet[k] = vetDir[j];
            numCopias++;

            j++;
        }
        k++;
    }

    while (i < tam1)
    {
        vet[k] = vetEsq[i];
        numCopias++;

        i++;
        k++;
    }

    while (j < tam2)
    {
        vet[k] = vetDir[j];
        numCopias++;

        j++;
        k++;
    }
}


