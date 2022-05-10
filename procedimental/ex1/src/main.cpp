#include <iostream>
#include "thread.hpp"
using namespace std;

int main(void) {
    cout << "Digite ENTER para iniciar e parar a thread...."  << endl;

    cin.get(); // aguarda um ENTER do user;
    thread_ligada = true;

    // inicia uma nova thread, passando como
    // parametro a thread e a funcao que se deseja
    // executar;
    
    pthread_create(&minha_thread, NULL, escreve_algo, NULL);

    cout << "Digite ENTER para finalizar...." << endl;

    cin.get();

    thread_ligada = false;
    
    return 0;
}
