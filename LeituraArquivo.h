#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <random>

#include "GameReview.h"

using namespace std;

class LeituraArquivo 
{
public:
	LeituraArquivo();
	LeituraArquivo(string nomeArquivo);
	~LeituraArquivo();

	GameReview* RandomRead(int qntdeLinhas);
	int* RandomReadIds(int qntdeLinhas);
	int* LerEntrada();

	void SetNomeArquivo(string nomeArquivo);

	void SaidaCenario1();

private:
	GameReview ParseLine(string registro);
	const string DIRETORIO = "arquivos/";
	string nomeArquivo;
	ifstream arquivo;

};