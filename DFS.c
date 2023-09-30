#include <stdio.h>
#include "cs4050.h"
#include "DFS.h"


void DFSVisit(Vertex* V, int countV, Edge* E, int countE, Vertex* u, int* time){

    *time = *time +1;

    u->d = *time;
    u->color = GRAY;
    for ( Adjacency* uAdjTraverser = u->list; uAdjTraverser != NULL ; uAdjTraverser=uAdjTraverser->next ){
        Vertex* v = &V[uAdjTraverser->pEdge->to-1];
        if ( v->color == WHITE ){
           v->predecessor = u->number;
           DFSVisit(V, countV, E, countE, v, time);
        }
    }

    *time = *time+1;
    u->f = *time;
    u->color = BLACK;
    printf("%d ", u->number);
}

void PrintDFS(Vertex * V, int countV, Edge * E, int countE)
{
    printf("DFS:\n");
    for ( int i = 0 ; i < countV ; i++){
        V[i].color = WHITE;
        V[i].predecessor = -1;
    }

    int time = 0;

    for ( int i = 0 ; i < countV ; i++ ){
        Vertex* u = &V[i];
        if ( u->color == WHITE ){
            DFSVisit(V, countV, E, countE, u, &time);
        }
    }
}
