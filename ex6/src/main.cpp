#include <iostream>
#include <pthread.h>
#include "thread.hpp"
using namespace std;

int main(void) {
    cout << "Digite ENTER para iniciar as threads...."  << endl;
    cin.get(); // aguarda um ENTER do user;
    
    for (int i = 0; i< NUM_THREADS; i++) {
        thread_ativa[i] = 0;
    }
    // inicializa semaforo
    sem_init(&meu_semaforo, 0, NUM_SEMAFORO);

    // inicia uma nova thread, passando como
    // parametro a thread e a funcao que deve executar
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&vt_thread[i], NULL, tarefa, (void*)&i);
        usleep(1000000);
    }

    monitorar(); // funcao que mostra as threads que estao ativas;
    
    sem_destroy(&meu_semaforo);
    cout << "Pressione ENTER para continuar...";
    cin.get();
    
    return 0;
}
