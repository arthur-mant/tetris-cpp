#include "controller.h"
#include "defs.h"

#ifndef _KEYBOARD_INPUT
#define _KEYBOARD_INPUT

class KeyboardInput: public Controller {

    public:
        char get_command();

};
#endif
