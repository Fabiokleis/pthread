#include <iostream>
#include <string>
#include <pthread.h>                    // lib pthread;
#include <stdlib.h>
using namespace std;

#pragma once
class Thread {
    private:
        pthread_t _threadID;             // pthread - ponteiro;
        pthread_attr_t _tAttribute;     // informacoes sobre o funcionamento da thread;

    private:
        static void *runThread(void *pThread); // inicia a thread;
        virtual void run();             // metodo que executara;
        void printError(const string msg) const;
    public:
        Thread();
        virtual ~Thread();
        void start();                   
        void join();                    // espera a thread acabar;
        void yield();                   // libera o processador;
};
