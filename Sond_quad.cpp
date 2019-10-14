#include <iostream>
#include <math.h>
#include "Sond_quad.h"
#include <windows.h>
#include <psapi.h>

using namespace std;

Sond_quad::Sond_quad(int tam)
{
    tamanho = tam;
    tabela = new GameReview[tamanho];
}

Sond_quad::~Sond_quad()
{
    delete tabela;
}

int Sond_quad::func_calc_hashing(int valor)
{
    return valor%tamanho;
}

void Sond_quad::inserir_func_quadratica(GameReview vetor[])
{
    for(int i=0;i<tamanho;i++){
        int f = func_calc_hashing(vetor[i].GetIndex());
        numcomparacoes++;
        if (tabela[f].GetIndex()==-1)
        {
            tabela[f] = vetor[i];
        }
        else
        {
            int cont=1;
            while(tabela[f].GetIndex()!=-1)
            {
                f=f+cont*cont;
                f=f%tamanho;
                numcomparacoes++;
            }
            numcomparacoes++;
            tabela[f] = vetor[i];
        }
    }
    ///calcular memoria gasta
    PROCESS_MEMORY_COUNTERS_EX pmc;
    //GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc , sizeof(pmc));
    SIZE_T memoria = pmc.PrivateUsage;
    memoriagasta=(memoria/(float)1024);
}

void Sond_quad::imprimir()
{
    for(int i=0;i<tamanho;++i)
    {
        cout << "Posicao " << i << ": "<< tabela[i].GetIndex() << endl;
    }
    cout<<"Comparacoes: "<<numcomparacoes<<endl;
    cout<<"Memoria Gasta: "<<memoriagasta<<" KB"<<endl;
}
