#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Pessoa
{
private:
    string nome;
    enum TSexo
    {
        sxMasculino, sxFeminino
    };
    TSexo sexo;
    int idade;
    enum TCorOlhos
    {
        coCastanho, coVerde, coAzul
    };
    TCorOlhos corOlhos;
    Pessoa *pai;
    Pessoa *mae;
public:
    Pessoa() {}

    ~Pessoa() {}

    Pessoa(string nome, TSexo sexo, int idade, TCorOlhos corOlhos, Pessoa *pai, Pessoa *mae)
    {
        this->nome = nome;
        this->idade = idade;
        this->sexo = sexo;
        this->pai = pai;
        this->mae = mae;
        this->corOlhos = corOlhos;
    }

    Pessoa *geraPessoa(string nome, TSexo sexo, int idade, Pessoa *pai)
    {
        srand(time(NULL));

        TCorOlhos cor;
        int valorRandom = rand() % 2 + 1;
        if ((this->getSexoStr() == "Feminino") && (pai->getSexoStr() == "Masculino"))
        {
            if ((this->getCorOlhosStr() == "Castanho") || (pai->getCorOlhosStr() == "Castanho"))
            {
                cor = (TCorOlhos) 0;
            }
            else if ((this->getCorOlhosStr() == "Verde") && (pai->getCorOlhosStr() == "Verde"))
            {
                cor = (TCorOlhos) 1;
            }
            else if ((this->getCorOlhosStr() == "Azul") && (pai->getCorOlhosStr() == "Azul"))
            {
                cor = (TCorOlhos) 2;
            }
            else
            {
                cor = (TCorOlhos) valorRandom;
            }
            Pessoa *filho = new Pessoa(nome, sexo, idade, cor, pai, this);
            return filho;
        }
        else
        {
            cout << "Membros nao podem se reproduzir" << endl;
            return NULL;
        }
    }

    string getNome()
    {
        return this->nome;
    }

    string getSexoStr()
    {
        string retorno="";
        if (this->sexo == 0)
        {
            retorno = "Masculino";
        }
        else
        {
            retorno = "Feminino";
        }
        return retorno;
    }

    char getSexoToChar()
    {
        char sexoChar;
        if (this->sexo == 0)
        {
            sexoChar = 'M';
        }
        else
        {
            sexoChar = 'F';
        }
        return sexoChar;
    }

    TSexo getSexo()
    {
        return this->sexo;
    }

    string getCorOlhosStr()
    {
        if (this->corOlhos == 0)
        {
            return "Castanho";
        }
        else if (this->corOlhos == 1)
        {
            return "Verde";
        }
        else
        {
            return "Azul";
        }
    }

    int getIdade()
    {
        return this->idade;
    }

    void setNome(string nome)
    {
        this->nome = nome;
    }

    void setSexo(TSexo sexo)
    {
        this->sexo = sexo;
    }

//Overcharge do setSexo() para fazer o mesmo funcionar recebendo
// inteiro e transformando brutalmente/hardcode/forçadamente
// em uma variável do tipo TSexo

    void setSexo(int sexoInt)
    {
        TSexo sexo = (TSexo) sexoInt;
        this->setSexo(sexo);
    }

    TSexo getSexoFilho(char sexo)
    {
        TSexo sex;
        if (sexo == 'M')
        {
            sex = (TSexo) 0;
        }
        else
        {
            sex = (TSexo) 1;
        }
        return sex;
    }

    void setCorOlhos(TCorOlhos corOlhos)
    {
        this->corOlhos = corOlhos;
    }

    void setCorOlhos(string corOlhosStr)
    {
        int cor;
        if (corOlhosStr == "Castanho")
        {
            cor = 0;
        }
        else if (corOlhosStr == "Verde")
        {
            cor = 1;
        }
        else if (corOlhosStr == "Azul")
        {
            cor = 2;
        }
        TCorOlhos corOlhos = (TCorOlhos) cor;
        this->setCorOlhos(corOlhos);
    }

    void setIdade(int idade)
    {
        this->idade = idade;
    }

    void setPai(Pessoa *pai)
    {
        this->pai = pai;
    }

    void setMae(Pessoa *mae)
    {
        this->mae = mae;
    }

    Pessoa *getPai()
    {
        return this->pai;
    }

    Pessoa *getMae()
    {
        return this->mae;
    }

    void imprimeDados()
    {

        cout << "Nome: " << this->getNome() << endl;
        cout << "Sexo: " << this->getSexoStr() << endl;
        cout << "Idade: " << this->getIdade() << endl;
        cout << "Cor dos Olhos: " << this->getCorOlhosStr() << endl;
        if (this->getPai())
        {
            cout << "Nome do pai: " << this->getPai()->getNome() << endl;
        }
        if (this->getMae())
        {
            cout << "Nome do mae: " << this->getMae()->getNome() << endl;
        }
    }

    string serialize()
    {
        ostringstream oss;
        oss << this->getNome() << '\t';
        oss << this->getSexoToChar() << '\t';
        oss << this->getIdade() << '\t';
        oss << this->getCorOlhosStr() << '\t';
        if(this->getPai()!= NULL)
        {
            oss << this->getPai()->getNome() << '\t';
        }
        if(this->getMae()!= NULL)
        {
            oss << this->getMae()->getNome();
        }
        return oss.str();
    }
};

