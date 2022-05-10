#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

#define NUM_THREADS 5 
#define NUM_SEMAFORO 3

pthread_t vt_thread[NUM_THREADS];
int thread_ativa[NUM_THREADS];

sem_t meu_semaforo; // objeto de semaforo;

// funcao passada para as threads;
void *tarefa(void *p) {

    // recupera o id da thread;
    int *valor = static_cast<int*>(p);
    int id = *valor;

    // REGIAO CRITICA
    sem_wait(&meu_semaforo);
    for (int i = 0; i < 5; i++) {
        thread_ativa[id] = 1;

        // marca a thread como ativa e aguarda
        // ate ser desmarcada pela thread principal;
        while (1 == thread_ativa[id]) {
            usleep(1000000);
        }
    }
    thread_ativa[id] = -1; // informa a thread principal que ja acabou o seu trabalho;
    sem_post(&meu_semaforo);
}

void monitorar() {
    for (int i = 0; i < NUM_THREADS; i++) {
        cout << "Thread " << i << "\t";
    }
    cout << endl;

    bool threads_executando;

    do {
        // verifica se há pelo menos 1 thread executando;
        threads_executando = false;

        for (int i = 0; i < NUM_THREADS; i++) {
            if (-1 != thread_ativa[i]) {
                threads_executando = true;
            }
        }

        if (threads_executando) {
            // imprime no console as threads que estão executando e que estao ativas
            // ou seja, estao com acesso ao semaforo;
            for (int i = 0; i < NUM_THREADS; i++) {
                if (1 == thread_ativa[i]) {
                    cout << "|";
                    thread_ativa[i] = 0;
                }
                cout << "\t\t";
            }
            cout << endl;
            usleep(5000000);
        }
    } while (threads_executando);
}


