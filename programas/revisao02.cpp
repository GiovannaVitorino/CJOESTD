//leia 5 notas e imprime quantas são maiores que 5
//usando while leia números do usuário e pare quando ele digitar 0. imprima a soma
//use for para imprimir a tabuada do num que o usua´rio digitar (1 a 10)
#include <iostream>
using namespace std;

void notaMaiorQueCinco(){
    int nota;
    int qtdNotas;
    int contador;

    do{
        cout << "Entre a " << contador+1 << "a. nota: ";
        cin >> nota;
        cout << endl;

        if (nota > 7){
            qtdNotas++;
        }
        ++contador;
    }
    while(contador < 5);

    cout << endl << qtdNotas;
    //retornand 6?
}

int main(void) {

 notaMaiorQueCinco();
return 0;
}