class Arvore
{
private:
    vector<Pessoa *> pessoa;
public:
    void lerArquivo(string arquivo)
    {
        fstream arq;
        arq.open(arquivo.c_str(), fstream::in);
        string nome, corOlhos, nomeMae, nomePai, idade, sexo;
        int idadeInt, sexoInt;
        if (arq.is_open())
        {
            string s;
            getline(arq, s);
            if (s != "Nome\tSexo\tIdade\tOlhos\tPai\tMae\n")
            {
                while (!arq.eof())
                {
                    getline(arq, nome, '\t');
                    //if linha atual == 0 pula para proxima
                    getline(arq, sexo, '\t');
                    if (sexo=="M")
                    {
                        sexoInt = 0;
                    }
                    else
                    {
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
        }
        else
        {
            cout << "Erro ao abrir" << endl;
        }
    }

    void setDadosPessoas(string nome, int sexoInt, int idadeInt, string corOlhos, string nomePai,
                         string nomeMae)
    {
        Pessoa *objPessoa = new Pessoa();
        objPessoa->setNome(nome);
        objPessoa->setSexo(sexoInt);
        objPessoa->setIdade(idadeInt);
        objPessoa->setCorOlhos(corOlhos);
        if (nomePai != "")
        {
            for (int i = 0; i < pessoa.size(); i++)
            {
                if (pessoa[i]->getNome() == nomePai)
                {
                    objPessoa->setPai(pessoa[i]);
                }
            }
        }
        else
        {
            objPessoa->setPai(NULL);
        }
        if (nomeMae != "")
        {
            for (int i = 0; i < pessoa.size(); i++)
            {
                if (pessoa[i]->getNome() == nomeMae)
                {
                    objPessoa->setMae(pessoa[i]);
                }
            }
        }
        else
        {
            objPessoa->setMae(NULL);
        }
        pessoa.push_back(objPessoa);
    }

    string toCamelCase(string palavra)
    {
        char c;
        int i=0;
        string camelCase="";
        while (palavra[i])
        {
            c=palavra[i];
            if(i==0)
            {
                camelCase += toupper(c);
            }
            else
            {
                camelCase += tolower(c);
            }
            i++;
        }
        return camelCase;
    }
    char toCamelCase(char letra)
    {
        return toupper(letra);
    }

    string adicionaPessoa(string nomeP, string nomeM, string nomeF, char sexoF, int idadeFilho)
    {

        //nomep = toCamelCase(nomeP);
        nomeP = toCamelCase(nomeP);
        nomeM = toCamelCase(nomeM);
        nomeF = toCamelCase(nomeF);
        sexoF = toCamelCase(sexoF);

        string msg="";

        int pVector = parentVector(nomeP);
        int mVector = parentVector(nomeM);

        if (pVector < 0 || mVector < 0)
        {
            msg = "Pais nao estao no vector";
        }
        else
        {
            bool nomeRepetido = verificaNome(nomeF);
            bool idadePai = parentAge(pVector);
            bool idadeMae = parentAge(mVector);
            bool idadeValida = validateIdade(pVector, mVector, idadeFilho);
            if(!idadeValida)
            {
                msg = "Filho mais velho que os pais ou eles nao tinham a idade necessaria no momento de sua geracao.";
            }
            else if(!nomeRepetido)
            {
                msg = "Pessoa ja inserida no vector";
            }
            else if(idadeFilho<0)
            {
                msg = "Idade invalida para o filho";
            }
            else if (idadePai && idadeMae)
            {
                Pessoa *pai = pessoa[pVector];
                Pessoa *mae = pessoa[mVector];
                Pessoa *filho = mae->geraPessoa(nomeF, mae->getSexoFilho(sexoF), idadeFilho, pai);
                pessoa.push_back(filho);
                msg = "Filho "+nomeF+" gerado com sucesso";
            }
            else
            {
                msg = "Pais nao possuem idade necessaria para gerar um filho";
            }
        }

        return msg;
    }

    int parentVector(string nome)
    {
        int i = 0;
        for (vector<Pessoa *>::iterator it=pessoa.begin(); it != pessoa.end(); it++)
        {
            if((*it)->getNome() == nome)
            {
                return i;
            }
            i++;
        }
        return -1;
    }

    bool parentAge(int i)
    {
        bool ret = false;
        if (pessoa[i]->getIdade() >= 18 && pessoa[i]->getIdade() <= 50)
        {
            ret = true;
        }
        return ret;
    }

    bool verificaNome(string nome)
    {
        for (int i=0; i<pessoa.size(); i++)
        {
            if(pessoa[i]->getNome()==nome)
            {
                return false;
            }
        }
        return true;
    }

    bool validateIdade(int idxPai, int idxMae, int idadeFilho)
    {
        int pai = pessoa[idxPai]->getIdade()-idadeFilho;
        int mae = pessoa[idxMae]->getIdade()-idadeFilho;
        if( pai>= 18 &&  mae>= 18)
        {
            return true;
        }
        return false;
    }

    string getPessoaVector()
    {
        string s = "";
        for (int i = 0; i < pessoa.size(); i++)
        {
            s += pessoa[i]->getNome();
        }
        return s;
    }

    int getTotalPessoas()
    {
        return pessoa.size();
    }

    int totalSexo(string sexo)
    {
        int total=0;
        for(int i=0; i<pessoa.size(); i++)
        {
            if(pessoa[i]->getSexoStr() == sexo)
            {
                total++;
            }
        }
        return total;
    }

    int toPorcentagem(float p)
    {
        int porCent = 0;
        for (int i = 0; i <= 100; i += 5)
        {
            if (p < (i + 2.5))
            {
                porCent = i / 5;
                break;
            }
        }
        return porCent;
    }

    void toGrafico(int multi5)
    {
        for (int i = 0; i < 20; i++)
        {
            if (multi5 > i)
            {
                printf("=");
            }
            else
            {
                printf(".");
            }
        }
    }

    void graficoSexo()
    {
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

    void graficoIdade()
    {
        int total = getTotalPessoas();
        int zeroVinte = 0;
        int vUmCinquenta = 0;
        int cUmSetenta = 0;
        int maiorSetenta = 0;

        for (int i=0; i<total; i++)
        {
            int idade = this->pessoa[i]->getIdade();
            if ( idade >= 0 && idade <= 20 )
            {
                zeroVinte++;
            }
            else if ( idade > 20 && idade <= 50 )
            {
                vUmCinquenta++;
            }
            else if ( idade > 50 && idade <= 70 )
            {
                cUmSetenta++;
            }
            else
            {
                maiorSetenta++;
            }
        }

        float porcentZeroVinte = (100.0 * zeroVinte) / total;
        int pZeroVinte = toPorcentagem(porcentZeroVinte);

        float porcentVinteCiquenta = (100.0 * vUmCinquenta) / total;
        int pVinteCinquenta = toPorcentagem(porcentVinteCiquenta);

        float porcentCinquentaSetenta = (100.0 * cUmSetenta) / total;
        int pCinquentaSetenta = toPorcentagem(porcentCinquentaSetenta);

        float porcentSetenta = (100.0 * maiorSetenta) / total;
        int pSetenta = toPorcentagem(porcentSetenta);

        printf("[00,20]:\t%3d - \t%5.1f%% [", zeroVinte, porcentZeroVinte);
        toGrafico(pZeroVinte);
        printf("]\n");

        printf("[21,50]:\t%3d - \t%5.1f%% [", vUmCinquenta, porcentVinteCiquenta);
        toGrafico(pVinteCinquenta);
        printf("]\n");

        printf("[51,70]:\t%3d - \t%5.1f%% [", cUmSetenta, porcentCinquentaSetenta);
        toGrafico(pCinquentaSetenta);
        printf("]\n");

        printf("[71, >]:\t%3d - \t%5.1f%% [", maiorSetenta, porcentSetenta);
        toGrafico(pSetenta);
        printf("]\n");

    }

    void graficoOlhos()
    {
        int total = getTotalPessoas();

        int verde = 0;
        int castanho = 0;
        int azul = 0;

        for(int i=0; i<total; i++)
        {
            string cor = this->pessoa[i]->getCorOlhosStr();
            if (cor=="Castanho")
            {
                castanho++;
            }
            else if(cor=="Verde")
            {
                verde++;
            }
            else
            {
                azul++;
            }
        }

        float porcentCastanho = (100.0 * castanho) / total;
        int pCastanho = toPorcentagem(porcentCastanho);

        float porcentVerde = (100.0 * verde) / total;
        int pVerde = toPorcentagem(porcentVerde);

        float porcentAzul = (100.0 * azul) / total;
        int pAzul = toPorcentagem(porcentAzul);


        printf("Castanho:\t%3d - \t%5.1f%% [", castanho, porcentCastanho);
        toGrafico(pCastanho);
        printf("]\n");

        printf("Verde:\t\t%3d - \t%5.1f%% [", verde, porcentVerde);
        toGrafico(pVerde);
        printf("]\n");

        printf("Azul:\t\t%3d - \t%5.1f%% [", azul, porcentAzul);
        toGrafico(pAzul);
        printf("]\n");
    }


    //falta mostrar conje
    void consultaPessoa(string nomeDigitado)
    {
        nomeDigitado = toCamelCase(nomeDigitado);
        Pessoa *p = NULL;
        cout << endl;
        for (int i = 0; i < pessoa.size(); i++)
        {
            if (nomeDigitado == pessoa[i]->getNome())
            {
                p = pessoa[i];
            }
        }
        if (p != NULL)
        {
            p->imprimeDados();
            cout<<endl;
        }
        else
        {
            cout << "A pessoa nao esta no vector" << endl;
        }
    }

    void consultaFamilia(string nomeDigitado)
    {
        nomeDigitado= toCamelCase(nomeDigitado);
        Pessoa *progenitor = NULL;
        Pessoa *conjuge = NULL;

        for (int i = 0; i < pessoa.size(); i++)
        {
            if (nomeDigitado == pessoa[i]->getNome())
            {
                progenitor = pessoa[i];
            }
        }
        if (progenitor != NULL)
        {
            cout << "\nDados da pessoa consultada:" << endl;
            cout << "---------------------------" << endl;
            progenitor->imprimeDados();
            cout << "---------------------------" << endl;
            cout<<endl;

            for (int i = 0; i < pessoa.size(); i++)
            {
                if(pessoa[i]->getMae() != NULL && pessoa[i]->getPai() != NULL)
                {
                    if (pessoa[i]->getMae()->getNome()== nomeDigitado)
                    {
                        conjuge = pessoa[i]->getPai();
                    }
                    else if(pessoa[i]->getPai()->getNome() == nomeDigitado)
                    {
                        conjuge = pessoa[i]->getMae();
                    }
                }
            }
            if(conjuge != NULL)
            {
                cout << "Dados do conjuge:" << endl;
                cout << "---------------------------" << endl;
                conjuge->imprimeDados();
                cout << "---------------------------" << endl;
                cout<<endl;
            }

            for (int i = 0; i < pessoa.size(); i++)
            {

                if(pessoa[i]->getMae() != NULL)
                {
                    if (pessoa[i]->getMae()->getNome()== nomeDigitado)
                    {
                        cout << "Dados do(a) filho(a):" << endl;
                        cout << "---------------------------" << endl;
                        pessoa[i]->imprimeDados();
                        cout << "---------------------------" << endl;
                        cout << endl;
                    }
                }
                if(pessoa[i]->getPai() != NULL)
                {
                    if (pessoa[i]->getPai()->getNome()== nomeDigitado)
                    {
                        cout << "Dados do(a) filho(a):" << endl;
                        cout << "---------------------------" << endl;
                        pessoa[i]->imprimeDados();
                        cout << "---------------------------" << endl;
                        cout << endl;
                    }
                }
            }
        }
        else
        {
            cout << "Nao encontrado." << endl;
        }
    }

    void salvaArquivo()
    {
        fstream arq;
        string novArquivo;
        cout << endl;
        cout << "Digite o novo nome do arquivo para salvar os dados: " << endl;
        cin >> novArquivo;
        novArquivo = novArquivo + ".txt";
        arq.open(novArquivo.c_str(), fstream::out);
        if (arq.is_open())
        {
            cout << "Salvando arquivo no banco de dados" << endl;
            arq << "Nome\tSexo\tIdade\tOlhos\tPai\tMae\n";
            for (int i = 0; i < pessoa.size(); i++)
            {
                string linha = pessoa[i]->serialize();
                arq << linha << endl;
            }
            cout << "Arquivos foram salvos." << endl;
        }
    }

    void removePessoa(string nomeDigitado)
    {
        int flag = 0;

        nomeDigitado = toCamelCase(nomeDigitado);
        for( int i=0; i<pessoa.size(); i++)
        {
            if( pessoa[i]->getNome() == nomeDigitado)
            {
                pessoa.erase(pessoa.begin()+i);
                cout << "Pessoa " << nomeDigitado << " removida com sucesso" << endl;
                flag = 1;
            }

        }
        if(flag == 0)
        {
            cout << "Pessoa digitada nao esta no vector" << endl;
        }
        for(int i=0; i<pessoa.size(); i++)
        {
            if (pessoa[i]->getPai() != NULL)
            {
                if(nomeDigitado == pessoa[i]->getPai()->getNome())
                {
                    pessoa[i]->setPai(NULL);
                }
            }
        }
        for(int i=0; i<pessoa.size(); i++)
        {
            if (pessoa[i]->getMae() != NULL)
            {
                if(nomeDigitado == pessoa[i]->getMae()->getNome())
                {
                    pessoa[i]->setMae(NULL);
                }
            }
        }
    }



    void alteraCaracteristica (string nomeDigitado)
    {

        nomeDigitado = toCamelCase(nomeDigitado);
        int num, novIdade, sexo;
        char novSexo;
        string novCorOlhos;
        string novNome;

        Pessoa *p = NULL;
        cout << endl;
        for (int i = 0; i < pessoa.size(); i++)
        {
            if (nomeDigitado == pessoa[i]->getNome())
            {
                p = pessoa[i];
            }
        }

        if(p != NULL)
        {

            for (int i=0; i<pessoa.size(); i++)
            {
                if (nomeDigitado == pessoa[i]->getNome())
                {


                    cout << "1 - Nome" << endl;
                    cout << "2 - Sexo" << endl;
                    cout << "3 - Cor dos olhos" << endl;
                    cout << "4 - Idade" << endl;
                    cout << "Digite o numero da  caracteristica que deseja modificar:";
                    cin >> num;

                    switch(num)
                    {
                    case 1:
                        cout << "Digite o novo nome: ";
                        cin >> novNome;
                        novNome = toCamelCase(novNome);
                        pessoa[i]->setNome(novNome);
                        cout << nomeDigitado << " agora eh conhecido como " << novNome << "." << endl;
                        break;

                    case 2:
                        while(novSexo!='M' && novSexo!='F')
                        {
                            cout << "Informe o novo sexo ('M' ou 'F'): ";
                            cin >> novSexo;
                            novSexo = toCamelCase(novSexo);
                            if (novSexo!='M' && novSexo!='F')
                            {
                                cout << "Opcao invalida"<<endl;
                            }
                        }
                        if (novSexo=='M')
                        {
                            sexo = 0;
                        }
                        else
                        {
                            sexo = 1;
                        }
                        pessoa[i]->setSexo(sexo);
                        cout << nomeDigitado << " agora eh " << novSexo << "." << endl;
                        break;

                    case 3:
                        cout << "Digite a nova cor dos olhos(Castanho,Verde,Azul): ";
                        cin >> novCorOlhos;
                        novCorOlhos = toCamelCase(novCorOlhos);
                        pessoa[i]->setCorOlhos(novCorOlhos);
                        cout << nomeDigitado << " agora possui olhos de cor " << novCorOlhos << "." << endl;
                        break;

                    case 4:
                        cout << "Digite a nova idade da pessoa: ";
                        cin >> novIdade;
                        pessoa[i]->setIdade(novIdade);
                        cout << nomeDigitado << " trocou de idade e agora tem " << novIdade << " anos." << endl;
                        break;
                    default:
                        cout << "Opcao invalida" << endl;
                    }
                }

            }
        }
        else
        {
            cout << "Pessoa nao esta no vector" << endl;
        }

    }

};

int main()
{
    string arquivo = "DadosPessoas.txt";
    string nomePai, nomeMae, nomeFilho, nomeParent, nomeDig;
    char sexoFilho;
    int idadeFilho, opcao, flag = 0;
    Arvore *arvore = new Arvore();
    arvore->lerArquivo(arquivo);
    while (1)
    {
        system("cls");
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
        switch (opcao)
        {
        case 1:
            flag = 1;
            cout << "================PREENCHA OS DADOS=================" << endl;
            cout << "\n";
            cout << "Informe o nome do pai: ";
            cin >> nomePai;
            cout << "Informe o nome da mae: ";
            cin >> nomeMae;
            cout << "Informe o nome do filho: ";
            cin >> nomeFilho;
            while(sexoFilho!='M' && sexoFilho!='F')
            {
                cout << "Informe o sexo do filho ('M' ou 'F'): ";
                cin >> sexoFilho;
                sexoFilho = arvore->toCamelCase(sexoFilho);
                if (sexoFilho!='M' && sexoFilho!='F')
                {
                    cout << "Opcao invalida"<<endl;
                }
            }
            cout << "Informe a idade do filho: ";
            cin >> idadeFilho;
            cout << arvore->adicionaPessoa(nomePai, nomeMae, nomeFilho, sexoFilho, idadeFilho) << endl;
            cout << "===============================================" << endl;
            system("PAUSE");
            break;
        case 2:
            flag = 1;
            cout << "================REMOVER PESSOA=================" << endl;
            cout << "Escreva o nome da pessoa que deseja remover do vector: ";
            cin >> nomeDig;
            arvore->removePessoa(nomeDig);
            cout << "===============================================" << endl;
            system("PAUSE");
            break;
        case 3:
            flag = 1;
            cout << "================EDITAR PESSOA==================" << endl;
            cout << "Digite o nome da pessoa que desejesa modificar: ";
            cin >> nomeDig;
            arvore->alteraCaracteristica(nomeDig);
            cout << "===============================================" << endl;
            system("PAUSE");
            break;
        case 4:
            cout << "================CONSULTAR PESSOA===============" << endl;
            cout << "Digite o nome da pessoa que deseja ver as caracteristicas: ";
            cin >> nomeDig;
            arvore->consultaPessoa(nomeDig);
            cout << "===============================================" << endl;
            system("PAUSE");
            break;
        case 5:
            cout << "===========CONSULTA DADOS DA FAMILIA===========" << endl;
            cout << '\n';
            cout << "Digite o nome do marido ou da esposa pra consultar os dados da familia: ";
            cin >> nomeParent;
            arvore->consultaFamilia(nomeParent);
            cout << "===============================================" << endl;
            system("PAUSE");
            break;
        case 6:
            cout << "==================ESTATISTICAS=================" << endl;
            cout << '\n';
            cout << "SEXO" << endl;
            arvore->graficoSexo();
            cout<<endl;
            cout << "IDADE" << endl;
            arvore->graficoIdade();
            cout<<endl;
            cout << "COR DOS OLHOS" << endl;
            arvore->graficoOlhos();
            cout << "===============================================" << endl;
            system("PAUSE");
            break;
        case 7:
            flag = 0;
            cout << "====SALVA NOVOS DADOS DA ARVORE GENEALOGICA====" << endl;
            cout << '\n';
            arvore->salvaArquivo();
            cout << "===============================================" << endl;
            system("PAUSE");
            break;
        case 8:
            cout << "=======================ENCERRAR PROGRAMA========================" << endl;
            if(flag == 1)
            {
                cout << "Dados do arquivo sofreram mudancas e nao foram salvas, para encerrrar o programa";
                cout << " salve o arquivo antes de fechar." << endl;
                arvore->salvaArquivo();
                flag = 0;
            }
            else
            {
                return 0;
            }
            cout << "================================================================" << endl;
            break;
        default:
            cout << "Opcao invalida" << endl;
            break;

        }
    }
}
