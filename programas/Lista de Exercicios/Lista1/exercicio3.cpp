/*
3 - Declare duas matrizes 3x3, some-as elemento por elemento armazenando o resultado
em uma terceira matriz. Crie uma função separada para imprimir qualquer matriz 3x3.

*/
#include <iostream>
using namespace std;

 void imprimeMatriz(int matriz[3][3]){
    for (int j = 0; j < 3; j++){
        for (int i = 0; i < 3; i++){
            cout << "Matriz ["<< j+1 << "][" << i+1 << "]: " << matriz [j][i] << endl;
        }
    }
 }

int main()
{
    int a[3][3] = {{1,2,3},{1,2,3},{1,2,3}};
    int b[3][3] = {{4,5,6},{4,5,6},{4,5,6}};
    int c[3][3];

    for (int j = 0; j < 3; j++){
        for (int i = 0; i < 3; i++){
            c[j][i] = a[j][i] + b[j][i];
        }
    }

    cout << "Matriz A: " << endl;
    imprimeMatriz(a);


    cout << "\nMatriz B: " << endl;
    imprimeMatriz(b);


    cout << "\nMatriz C: " << endl;
    imprimeMatriz(c);

    return 0;
}

