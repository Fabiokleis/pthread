#include "principal.hpp"

Principal::Principal() : c1(100), c2(100) {}
Principal::~Principal() {}

void Principal::executar() {
    c1.setNome("Michael");
    c2.setNome("Ralf");
    c1.start();
    c2.start();
    c1.join();
    c2.join();
}
