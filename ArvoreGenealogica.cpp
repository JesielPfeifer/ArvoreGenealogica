#include "ArvoreGenealogica.h"

void Pessoa::setCorOlhos(Pessoa::olhos) {
    this->olhos=olhos;
}

string Pessoa::getCorOlhosStr() {
    int cor1;
    cin >> cor1;
    if(cor1 == coAzul) {
        return "Azul";
    } else if(cor1 == coCastanho) {
        return "Castanho";
    } else if(cor1 == coVerde) {
        return "Verde";
    } else {
        cout << "opcao invalida" << endl;
    }
}
