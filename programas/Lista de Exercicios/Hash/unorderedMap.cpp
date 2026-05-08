#include <iostream>
#include <unordered_map>

using namespace std;

int main() {

    // Declara um unordered_map que associa strings a strings
    unordered_map<string, string> tabela;

    // Se a chave não existir, ela é criada; se existir, o valor é sobrescrito
    // Chave["País"] = "Capital" - Atribui o valor "Capital" à chave "País"
    tabela["Brasil"]    = "Brasilia";
    tabela["Argentina"] = "Buenos Aires";
    tabela["Japao"]     = "Toquio";
    tabela["Franca"]    = "Paris";
    tabela["Canada"]    = "Ottawa";

    //find() - busca sem criar entrada adicional
    string pais = "Japao";

    auto it = tabela.find(pais); // 'it' aponta para o par {chave, valor} encontrado

    if (it != tabela.end()) {            // Verifica se o país foi encontrado
        cout << "Capital de " << pais << ": "
             << it->second << endl;      // it->second acessa o valor (capital)
    } else {
        cout << "Pais nao encontrado." << endl;
    }

    // erase() remove o par associado à chave fornecida, caso exista
    tabela.erase("Argentina");

    // count() retorna 1 se a chave existir, ou 0 se não existir
    if (tabela.count("Argentina") == 0) {
        cout << "Argentina foi removida.\n";
    }

    cout << "\nTabela restante:\n";
    // 'auto& p' aponta o endereço de cada par {chave, valor} do mapa
    for (auto& p : tabela) {
        cout << p.first << " -> "   // p.first  = chave  (país)
             << p.second << endl;   // p.second = valor  (capital)
    }

    // Muda a capital para "Rio de Janeiro"
    tabela["Brasil"] = "Rio de Janeiro";
    // sobrescreve novamente para "Brasilia"
    tabela["Brasil"] = "Brasilia";

    cout << "\nCapital atual do Brasil: "
         << tabela["Brasil"] << endl; // Exibe o valor após sobrescrever

    return 0;
}