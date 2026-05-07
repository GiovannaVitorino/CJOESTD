#include <iostream>

using namespace std;

int main(){
int *p = new int(42);
    cout << *p;
delete p;
p = nullptr;
}
