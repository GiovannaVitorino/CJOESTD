// declare um array de 5 inteiros lidos pelo teclado e imprima o maior
//percorra o array ao contrario (ultimo ao primeiro) com for
// leia strind do usuario e imprima qts vzzs a letra a aparece nela

#include <iostream>
using namespace std;

int maiorNum (int maior){
    int arrayMaior[5];

    for (int i = 0; i < 5; i++){
        cout << "Entre o " << i+1 << "o. numero: ";
        cin >> arrayMaior[i];

        if(arrayMaior[i] > arrayMaior[i-1])
            maior = arrayMaior[i];
    }

    cout << maior;
}

int main(void) {
    int maior;

    maiorNum(maior);


    return 0;
}
