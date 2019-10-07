#include <iostream>
#include "Hash_coalesc.h"
#include <windows.h>
#include <psapi.h>

using namespace std;

Hash_coalesc::Hash_coalesc(int tam)
{
    tamanho = tam;
    tabela = new ponteiro*[tam];
    for(int i=0; i<tam; i++)
    {
        tabela[i] = new ponteiro();
        tabela[i]->setEnde(-2); /// Define a chave de todos os elementos do vetor como -2(Ou seja, vazias)
    }
}

Hash_coalesc::~Hash_coalesc()
{
    for(int i=0; i<tamanho; ++i)
    {
        delete tabela[i];
    }
    delete tabela;
}

void Hash_coalesc::imprimir()
{
    for(int i=0; i<tamanho; i++)
    {
        GameReview gr= tabela[i]->getGameReview();
        cout << "Posicao " << i << " ["  << gr.GetIndex() << "] " << "[" << tabela[i]->getEnde() << "]" << endl;
    }
    cout<<"Comparacoes: "<<numcomparacoes<<endl;
    cout<<"Memoria Gasta: "<<memoriagasta<<" KB"<<endl;
}

int Hash_coalesc::func_hashCoalescido(int valor)
{
    return valor%tamanho;
}

void Hash_coalesc::insere_hashCoalescido(GameReview vetor[])
{
    for(int i=0; i<tamanho; i++)
    {
        int f = func_hashCoalescido(vetor[i].GetIndex());
        numcomparacoes++;
        if(tabela[f]->getEnde()==-2)
        {
            tabela[f]->setChave(vetor[i]);
            tabela[f]->setEnde(-1);
        }
        else
        {
            for(int j=tamanho-1; j>=0; --j) //j é o indice da tabela percorrida de tras pra frente
            {
                numcomparacoes++;
                if(tabela[j]->getEnde()==-2)
                {
                    tabela[j]->setChave(vetor[i]);
                    tabela[f]->setProx(tabela[j]);
                    tabela[f]->setEnde(j);
                    tabela[j]->setEnde(-1);
                    break;
                }
            }
        }
    }
    ///calcular memoria gasta
    PROCESS_MEMORY_COUNTERS_EX pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
    SIZE_T memoria = pmc.PrivateUsage;
    memoriagasta=(memoria/(float)1024);
}
