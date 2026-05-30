#include <iostream>
#include <set>

int main() {
    std::set<int> arvore;  // usa std::set

    arvore.insert(4);

    if (arvore.count(4)) 
        std::cout << "4 encontrado" << std::endl;

    for (int v : arvore) 
        std::cout << v << std::endl;

    arvore.erase(4);

    return 0;
}
