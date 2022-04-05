#include "queue.h"

Queue::Queue() {
    head = tail = 0;
}

bool Queue::empty() {
    return (this->head == this->tail);
}

bool Queue::full() {
    return ((this->tail+1)%QUEUE_SIZE == this->head);
}

int Queue::get_size() {
    if (this->tail >= this->head)
        return (this->tail - this->head);
    else
        return (QUEUE_SIZE + this->tail - this->head);
}

void Queue::push(char c) {
    if (!this->full()) {
        this->q[this->tail] = c;
        this->tail = (this->tail+1)%QUEUE_SIZE;
    }
    else
        fprintf(stderr, "ERROR PUSHING INTO QUEUE: QUEUE IS FULL\n");
}
char Queue::pop() {

    if (!this->empty()) {
        char c = this->q[this->head];
        this->head = (this->head + 1)%QUEUE_SIZE;
    }
    else
        fprintf(stderr, "ERROR POPPING FROM QUEUE: QUEUE IS EMPTY\n");
}
