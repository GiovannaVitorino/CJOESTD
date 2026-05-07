//strcuct aluno com note  npta
//aloque dinamicamente umn array com 3 alunos
//leia nome e nota de cada aluno
//percorra o array e imprima o nome do aliuno com a maior nota
//libere a memoria
#include <iostream>

using namespace std;

struct Aluno{
    string nome;
    float nota;
};

int main(){
    int maior;
    Aluno *alunos = new Aluno[3];

    for (int i = 0; i < 3; i++){
        cout << "Entre o nome do " << i+1 << "o. aluno: ";
        cin >> alunos[i].nome;
        cout << endl;

        cout << "Entre a nota do " << i+1 << "o. aluno: ";
        cin >> alunos[i].nota;
        cout << endl;
    }

    for (int i=0; i<3; i++){
        if(alunos[i].nota > alunos[i-1].nota)
           maior = i;
    }

    cout << "Aluno com maior nota: " << endl;
    cout << "Nome: "<< alunos[maior].nome << endl;
    cout << "Nota: "<< alunos[maior].nota << endl;

    delete[] alunos;
return 0;
}
