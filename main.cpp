#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Pessoa {
private:
    string nome;
    enum TSexo {sxMasculino, sxFeminino};
    TSexo sexo;
    int idade;
    enum TCorOlhos {coCastanho, coVerde, coAzul};
    TCorOlhos corOlhos;
    Pessoa *pai;
    Pessoa *mae;
public:
    Pessoa() {}
    ~Pessoa() {}
    Pessoa(string nome, TSexo sexo, int idade, TCorOlhos corOlhos, Pessoa *pai, Pessoa *mae) {
        this->nome = nome;
        this->idade = idade;
        this->sexo = sexo;
        this->pai = pai;
        this->mae = mae;
        this->corOlhos = corOlhos;
    }
    Pessoa *geraPessoa(string nome, TSexo sexo, int idade, Pessoa *pai) {}
    string getNome(){
        return this->nome;
    }
    string getSexoStr(){
    }
    string getCorOlhosStr();
    int getIdade() {
        return this->idade;
    }
    void setNome(string nome) {
        this->nome = nome;
    }
    void setSexo(TSexo sexo) {
        this->sexo = sexo;
    }
    void setCorOlhos(TCorOlhos corOlhos) {
        this->corOlhos = corOlhos;
    }
    void setIdade(int idade) {
        this->idade = idade;
    }
    void setPai(Pessoa *pai) {
        this->pai = pai;
    }
    void setMae(Pessoa *mae) {
        this->mae = mae;
    }
    Pessoa* getPai(){

    }
    Pessoa* getMae(){

    }
    void imprimeDados();
    string serializaPessoa();
};

class Arvore {
private:
    vector <Pessoa*> pessoas;
public:
    void inserirPessoa();
    void removerPessoa();

};

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
            cin >> nomePai;
            cout << "Informe o nome da mae: ";
            cin >> nomeMae;
            cout << "Informe o nome do filho: ";
            cin >> nomeFilho;
            cout << "Informe o sexo do filho: ";
            cin >> sexoFilho;
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
        default:
            cout << "Opcao invalida" << endl;

        }
    }
}
