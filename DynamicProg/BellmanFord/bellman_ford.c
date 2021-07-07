#include <stdio.h>
#include <stdlib.h>
#define inf 99999


typedef struct Edge
{
    int start;
    int end;
    int weight;
} EDGE;

typedef struct Graph
{
    int Vertices;
    int Edges;
    struct Edge *edge;
} GRAPH;

void input(GRAPH **);
void BELLMAN_FORD(GRAPH *, int);
void output(int *, int *, int);
void Solution(int[], int[], int, int);

int main(int argc, char const *argv[])
{

    GRAPH *graph = NULL;
    int source = 0;
    graph = (GRAPH *)malloc(sizeof(GRAPH));

    printf("Input the number of Vertices in the Graph!\n");
    scanf("%d", &graph->Vertices);
    printf("Input the number of edges in the Graph!\n");
    scanf("%d", &graph->Edges);

    graph->edge = (EDGE *)malloc(sizeof(EDGE) * graph->Edges);

    input(&graph);

    printf("Input the source Vertex!\n");
    scanf("%d", &source);

    BELLMAN_FORD(graph, source);

    free(graph->edge);
    graph->edge = NULL;
    free(graph);
    graph = NULL;

    return 0;
}

void input(GRAPH **G)
{
    int i = 0;
    printf("Input the EDGES one by one along with their start(u) and end(v) vertex !\n");
    for (i = 0; i < (*G)->Edges; i++)
    {
        printf("Input the u!\n");
        scanf("%d", &(*G)->edge[i].start);
        printf("Input the v!\n");
        scanf("%d", &(*G)->edge[i].end);
        printf("Weight:\n");
        scanf("%d", &(*G)->edge[i].weight);
    }
}

void BELLMAN_FORD(GRAPH *G, int source)
{
    int i = 0, j = 0, pass = 0, src = 0, dstn = 0, wt = 0;
    int Nodes = G->Vertices;
    int Paths = G->Edges;
    int Distance[Nodes];
    int Parent[Nodes];

    for (i = 0; i < Nodes - 1; i++)
    {
        Distance[i] = inf;
        Parent[i] = 0;
    }

    Distance[source] = 0;

    for (pass = 1; pass <= (Nodes - 1); pass++)
    {
        for (j = 0; j < Paths; j++)
        {
            src = G->edge[j].start;
            dstn = G->edge[j].end;
            wt = G->edge[j].weight;
            if ((Distance[src] + wt) < Distance[dstn])
            {
                Distance[dstn] = Distance[src] + wt;
                Parent[dstn] = src;
            }
        }
    }

    for (j = 0; j < Paths; ++j)
    {
        src = G->edge[j].start;
        dstn = G->edge[j].end;
        wt = G->edge[j].weight;
        if ((Distance[src] + wt) < Distance[dstn])
        {
            printf("Negative Cycle Detected!\n");
            return;
        }
    }

    Solution(Distance, Parent, Nodes, source);
}

void Solution(int Distance[], int Parent[], int V, int Source)
{
    int i = 0;
    printf("\nVertex\tDistance from Source %d\tParent \n", Source);
    for (i = 0; i < V; i++)
    {
        printf("%d\t\t%d\t\t%d\n", i, Distance[i], Parent[i]);
    }
    printf("\n");
}
