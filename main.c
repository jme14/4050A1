// test program to try out libcs4050

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs4050.h"
#include "BFS.h"
#include "DFS.h"

int main(void)
{
    /******************************************************/
    /* Set things up by loading the graph and printing it */
    int countVertices, countEdges;

    //SetDirected(1);
	IsDirected();
    GetCounts(&countVertices,&countEdges);


    Vertex vertices[countVertices];
    Edge edges[countEdges];
    memset(vertices,0,sizeof(vertices));
    memset(edges,0,sizeof(edges));

    GetEdges(edges,countEdges);
    BuildAdjacency(vertices,edges,countVertices,countEdges);
    PrintVertices(vertices,countVertices);
    /******************************************************/
    PrintBFS(vertices,countVertices,edges,countEdges,1);
    PrintDFS(vertices,countVertices,edges,countEdges);
}
