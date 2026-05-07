/*
5 - Escreva uma função recursiva que retorne o N-ésimo número da sequência de Fibonacci. Imprima os 8 primeiros termos da sequência.
*/
#include <iostream>
using namespace std;

int fibonacci(int n){
    if (n <= 1)
        return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){

    cout << "8 primeiros termos de fibonacci:\n";

    for(int i = 0; i < 8; i++){
        cout << fibonacci(i) << " ";
    }

    cout << endl;

    return 0;
}
