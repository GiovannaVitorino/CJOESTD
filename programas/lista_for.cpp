#include <iostream>
using namespace std;

int main(){
    int lista[] = {1, 2, 3, 4, 5};
    int n;

    cin >> n;

    bool encontrado;
    for(int i=0; i<= 4; ++i){
        if(lista[i] == n){
            cout << "Encontrado na posicao " << i+1;
            encontrado = true;
        }
    }

    if(!encontrado)
        cout << "Nao encontrado";

    return 0;
}
