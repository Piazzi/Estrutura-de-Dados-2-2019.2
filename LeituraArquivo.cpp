#include "LeituraArquivo.h"

LeituraArquivo::LeituraArquivo()
{
	srand(time(NULL));
}

LeituraArquivo::LeituraArquivo(string nomeArquivo) : LeituraArquivo()
{
	this->nomeArquivo = nomeArquivo;
}

LeituraArquivo::~LeituraArquivo()
{ }

void LeituraArquivo::SetNomeArquivo(string nomeArquivo)
{
	this->nomeArquivo = nomeArquivo;
}

int* LeituraArquivo::LerEntrada()
{
	arquivo.open("entrada.txt");
	int* entradas = new int[5];

	if (arquivo.is_open())
	{
		arquivo.seekg(0, ios::beg);
		int i = 0;
		while (!arquivo.eof() || i < 5)
		{
			string aux;
			getline(arquivo, aux, '\n');
			entradas[i] = stoi(aux);
			i++;
		}
	}
	else
	{
		cerr << "Erro: Nao conseguiu abrir o arquivo entrada.txt" << endl;
	}
	arquivo.close();
	return entradas;
}

GameReview* LeituraArquivo::RandomRead(int qntdeLinhas)
{
	GameReview* registros = new GameReview[qntdeLinhas];
	if (nomeArquivo.empty())
		cerr << "Erro: O nome do arquivo não foi especificado." << endl;
	else
		arquivo.open(nomeArquivo); 		// Abre o arquivo de acordo com o nome do diretório e do arquivo

	if (arquivo.is_open())
	{
		arquivo.seekg(0, ios::end); // move o ponteiro para o final da stream do arquivo
		int tamanhoArquivo = arquivo.tellg(); // tamanho do arquivo

		for (int i = 0; i < qntdeLinhas; i++)
		{
			// obtem um valor aleatorio entre 1 e o tamanho do arquivo
			mt19937 mt(rand());
			uniform_int_distribution<int> linear_i(0, tamanhoArquivo);
			int aleatorio = linear_i(mt);

			//int aleatorio = rand() % tamanhoArquivo;
			// vai para uma posição aleatória do arquivo e ajusta para  começo da próxima linha
			arquivo.seekg(aleatorio, ios::beg);
			string strAux;
			getline(arquivo, strAux, '\n');
			if (arquivo.eof())
				continue;

			// Armazena o conteudo da linha na variável registro
			string registro;
			getline(arquivo, registro);
			registros[i] = ParseLine(registro); // Transforma a linha csv em um objeto do tipo GameReview
		}
	}
	else
	{
		cerr << "Erro: Nao conseguiu abrir o arquivo" << endl;
	}
	arquivo.close();
	return registros;
}

int* LeituraArquivo::RandomReadIds(int qntdeLinhas)
{
	int* ids = new int[qntdeLinhas];
	if (nomeArquivo.empty())
		cerr << "Erro: O nome do arquivo não foi especificado." << endl;
	else
		arquivo.open(nomeArquivo); 		// Abre o arquivo de acordo com o nome do diretório e do arquivo

	if (arquivo.is_open())
	{
		arquivo.seekg(0, ios::end); // move o ponteiro para o final da stream do arquivo
		int tamanhoArquivo = arquivo.tellg(); // tamanho do arquivo

		for (int i = 0; i < qntdeLinhas; i++)
		{
			// obtem um valor aleatorio entre 1 e o tamanho do arquivo
			mt19937 mt(rand());
			uniform_int_distribution<int> linear_i(0, tamanhoArquivo);
			int aleatorio = linear_i(mt);

			//int aleatorio = rand() % tamanhoArquivo;
			// vai para uma posição aleatória do arquivo e ajusta para  começo da próxima linha
			arquivo.seekg(aleatorio, ios::beg);
			string strAux;
			getline(arquivo, strAux, '\n');
			if (arquivo.eof())
				continue;

			// Armazena o conteudo da linha na variável registro
			string registro;
			getline(arquivo, registro, ',');
			ids[i] = stoi(registro); // Transforma a linha csv em um objeto do tipo GameReview
		}
	}
	else
	{
		cerr << "Erro: Nao conseguiu abrir o arquivo" << endl;
	}
	arquivo.close();
	return ids;
}

//Esta função recebe como parâmetro as informações do review do jogo em formato csv e converte as informações em um objeto GameReview
GameReview LeituraArquivo::ParseLine(string registro)
{
	string *ColunasCsv = new string[6]; // vetor de strings que irá armazenar cada valor separado por vírgula
	const char *InicioColuna = registro.c_str(); // ponteiro que aponta para o primeiro caractere da string registro
	bool inString{ false }; // booleano que identifica se a informação contém aspas duplas em seu registro
	int i = 0;
	for (const char *c = InicioColuna; *c; c++) // percorre toda a string registro através do ponteiro *c, passando por seus caracteres
	{
		if (*c == '"') // Consegue identificar se o ponteiro está dentro de alguma aspas duplas
			inString = !inString;
		else if (*c == ',' && !inString) // se o caractere for uma vírgula (final da informação) e não está dentro de aspas
		{
			ColunasCsv[i] = string(InicioColuna, c - InicioColuna); // guarda a informação separada por vírgula
			InicioColuna = c + 1; // atualiza o ponteiro para o próximo valor após a vírgula
			i++;
		}
		else if (i == 5) // se i == 5 então é o último valor a ser lido e não haverá uma vírgula após o valor
		{
			ColunasCsv[i] = string(InicioColuna); // armazena a string de caracteres desde o apontado por InicioColuna até o final da linha
			break;
		}
	}

	GameReview gr(ColunasCsv[0], ColunasCsv[1], ColunasCsv[2], ColunasCsv[3], ColunasCsv[4], ColunasCsv[5]); // Inicializando objeto de acordo com os valores informados pela linha
	return gr;
}