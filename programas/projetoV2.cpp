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

vector<Chamado> chamados;
vector<Chamado> encerrados;
stack<Chamado> historico;

int proximoID = 1;

// ================= QUICK SORT =================

// Partição por prioridade (decrescente)
int particaoPrioridade(vector<Chamado>& v, int inicio, int fim) {
    int pivo = v[fim].prioridade;
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (v[j].prioridade > pivo) { // maior prioridade primeiro
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[fim]);
    return i + 1;
}

void quickSortPrioridade(vector<Chamado>& v, int inicio, int fim) {
    if (inicio < fim) {
        int p = particaoPrioridade(v, inicio, fim);
        quickSortPrioridade(v, inicio, p - 1);
        quickSortPrioridade(v, p + 1, fim);
    }
}

// Partição por ID (crescente)
int particaoID(vector<Chamado>& v, int inicio, int fim) {
    int pivo = v[fim].id;
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (v[j].id < pivo) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[fim]);
    return i + 1;
}

void quickSortID(vector<Chamado>& v, int inicio, int fim) {
    if (inicio < fim) {
        int p = particaoID(v, inicio, fim);
        quickSortID(v, inicio, p - 1);
        quickSortID(v, p + 1, fim);
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

// ================= RECURSÃO =================
int somaPrioridadeUsuario(string usuario, int i) {
    if (i >= chamados.size())
        return 0;

    int soma = 0;
    if (chamados[i].usuario == usuario && chamados[i].aberto)
        soma = chamados[i].prioridade;

    return soma + somaPrioridadeUsuario(usuario, i + 1);
}

// ================= FUNÇÕES =================

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
    if (!chamados.empty())
        quickSortPrioridade(chamados, 0, chamados.size() - 1);

    cout << "\n--- Chamados Abertos ---\n";
    for (auto &c : chamados) {
        if (c.aberto) {
            cout << "ID: " << c.id
                 << " | " << c.titulo
                 << " | " << c.usuario
                 << " | P: " << c.prioridade << endl;
        }
    }
}

void buscarChamado() {
    if (!chamados.empty())
        quickSortID(chamados, 0, chamados.size() - 1);

    int id;
    cout << "ID: ";
    cin >> id;

    int pos = buscaBinaria(id);

    if (pos != -1)
        cout << "Encontrado: " << chamados[pos].titulo << endl;
    else
        cout << "Nao encontrado.\n";
}

void encerrarChamado() {
    if (!chamados.empty())
        quickSortID(chamados, 0, chamados.size() - 1);

    int id;
    cout << "ID: ";
    cin >> id;

    int pos = buscaBinaria(id);

    if (pos != -1 && chamados[pos].aberto) {
        chamados[pos].aberto = false;
        historico.push(chamados[pos]);
        encerrados.push_back(chamados[pos]);

        cout << "Encerrado.\n";
    } else {
        cout << "Erro.\n";
    }
}

void desfazer() {
    if (historico.empty()) {
        cout << "Nada para desfazer.\n";
        return;
    }

    Chamado c = historico.top();
    historico.pop();

    for (auto &ch : chamados) {
        if (ch.id == c.id)
            ch.aberto = true;
    }

    encerrados.pop_back();
    cout << "Desfeito.\n";
}

void cargaUsuario() {
    string usuario;
    cout << "Usuario: ";
    cin.ignore();
    getline(cin, usuario);

    cout << "Carga: " << somaPrioridadeUsuario(usuario, 0) << endl;
}

void listarEncerrados() {
    cout << "\n--- Encerrados ---\n";
    for (auto &c : encerrados) {
        cout << c.id << " - " << c.titulo << endl;
    }
}

// ================= MAIN =================

int main() {
    int op;

    do {
        cout << "\n1 Abrir\n2 Listar\n3 Buscar\n4 Encerrar\n5 Desfazer\n6 Carga\n7 Encerrados\n0 Sair\n";
        cin >> op;

        switch (op) {
            case 1: abrirChamado(); break;
            case 2: listarChamados(); break;
            case 3: buscarChamado(); break;
            case 4: encerrarChamado(); break;
            case 5: desfazer(); break;
            case 6: cargaUsuario(); break;
            case 7: listarEncerrados(); break;
        }

    } while (op != 0);
}
