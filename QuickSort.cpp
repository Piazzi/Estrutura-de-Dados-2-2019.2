#include "QuickSort.h";
#include "InsertionSort.h";

/**
 * Algortimo de particionamento do m�todo de quick sort recursivo
 *
 * @param int arr[]
 * @param int inicio
 * @param int fim
 * @return int
*/
int QuickSort::particionar(int arr[], int inicio, int fim)
{
    int pivo = arr[fim];
    numCopias++;

    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++)
    {
        numComparacoes++;
        if (arr[j] <= pivo)
        {
            i++;
            swap(arr[i], arr[j]);
            numCopias+=3;
        }
    }

    swap(arr[i + 1], arr[fim]);
    numCopias+=3;

    return (i + 1);
}

int QuickSort::particionar(GameReview arr[], int inicio, int fim)
{
    int pivo = arr[fim].GetIndex();
    numCopias++;

    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++)
    {
        numComparacoes++;
        if (arr[j].GetIndex() <= pivo)
        {
            i++;
            swap(arr[i], arr[j]);
            numCopias+=3;
        }
    }

    swap(arr[i + 1], arr[fim]);
    numCopias+=3;

    return (i + 1);
}


/**
 * Utiliza o algortimo de Quick Sort recursivo para ordenar um dado array de inteiros
 *
 * @param int arr[]
 * @param int inicio
 * @param int fim
 * @return void
*/
void QuickSort::auxQuickSort(int arr[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int pi = particionar(arr, inicio, fim);

        auxQuickSort(arr, inicio, pi - 1);
        auxQuickSort(arr, pi + 1, fim);
    }
}

void QuickSort::quickSort(int arr[], int tam)
{
	auto started = chrono::high_resolution_clock::now();
	auxQuickSort(arr, 0, tam - 1);
	auto time = chrono::high_resolution_clock::now() - started;
	tempoExecucao = chrono::duration<double, std::nano>(time).count();
}

void QuickSort::quickSort(GameReview arr[], int tam)
{
	auto started = chrono::high_resolution_clock::now();
	auxQuickSort(arr, 0, tam - 1);
	auto time = chrono::high_resolution_clock::now() - started;
	tempoExecucao = chrono::duration<double, std::nano>(time).count();
}

void QuickSort::auxQuickSort(GameReview arr[], int inicio, int fim)
{
	if (inicio < fim)
	{
		int pi = particionar(arr, inicio, fim);

		auxQuickSort(arr, inicio, pi - 1);
		auxQuickSort(arr, pi + 1, fim);
	}
}


/**
 * Utiliza uma variação do algoritmo de Quick Sort que usa
 * a mediana do vetor para determinar o pivo.
 *
 * @param int arr[]
 * @param int inicio
 * @param int fim
 * @param int k
 * @return void
*/
void QuickSort::quickSortMediana(int arr[], int inicio, int fim, int k)
{
	auto started = chrono::high_resolution_clock::now();
	auxQuickSortMediana(arr, inicio, fim, k);
	auto time = chrono::high_resolution_clock::now() - started;
	tempoExecucao = chrono::duration<double, std::nano>(time).count();
}

void QuickSort::auxQuickSortMediana(int arr[], int inicio, int fim, int k)
{
	if (inicio < fim)
	{
		int q = particionarMediana(arr, inicio, fim, mediana(arr, inicio, fim, k));
		auxQuickSortMediana(arr, inicio, q - 1, k);
		auxQuickSortMediana(arr, q + 1, fim, k);
	}
}

/**
 * Utiliza uma variação do algoritmo de Quick Sort que usa
 * a mediana do vetor para determinar o pivo.
 *
 * @param GameReview arr[]
 * @param int inicio
 * @param int fim
 * @param int k
 * @return void
*/
void QuickSort::quickSortMediana(GameReview arr[], int inicio, int fim, int k)
{
	auto started = chrono::high_resolution_clock::now();
	auxQuickSortMediana(arr, inicio, fim, k);
	auto time = chrono::high_resolution_clock::now() - started;
	tempoExecucao = chrono::duration<double, std::nano>(time).count();
}

void QuickSort::auxQuickSortMediana(GameReview arr[], int inicio, int fim, int k)
{
	if (inicio < fim)
	{
		int q = particionarMediana(arr, inicio, fim, mediana(arr, inicio, fim, k));
		auxQuickSortMediana(arr, inicio, q - 1, k);
		auxQuickSortMediana(arr, q + 1, fim, k);
	}
}

/**
 * Fun��o que encontra a mediana, dado um array.
 *
 * @param Registro arr[]
 * @param int inicio
 * @param int fim
 * @param int k
 * @return int
*/
int QuickSort::mediana(int arr[], int inicio, int fim, int k)
{
    InsertionSort is = InsertionSort();
    int indiceMediana;
    int indiceRand;

    //int vetor[k];
	int* vetor = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++)
    {
        srand(i);
        indiceRand = rand() % (fim - inicio);
        vetor[i] = arr[indiceRand];
        numCopias++;
    }

    is.insertionSortHibrido(vetor, 0, k);
    indiceMediana = vetor[k == 3 ? 1 : 2];
    return indiceMediana;
}

