/*
6 - Escreva uma função recursiva que inverta uma string sem usar laços (for/while).
Teste com as palavras: "radar", "hello" e "estrutura".
*/
#include <iostream>
using namespace std;

string inverterPalavra(string palavra) {
    if (palavra.size() <= 1) {
        return palavra;
    }
    return inverterPalavra(palavra.substr(1)) + palavra[0];
}

int main() {
    cout << "Palavras invertidas: " << endl;
    cout << "radar = " << inverterPalavra("radar") << endl;
    cout << "hello = " << inverterPalavra("hello") << endl;
    cout << "estrutura = " << inverterPalavra("estrutura") << endl;

    return 0;
}
