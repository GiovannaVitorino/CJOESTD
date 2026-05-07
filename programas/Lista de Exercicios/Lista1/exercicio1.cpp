/*1 - Dado o array abaixo, escreva um programa em C++ que calcule e exiba a média, o maior e o menor valor. Use apenas um loop para resolver tudo.

int notas[] = {7, 9, 5, 8, 6, 10, 4};
*/
#include <iostream>
using namespace std;

int main()
{
    int notas[] = {7, 9, 5, 8, 6, 10, 4};
    int soma, maior, menor;
    float media;

    for (int i = 0; i < 7; i++){
        soma += notas[i];
        if(notas[i] < notas[i-1]){
            menor = notas[i];
        }
        else{
            maior = notas[i];
        }
    }

    media = soma/7;

    cout << "Media: " << media << endl;
    cout << "Maior: " << maior << endl;
    cout << "Menor: " << menor << endl;

    return 0;
}
