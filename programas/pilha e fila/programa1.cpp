/*exercicio: verificador de parenteses
Escreva um programa que receba uma string e verifique se ps parerenteses, colchetes e chaves estão corretamente balanceados.
implemente em  c++ usando stack<char>. teste com: {[(])} -> invalido | ([]) -> valido | {[]()} -> valido*/
#include <iostream>
#include <stack>
#include <string>
#include <map>

bool estaBalanceado(std::string expressao) {
    std::stack<char> pilha;
    
    // Mapeamento para facilitar a comparação
    std::map<char, char> pares = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char c : expressao) {
        // Se for um caractere de abertura, empilha
        if (c == '(' || c == '[' || c == '{') {
            pilha.push(c);
        } 
        // Se for um caractere de fechamento
        else if (c == ')' || c == ']' || c == '}') {
            // Se a pilha estiver vazia ou o topo não for o par correspondente
            if (pilha.empty() || pilha.top() != pares[c]) {
                return false;
            }
            pilha.pop(); // Remove o par correspondente do topo
        }
    }

    return pilha.empty(); // Se sobrar algo, está desbalanceado
}

void testar(std::string s) {
    std::cout << "String: " << s << " -> " 
              << (estaBalanceado(s) ? "valido" : "invalido") << std::endl;
}

int main() {
    testar("{[(])}"); // Invalido
    testar("([])");   // Valido
    testar("{[]()}"); // Valido
    
    return 0;
}