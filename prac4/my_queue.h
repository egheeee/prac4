#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include "printer.h"

typedef struct Node {
    Printer* data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} Queue;

void enqueue(Queue* queue, Printer* data);
Printer* dequeue(Queue* queue);
void delete_queue(Queue* queue);

#endif // MY_QUEUE_H

