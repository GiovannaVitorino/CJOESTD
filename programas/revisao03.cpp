//funcao int maximo(int a, int b) que retoena o maior dos dois
//funcao void trocar(int a, int b) que troca
//funcao bool ePar(int n) retorna true se o num for par
#include <iostream>

using namespace std;

int maximo(int a, int b){
    cout << endl << "Maior valor: ";

    cout << ((a > b)? a : b);
}

void troca(int a, int b){
    int x;

    x =a;
    a = b;
    b = x;
}

int main(void) {
    int a, b;

    cout << "Entre A: ";
    cin >> a;
    cout << endl;
    cout << "Entre B: ";
    cin >> b;
    cout << endl;

    maximo(a, b);

    cout << endl << "valores trocados: ";

    troca(a, b);

}
