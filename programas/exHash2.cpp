#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

long long hashString(const string& s, const unordered_map<char, int>& primo) {
    long long h = 1;
    for (char c : s) {
        auto it = primo.find(c);
        if (it != primo.end()) {
            h *= it->second;
        }
    }
    return h;
}

int main() { 
    // Tabela hash: cada letra tem um número primo associado
    unordered_map<char, int> primo = {
        {'a', 2},  {'b', 3},  {'c', 5},  {'d', 7},  {'e', 11},
        {'f', 13}, {'g', 17}, {'h', 19}, {'i', 23}, {'j', 29},
        {'k', 31}, {'l', 37}, {'m', 41}, {'n', 43}, {'o', 47},
        {'p', 53}, {'r', 61}, {'s', 67}, {'t', 71}, {'u', 73},
        {'v', 79}, {'w', 83}, {'x', 89}, {'y', 97}, {'z', 101}
    };

    char letra;


    cout << "Informe a letra: ";
    cin >> letra;


        cout << "A letra '" << letra << "' tem o primo: " << primo[letra] << endl;

string palavra;
    cout << "Informe uma palavra: ";
    cin >> palavra;

    long long valorHash = hashString(palavra, primo);
    cout << "A palavra '" << palavra << "' tem hash: " << valorHash << endl;

    return 0;
}