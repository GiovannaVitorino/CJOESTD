#include <iostream>
using namespace std;

int fibonacci(int n){
    if (n <= 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(void){
    int termos = 10;
 
    cout << "Sequencia de fibonacci: ";
    for (int i = 0; i < termos; i++){
        cout << fibonacci(i);
        if (i < termos - 1)
            cout << " ";
    }
    return 0;
}
