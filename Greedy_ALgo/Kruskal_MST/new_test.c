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
    int size;
    node *edges;
} graph;

graph *create_GRAPH(int, int);
void free_GRAPH(graph **);
void out_GRAPH(graph *);
void Union(int, int, int **);
void kruskals_ALGO(graph *);
void print_SOLUTION(node *, int);
int find(int, int **);
void Heapify(node **, int, int);
void swap(node *, node *);
void Heapify(node **, int, int);
node *delete_Root(graph **);
void Build_Heap(graph **);

int main(int argc, char const *argv[])
{

    int edges, vertices;
    graph *g = NULL;
    printf("Input the number of edges and vertices in the graph!\n");
    scanf("%d%d", &edges, &vertices);

    g = create_GRAPH(edges, vertices);
    out_GRAPH(g);

    Build_Heap(&g);

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
    g->size = Edges;
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
    int pass = 0, u = 0, v = 0;
    node *min = NULL;
    int *SET = (int *)malloc(sizeof(int) * ((g->V) + 1));
    node *solution = (node *)malloc(sizeof(node) * (g->V) - 1);

    //initialisation

    for (int i = 0; i < (g->V) + 1; i++)
    {
        SET[i] = -1;
    }

    //actual algorithm
    pass = 0;
    while (pass < (g->V) - 1)
    {
        min = delete_Root(&g);

        u = min->from;
        v = min->to;

        if (find(u, &SET) != find(v, &SET))
        {
            solution[pass].from = u;
            solution[pass].to = v;
            solution[pass].weight = min->weight;

            Union(find(u, &SET), find(v, &SET), &SET);

            ++pass;
        }
    }

    print_SOLUTION(solution, g->V - 1);

    free(SET);
    free(solution);
}

void Union(int u, int v, int **set)
{

    if ((*set)[u] < (*set)[v])
    {
        (*set)[u] = (*set)[u] + (*set)[v];
        (*set)[v] = u;
    }
    else
    {
        (*set)[v] += (*set)[u];
        (*set)[u] = v;
    }
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

    printf("The MST Cost is %d\n", cost);
}

int find(int u, int **set)
{
    int x = u;
    while ((*set)[x] > 0)
    {
        x = (*set)[x];
    }

    return x;
}

void Heapify(node **array, int i, int size)
{

    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < size && (*array)[left].weight < (*array)[largest].weight)
        largest = left;
    if (right < size && (*array)[right].weight < (*array)[largest].weight)
        largest = right;
    if (largest != i)
    {
        swap(&(*array)[largest], &(*array)[i]);
        Heapify(array, largest, size);
    }
}

node *delete_Root(graph **g)
{
    node *element = (node *)malloc(sizeof(node));
    swap(&(*g)->edges[0], &(*g)->edges[(*g)->size - 1]);

    element = &(*g)->edges[(*g)->size - 1];

    (*g)->size--;
    for (int i = ((*g)->size / 2) - 1; i >= 0; i--)
    {
        Heapify(&(*g)->edges, i, (*g)->size);
    }

    return element;
}

void swap(node *x, node *y)
{
    node *temp=NULL;
    temp = x;
    x = y;
    y = temp;
}

void Build_Heap(graph **g)
{
    int i = ((*g)->size / 2) - 1;

    for (; i >= 0; i--)
    {
        Heapify(&(*g)->edges, i, (*g)->size);
    }
}

//input
//8 6 0 1 4 1 2 2 0 2 4 2 3 3 2 5 2 2 4 4 3 4 3 5 4 3