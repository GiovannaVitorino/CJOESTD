#include <iostream>
using namespace std;

int buscaBinaria(int vetor[], int tamanho, int chave){
    int esquerda = 0;
    int direita = tamanho - 1;

    while (esquerda <= direita){
        int meio = esquerda + (direita - esquerda) / 2;
        if (vetor[meio] == chave)
            return meio;
        else if (vetor[meio] < chave)
            esquerda = meio + 1;
        else
            direita = meio - 1;
    }

    return -1; // não encontrado
}

int main(){
    int vetor[10] = {11, 12, 22, 25, 34, 45, 50, 64, 88, 90};
    const int tamanho = 10;

    int chave;
    cout << "Digite o numero a buscar: ";
    cin >> chave;

    int indiceEncontrado = buscaBinaria(vetor, tamanho, chave);
    if (indiceEncontrado == -1)
        cout << "Elemento nao encontrado." << endl;
    else
        cout << "Elemento encontrado na posicao " << indiceEncontrado + 1 << endl;

    return 0;
}
