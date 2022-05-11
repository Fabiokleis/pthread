#ifndef MINHAT_HPP_QEYU7W4P
#define MINHAT_HPP_QEYU7W4P

#include "thread.hpp"

// class derivda de thread;
class MinhaT : public Thread {
    public:
        MinhaT() {}
        ~MinhaT() {}

        void run() {
            for (int i = 0; i < 10; i++) {
                cout << i+1 << " Oi!" << endl;
            }
        }
};

#endif /* end of include guard: MINHAT_HPP_QEYU7W4P */
