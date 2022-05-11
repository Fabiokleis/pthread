#ifndef CORREDOR_HPP_J9EPIDZH
#define CORREDOR_HPP_J9EPIDZH

#include <iostream>
#include <string>
#include "thread.hpp"

class Corredor : public Thread {
    private:
        string _nome;
        int _nVoltas;
        void run();

    public:
        Corredor(const int voltas = 0);
        ~Corredor();

        void setNome(const string nome);
        string getNome() const;
        void setVoltas(const int voltas);
        int getVoltas() const;
};

#endif /* end of include guard: CORREDOR_HPP_J9EPIDZH */
