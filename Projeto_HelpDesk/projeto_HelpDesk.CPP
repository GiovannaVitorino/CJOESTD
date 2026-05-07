#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Chamado {
    int id;
    string titulo;
    string usuario;
    int prioridade;
    bool aberto;
};

// ================= VARIÁVEIS GLOBAIS =================
vector<Chamado> chamados;
vector<Chamado> encerrados;
stack<Chamado> historico;

int proximoID = 1;

// ================= QUICK SORT =================
//---ORDENACAO POR PRIORIDADE
//PARTICAO
int particaoPrioridade(int inicio, int fim) {
    int pivo = chamados[fim].prioridade;
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (chamados[j].prioridade > pivo) {
            i++;
            swap(chamados[i], chamados[j]);
        }
    }
    swap(chamados[i + 1], chamados[fim]);
    return i + 1;
}

void quickSortPrioridade(int inicio, int fim) {
    if (inicio < fim) {
        int p = particaoPrioridade(inicio, fim);
        quickSortPrioridade(inicio, p - 1);
        quickSortPrioridade(p + 1, fim);
    }
}

//ORDENACAO POR ID
int particaoID(int inicio, int fim) {
    int pivo = chamados[fim].id;
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (chamados[j].id < pivo) {
            i++;
            swap(chamados[i], chamados[j]);
        }
    }
    swap(chamados[i + 1], chamados[fim]);
    return i + 1;
}

void quickSortID(int inicio, int fim) {
    if (inicio < fim) {
        int p = particaoID(inicio, fim);
        quickSortID(inicio, p - 1);
        quickSortID(p + 1, fim);
    }
}

// ================= BUSCA BINÁRIA =================
int buscaBinaria(int id) {
    int inicio = 0, fim = chamados.size() - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (chamados[meio].id == id)
            return meio;
        else if (chamados[meio].id < id)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}


// ================= OPERAÇÕES =================

void abrirChamado() {
    Chamado c;
    c.id = proximoID++;

    cout << "Titulo: ";
    cin.ignore();
    getline(cin, c.titulo);

    cout << "Usuario: ";
    getline(cin, c.usuario);

    cout << "Prioridade (1-5): ";
    cin >> c.prioridade;

    c.aberto = true;

    chamados.push_back(c);
    cout << "Chamado criado com ID: " << c.id << endl;
}

void listarChamados() {
    /*if (chamados.empty()) {
        cout << "\nNenhum chamado cadastrado.\n";
        return;
    }*/

    if (!chamados.empty())
        quickSortPrioridade(0, chamados.size() - 1);

    bool encontrou = false;

    cout << "\n--- Chamados Abertos ---\n";
    for (auto &c : chamados) {
        if (c.aberto) {
            encontrou = true;
            cout << "ID: " << c.id
                 << " | Titulo: " << c.titulo
                 << " | Usuario: " << c.usuario
                 << " | Prioridade: " << c.prioridade << endl;
        }
    }

    if (!encontrou) {
        cout << "Nenhum chamado aberto encontrado.\n";
    }
}

void buscarChamado() {
    if (!chamados.empty())
        quickSortID(0, chamados.size() - 1);

    int id;
    cout << "Digite o ID: ";
    cin >> id;

    int pos = buscaBinaria(id);

    if (pos != -1) {
        Chamado c = chamados[pos];
        cout << "Encontrado: " << c.titulo << " (" << c.usuario << ")\n";
    } else {
        cout << "Chamado nao encontrado.\n";
    }
}

void encerrarChamado() {
    if (!chamados.empty())
        quickSortID(0, chamados.size() - 1);

    int id;
    cout << "ID para encerrar: ";
    cin >> id;

    int pos = buscaBinaria(id);

    if (pos != -1 && chamados[pos].aberto) {
        chamados[pos].aberto = false;
        historico.push(chamados[pos]);
        encerrados.push_back(chamados[pos]);

        cout << "Chamado encerrado.\n";
    } else {
        cout << "Chamado nao encontrado ou ja encerrado.\n";
    }
}

void desfazerEncerramento() {
    if (historico.empty()) {
        cout << "Nada para desfazer.\n";
        return;
    }

    Chamado c = historico.top();
    historico.pop();

    for (auto &ch : chamados) {
        if (ch.id == c.id) {
            ch.aberto = true;
            break;
        }
    }

    encerrados.pop_back();
    cout << "Ultimo encerramento desfeito.\n";
}

void listarEncerrados() {
    if (encerrados.empty()) {
        cout << "\nNenhum chamado encerrado.\n";
        return;
    }

    cout << "\n--- Chamados Encerrados ---\n";
    for (auto &c : encerrados) {
        cout << "ID: " << c.id
             << " | Titulo: " << c.titulo
             << " | Usuario: " << c.usuario
             << " | Prioridade: " << c.prioridade << endl;
    }
}

// ================= MAIN =================

int main() {
    int opcao;

    do {
        cout << "\n===== HELP DESK =====\n";
        cout << "1 - Abrir chamado\n";
        cout << "2 - Listar chamados abertos\n";
        cout << "3 - Buscar chamado por ID\n";
        cout << "4 - Encerrar chamado\n";
        cout << "5 - Desfazer ultimo encerramento\n";
        cout << "6 - Exibir chamados encerrados\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: abrirChamado(); break;
            case 2: listarChamados(); break;
            case 3: buscarChamado(); break;
            case 4: encerrarChamado(); break;
            case 5: desfazerEncerramento(); break;
            case 6: listarEncerrados(); break;
            case 0: cout << "Encerrando...\n"; break;
            default: cout << "Opcao invalida.\n";
        }

    } while (opcao != 0);

    return 0;
}
