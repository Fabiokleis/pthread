#include <iostream>
#include <pthread.h>
#include "thread.hpp"
using namespace std;

int main(void) {
    struct limite limite_1, limite_2;
    pthread_t thd1, thd2;
    pthread_mutex_init(&meu_mutex, NULL);      
    limite_1.baixo = 0;
    limite_1.alto = 1000;
    pthread_create(&thd1, NULL, encontre_primos, &limite_1);
    limite_2.baixo = 1000;
    limite_2.alto = 2000;
    pthread_create(&thd2, NULL, encontre_primos, &limite_2);
    pthread_join(thd1, NULL);
    pthread_join(thd2, NULL);
    pthread_mutex_destroy(&meu_mutex);

    cin.get();
    return 0;
}
