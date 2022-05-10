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
