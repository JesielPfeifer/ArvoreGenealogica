#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstdlib>

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

    Pessoa *geraPessoa(string nome, TSexo sexo, int idade, Pessoa *pai) {
        srand(time(NULL));
        int valorRandom = rand() % 2 + 1;
        if ((this->getSexoStr() == "Feminino") && (pai->getCorOlhosStr() == "Masculino")) {
            if ((this->getCorOlhosStr() == "Castanho") || (pai->getCorOlhosStr() == "Castanho")) {
                Pessoa *filho = new Pessoa();
            } else if ((this->getCorOlhosStr() == "Verde") && (pai->getCorOlhosStr() == "Verde")) {
                Pessoa *filho = new Pessoa();
                return filho;
            } else if ((this->getCorOlhosStr() == "Azul") && (pai->getCorOlhosStr() == "Azul")) {
                Pessoa *filho = new Pessoa();
                return filho;
            } else if (((this->getCorOlhosStr() == "Verde") && (pai->getCorOlhosStr() == "Azul")) ||
                       ((this->getCorOlhosStr() == "Azul") && (pai->getCorOlhosStr() == "Verde"))) {
                if (valorRandom == 1) {
                    Pessoa *filho = new Pessoa();
                    return filho;
                } else if (valorRandom == 2) {
                    Pessoa *filho = new Pessoa();
                    return filho;
                }
            }
        } else {
            cout << "Membros nao podem se reproduzir" << endl;
            return NULL;
        }
    }

    string getNome() {
        return this->nome;
    }

    string getSexoStr() {
        if (this->sexo == 0) {
            return "Masculino";
        } else if (this->sexo == 1) {
            return "Feminino";
        }
    }

    string getCorOlhosStr() {
        if (this->corOlhos == 0) {
            return "Castanho";
        } else if (this->corOlhos == 1) {
            return "Verde";
        } else if (this->corOlhos == 2) {
            return "Azul";
        }
    }

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

    Pessoa *getPai() {
        return this->pai;
    }

    Pessoa *getMae() {
        return this->mae;
    }

    void imprimeDados();

    string serializaPessoa();
};

class Arvore {
private:
    vector<Pessoa *> pessoa;
public:
    Pessoa *objPessoa = new Pessoa();

    void lerArquivo(string arquivo, string nomePaiDigitado, string nomeMaeDigitado) {
        fstream arq;
        arq.open(arquivo.c_str(), fstream::in);
        string nome_, corOlhos_, nomeMae_, nomePai_, sexo_, idade_;
        int idadeInt;
        if (arq.is_open()) {
            while (!arq.eof()) {
                getline(arq, nome_, '\t');
                getline(arq, sexo_, '\t');
                getline(arq, idade_, '\t');
                // Usa o fluxo de string para transformar string idade para valor Inteiro
                istringstream issIdade{idade_};
                //Transforma string to int
                issIdade >> idadeInt;
                getline(arq, corOlhos_, '\t');
                getline(arq, nomePai_, '\t');
                getline(arq, nomeMae_, '\n');

                if ((nome_ == nomePaiDigitado || nome_ == nomeMaeDigitado) && (idadeInt >= 18 && idadeInt <= 50)) {
                    Pessoa *filho = new Pessoa(nomePaiDigitado, sexo);
                }
            }
        } else {
            cout << "erro" << endl;
        }
    }
};

int main() {
    string arquivo = "DadosPessoas.txt";
    string nomePai, nomeMae, nomeFilho, sexoFilho;
    int idadeFilho, opcao;
    Arvore *arvore = new Arvore();

    while (1) {
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
