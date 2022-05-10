#include <iostream>
#include <pthread.h>
using namespace std;

pthread_t thread_1;
pthread_t thread_2;

// funcao passada para thread_1;
void *tarefa_1(void *p) {
    // REGIAO CRITICA
    string s = "123456";
    for (auto& c : s) {
        cout << c;
    }
    pthread_exit(&thread_1);
}

// funcao passada para a thread_2;
void *tarefa_2(void *p) {
    // REGIAO CRITICA
    string s = "ABCDEF";
    for (auto& c : s) {
        cout << c;
    }
    pthread_exit(&thread_2);
}
