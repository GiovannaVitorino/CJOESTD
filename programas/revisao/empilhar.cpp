#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<char> pilha;

    // Empilhar A, B, C
    pilha.push('A');
    pilha.push('B');
    pilha.push('C');

    // Apresentar elemento do topo
    cout << "Topo atual: " << pilha.top() << endl;

    // Desempilhar e mostrar o elemento desempilhado
    cout << "Desempilhando: " << pilha.top() << endl;
    pilha.pop();

    return 0;
}
