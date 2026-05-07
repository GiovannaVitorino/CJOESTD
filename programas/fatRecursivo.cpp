#include <iostream>
using namespace std;

int fatorial(int n){
    if (n == 0)
        return 1;

    return fatorial(n-1) * n;
}


int main(){
    int n;

    cout << "Programa Fatorial" << endl << endl;
    cout << "Fatorial de que valor: ";
    cin >> n;

    cout << "\nFatorial de " << n << ": " << fatorial(n);
    cout << endl;

    return 0;
}
