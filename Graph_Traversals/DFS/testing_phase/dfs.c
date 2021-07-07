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

typedef struct STACK
{
    int top;
    int *array;
    int size;
} stack;

stack *create_Stack(int);
int is_Empty(stack *);
int is_Full(stack *);
void Push(stack *, int);
int Pop(stack *);
void free_STACK(stack **);
graph *create_GRAPH(int);
node *create_NODE(int);
void add_EDGE(graph *, int, int);
void Depth_First_Search(graph *, stack *, int);
void free_LIST(node *);
void free_GRAPH(graph *);
void print_GRAPH(graph *);

int main(int argc, char const *argv[])
{

    stack *stk = NULL;
    stk = create_Stack(15);
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

        printf("Input the source node!\n");
        scanf("%d", &source);
        printf("Input the destination node!\n");
        scanf("%d", &destn);

        add_EDGE(g, source, destn);
    }

    print_GRAPH(g);

    printf("Input the search start node!\n");
    scanf("%d", &start);

    Depth_First_Search(g, stk, start);

    free_STACK(&stk);
    stk = NULL;

    free_GRAPH(g);
    g = NULL;

    return 0;
}

int Pop(stack *stack)
{
    int element = -1;
    if (is_Empty(stack) != 1)
    {
        element = stack->array[stack->top];
        stack->top--;
    }
    else
    {
        printf("STACK UNDERFLOW!\n");
    }
    return element;
}

void Push(stack *stack, int element)
{
    if (is_Full(stack) != 1)
    {
        stack->top++;
        stack->array[stack->top] = element;
    }
    else
    {
        printf("STACK OVERFLOW!\n");
    }
}
int is_Full(stack *stack)
{
    return (stack->top == stack->size - 1) ? 1 : 0;
}

int is_Empty(stack *stack)
{
    return (stack->top == -1) ? 1 : 0;
}
stack *create_Stack(int size)
{
    stack *stk = NULL;
    stk = (stack *)malloc(sizeof(stack));
    stk->array = (int *)malloc(sizeof(int) * size);
    stk->size = size;
    stk->top = -1;

    return stk;
}

void free_STACK(stack **stack)
{
    free((*stack)->array);
    (*stack)->array = NULL;
    free(*stack);
}

graph *create_GRAPH(int size)
{
    graph *g = NULL;
    g = (graph *)malloc(sizeof(graph));
    g->V = size;
    g->visited = (int *)malloc(sizeof(int));

    g->AdjList = (struct NODE **)malloc(sizeof(struct NODE *) * size);

    for (int i = 0; i < size; i++)
    {
        g->AdjList[i] = NULL;
        g->visited = 0; //no node visited till now
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

void Depth_First_Search(graph *g, stack *stk, int start)
{

    int visit_node;
    struct NODE *temp = NULL;
    printf("Visited Order!\n");
    printf("%d ", start);
    g->visited[start] = 1;
    Push(stk, start);
    while (is_Empty(stk) != 1)
    {
        visit_node = Pop(stk);
        temp = g->AdjList[visit_node];
        while (temp != NULL && g->visited[temp->vertex] == 0)
        {
            Push(stk, temp->vertex);
            printf("%d  ", temp->vertex);
            g->visited[temp->vertex] = 1; //discovered but not explored

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
    printf("The graph is :\n");

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
}

