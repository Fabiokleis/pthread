#include <iostream>
#include <pthread.h>
using namespace std;

struct limite {
    int baixo;
    int alto;
};


pthread_t thread_1;
pthread_t thread_2;
pthread_mutex_t meu_mutex;


void *encontre_primos(void *param) {
    struct limite *aux;
    aux = (struct limite *) param;
    int n, k;
    int primo;

    for (n = aux->baixo; n <= aux->alto; n++) {
        primo = 1;
        for (k = 2; k < n; k++) {
            if ((n % k) == 0) {
                primo = 0;
                break;
            }
        }

        if (primo) {
            pthread_mutex_lock(&meu_mutex);
            printf(" %u ", n);
            printf("\n");
            pthread_mutex_unlock(&meu_mutex);
        }
    }
}

// funcao passada para thread_1;
void *tarefa_1(void *p) {
    // REGIAO CRITICA
    pthread_mutex_lock(&meu_mutex);
    string s = "123456";
    for (auto& c : s) {
        cout << c;
    }
    pthread_mutex_unlock(&meu_mutex);
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
}
