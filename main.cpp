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
	LeituraArquivo leitura("bgg-13m-reviews.csv");

	saida.WriteLine("Cenario1");
	int* tamanhos = leitura.LerEntrada();

	cout << "vetor de inteiros de tamanho N..." << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "N = " << tamanhos[i]  << "          "<< "\t\r" << flush;
		saida.WriteLine(tamanhos[i]);
		for (int j = 1; j <= 5; j++)
		{
			int* ids = leitura.RandomReadIds(tamanhos[i]);

			QuickSort qs;
			qs.quickSort(ids, tamanhos[i]);
			saida.WriteResult(qs.numComparacoes, qs.numCopias, qs.tempoExecucao);
		}
	}
	cout << "\033[F";
	cout << "vetor de objetos de tamanho N... " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "N = " << tamanhos[i] << "          " << "\t\r" << flush;
		saida.WriteLine(tamanhos[i]);
		for (int j = 1; j <= 5; j++)
		{
			GameReview* registros = leitura.RandomRead(tamanhos[i]);

			QuickSort qs;
			qs.quickSort(registros, tamanhos[i]);
			saida.WriteResult(qs.numComparacoes, qs.numCopias, qs.tempoExecucao);
		}
	}
	cout << "                                               ";

	cout << "\033[F";
	cout << "                                               ";

	cout << "\033[F";
	saida.Close();

	cout << "\033[F";
	cout << "                                                  ";
	cout << "\033[F";
	cout << "fim Cenario 1.                                              " << "\t\r" << flush;
}

void Cenario2()
{
	cout << "Cenario 2         " << endl;

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
	Cenario1();
	Cenario2();
	//Cenario3();
	//Cenario4();
	//EstatisticasDeDesempenho();
    return 0;
}