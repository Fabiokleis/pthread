#include <iostream>
#include "principal.hpp"
using namespace std;

int main() { 
    cout << "Digite ENTER para iniciar e terminar a thread..." << endl;
    cin.get();

    Principal *p = new Principal();

    p->executar();
    cout << endl << "Oi! Eu sou a thread principal." << endl;

    cout << "Pressione ENTER para continuar..." << endl;
    cin.get();

    delete p;
    return 0;
}
