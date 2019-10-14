#include <iostream>
#include "Sondagem_Linear.h"
#include <windows.h>
#include <psapi.h>

using namespace std;

Sondagem_Linear::Sondagem_Linear(int tam)
{
    tamanho = tam;
    tabela = new GameReview[tamanho];
}

Sondagem_Linear::~Sondagem_Linear()
{
    delete tabela;
}

int Sondagem_Linear::func_sond_linear(int valor)
{
    return valor%tamanho;
}

void Sondagem_Linear::insere_sond_linear(GameReview vetor[])
{
    for(int i=0;i<tamanho;i++){
        int f = func_sond_linear(vetor[i].GetIndex());
        numcomparacoes++;
        if(tabela[f].GetIndex()==-1)
        {
            tabela[f] = vetor[i];
        }
        else
        {
            while(tabela[f].GetIndex()!=-1)
            {
                numcomparacoes++;
                if(f<tamanho-1)
                {
                    f++;
                }
                else
                {
                    f=0;
                }
            }
            numcomparacoes++;
            tabela[f]=vetor[i];
        }
    }
    ///calcular memoria gasta
    PROCESS_MEMORY_COUNTERS_EX pmc;
    //GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc , sizeof(pmc));
    SIZE_T memoria = pmc.PrivateUsage;
    memoriagasta=(memoria/(float)1024);
}

void Sondagem_Linear::imprimir()
{
    for(int i=0;i<tamanho;i++)
    {
        cout << "Posicao " << i << ": "<< tabela[i].GetIndex() << endl;
    }
    cout<<"Comparacoes: "<<numcomparacoes<<endl;
    cout<<"Memoria Gasta: "<<memoriagasta<<" KB"<<endl;
}
