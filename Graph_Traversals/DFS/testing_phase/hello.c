#include <stdio.h>
#include <stdlib.h>
typedef struct NODE
{
    int vertex;
    struct NODE *next;
} node;

typedef struct GRAPH
{
    int *visited;
    int V;
    struct NODE **AdjList;

} graph;

struct Stack
{
    int Top;
    int Size;
    int *array;
};

int isEmpty(struct Stack *);
int isFull(struct Stack *);
void freeStack(struct Stack *);
struct Stack *createStack();
void Push(struct Stack *, int);
int Pop(struct Stack *);
graph *create_GRAPH(int);
node *create_NODE(int);
void add_EDGE(graph *, int, int);
void Depth_First_Search(graph *, struct Stack *, int);
void free_LIST(node *);
void free_GRAPH(graph *);
void print_GRAPH(graph *);
void print_STACK(struct Stack *);

struct Stack *createStack()
{
    struct Stack *temp;
    temp = (struct Stack *)malloc(sizeof(struct Stack));
    printf("Input the size of the stack to be created:\n");
    scanf("%d", &temp->Size);
    temp->array = (int *)malloc(sizeof(int) * temp->Size);
    temp->Top = -1;

    return temp;
}

int isEmpty(struct Stack *temp)
{
    if (temp->Top == -1)
        return 1;
    else
    {
        return 0;
    }
}

int isFull(struct Stack *temp)
{
    if (temp->Top == temp->Size - 1)
        return 1;
    else
    {
        return 0;
    }
}

void Push(struct Stack *stack, int element)
{

    if (isFull(stack) != 1)
    {
        stack->Top++;
        stack->array[stack->Top] = element;
    }
}

int Pop(struct Stack *stack)
{
    int element = -1;

    if (isEmpty(stack) != 1)
    {
        element = stack->array[stack->Top];
        --stack->Top;
    }
    return element;
}

void freeStack(struct Stack *stack)
{
    free(stack->array);
    free(stack);
}

graph *create_GRAPH(int size)
{
    graph *g = NULL;
    g = (graph *)malloc(sizeof(graph));
    g->V = size;
    g->visited = (int *)malloc(sizeof(int) * size);

    g->AdjList = (struct NODE **)malloc(sizeof(struct NODE *) * size);

    for (int i = 0; i < size; i++)
    {
        g->AdjList[i] = NULL;
        g->visited[i] = 0; //no node visited till now
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

void Depth_First_Search(graph *g, struct Stack *stk, int start)
{

    int visit_node;
    struct NODE *temp = NULL;
    printf("Visited Order!\n");
    printf("%d ", start);
    g->visited[start] = 1;
    Push(stk, start);
    while (isEmpty(stk) != 1)
    {
        visit_node = Pop(stk);
        temp = g->AdjList[visit_node];

        while (temp != NULL)
        {
            if (g->visited[temp->vertex] == 0)
            {
                Push(stk, temp->vertex);
                printf("%d  ", temp->vertex);
                g->visited[temp->vertex] = 1; //discovered but not explored
            }

            temp = temp->next;
        }

        g->visited[visit_node] = 2; //completely explored
    }
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
    free(g->visited);
    g->visited = NULL;
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
        printf("Verted %d : ", i);
        while (temp != NULL)
        {
            printf("%d  ", temp->vertex);

            temp = temp->next;
        }

        printf("\n");
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{

    struct Stack *stk = NULL;
    stk = createStack();
    int vertices = 0, edges = 0, source = 0, destn = 0, start = 0;
    graph *g = NULL;
    printf("INput the number of vertices in the graph!\n");
    scanf("%d", &vertices);
    printf("Input the number of edges in the graph!\n");
    scanf("%d", &edges);

    g = create_GRAPH(vertices);

    printf("INput the edges one by one!\n");
    for (int i = 0; i < edges; i++)
    {

        printf("\nInput the (source node , destiation node) !\n");
        scanf("%d %d", &source, &destn);

        add_EDGE(g, source, destn);
    }

    print_GRAPH(g);

    printf("Input the search start node!\n");
    scanf("%d", &start);

    Depth_First_Search(g, stk, start);

    freeStack(stk);
    stk = NULL;

    free_GRAPH(g);
    g = NULL;
    return 0;
}

void print_STACK(struct Stack *stk)
{
    int n = 0;

    if (isEmpty(stk) != 1)
    {
        while (n <= stk->Top)
        {
            printf("%d  ", stk->array[n]);
            n++;
        }
    }
    else
    {
        printf("Stack EMpty\n");
    }
}
