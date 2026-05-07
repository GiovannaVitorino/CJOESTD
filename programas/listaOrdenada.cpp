#include <iostream>

using namespace std;

int main(){
    struct No{
        int dado;
        No* proximo;
    };

    No *n1 = new No;
    No *n2 = new No;

    n1->dado = 10;
    n1->proximo = n2;
}
