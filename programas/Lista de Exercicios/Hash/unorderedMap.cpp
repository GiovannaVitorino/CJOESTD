#include <iostream>
#include <unordered_map>

using namespace std;

int main() {

    unordered_map<string, string> tabela;

    //tabela[]
    tabela["Brasil"] = "Brasilia";
    tabela["Argentina"] = "Buenos Aires";
    tabela["Japao"] = "Toquio";
    tabela["Franca"] = "Paris";
    tabela["Canada"] = "Ottawa";

    // 2. Usando find() para buscar um país
    string pais = "Japao";

    auto it = tabela.find(pais);

    if (it != tabela.end()) {
        cout << "Capital de " << pais << ": "
             << it->second << endl;
    } else {
        cout << "Pais nao encontrado." << endl;
    }

    // 3. Removendo um país com erase()
    tabela.erase("Argentina");

    // Confirmando com count()
    if (tabela.count("Argentina") == 0) {
        cout << "Argentina foi removida.\n";
    }

    // 4. Exibindo todos os pares restantes
    cout << "\nTabela restante:\n";

    for (auto& p : tabela) {
        cout << p.first << " -> "
             << p.second << endl;
    }

    // 5. Inserindo o mesmo país duas vezes
    tabela["Brasil"] = "Rio de Janeiro";
    tabela["Brasil"] = "Brasilia";

    cout << "\nCapital atual do Brasil: "
         << tabela["Brasil"] << endl;

    return 0;
}