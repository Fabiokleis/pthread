#include <iostream>
#include "corredor.hpp"
using namespace std;

#ifndef PRINCIPAL_HPP_OMEITQWG
#define PRINCIPAL_HPP_OMEITQWG

class Principal {
    private:
        bool consoleOcupado;
        Corredor c1;
        Corredor c2;
    public:
        Principal();
        ~Principal();
        void executar();

};
#endif /* end of include guard: PRINCIPAL_HPP_OMEITQWG */
