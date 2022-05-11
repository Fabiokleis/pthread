#include "thread.hpp"
#include <pthread.h>
#include <sched.h>

Thread::Thread() {}
Thread::~Thread() {}
void Thread::run() {} // deve ser redefinido;
void Thread::yield() {
    sched_yield();
}

void Thread::start() {
    // inicia attr;
    int status = pthread_attr_init(&_tAttribute);
    status = pthread_attr_setscope(&_tAttribute, PTHREAD_SCOPE_SYSTEM);

    if (status != 0) {
        printError("falha ao iniciar atributo da thread.");
    }

    // cria uma Thread;
    status = pthread_create(&_threadID, &_tAttribute, Thread::runThread, (void*)this);
    if (status != 0) {
        printError("falha ao iniciar a thread.");
    }
    // destroi o attr;
    status = pthread_attr_destroy(&_tAttribute);
    if (status != 0) {
        printError("falha ao destruir o atributo da thread.");
    }
}

void Thread::join() {
    int status = pthread_join(_threadID, NULL);
    if (status != 0) {
        printError("comando join falhou.");
    }
}

void *Thread::runThread(void* pThread) {
    Thread* sThread = static_cast<Thread*>(pThread);

    if (NULL == sThread) {
        cout << "thread falhou." << endl;
    } else {
        sThread->run(); // executa a thread;
    }
//    pthread_exit(NULL);
}

void Thread::printError(const string msg) const {
    cout << "Erro: " << msg << endl;
}
