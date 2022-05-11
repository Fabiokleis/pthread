#include <iostream>
#include "minhaT.hpp"
using namespace std;

int main(void) {
    cout << "Digite ENTER para iniciar e parar a thread...."  << endl;
    cin.get(); // aguarda um ENTER do user;
    MinhaT *t = new MinhaT();
    t->start();
    t->yield();
    t->join();

    cout << endl << "Oi! Eu sou a thread principal." << endl;

    cout << "Pressione ENTER para continuar..." << endl;
    cin.get();
    delete t;
    return 0;
}
