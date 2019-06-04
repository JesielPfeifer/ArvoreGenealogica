#include "ArvoreGenealogica.h"

int main() {
    string nomePai, nomeMae, nomeFilho, sexoFilho;
    int idadeFilho, opcao;
    Pessoa *pessoa = new Pessoa();
    while(1) {
        cout << "====================MENU====================="<<endl;
        cout << "\n";
        cout << "1 - Inserir pessoa na arvore genealogica" << endl;
        cout << "2 - Remover pessoa da arvore genealogica" << endl;
        cout << "3 - Modificar pessoa da arvore genealogica" << endl;
        cout << "4 - Consultar informacoes de uma pessoa" << endl;
        cout << "5 - Consultar informacoes de uma familia" << endl;
        cout << "6 - Estatisticas da arvore genealogica" << endl;
        cout << "7 - Salvar os dados da arvore genealogica em arquivo" << endl;
        cout << "8 - Sair" << endl;
        cout << "\n";
        cout << "=============================================" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        switch(opcao) {
        case 1:
            cout << "================PREENCHA OS DADOS================="<<endl;
            cout << "\n";
            cout << "Informe o nome do pai: ";
            cin >> getline(cin,nomePai);
            cout >> "Informe o nome da mae: ";
            cin >> getline(cin,nomeMae);
            cout << "Informe o nome do filho: ";
            cin >> getline(cin, nomeFilho);
            cout << "Informe o sexo do filho: ";
            cin >> getline(cin,sexoFilho);
            cout << "Informe a idade do filho: ";
            cin >> idadeFilho;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;

        }
    }
}
