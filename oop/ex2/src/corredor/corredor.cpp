#include "corredor.hpp"
#include "principal.hpp"

Corredor::Corredor(const int voltas) {
    setVoltas(voltas);
}

void Corredor::setVoltas(const int voltas) {
    _nVoltas = voltas;
}

void Corredor::setNome(const string nome) {
    _nome = nome;
}

string Corredor::getNome() const {
    return _nome;
}

Corredor::~Corredor() {}

// redefinicao do metodo virtual de Thread;
void Corredor::run() {
    for (int i = 0; i < _nVoltas; i++) {
        if (i % 10 == 0) {
            yield(); // irmaos sendo generosos;
        }
    }
    // mutex na mao
    while(true) {
        if (!Principal::consoleOcupado) {
            Principal::consoleOcupado = true;
            cout << getNome() << " chegou!" << endl;
            Principal::consoleOcupado = false;
            break;
        }
    }
}
