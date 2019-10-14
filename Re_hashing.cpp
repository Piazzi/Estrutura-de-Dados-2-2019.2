#include <iostream>
#include "Re_hashing.h"
#include <windows.h>
#include <psapi.h>

using namespace std;

Re_hashing::Re_hashing(int tam)
{
    tamanho = tam;
    tamanho2=calculaProxPrimo(tamanho);
    tabela = new GameReview[tamanho2];
}

Re_hashing::~Re_hashing()
{
    delete tabela;
}

int Re_hashing::calculaProxPrimo(int n){
    int primo=n;
    int i;
    while(true){
       for(i=2;i<(primo/2);i++) {
            if(primo%i==0){
                primo++;
                break;
            }
       }
       if (i>=(primo/2))
            break;
    }
    return primo;
}

int Re_hashing::func_calc_hashing(int valor)
{
    return valor%tamanho;
}

int Re_hashing::func2_calc_hashing(int valor,int cont)
{
    return (cont*7)%tamanho2;
}

void Re_hashing::inserir_rehashing(GameReview vetor[])
{
    for(int i=0; i<tamanho; i++) {
        int f=func_calc_hashing(vetor[i].GetIndex());
        numcomparacoes++;
        if(tabela[f].GetIndex() == -1){
            tabela[f]=vetor[i];
        }
        else{
            int cont=1;
            while(tabela[f].GetIndex()!=-1){
                f=(((func_calc_hashing(vetor[i].GetIndex()))+func2_calc_hashing(vetor[i].GetIndex(),cont)));
                f=f%tamanho;
                cont++;
                numcomparacoes++;
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

void Re_hashing::imprimir()
{
    for(int i=0; i<tamanho; i++)
    {
        cout << "Posicao " << i << ": "<< tabela[i].GetIndex() << endl;
    }
    cout<<"Comparacoes: "<<numcomparacoes<<endl;
    cout<<"Memoria Gasta: "<<memoriagasta<<" KB"<<endl;
}
