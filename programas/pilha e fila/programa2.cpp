/*sistema de atendimento com senhas numericas -> o cliente retira um bilhete e aguarda o atendente chamar
retirar_bilhete() gera o proximo numero e enfilera cliente
proximo() chama o primeiro da fila e o remove. exibe o numero chamado
exibir_fila() percorre toda a fila do primeiroao ultimo exibindo os numeros
vazia() retorna true se não tiver cliente aguardando
simule 5 clientes retiram bilhetes -> exibir_fila() -> proximo() 3x -> 2 novos clientes -> exibir_fila() -> proximo() até vazia()*/
#include <iostream>
#include <queue>
using namespace std;

queue<int> fila;
int senha = 1;

void retirar_bilhete(){
    fila.push(senha);
    senha++;
}

void proximo(){
    if(fila.empty()){
        cout << "Fila vazia!\n" << endl;
        return;
    }

    cout << "Senha chamada: " << fila.front() << endl;
    fila.pop();
}

void exibir_fila(){
    if(fila.empty()){
        cout << "Fila vazia!\n" << endl;
        return;
    }

    queue<int> copia = fila;

    cout << "Fila atual:\n";

    while(!copia.empty()){
        cout << copia.front() << " ";
        copia.pop();
    }
    cout << endl;
}

bool vazia(){
    return fila.empty();
}

int main(){
    // 5 clientes retiram bilhetes
    for (int i = 0; i < 5; i++){
        retirar_bilhete();
    }

    // exibe a fila
    exibir_fila();

    // chama 3 clientes
    for (int i = 0; i < 3; i++){
        proximo();
    }

    // entram 2 novos clientes
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