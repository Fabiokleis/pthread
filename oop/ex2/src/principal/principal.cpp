#include "principal.hpp"

bool Principal::consoleOcupado = false;

Principal::Principal() {}
Principal::~Principal() {}

void Principal::executar() {
    c1.setNome("Ralf Schumacher");
    c1.setVoltas(100);

    c2.setNome("Michael Schumacher");
    c2.setVoltas(100);

    cout << "Inicio da corrida..." << endl << endl;
    c1.start();
    c2.start();
    
    c1.join();
    c2.join();
}
