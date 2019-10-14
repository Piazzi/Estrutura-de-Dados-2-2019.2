#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <chrono>
#include <fstream>

#include "InsertionSort.h"
#include "ShellSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "LeituraArquivo.h"
#include "GameReview.h"

using namespace std;
using namespace std::chrono;

/// Variaveis que registram as estatisticas;
extern int numComparacoes = 0;
extern int numCopias = 0;

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


/**
 * Execução do primeiro cenário proposto.
 *
*/
void Cenario1()
{
    QuickSort qs;
    ofstream saida ("saida.txt");
    saida << "Resultado: ";
    cout << endl << "Cenario 1: Impacto de diferentes estruturas de dados." << endl;
	cout << "Avaliando o desempenho do metodo de ordenacao QuickSort para inteiros armazenados em vetores de tamanho N = 1000, 5000, 10000, 50000,100000" << endl << endl;
	LeituraArquivo entrada("bgg-13m-reviews.csv");

    int* vetor = entrada.LerEntrada(1000);
	cout << "PARA N = 1000" << endl;
	for(int i = 0; i < 5; i++)
    {
        cout << "Iteracao de numero: " << i+1 << endl;
        qs.quickSort(vetor, 1000);
        vetor = entrada.LerEntrada(1000);
    }

    cout << "------------------------------------------------------" << endl;
    cout << "PARA N = 5000" << endl;
    for(int i = 0; i < 5; i++)
    {
        vetor = entrada.LerEntrada(5000);
        cout << "Iteracao de numero: " << i+1 << endl;
        qs.quickSort(vetor, 5000);
    }

    cout << "------------------------------------------------------" << endl;
    cout << "PARA N = 10000" << endl;
    for(int i = 0; i < 5; i++)
    {
        vetor = entrada.LerEntrada(10000);
        cout << "Iteracao de numero: " << i+1 << endl;
        qs.quickSort(vetor, 10000);
    }
    /*
    cout << "------------------------------------------------------" << endl;
    cout << "PARA N = 50000" << endl;
    for(int i = 0; i < 5; i++)
    {
        vetor = entrada.LerEntrada(50000);
        cout << "Iteracao de numero: " << i+1 << endl;
        qs.quickSort(vetor, 50000);
    }

    cout << "------------------------------------------------------" << endl;
    cout << "PARA N = 100000" << endl;
    for(int i = 0; i < 5; i++)
    {
        vetor = entrada.LerEntrada(100000);
        cout << "Iteracao de numero: " << i+1 << endl;
        qs.quickSort(vetor, 100000);
    }
    */
    cout << "------------------------------------------------------" << endl;

    cout << "Avaliando agora os resultados usando um vetor de Objetos" << endl << endl;
    GameReview *registros;

    cout << "PARA N = 1000" << endl;

	for(int i = 0; i < 5; i++)
    {
        registros = entrada.RandomRead(1000);
        cout << "Iteracao de numero: " << i+1 << endl;
        qs.quickSort(registros, 1000);
    }
    cout << "------------------------------------------------------" << endl;

    cout << "PARA N = 5000" << endl;
	for(int i = 0; i < 5; i++)
    {
        registros = entrada.RandomRead(5000);
        cout << "Iteracao de numero: " << i+1 << endl;
        qs.quickSort(registros, 5000);
    }
    cout << "------------------------------------------------------" << endl;

    cout << "PARA N = 10000" << endl;
	for(int i = 0; i < 5; i++)
    {
        registros = entrada.RandomRead(10000);
        cout << "Iteracao de numero: " << i+1 << endl;
        qs.quickSort(registros, 10000);
    }
    cout << "------------------------------------------------------" << endl;

     cout << "PARA N = 50000" << endl;
	for(int i = 0; i < 5; i++)
    {
        registros = entrada.RandomRead(50000);
        cout << "Iteracao de numero: " << i+1 << endl;
        qs.quickSort(registros, 50000);
    }
    cout << "------------------------------------------------------" << endl;

     cout << "PARA N = 100000" << endl;
	for(int i = 0; i < 5; i++)
    {
        registros = entrada.RandomRead(100000);
        cout << "Iteracao de numero: " << i+1 << endl;
        qs.quickSort(registros, 100000);
    }
    cout << "------------------------------------------------------" << endl;

}

void Menu(int vet[], int n)
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
	cout << "Escolha o cenário que deseja executar: " << endl;
	cout << "[1] = Cenario 1" << endl;
    cout << "[2] = Cenario 2" << endl;
    cout << "[3] = Cenario 3" << endl;
    cout << "[4] = Cenario 4" << endl;
    cout << "[5] = Menu de Testes" << endl;
	int op = 0;
	cin >> op;
    switch (op)
    {
    case 1:
        {
            Cenario1();
            break;
        }
    case 2:
        {

        }
    case 3:
        {

        }
    case 4:
        {

        }
    case 5:
        {
            cout << "Seu vetor antes de ordenar: " << endl;
            int vet[50];
            randomVector(vet, 50);
            print(vet, 50);
            Menu(vet ,50);
            cout << "Seu vetor depois de ordenar: " << endl;
            print(vet,50);

        }
    default:
        exit(1);
        break;
    }
    return 0;
}
