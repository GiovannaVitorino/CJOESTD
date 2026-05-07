#include <iostream>
using namespace std;

int bubbleSort(int lista[], int tamanho, int &comparacoes) {
    comparacoes = 0;

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            comparacoes++;
            if (lista[j] > lista[j + 1]) {
                int x = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = x;
            }
        }
    }
    return comparacoes;
    //swap(arr[j], arr[j+1]);
}
/*
void bubbleSort(int arr[], int n)
*/

int main() {
    const int tamanho = 10;
    int lista[tamanho] = {64, 25, 12, 22, 11, 90, 33, 47, 5, 78};
    int comparacoes;

    cout << "Array antes da ordenacao: " << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << lista[i] << " ";
    }
    cout << endl;

    bubbleSort(lista, tamanho, comparacoes);

    cout << "\nArray apos ordenacao: " << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << lista[i] << " ";
    }
    cout << endl;

    cout << "\nNumero de comparacoes: " << comparacoes << endl;

    return 0;
}
