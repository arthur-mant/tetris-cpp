
        InputInterface();
        void rotate();
        void go_side(int n);
        void go_down(int n);
        void hard_drop();

        char get_command();

#include "input_interface.h"

InputInterface::InputInterface() {

    this->q = new Queue();

}

void rotate(int n) {
    if (n <= 0)
        fprintf(stderr, "ERROR: invalid rotation number %d\n", n);
    for (int i=0; i<n; i++)
        this->q->push('U');
}
void go_side(int n) {
    if (n == 0)
        fprintf(stderr, "ERROR: invalid sideways movement number %d\n", n);
    if (n > 0) {
        for (int i=0; i<n; i++)
            this->q->push('R');
    }
    if (n < 0) {
        for (int i=0; i>n; i--)
            this->q->push('L');
    }

}
void go_down(int n) {
    if (n <= 0)
        fprintf(stderr, "ERROR: invalid down movement number %d\n", n);
    for (int i=0; i<n; i++)
        this->q->push('D');

}
void hard_drop() {
    this->q->push('H');
}
char get_command() {
    return this->q->pop();
}

void send_game(Game game) {

}
