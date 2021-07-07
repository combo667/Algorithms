#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 25

int Solution[max] = {0};

typedef struct NODE
{
    int vertex;
    struct NODE *next;
} node;

typedef struct GRAPH
{

    int V;
    struct NODE **AdjList;

} graph;

graph *create_GRAPH(int);
node *create_NODE(int);
void add_EDGE(graph *, int, int);
void free_LIST(node *);
void free_GRAPH(graph *);
void print_GRAPH(graph *);
void print_Chromatic_Solution(int);
void Graph_Colouring(int, int, graph *);
bool isSafe(int, int, graph *);
int find_Min(int);

int main(int argc, char const *argv[])
{
    int V = 0, edges = 0, source = 0, destn = 0, m = 0;
    ;
    graph *g = NULL;

    printf("INput the number of vertices!\n");
    scanf("%d", &V);
    printf("Input the number of edges in the graph!\n");
    scanf("%d", &edges);
    printf("Input the maximum no of Colours you have!\n");
    scanf("%d", &m);

    g = create_GRAPH(V);

    printf("INput the edges one by one!\n");
    for (int i = 0; i < edges; i++)
    {

        printf("\nInput the (source node , destination node) !\n");
        scanf("%d %d", &source, &destn);

        add_EDGE(g, source, destn);
    }

    print_GRAPH(g);

    Graph_Colouring(0, m, g);

    free_GRAPH(g);
    g = NULL;

    return 0;
}

void Graph_Colouring(int Node, int m, graph *g)
{
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(Node, c, g))
        {
            Solution[Node] = c;
            if ((Node + 1) < g->V)
                Graph_Colouring(Node + 1, m, g);
            else
            {
                print_Chromatic_Solution(g->V);
                return;
            }
        }
    }
}

bool isSafe(int Node, int color, graph *g)
{
    node *temp = NULL;
    temp = g->AdjList[Node];
    while (temp != NULL)
    {
        if (Solution[temp->vertex] == color)
            return false;
        temp = temp->next;
    }

    return true;
}

graph *create_GRAPH(int size)
{
    graph *g = NULL;
    g = (graph *)malloc(sizeof(graph));
    g->V = size;

    g->AdjList = (struct NODE **)malloc(sizeof(struct NODE *) * size);

    for (int i = 0; i < size; i++)
    {
        g->AdjList[i] = NULL;
    }

    return g;
}

node *create_NODE(int v)
{
    struct NODE *n = (struct NODE *)malloc(sizeof(struct NODE));
    n->next = NULL;
    n->vertex = v;
    return n;
}

void add_EDGE(graph *g, int u, int v)
{
    struct NODE *new_node = NULL;
    struct NODE *new_node2 = NULL;
    new_node = create_NODE(v);
    new_node->next = g->AdjList[u];
    g->AdjList[u] = new_node;

    new_node2 = create_NODE(u);
    new_node2->next = g->AdjList[v];
    g->AdjList[v] = new_node2;
}

void free_GRAPH(graph *g)
{
    for (int i = 0; i < g->V; i++)
    {
        if (g->AdjList[i] != NULL)
        {
            free_LIST(g->AdjList[i]);
            g->AdjList[i] = NULL;
        }
    }
    g->AdjList = NULL;
    g = NULL;
}

void free_LIST(node *n)
{
    node *temp1 = NULL, *temp2 = NULL;
    temp1 = n;
    while (temp1 != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->next;
        temp2->next = NULL;
        free(temp2);
    }
}

void print_GRAPH(graph *g)
{
    node *temp = NULL;
    printf("\nThe graph, Adjacency List is :\n");

    for (int i = 0; i < g->V; i++)
    {
        temp = g->AdjList[i];
        printf("Vertex %d : ", i);
        while (temp != NULL)
        {
            printf("%d  ", temp->vertex);

            temp = temp->next;
        }

        printf("\n");
    }
    printf("\n");
}

void print_Chromatic_Solution(int Vertices)
{
    static int count = 1;
    int (*p)(int) = &find_Min;
    if (count == 1)
    {

        int min_col = p(Vertices);
        printf("Minimum No of Colour required is %d\n", min_col);
    }

    printf("\nSolution %d:\n", count++);
    printf("Node\t->\tColour\n");
    for (int i = 0; i < Vertices; i++)
    {
        printf("%d\t->\t%d\n", i, Solution[i]);
    }
    printf("\n");
}

int find_Min(int V)
{
    int mini = -999;
    for (int i = 0; i < V; i++)
    {
        if (Solution[i] > mini)
            mini = Solution[i];
    }

    return mini;
}

/* 
Input
V=6
E=8

0 2 0 3 0 1 2 3 1 3 2 5 3 4 4 5 */