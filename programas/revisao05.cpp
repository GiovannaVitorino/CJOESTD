// declare int x = 7 crie ptr para x mude o valor de x para 21 e imprima
//aloque dinamicamente um int ocm new atribua o valor 100 imprima e libere com delete
// crie uma struct Ponto com x e y aloque um Ponto com new atribua valores usando -> imprima e delete

#include <iostream>
using namespace std;

void mudeX(){
    int x = 7;
    int *px = &x;

    cout << "Valor de x: " << *px << endl;

    *px = 21;

    cout << "Valor de x: " << *px << endl;
}

void alocarDinamicamente(){
    int *p = new int(100);
    cout << *p << endl;
    delete p;
    p = nullptr;
}

void alocarPonto(){
    struct ponto{
        int x;
        int y;
    };

    ponto *x = new No;
    ponto *y = new No;

    ponto->dado = 10;
    x->proximo = y;
}

int main(void) {
    mudeX();
    alocarDinamicamente();
    alocarPonto();

    return 0;
}
