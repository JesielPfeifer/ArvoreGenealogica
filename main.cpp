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

        TCorOlhos cor;
        int valorRandom = rand() % 2 + 1;
        if ((this->getSexoStr() == "Feminino") && (pai->getSexoStr() == "Masculino")) {
            if ((this->getCorOlhosStr() == "Castanho") || (pai->getCorOlhosStr() == "Castanho")) {
                cor = (TCorOlhos) 0;
            } else if ((this->getCorOlhosStr() == "Verde") && (pai->getCorOlhosStr() == "Verde")) {
                cor = (TCorOlhos) 1;
            } else if ((this->getCorOlhosStr() == "Azul") && (pai->getCorOlhosStr() == "Azul")) {
                cor = (TCorOlhos) 2;
            } else {
                cor = (TCorOlhos) valorRandom;
            }
            Pessoa *filho = new Pessoa(nome, sexo, idade, cor, pai, this);
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
        } else {
            return "Feminino";
        }
    }

    string getCorOlhosStr() {
        if (this->corOlhos == 0) {
            return "Castanho";
        } else if (this->corOlhos == 1) {
            return "Verde";
        } else {
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

//Overcharge do setSexo() para fazer o mesmo funcionar recebendo
// inteiro e transformando brutalmente/hardcode/forçadamente
// em uma variável do tipo TSexo

    void setSexo(int sexoInt) {
        TSexo sexo = (TSexo) sexoInt;
        this->setSexo(sexo);
    }

    TSexo getSexoFilho(string sexo) {
        TSexo sex;
        if (sexo == "Masculino") {
            sex = (TSexo) 0;
        } else {
            sex = (TSexo) 1;
        }
        return sex;
    }

    void setCorOlhos(TCorOlhos corOlhos) {
        this->corOlhos = corOlhos;
    }

    void setCorOlhos(string corOlhosStr) {
        int cor;
        if (corOlhosStr == "Castanho") {
            cor = 0;
        } else if (corOlhosStr == "Verde") {
            cor = 1;
        } else if (corOlhosStr == "Azul") {
            cor = 2;
        }
        TCorOlhos corOlhos = (TCorOlhos) cor;
        this->setCorOlhos(corOlhos);
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

    void imprimeDados() {
        cout << "Nome do pai: " << pai->getNome() << endl;
        cout << "Nome da mae: " << mae->getNome() << endl;
        cout << "Nome do filho: " << this->getNome() << endl;
        cout << "Cor dos olhos: " << this->getCorOlhosStr() << endl;
        cout << "Sexo: " << this->getSexoStr();
    }

    string serializaPessoa();
};

class Arvore {
private:
    vector<Pessoa *> pessoa;
public:
    void lerArquivo(string arquivo) {
        fstream arq;
        arq.open(arquivo.c_str(), fstream::in);
        string nome, corOlhos, nomeMae, nomePai, idade, sexo;
        int idadeInt, sexoInt;
        if (arq.is_open()) {
            string s;
            getline(arq, s);
            if (s != "Nome\tSexo\tIdade\tOlhos\tPai\tMae\n") {
                while (!arq.eof()) {
                    getline(arq, nome, '\t');
                    //if linha atual == 0 pula para proxima
                    getline(arq, sexo, '\t');
                    if (sexo=="M"){
                        sexoInt = 0;
                    } else {
                        sexoInt = 1;
                    }
                    getline(arq, idade, '\t');
                    // Usa o fluxo de string para transformar string idade para valor Inteiro
                    istringstream issIdade{idade};
                    //Transforma string to int
                    issIdade >> idadeInt;
                    getline(arq, corOlhos, '\t');
                    getline(arq, nomePai, '\t');
                    getline(arq, nomeMae, '\n');
                    setDadosPessoas(nome, sexoInt, idadeInt, corOlhos, nomePai, nomeMae);
                }
            }
        } else {
            cout << "Erro ao abrir" << endl;
        }
    }

    void setDadosPessoas(string nome, int sexoInt, int idadeInt, string corOlhos, string nomePai,
                         string nomeMae) {
        Pessoa *objPessoa = new Pessoa();
        objPessoa->setNome(nome);
        objPessoa->setSexo(sexoInt);
        objPessoa->setIdade(idadeInt);
        objPessoa->setCorOlhos(corOlhos);
        if (nomePai != "") {
            for (int i = 0; i < pessoa.size(); i++) {
                if (pessoa[i]->getNome() == nomePai) {
                    objPessoa->setPai(pessoa[i]);
                } else {
                    break;
                }
            }
        }
        if (nomeMae != "") {
            for (int i = 0; i < pessoa.size(); i++) {
                if (pessoa[i]->getNome() == nomeMae) {
                    objPessoa->setMae(pessoa[i]);
                } else {
                    break;
                }
            }
        }
        pessoa.push_back(objPessoa);
    }

    string adicionaPessoa(string nomeP, string nomeM, string nomeF, string sexoF, int idadeFilho) {

        string msg="";

        int pVector = ParentVector(nomeP);
        int mVector = ParentVector(nomeM);

        if (pVector < 0 || mVector < 0) {
            msg = "Pais nao estao no vector";
        } else {
            bool idadePai = ParentAge(pVector);
            bool idadeMae = ParentAge(mVector);

            if (idadePai && idadeMae) {
                Pessoa *pai = pessoa[pVector];
                Pessoa *mae = pessoa[mVector];
                cout<<mae->getSexoFilho(sexoF)<<endl;

                pessoa.push_back(mae->geraPessoa(nomeF, mae->getSexoFilho(sexoF), idadeFilho, pai));
                msg = "Filho "+nomeF+" gerado com sucesso";
            } else {
                msg = "Pais nao possuem idade necessaria para gerar um filho";
            }
        }

        return msg;
    }

    int ParentVector(string nome) {
        for (int i = 0; i < pessoa.size(); i++) {
            if (pessoa[i]->getNome() == nome) {
                return i;
            }
        }
        return -1;
    }

    bool ParentAge(int i) {
        bool ret = false;
        if (pessoa[i]->getIdade() >= 18 && pessoa[i]->getIdade() <= 50) {
            ret = true;
        }
        return ret;
    }

    string getPessoaVector() {
        string s = "";
        for (int i = 0; i < pessoa.size(); i++) {
            s += pessoa[i]->getNome();
        }
        return s;
    }

    int getTotalPessoas() {
        return pessoa.size();
    }

    int totalSexo(string sexo) {
        int total=0;
        for(int i=0; i<pessoa.size(); i++) {
            cout<<pessoa[i]->getSexoStr()<<endl;
            if(pessoa[i]->getSexoStr() == sexo) {
                total++;
            }
        }
        return total;
    }

    int toPorcentagem(float p) {
        int porCent = 0;
        for (int i = 0; i <= 100; i += 5) {
            if (p < (i + 2.5)) {
                porCent = i / 5;
                break;
            }
        }
        return porCent;
    }

    void toGrafico(int multi5) {
        for (int i = 0; i < 20; i++) {
            if (multi5 > i) {
                printf("=");
            } else {
                printf(".");
            }
        }
    }

    void graficoSexo() {
        int tMasc = totalSexo("Masculino");
        int tFem  = totalSexo("Feminino");
        int total = getTotalPessoas();

        float porcentMasc = (100.0 * tMasc) / total;
        int pMasc = toPorcentagem(porcentMasc);

        float porcentFem = (100.0 * tFem) / total;
        int pFem = toPorcentagem(porcentFem);

        printf("Homens:\t\t%3d - \t%5.1f%% [", tMasc, porcentMasc);
        toGrafico(pMasc);
        printf("]\n");
        printf("Mulheres:\t%3d - \t%5.1f%% [", tFem, porcentFem);
        toGrafico(pFem);
        printf("]\n");

    }

    void graficoIdade(){
    }

    void graficoOlhos(){
    }
};

int main() {
    string arquivo = "DadosPessoas.txt";
    string nomePai, nomeMae, nomeFilho, sexoFilho;
    int idadeFilho, opcao;
    Arvore *arvore = new Arvore();
    arvore->lerArquivo(arquivo);
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
        system("cls");
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
            cout << arvore->adicionaPessoa(nomePai, nomeMae, nomeFilho, sexoFilho, idadeFilho) << endl;
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

            arvore->graficoSexo();
            arvore->graficoIdade();
            arvore->graficoOlhos();

            system("PAUSE");

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
