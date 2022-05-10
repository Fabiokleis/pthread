#include <iostream>
#include <pthread.h>
#include "thread.hpp"
using namespace std;

int main(void) {
    cout << "Digite ENTER para iniciar a thread...."  << endl;

    cin.get(); // aguarda um ENTER do user;
               //
    // inicia uma nova thread, passando como
    // parametro a thread e a funcao que se deseja
    // executar;
    pthread_create(&thread_1, NULL, tarefa_1, NULL);
    pthread_create(&thread_2, NULL, tarefa_2, NULL);

    // faz com que a thread principal espere a thread_1 e a thread_2 acabarem;
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);

    cout << endl << "Pressione ENTER para continuar..."  << endl;

    cin.get();
    
    return 0;
}
