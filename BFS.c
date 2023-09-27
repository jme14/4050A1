#include <stdio.h>
#include <stdlib.h>
#include "cs4050.h"
#include "BFS.h"

int IsDirected(void){ // ??? 
    return 1;
}
void SetDirected(int fIsDirected){ // requires user input regarding if graph is directed or not  
    
}

void GetCounts(int * pCountVertices, int * pCountEdges){ // requires user input regarding amount of vertices and edges 

}

void GetEdge(Edge * pEdge){ // requires user input regarding edge content 

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

   // no mem leaks this way
   /* 
   Adjacency newAdjNode;
   newAdjNode.next = NULL;
   newAdjNode.pEdge = pEdge;
    */


    Adjacency* adjFinder = pVertex->list;
    if ( adjFinder == NULL ){
        pVertex->list = newAdjNode;
    } else {
        while ( adjFinder->next != NULL ) adjFinder = adjFinder->next;
        adjFinder->next = newAdjNode;
    }

}

// below initializes the vertices 
void BuildAdjacency(Vertex vertices[], Edge edges[], int countVertices, int countEdges) {

    for ( int i = 0 ; i < countEdges ; i++ ){
        int fromVertex = edges[i].from;
        
        // simple vertex initialization
        vertices[fromVertex].number = fromVertex;
        vertices[fromVertex].color = WHITE;
        vertices[fromVertex].d = -1;
        vertices[fromVertex].f = -1;
        vertices[fromVertex].predecessor = -1;

        AddAdjacentEdge(&vertices[fromVertex], &edges[i]);
    }
    
}

void PrintBFS(Vertex * V, int countV, Edge * E, int countE, int s)
{
    printf("We did it gang!\n");
}
