#include "ShellSort.h";

/**
 * Utiliza o algortimo de shellSort para ordenar um dado array
 *
 * @param Registro arr[]
 * @param  int tam
 * @return void
*/
void ShellSort::shellSort(int vet[], int tam)
{
    int i,j;
    // Comeca o algoritmo com uma lacuna grande entre as chaves e vai sempre
    // dividindo por 2 o tamanho em cada intera��o
    for (int lacuna = tam/2; lacuna > 0; lacuna /= 2)
    {
        // percorre a lacuna que acabou de ser dividida
        for (i = lacuna; i < tam; i += 1)
        {
            // pega o pivo para essa lacuna
            int pivo = vet[i];

            // compara o elementos da lacuna e faz a troca dos elementos quando necessaria
            numComparacoes++;
            for (j = i; j >= lacuna && vet[j - lacuna] > pivo; j -= lacuna)
            {
                vet[j] = vet[j-lacuna];
                numCopias++;
            }


            // volta o pivo para sua posicao inicial
            vet[j] = pivo;
            numCopias++;
        }
    }
}
