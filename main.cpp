#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <bits/stdc++.h>
#include <chrono>
#include "InsertionSort.h"
#include "ShellSort.h"

using namespace std;
using namespace std::chrono;

/// Variaveis do quickSort.cpp que registram as estatisticas;
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

void print(int vet[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << vet[i] << " ";
    }
    cout << endl;
}

void randomVector(int vet[], int n)
{
    for(int i = 0; i < n; i++)
    {
        vet[i] = rand() % 100;
    }
}

void Menu(int vet[],int n)
{
    int option = -1;

    cout << "Escolha qual algoritmo voce quer usar: " << endl;
    cout << "[1] = Insertion Sort" << endl;
    cout << "[2] = Heap Sort" << endl;
    cout << "[3] = Merge Sort" << endl;
    cout << "-- Quick Sort --" << endl;
    cout << "[4] = Quick Sort" << endl;
    cout << "[5] = Quick Sort Mediana [5]" << endl;
    cout << "[6] = Quick Sort Inserção [10]" << endl;
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

    /*
    case 2:

    break;
    case 3:

    break;
    case 4:

    break;
    case 5:

    break;
    case 6:

    break;
    */
    case 7:
    {
        ShellSort ss;
        ss.shellSort(vet, n);
        break;
    }

    case 0:
        exit(1);
        break;
    }

}

int main()
{
    cout << "Escolha o tamanho do vetor: " << endl;
    int n = 0;
    cin >> n;
    int vet[n];
    randomVector(vet, n);
    cout << "Vetor: " << endl;
    print(vet,n);
    Menu(vet, n);
    print(vet,n);

    return 0;
}
