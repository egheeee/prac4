#include <stdlib.h>
#include "my_queue.h"

void enqueue(Queue* queue, Printer* data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = queue->head;
    new_node->prev = NULL;

    if (queue->head) {
        queue->head->prev = new_node;
    }
    queue->head = new_node;
    if (!queue->tail) {
        queue->tail = new_node;
    }
}

Printer* dequeue(Queue* queue) {
    if (!queue->tail) {
        return NULL;
    }

    Node* node_to_remove = queue->tail;
    Printer* data = node_to_remove->data;
    queue->tail = node_to_remove->prev;

    if (queue->tail) {
        queue->tail->next = NULL;
    }
    else {
        queue->head = NULL;
    }
    free(node_to_remove);
    return data;
}

void delete_queue(Queue* queue) {
    while (queue->head) {
        Printer* data = dequeue(queue);
        free(data);
    }
}
