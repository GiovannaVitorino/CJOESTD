#include <iostream>
using namespace std;

int fatorial(int n){
    if (n == 0)
        return 1;

    return fatorial(n-1) * n;
}


int main(int argc, char const *argv[]){

    return 0;
}
