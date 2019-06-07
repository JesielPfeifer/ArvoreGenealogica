#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class Pessoa {
private:
    string nome;
    enum TSexo {
        sxMasculino, sxFeminino
    };
    TSexo sexo;
    int idade;
    enum TCorOlhos {
        coCastanho, coVerde, coAzul
    };
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

    Pessoa *geraPessoa(string nome, TSexo sexo, int idade, Pessoa *pai);

    string getNome() {
        return this->nome;
    }

//    string getSexoStr() {
//    }

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

//    Pessoa *getPai() {
//
//    }
//
//    Pessoa *getMae() {
//
//    }

    void imprimeDados();

    string serializaPessoa();
};

class Arvore {
private:
    vector<Pessoa *> pessoa;
public:
    void lerArquivo(string arquivo, string nomePaiDigitado, string nomeMaeDigitado) {
        int pos;
        fstream arq;
        istringstream input{};
        arq.open(arquivo.c_str(), fstream::in);
        string nome_, corOlhos_, nomeMae_, nomePai_, sexo_, idade_;
        if (arq.is_open()) {
            string linha;
//            for (linha; getline(arq, linha);)
            while(!arq.eof())
            {

                getline(arq, nome_, '\t');
                getline(arq, sexo_, '\t');
                getline(arq, idade_, '\t');
                getline(arq, corOlhos_, '\t');
                getline(arq, nomePai_, '\t');
                getline(arq, nomeMae_, '\n');

                cout << nome_;
                cout << sexo_;
                cout << idade_;
                cout << corOlhos_;
                cout << nomePai_;
                cout << nomeMae_ << endl;

                if (nomePai_ == nomePaiDigitado) {
                    cout << "Nome: " << nome_ << endl;
                    cout << "Idade: " << idade_ << endl;

                }
            }
        } else {
            cout << "erro" << endl;
        }
    }

//    void carregarArquivo(string arquivo) {
//        fstream arq1;
//        arq1.open(arquivo.c_str(), fstream::in);
//        for (int i = 0; i < arquivo.size(); i++) {
//            if (arq1.is_open()) {
//                getline(arq1, arquivo);
//                string leitura = arquivo;
//                Arvore *arv = new Arvore();
//                arv->lerArquivo(leitura);
//            }
//        }
//    }
};

int main() {
    string arquivo = "DadosPessoas.txt";
    string nomePai, nomeMae, nomeFilho, sexoFilho;
    int idadeFilho, opcao;
    Arvore *arvore = new Arvore();

    while (1) {
//        arvore->carregarArquivo(arquivo);

        cout << "====================MENU=====================" << endl;
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
        switch (opcao) {
            case 1:
                cout << "================PREENCHA OS DADOS=================" << endl;
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
                arvore->lerArquivo(arquivo, nomePai, nomeMae);
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
