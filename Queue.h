#ifndef _Queue

#include "cs4050.h"
#include <stdio.h>
#include <stdlib.h>

// behind the scenes 
typedef struct _QueueNode{
    struct _QueueNode* prior;
    struct _QueueNode* next;
    Vertex* vert; // might need to change 
} QueueNode;


typedef struct _Queue{
    struct _QueueNode* head;
    struct _QueueNode* tail;
} Queue;

Queue newQueue();
Queue* enqueue(Queue* queue, Vertex* vert);
Vertex* dequeue(Queue* queue);
int isEmpty(Queue queue);

#endif