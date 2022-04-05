#include "controller.h"
#include "queue.h"
#include "defs.h"

#ifndef _INPUT_INTERFACE
#define _INPUT_INTERFACE

class InputInterface: public Controller {

    private:
        Queue q;

    public:
        InputInterface();
        void rotate();
        void go_side(int n);
        void go_down(int n);
        void hard_drop();

        char get_command();

};

#endif
