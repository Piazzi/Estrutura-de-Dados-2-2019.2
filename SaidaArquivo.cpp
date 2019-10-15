#include "SaidaArquivo.h"

SaidaArquivo::SaidaArquivo()
{ }

SaidaArquivo::SaidaArquivo(string nomeArquivo)
{
	this->nomeArquivo = nomeArquivo;
	Open();
}

SaidaArquivo::~SaidaArquivo()
{ 
	Close();
}

void SaidaArquivo::SetNomeArquivo(string nomeArquivo)
{
	this->nomeArquivo = nomeArquivo;
}

void SaidaArquivo::WriteResult(int numComparacoes, int numCopias, volatile long long tempoExecucao)
{
	arquivo << numComparacoes << "," << numCopias << "," << tempoExecucao << endl;
}

void SaidaArquivo::Open()
{
	arquivo.open(nomeArquivo);
	if (arquivo.is_open())
	{
		cout << "stream for " << nomeArquivo << " is open" << endl;
	}
	else
	{
		cerr << "Could not open file " << nomeArquivo << endl;
	}
}

void SaidaArquivo::Close()
{
	arquivo.close();
	cout << "stream for " << nomeArquivo << " closed" << endl;
}
