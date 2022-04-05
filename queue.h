#include "defs.h"

#ifndef _QUEUE
#define _QUEUE

#define QUEUE_SIZE 128

class Queue {

    private:
        char q[QUEUE_SIZE];
        int head, tail;

    public:
        Queue():
        bool empty();
        bool full();
        int get_size();
        void push(char c);
        char pop();

#endif
