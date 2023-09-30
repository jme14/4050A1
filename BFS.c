#include <stdio.h>
#include <stdlib.h>
#include "cs4050.h"
#include "BFS.h"
#include "Queue.h"


#define INF 1000000
int IsDirected(void){ // ??? 

    char input[100];
    int rando = 0;
    printf("The graph is going to be directed whether you like it or not");
    if ( fgets(input, sizeof(input), stdin) != NULL){
        if (!sscanf(input, "%d", &rando)){
            printf("A problem occured\n");
        }
    }
    return 1;
}
void SetDirected(int fIsDirected){ // requires user input regarding if graph is directed or not  
    
}

void GetCounts(int * pCountVertices, int * pCountEdges){ // requires user input regarding amount of vertices and edges 

    char input[100];
    printf("Enter number of vertices: \n");
    if ( fgets(input, sizeof(input), stdin) != NULL){ // if fgets works
        if ( sscanf(input, "%d\n", pCountVertices) != 1){
            printf("Invalid number, start over\n");
            GetCounts(pCountVertices, pCountEdges);
            return;
        }
    } else {
        printf("Input too large, start over\n");
        printf("%s\n", input);
        GetCounts(pCountVertices, pCountEdges);
        return;
    }

    printf("Enter number of edges: \n");
    if ( fgets(input, sizeof(input), stdin) != NULL){ // if fgets works
        if ( sscanf(input, "%d", pCountEdges) != 1){
            printf("Invalid number, start over\n");
            GetCounts(pCountVertices, pCountEdges);
            return;
        }
    } else {
        printf("Input too large, start over\n");
        GetCounts(pCountVertices, pCountEdges);
        return;
    }

}

void GetEdge(Edge * pEdge){ // requires user input regarding edge content 

    char input[100];
    printf("Enter edge\n");
    if ( fgets(input, sizeof(input), stdin) != NULL ){
        if ( !sscanf(input, "%d %d %f\n", &pEdge->from, &pEdge->to, &pEdge->weight)){
            printf("Invalid edge, try again\n");
            GetEdge(pEdge);
        }
    }
    else {
        printf("Input too large, try again\n");
        GetEdge(pEdge);
    }
}

void GetEdges(Edge edges[], int countEdges){ // requires user input of all edges 
    for ( int i = 0 ; i < countEdges ; i++){
        GetEdge(&edges[i]);
    }
}

void PrintVertex(Vertex vertex){ // prints information about the vertex 
    printf("Vertex %d:\n", vertex.number);

    Adjacency* adjLister = vertex.list;
    while ( adjLister != NULL ){

        int otherVertex = adjLister->pEdge->from;
        /* potentially remove the following */
        if ( otherVertex == vertex.number) otherVertex = adjLister->pEdge->to;
        /* */

        printf("%d->%d (%f)\n", vertex.number, otherVertex, adjLister->pEdge->weight);
        adjLister = adjLister->next;
    }
}

void PrintVertices(Vertex vertices[], int count){
    for ( int i = 0 ; i < count ; i++){
        PrintVertex(vertices[i]);
    }
}

void AddAdjacentEdge(Vertex * pVertex, Edge * pEdge){

    Adjacency* newAdjNode = malloc(sizeof(Adjacency));
    newAdjNode->next = NULL;
    newAdjNode->pEdge = pEdge;

    Adjacency* adjFinder = pVertex->list;
    if ( adjFinder == NULL ){
        pVertex->list = newAdjNode;
    } else {
        while ( adjFinder->next != NULL ) adjFinder = adjFinder->next;
        adjFinder->next = newAdjNode;
    }

}

void BuildAdjacency(Vertex vertices[], Edge edges[], int countVertices, int countEdges) {


    // vertices initialization
    for ( int i = 0 ; i < countVertices ; i++ ){
        vertices[i].number = i+1;
        vertices[i].color = WHITE;
        vertices[i].d = -1;
        vertices[i].f = -1;
        vertices[i].predecessor = -1;
    }

    // including data from each edge to each vertex containing an edge 
    for ( int i = 0 ; i < countEdges ; i++ ){
        int fromVertex = edges[i].from;
        AddAdjacentEdge(&vertices[fromVertex-1], &edges[i]);
    }
    
}

void PrintBFS(Vertex * V, int countV, Edge * E, int countE, int s)
{
    printf("BFS:\n");
    for ( int i = 1 ; i < countV ; i++){
        V[i].color = WHITE;
        V[i].d = INF;
        V[i].predecessor = -1;
    }

    V[0].color = GRAY;
    V[0].d = 0;
    V[0].predecessor = -1;

    Queue q = newQueue();
    enqueue(&q,&V[0]);

    while ( !isEmpty(q)){
        Vertex* u = dequeue(&q);

        for ( Adjacency* uAdjTraverser = u->list ; uAdjTraverser != NULL ; uAdjTraverser = uAdjTraverser->next ){
            Vertex* v = &V[uAdjTraverser->pEdge->to-1];

            if ( v->color == WHITE ){
                v->color = GRAY;
                v->d = u->d+1;
                v->predecessor = u->number;
                enqueue(&q, v);
            }
        }
        u->color = BLACK;
        printf("%d ", u->number);
    }

    puts("");
}
