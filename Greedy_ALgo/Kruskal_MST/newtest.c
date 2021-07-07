#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct NODE
{
    int from;
    int to;
    int weight;
} node;

typedef struct GRAPH
{
    int E;
    int V;
    node *edges;
} graph;

graph *create_GRAPH(int, int);
void free_GRAPH(graph **);
void out_GRAPH(graph *);
int extract_MIN(graph *, int *);
void kruskals_ALGO(graph *);
void print_SOLUTION(node *, int);
void Union(int [], int , int , int );
int Find(int [], int , int );
void MAKE_SET(int [], int );

int main(int argc, char const *argv[])
{

    int edges, vertices;
    graph *g = NULL;
    printf("Input the number of edges and vertices in the graph!\n");
    scanf("%d%d", &edges, &vertices);

    g = create_GRAPH(edges, vertices);
    out_GRAPH(g);

    kruskals_ALGO(g);

    free_GRAPH(&g);
    g = NULL;

    return 0;
}

graph *create_GRAPH(int Edges, int Vertices)
{
    graph *g = NULL;
    int i = 0;
    g = (graph *)malloc(sizeof(graph));

    g->E = Edges;
    g->V = Vertices;
    g->edges = (node *)malloc(sizeof(node) * g->E);

    printf("Input the edges one by one !\n");
    for (i = 0; i < g->E; i++)
    {
        printf("FROM:\tTO:\tWeight:\t\n");
        scanf("%d%d%d", &g->edges[i].from, &g->edges[i].to, &g->edges[i].weight);
    }

    return g;
}

void out_GRAPH(graph *g)
{
    printf("The graph is :\n");
    printf("FROM:\tTo:\tWeight\t\n");
    for (int i = 0; i < g->E; i++)
    {
        printf("%d\t%d\t%d\n", g->edges[i].from, g->edges[i].to, g->edges[i].weight);
    }
}

void free_GRAPH(graph **g)
{
    free((*g)->edges);
    (*g)->edges = NULL;
    free((*g));
    *g = NULL;
}

void kruskals_ALGO(graph *g)
{
    int pass = 0, u = 0, v = 0, min = 0;
    int find1 = 0, find2 = 0;
    int *processed = (int *)malloc(sizeof(int) * g->E);
    int *SET = (int *)malloc(sizeof(int) * ((g->V) + 1));
    node *solution = (node *)malloc(sizeof(node) * (g->V) - 1);

    //initialisation

    for (int i = 0; i < g->E; i++)
    {
        processed[i] = 0;
    }

    for (int i = 0; i < (g->V) + 1; i++)
    {
        SET[i] = -1;
    }

    //actual algorithm
    pass = 0;
    while (pass < (g->V) - 1)
    {
        min = extract_MIN(g, processed);

        u = g->edges[min].from;
        v = g->edges[min].to;

        if (find(u, &SET) != find(v, &SET))
        {
            solution[pass].from = u;
            solution[pass].to = v;
            solution[pass].weight = g->edges[min].weight;

            Union(find(u, &SET), find(v, &SET), &SET);

            ++pass;
        }
        processed[min] = 1;
    }

    print_SOLUTION(solution, g->V - 1);

    free(processed);
    free(SET);
    free(solution);
}



int extract_MIN(graph *g, int *processed)
{
    int j = 0;
    int min = INT_MAX;
    int k = 0;
    for (j = 0; j < g->E; j++)
    {
        if (processed[j] == 0 && g->edges[j].weight < min)
        {
            min = g->edges[j].weight;
            k = j;
        }
    }

    return k;
}

void print_SOLUTION(node *solution, int n)
{
    int cost = 0;
    printf("The MST is :\n");
    printf("FROM:\tTO:\tWeight:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\n", solution[i].from, solution[i].to, solution[i].weight);
        cost += solution[i].weight;
    }

    printf("\nThe MST Cost is %2d\n", cost);
}



void MAKE_SET(int set[], int size)
{
    for (int i = 0; i < size; i++)
    {
        set[i] = i;
    }
}

int Find(int set[], int size, int x)
{
    if (!(x >= 0 && x < size))
        return;
    if (set[x] == x)
        return x;
    else
        return Find(set, size, set[x]);
}

void Union(int set[], int size, int root1, int root2)
{
    if (Find(set, size, root1) == Find(set, size, root2))
    {
        return;
    }
    if (!((root1 >= 0 && root1 < size) && (root2 >= 0 && root2 < size)))
    {
        return;
    }
    set[root1] = set[root2];
}

//input
//8 6 0 1 4 1 2 2 0 2 4 2 3 3 2 5 2 2 4 4 3 4 3 5 4 3