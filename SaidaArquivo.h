#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class SaidaArquivo
{
public:
	SaidaArquivo();
	SaidaArquivo(string nomeArquivo);
	SaidaArquivo(string nomeArquivo, bool appendFile);
	~SaidaArquivo();

	template <typename T>
	void WriteLine(T linha);

	void SetNomeArquivo(string nomeArquivo);
	void WriteResult(int numComparacoes, int numCopias, long long tempoExecucao);
	void Open();
	void Append();
	void Close();
	

private:
	string nomeArquivo;
	ofstream arquivo;
};

template<typename T>
inline void SaidaArquivo::WriteLine(T linha)
{
	arquivo << linha << endl;
}
