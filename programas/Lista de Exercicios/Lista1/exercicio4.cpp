/*
4 - Escreva uma função recursiva que calcule a soma de todos os números de 1 até N.
Demonstre a chamada no main para N = 5 e N = 10.
*/
#include <iostream>
using namespace std;

int soma(int n) {
    if (n == 1){
        return 1;
    } else {
        return n + soma(n - 1);
    }
}

int main() {

    cout << "Soma de 1 ate 5: " << soma(5) << endl;
    cout << "Soma de 1 ate 10: " << soma(10) << endl;

    return 0;
}

