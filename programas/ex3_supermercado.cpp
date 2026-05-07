#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>
using namespace std;

int main(void){
    unordered_map<string, double> mercado;

    mercado["Arroz"] = 8.90;
    mercado["Feijao"] = 7.50;
    mercado["Leite"] = 4.20;
    mercado["Ovos"] = 12.00;
    mercado["Manteiga"] = 9.80;

    //find() - busca sem criar entrada adicional
    //tabela["chave"] = criaria a entrada se não existisse

    cout << fixed << setprecision(2);

    auto it = mercado.find("Leite");

    if(it != mercado.end()){
        cout << "Leite encontrado:  R$" << it -> second << endl;
    }
    else{
        cout << "Leite não encontrado." << endl;
    }

    //erase() - remove o produto da tabela
    mercado.erase("Ovos");

    //count confirma se o produto ainda existe
    if(mercado.count("Ovos") == 0){
        cout << "Ovos foi removido do cadastro." << endl;
    }

    //percorre e exibe todos os produtos restantes
    cout << "\n-- Produtos no mercado --" << endl;

    for(auto &p : mercado){
        cout << p.first << ": R$" << p.second <<endl;
    }
    return 0;
}
