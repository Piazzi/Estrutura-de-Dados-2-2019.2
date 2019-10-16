#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <chrono>

#include "InsertionSort.h"
#include "ShellSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "LeituraArquivo.h"
#include "GameReview.h"
#include "SaidaArquivo.h"

using namespace std;
using namespace std::chrono;

/// Variaveis que registram as estatisticas;
extern int numComparacoes;
extern int numCopias;

/**
 * Fun��o que troca o valor de duas vari�veis usando uma
 * vari�vel auxiliar
 *
 * @param int *x
 * @param int *y
 * @return void
*/
void swap(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

/**
 * Fun��o que troca o valor de dois objetos usando uma
 * vari�vel auxiliar
 *
 * @param GameReview *x
 * @param GameReview *y
 * @return void
*/
void swap(GameReview* x, GameReview* y)
{
	GameReview aux = *x;
	*x = *y;
	*y = aux;
}

/**
 * Imprime na tela um array
 * @return void
*/
void print(int vet[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << vet[i] << " ";
    }
    cout << endl;
}

/**
 * Gera um vetor aleatório de tamanho n
 * @return void
*/
void randomVector(int vet[], int n)
{
    for(int i = 0; i < n; i++)
    {
        vet[i] = rand() % 100;
    }
}

void Cenario1() 
{
	cout << "Cenario 1: Impacto de diferentes estruturas de dados." << endl;
	SaidaArquivo saida("saida.txt");
	LeituraArquivo entrada("bgg-13m-reviews.csv");

	saida.WriteLine("Cenario1");
	int* entradas = entrada.LerEntrada();
	for (int i = 0; i < 5; i++)
	{
		saida.WriteLine(entradas[i]);
		for (int j = 1; j <= 5; j++)
		{
			int* ids = entrada.RandomReadIds(entradas[i]);
			QuickSort qs;
			qs.quickSort(ids, entradas[i]);
			saida.WriteResult(qs.numComparacoes, qs.numCopias, qs.tempoExecucao);
		}
	}
	for (int i = 0; i < 5; i++)
	{
		saida.WriteLine(entradas[i]);
		for (int j = 1; j <= 5; j++)
		{
			GameReview* registros = entrada.RandomRead(entradas[i]);
			QuickSort qs;
			qs.quickSort(registros, entradas[i]);
			saida.WriteResult(qs.numComparacoes, qs.numCopias, qs.tempoExecucao);
		}
	}
}

void Cenario2()
{
	
}



void Menu(GameReview vet[], int n)
{
    int option = -1;

    cout << "Escolha qual algoritmo voce quer usar: " << endl;
    cout << "[1] = Insertion Sort" << endl;
    cout << "[2] = Heap Sort" << endl;
    cout << "[3] = Merge Sort" << endl;
    cout << "-- Quick Sort --" << endl;
    cout << "[4] = Quick Sort" << endl;
    cout << "[5] = Quick Sort Mediana [5]" << endl;
    cout << "[6] = Quick Sort Insercao [10]" << endl;
    cout << "-- Meu Sort --" << endl;
    cout << "[7] = ShellSort" << endl;
    cout << "-- Sair --" << endl;
    cout << "[0] = Sair" << endl;

    cin >> option;

    switch (option)
    {
    case 1:
        {
            InsertionSort is;
            is.insertionSort(vet, n);
            break;
        }
    case 2:
        {
            HeapSort hs;
            hs.heapSort(vet,n);
            break;
        }
    case 3:
        {
            MergeSort ms;
            ms.mergeSort(vet, 0, n-1);
            break;

        }

    case 4:
        {
            QuickSort qs;
            qs.quickSort(vet, n);
            break;
        }
    case 5:
        {
            QuickSort qs;
            qs.quickSortMediana(vet, 0, n -1, 5);
            break;
        }

    case 6:
        {
            QuickSort qs;
            qs.quickSortInsercao(vet, 0, n -1, 10);
            break;
        }
    case 7:
        {
            ShellSort ss;
            ss.shellSort(vet, n);
            break;
        }

    default:
        exit(1);
        break;
    }

}

int main()
{
 //   cout << "Escolha o tamanho do vetor: " << endl;
 //   int n = 0;
	//cin >> n;

	//LeituraArquivo arquivo("bgg-13m-reviews.csv");
	//int* valores = arquivo.LerEntrada();
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << valores[i] << endl;
	//}
	//GameReview* Reviews = arquivo.RandomRead(n);
	////GameReview* Reviews2 = arquivo.RandomRead(n);
	//for (int i = 0; i < n; i++)
	//{
	//	Reviews[i].PrintMainInfo();
	//}

 //   Menu(Reviews, n);

	//for (int i = 0; i < n; i++)
	//{
	//	Reviews[i].PrintMainInfo();
	//}
	Cenario1();
    return 0;
}