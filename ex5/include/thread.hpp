#include <iostream>
#include <pthread.h>
#include <semaphore.h>
using namespace std;

pthread_t thread_1;
pthread_t thread_2;
sem_t meu_semaforo;


// funcao passada para thread_1;
void *tarefa_1(void *p) {
    // REGIAO CRITICA
    sem_wait(&meu_semaforo);
    string s = "123456";
    for (auto& c : s) {
        cout << c;
    }
    sem_post(&meu_semaforo);
    pthread_exit(&thread_1);
}

// funcao passada para a thread_2;
void *tarefa_2(void *p) {
    // REGIAO CRITICA
    sem_wait(&meu_semaforo);
    string s = "ABCDEF";
    for (auto& c : s) {
        cout << c;
    }
    sem_post(&meu_semaforo);
    pthread_exit(&thread_2);
}
