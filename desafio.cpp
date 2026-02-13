/*Desafio
Criar um programa simples de gereciamento de notas de uma turma de até 10 alunos, utilizando:
- switch para controçar o menu
- do-while para repetir o menu até a saída
- funcoes para modularizar as operações
- vetores para armazenar as notas
*/

#include <iostream>
using namespace std;

void cadastrarNotas(int notas [10]){
    for (int i; i <= 10; i++){
    cout << "Digite a nota do aluno " << i + 1 << ": " << endl;
    cin >> notas[i];
    }
}

void vizualizarNotas(int notas [10]){
    for (int i; i <= 10; i++){
    cout << "Nota do aluno " << i + 1 << ": " << notas[i] << endl;
    }
}

int main(int argc, char const *argv[]){
    int opcao = 0;

    do{
    cout << "Escolha uma opcao: ";
    cout << "\n0 - Sair";
    cout << "\n1 - Cadastrar";
    cout << "\n2 - Editar";
    cout << "\n3 - Exluir";
    cout << "\n4 - Vizualizar" << endl << endl;

    cin >> opcao;

    switch (opcao){
        case 0:
            cout << "Ate a proxima!" << endl;
            break;
        case 1:
            cout << "Cadastrar notas" << endl;
            break;
        case 2:
            cout << "Editar notas" << endl;
            break;
        case 3:
            cout << "Excluir notas" << endl;
            break;
        case 4:
            cout << "Vizualizar notas" << endl;
            break;
        default:
            cout << "Digite uma opcao valida!" << endl;
            break;
    }
    }while (opcao != 0);
    return 0;
}
