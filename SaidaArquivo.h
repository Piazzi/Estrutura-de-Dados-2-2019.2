#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class SaidaArquivo
{
public:
	SaidaArquivo();
	SaidaArquivo(string nomeArquivo);
	~SaidaArquivo();

	void SetNomeArquivo(string nomeArquivo);
	template <typename T>
	void WriteLine(T linha);
	void WriteResult(int numComparacoes, int numCopias, volatile long long tempoExecucao);
	void Open();
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
