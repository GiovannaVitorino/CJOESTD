/*
2 - Escreva uma FUNÇÃO que receba um array e o inverta sem usar um segundo array auxiliar.
Em seguida, chame a função no main e imprima o array antes e depois.
*/
#include <iostream>
using namespace std;

 void inverterArray(int matriz[], int tam){
     int x;

    for (int i = 0; i < tam/2; i++){
        x = matriz[i];
        matriz[i] = matriz[tam-1-i];
        matriz[tam-1-i] = x;
    }
 }

int main()
{
    int matriz[] = {1, 2, 3, 4, 5};
    int tam = 5;

    cout << "**Array**" << endl;
    for (int i = 0; i < tam; i++){
        cout << "Elemento " << i+1 << ": " << matriz[i] << endl;
    }

    inverterArray(matriz, tam);
    cout << "\n**Array invertido**" << endl;
    for (int i = 0; i < tam; i++){
        cout << "Elemento " << i+1 << ": " << matriz[i] << endl;
    }

    return 0;
}

