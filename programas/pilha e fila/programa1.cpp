/*exercicio: verificador de parenteses
Escreva um programa que receba uma string e verifique se ps parerenteses, colchetes e chaves estão corretamente balanceados.
implemente em  c++ usando stack<char>. teste com: {[(])} -> invalido | ([]) -> valido | {[]()} -> valido*/
#include <iostream>
#include <stack>
using namespace std;

bool verificarParenteses(string s) {
    stack<char> pilha;

    // percorre a string
    for (char c : s) {

        // se for símbolo de abertura, empilha
        if (c == '(' || c == '{' || c == '[') {
            pilha.push(c);
        }

        else if (c == ')' || c == '}' || c == ']') {

            // se a pilha estiver vazia, não há abertura
            if (pilha.empty()) return false;

            // pega o topo da pilha
            char topo = pilha.top();
            pilha.pop(); 

            if ((c == ')' && topo != '(') ||
                (c == '}' && topo != '{') ||
                (c == ']' && topo != '[')) {
                return false; 
            }
        }
    }

    return pilha.empty();
}

int main() {
    string s;

    // leitura da expressão
    cout << "Digite a expressao: ";
    cin >> s;

    // verifica e exibe o resultado
    if (verificarParenteses(s)) {
        cout << "Valido\n";
    } else {
        cout << "Invalido\n";
    }

    return 0;
}