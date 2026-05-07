#include <iostream>
#include <utility> // para std::pair
using namespace std;

pair<int,int> pesquisa(int lista[], int tamanho, int alvo) {
    int ciclos = 0;
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        ciclos++;
        int meio = (inicio + fim) / 2;

        if (lista[meio] == alvo)
            return {meio, ciclos}; // retorna posição e ciclos
        else if (lista[meio] < alvo)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return {-1, ciclos}; // não encontrado
}

int main() {
    int lista[10] = {3, 7, 12, 18, 25, 31, 44, 56, 70, 88};
    int alvo;

    cout << "Digite o numero que deseja buscar: ";
    cin >> alvo;

    pair<int,int> resultado = pesquisa(lista, 10, alvo);

    if (resultado.first != -1) {
        cout << "Numero encontrado na posicao " << resultado.first+1
             << " em " << resultado.second << " ciclos." << endl;
    } else {
        cout << "Numero nao encontrado apos " << resultado.second << " ciclos." << endl;
    }

    return 0;
}
