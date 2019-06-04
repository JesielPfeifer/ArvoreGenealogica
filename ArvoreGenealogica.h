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
    TCorOlhos olhos;
//   Pessoa *pai;
//    Pessoa *mae;
public:
    Pessoa(){}
    ~Pessoa(){}
    Pessoa(string nome, TSexo sexo, int idade, TCorOlhos corOlhos, Pessoa *pai, Pessoa *mae){}
    Pessoa *geraPessoa(string nome, TSexo sexo, int idade, Pessoa *pai){}
    string getNome();
    string getSexoStr();
    string getCorOlhosStr();
    int getIdade();
    void setNome(string nome);
    void setSexo(TSexo sexo);
    void setCorOlhos(TCorOlhos olhos);
    void setIdade(int idade);
    void setPai(Pessoa *pai);
    void setMae(Pessoa *mae);
    Pessoa* getPai();
    Pessoa* getMae();
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

