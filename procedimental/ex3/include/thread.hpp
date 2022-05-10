#include <iostream>
#include <pthread.h>
using namespace std;

pthread_t thread_1;
pthread_t thread_2;
pthread_mutex_t meu_mutex;

// funcao passada para thread_1;
void *tarefa_1(void *p) {
    // REGIAO CRITICA
    pthread_mutex_lock(&meu_mutex);
    string s = "123456";
    for (auto& c : s) {
        cout << c;
    }
    pthread_mutex_unlock(&meu_mutex);
    pthread_exit(&thread_1);
}

// funcao passada para a thread_2;
void *tarefa_2(void *p) {
    // REGIAO CRITICA
    pthread_mutex_lock(&meu_mutex);

    string s = "ABCDEF";
    for (auto& c : s) {
        cout << c;
    }
    pthread_mutex_unlock(&meu_mutex);
    pthread_exit(&thread_2);

}