/**
 * Fun��o que encontra a mediana, dado um array.
 *
 * @param GameReview arr[]
 * @param int inicio
 * @param int fim
 * @param int k
 * @return int
*/
int QuickSort::mediana(GameReview arr[], int inicio, int fim, int k)
{
    InsertionSort is = InsertionSort();
    int indiceMediana;
    int indiceRand;

    //int vetor[k];
	//int* vetor = (int*)malloc(k * sizeof(int));
	GameReview* vetor = new GameReview[k];
    for (int i = 0; i < k; i++)
    {
        srand(i);
        indiceRand = rand() % (fim - inicio);
        vetor[i] = arr[indiceRand];
        numCopias++;
    }

    is.insertionSortHibrido(vetor, 0, k);
    indiceMediana = vetor[k == 3 ? 1 : 2].GetIndex();
    return indiceMediana;
}

/**
 * Algoritmo de particionamento do quick sort recursivo
 * que utiliza a mediana de n�meros aleat�rios como pivo.
 *
 * @param int arr[]
 * @param int inicio
 * @param int fim
 * @param int mediana
 * @return int
*/
int QuickSort::particionarMediana(int arr[], int inicio, int fim,int mediana)
{
    int pospiv = inicio + (mediana % (fim - inicio + 1));
    int pivo = arr[pospiv]; //Pega o userID da posicao que foi pedida e coloca ela como pivo
    numCopias++;

    swap(arr[pospiv], arr[fim]);
    numCopias+=3;

    pospiv = fim;
    int i = inicio - 1;
    int j;
    for (j = inicio; j <= fim - 1; j++)
    {
        numComparacoes++;
        if (arr[j]<= pivo)
        {
            i++;
            swap(arr[i], arr[j]);
            numCopias+=3;
        }
    }
    swap(arr[i + 1], arr[fim]);
    numCopias+=3;

    return i + 1;
}

/**
 * Algoritmo de particionamento do quick sort recursivo
 * que utiliza a mediana de n�meros aleat�rios como pivo.
 *
 * @param GameReview arr[]
 * @param int inicio
 * @param int fim
 * @param int mediana
 * @return int
*/
int QuickSort::particionarMediana(GameReview arr[], int inicio, int fim,int mediana)
{
    int pospiv = inicio + (mediana % (fim - inicio + 1));
    int pivo = arr[pospiv].GetIndex(); //Pega o userID da posicao que foi pedida e coloca ela como pivo
    numCopias++;

    swap(arr[pospiv], arr[fim]);
    numCopias+=3;

    pospiv = fim;
    int i = inicio - 1;
    int j;
    for (j = inicio; j <= fim - 1; j++)
    {
        numComparacoes++;
        if (arr[j].GetIndex() <= pivo)
        {
            i++;
            swap(arr[i], arr[j]);
            numCopias+=3;
        }
    }
    swap(arr[i + 1], arr[fim]);
    numCopias+=3;

    return i + 1;
}

/**
 * Algortimo de Quick Sort Hibrido que utiliza o Insert Sort
 * para ordenar valores de pequenas parti��es.
 *
 * @param Registro arr[]
 * @param int inicio
 * @param int fim
 * @param int m
 * @return int
*/
void QuickSort::quickSortInsercao(int arr[], int inicio, int fim, int m)
{
	auto started = chrono::high_resolution_clock::now();
	auxQuickSortInsercao(arr, inicio, fim, m);
	auto time = chrono::high_resolution_clock::now() - started;
	tempoExecucao = chrono::duration<double, std::nano>(time).count();
}

void QuickSort::auxQuickSortInsercao(int arr[], int inicio, int fim, int m)
{
	InsertionSort is = InsertionSort();
	if (inicio < fim)
	{
		if (m = 10)
		{
			if (fim - inicio <= 10)
			{
				is.insertionSortHibrido(arr, inicio, fim + 1);
			}
			else
			{
				int part = particionar(arr, inicio, fim);
				auxQuickSortInsercao(arr, inicio, part - 1, 10);
				auxQuickSortInsercao(arr, part + 1, fim, 10);
			}
		}
		else
		{
			if (fim - inicio <= 100)
			{
				is.insertionSortHibrido(arr, inicio, fim + 1);
			}
			else
			{
				int part = particionar(arr, inicio, fim);
				auxQuickSortInsercao(arr, inicio, part - 1, 100);
				auxQuickSortInsercao(arr, part + 1, fim, 100);
			}
		}
	}
}

/**
 * Algortimo de Quick Sort Hibrido que utiliza o Insert Sort
 * para ordenar valores de pequenas parti��es.
 *
 * @param GameReview arr[]
 * @param int inicio
 * @param int fim
 * @param int m
 * @return int
*/
void QuickSort::quickSortInsercao(GameReview arr[], int inicio, int fim, int m)
{
	auto started = chrono::high_resolution_clock::now();
	auxQuickSortInsercao(arr, inicio, fim, m);
	auto time = chrono::high_resolution_clock::now() - started;
	tempoExecucao = chrono::duration<double, std::nano>(time).count();
}

void QuickSort::auxQuickSortInsercao(GameReview arr[], int inicio, int fim, int m)
{
	InsertionSort is = InsertionSort();
	if (inicio < fim)
	{
		if (m == 10)
		{
			if (fim - inicio <= 10)
			{
				is.insertionSortHibrido(arr, inicio, fim + 1);
			}
			else
			{
				int part = particionar(arr, inicio, fim);
				auxQuickSortInsercao(arr, inicio, part - 1, 10);
				auxQuickSortInsercao(arr, part + 1, fim, 10);
			}
		}
		else
		{
			if (fim - inicio <= 100)
			{
				is.insertionSortHibrido(arr, inicio, fim + 1);
			}
			else
			{
				int part = particionar(arr, inicio, fim);
				auxQuickSortInsercao(arr, inicio, part - 1, 100);
				auxQuickSortInsercao(arr, part + 1, fim, 100);
			}
		}
	}
}
