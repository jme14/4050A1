#include "Queue.h"

Queue newQueue(){

    Queue q;
    q.head = NULL;
    q.tail = NULL;
    return q;
}

Queue* enqueue(Queue* queue, Vertex* vert){


    QueueNode* newNode = malloc(sizeof(QueueNode));
    newNode->vert = vert;
    if ( queue->head == NULL ){
        queue->tail = queue->head = newNode;
        newNode->next = NULL;
        newNode->prior = NULL;
        return queue;
    }

    newNode->next = queue->tail;
    newNode->prior = NULL;
    queue->tail->prior = newNode;
    queue->tail = newNode;

    return queue;
}

Vertex* dequeue(Queue* queue){ //removes element in the queue to exist here for the longest time 

    if ( queue->head == NULL ) return NULL;

    QueueNode* freer = queue->head;
    Vertex* returner = freer->vert;
    queue->head = queue->head->prior;
    if( queue->head != NULL) queue->head->next = NULL;
    free(freer);

    return returner;
}

void printQueue(Queue* queue ){
    if ( queue == NULL ) return;
    QueueNode* traverser = queue->head;

    printf("(OLDEST) ");
    while ( traverser != NULL ){
        Vertex* contents = traverser->vert;
        printf("Vert is %d -> ", contents->number);
        traverser = traverser->prior;
    }
    printf(" (NEWEST)");
    puts("");
}

int isEmpty(Queue queue){
    if ( queue.head == NULL) return 1;
    return 0;
}

//TESTING QUEUE FUNCTIONALITY 
/*  
int main ( void ) {

    Queue q = newQueue();

    for ( int i = 0 ; i < 5 ; i++ ){
        Vertex* newVert = malloc(sizeof(Vertex));
        newVert->number = i;

        enqueue(&q, newVert);
        printQueue(&q);
    }
        printQueue(&q);

    for ( int i = 0 ; i < 5 ; i++ ){
        Vertex* vert = dequeue(&q);
        printf("Vert removed is %d\n", vert->number);
        printQueue(&q);

    }
}
*/