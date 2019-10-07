#include <iostream>
#include "Hash_separa.h"
#include <windows.h>
#include <psapi.h>

using namespace std;

Hash_separa::Hash_separa(int tamanho)
{
    tam = tamanho;
    tabela = new ListaEncadeada*[tam];
    for(int i=0;i<tam;++i)
    {
        tabela[i] = new ListaEncadeada;
    }
}

Hash_separa::~Hash_separa()
{
    for(int i=0;i<tam;++i)
    {
        delete tabela[i];
    }
    delete tabela;
}

int Hash_separa::func_hash_separado(int valor)
{
    return valor%tam;
}

void Hash_separa::insere_hash_separado(GameReview vetor[])
{

    for(int i=0;i<tam;i++){
        int f = func_hash_separado(vetor[i].GetIndex());
        tabela[f]->insere(vetor[i]);
        numcomparacoes+=tabela[f]->numcomparacoes;
    }
    ///calcular memoria gasta
    PROCESS_MEMORY_COUNTERS_EX pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc , sizeof(pmc));
    SIZE_T memoria = pmc.PrivateUsage;
    memoriagasta=(memoria/(float)1024);
}

void Hash_separa::imprimir()
{
    for(int i=0;i<tam;i++)
    {
       cout << "Posicao " << i << ": ";
       tabela[i]->imprimir();
       cout << endl;
    }
    cout<<"Comparacoes: "<<numcomparacoes<<endl;
    cout<<"Memoria Gasta: "<<memoriagasta<<" KB"<<endl;
}
