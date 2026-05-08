#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string, int> mapa;
    mapa.reserve(50); // Prepara o mapa para 50 elementos

    // insere 10 elementos
    for(int i = 0; i < 10; i++) {
        mapa["chave" + to_string(i)] = i + 1; // Valores de 1 a 10
    }
    
    //imprima load_factor() e bucket_count()
    cout << "--- Status Inicial (10 elementos) ---" << endl;
    cout << "Load Factor: " << mapa.load_factor() << endl;
    cout << "Bucket Count: " << mapa.bucket_count() << endl;

    //Use find() com iterador para buscar uma chave
    auto it_busca = mapa.find("chave5");
    if(it_busca != mapa.end()) {
        cout << "\nValor encontrado para 'chave5': " << it_busca->second << endl;
    }

    // Remover elementos com valor menor que 5
       for (auto it = mapa.begin(); it != mapa.end(); ) {
        if (it->second < 5) {
            it = mapa.erase(it); // erase retorna o proximo iterador valido
        } else {
            ++it;
        }
    }
    cout << "\nElementos apos remocao (<5): " << mapa.size() << endl;

    //Compare o load_factor() antes e depois de usar max_load_factor(0.5)
    cout << "\n--- Comparacao Load Factor ---" << endl;
    cout << "Load Factor atual: " << mapa.load_factor() << endl;
    
    mapa.max_load_factor(0.5); // Diminui o limite para forcar redistribuicao
    
    cout << "Apos max_load_factor(0.5): " << mapa.load_factor() << endl;
    cout << "Novo Bucket Count: " << mapa.bucket_count() << endl; // aumentou para manter o factor

    return 0;
}