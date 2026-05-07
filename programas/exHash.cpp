#include <iostream>
#include <iomanip>
using namespace std;

int main(void){
    int hashB(string S){
        return S.length();
    }

    int hashC(string s){
        return (int)s[0] % 10;
    }

    int hashD(string s){
        //alfabeto sequencia de numeros primos
        int soma = 0;
        for (char c : c)soma += primo[c]; //soma os valores primos correspondentes aos caracteres
        return soma%10;
    }
    //houve quantas colisões compare com as funções A, B e C.Qual distribuiu melhor?

    return 0;
}
//quantas colisões ocorreram? Pq não é o ideial?