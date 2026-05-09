/*A clínica agora atende idosos, gestantes e pessoas com deficiência com prioridade —
antes dos demais, mesmo que tenham chegado depois.
Use a deque (#include<deque>) — ela permite inserção e remoção em ambas
as extremidades, combinando fila e pilha em uma só estrutura. */
#include <iostream>
#include <deque>
using namespace std;

deque<int> fila;
int senha = 1;

void retirar_bilhete(bool prioritario = false){
    if(prioritario){
        fila.push_front(senha);   // entra na frente
    } else {
        fila.push_back(senha);    // entra no fim
    }
    cout << "Senha retirada: " << senha 
         << (prioritario ? " (prioritário)" : "") << endl;
    senha++;
}

void proximo(){
    if(fila.empty()){
        cout << "Fila vazia!\n" << endl;
        return;
    }

    cout << "Senha chamada: " << fila.front() << endl;
    fila.pop_front();
}

void exibir_fila(){
    if(fila.empty()){
        cout << "Fila vazia!\n" << endl;
        return;
    }

    deque<int> copia = fila;

    cout << "Fila atual:\n";
    while(!copia.empty()){
        cout << copia.front() << " ";
        copia.pop_front();
    }
    cout << endl;
}

bool vazia(){
    return fila.empty();
}

int main(){
    // 5 clientes comuns
    for (int i = 0; i < 5; i++){
        retirar_bilhete();
    }

    // 2 prioritários chegam
    retirar_bilhete(true);
    retirar_bilhete(true);

    // exibe a fila
    exibir_fila();

    // chama 3 clientes
    for (int i = 0; i < 3; i++){
        proximo();
    }

    // entram 2 novos clientes comuns
    retirar_bilhete();
    retirar_bilhete();

    // exibe a fila
    exibir_fila();

    // chama clientes até esvaziar
    while(!vazia()){
        proximo();
    }

    return 0;
}
