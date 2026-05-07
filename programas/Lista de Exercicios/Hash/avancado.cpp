#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    // 1. Crie um unordered_map e use reserve(50) antes de inserir
    unordered_map<string, int> mapa;
    mapa.reserve(50); // Prepara o mapa para 50 elementos, evitando realocações

    // 2. Após inserir 10 elementos, imprima load_factor() e bucket_count()
    for(int i = 0; i < 10; i++) {
        mapa["chave" + to_string(i)] = i + 1; // Valores de 1 a 10
    }
    
    cout << "--- Status Inicial (10 elementos) ---" << endl;
    cout << "Load Factor: " << mapa.load_factor() << endl;
    cout << "Bucket Count: " << mapa.bucket_count() << endl;

    // 3. Use find() com iterador para buscar uma chave
    auto it_busca = mapa.find("chave5");
    if(it_busca != mapa.end()) {
        cout << "\nValor encontrado para 'chave5': " << it_busca->second << endl;
    }

    // 4. Remover elementos com valor menor que 5 usando o padrao correto com iterador
    // Nota: Em C++20+, existe o erase_if, mas o padrao classico com iterador e:
    for (auto it = mapa.begin(); it != mapa.end(); ) {
        if (it->second < 5) {
            it = mapa.erase(it); // erase retorna o proximo iterador valido
        } else {
            ++it;
        }
    }
    cout << "\nElementos apos remocao (<5): " << mapa.size() << endl;

    // 5. Compare o load_factor() antes e depois de usar max_load_factor(0.5)
    cout << "\n--- Comparacao Load Factor ---" << endl;
    cout << "Load Factor atual: " << mapa.load_factor() << endl;
    
    mapa.max_load_factor(0.5); // Diminui o limite para forcar redistribuicao (rehash)
    
    cout << "Apos max_load_factor(0.5): " << mapa.load_factor() << endl;
    cout << "Novo Bucket Count (aumentou para manter o factor): " << mapa.bucket_count() << endl;

    return 0;
}