#include <iostream>
#include <pthread.h>
using namespace std;

bool thread_ligada = true;

pthread_t minha_thread;

// funcao passada como parametro para nova thread;
void *escreve_algo(void *p) {
    while (thread_ligada) {
        cout << "Executando thread...." << endl;
    }


    // termina a thread
    pthread_exit(&minha_thread);
}
