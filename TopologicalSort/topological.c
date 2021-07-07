#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 25

typedef struct Queue
{
    int Size, Front, Rear;
    int *array;
} Queue;

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

bool isEmpty(Queue *);
bool isFull(Queue *);
void Enqueue(Queue *, int);
int Dequeue(Queue *);
Queue *createQueue();
void freeQueue(Queue *);
graph *create_GRAPH(int);
node *create_NODE(int);
void add_EDGE(graph *, int, int);
void free_LIST(node *);
void free_GRAPH(graph *);
void print_topological_order(int[], int);
void TOPOLOGICAL(graph *);
void print_GRAPH(graph *);

int main(int argc, char const *argv[])
{

    graph *g = NULL;
    int V = 0, E = 0;
    int u = 0, v = 0;

    printf("Input the number of vertices!\n");
    scanf("%d", &V);
    printf("Input the number of Edges!\n");
    scanf("%d", &E);
    g = create_GRAPH(V);

    for (int i = 0; i < E; i++)
    {
        printf("Input the Source [S] and Destn [D]!\n");
        scanf("%d%d", &u, &v);

        add_EDGE(g, u, v);
    }

    print_GRAPH(g);

    TOPOLOGICAL(g);

    free_GRAPH(g);
    g = NULL;

    return 0;
}

void TOPOLOGICAL(graph *g)
{

    int T[max], visited[max], in_degree[max];
    node *temp = NULL;
    int vertex;
    int count = 0;

    Queue *queue = createQueue();

    for (int i = 0; i < g->V; i++)
    {
        in_degree[i] = visited[i] = 0;
    }

    for (int i = 0; i < g->V; i++)
    {
        temp = g->AdjList[i];

        while (temp != NULL)
        {
            in_degree[temp->vertex]++;
            temp = temp->next;
        }
    }

    for (int i = 0; i < g->V; i++)
    {
        if (in_degree[i] == 0)
        {
            Enqueue(queue, i);
            visited[i] = 1;
        }
    }

    count = 0;

    while (isEmpty(queue) != true)
    {
        vertex = Dequeue(queue);
        T[count] = vertex;
        temp = g->AdjList[vertex];

        while (temp != NULL)
        {
            if (visited[temp->vertex] == 0)
            {
                in_degree[temp->vertex]--;

                if (in_degree[temp->vertex] == 0)
                {
                    Enqueue(queue, temp->vertex);
                    visited[temp->vertex] = 1;
                }
            }

            temp = temp->next;
        }

        ++count;
    }

    print_topological_order(T, g->V);

    freeQueue(queue);
    queue = NULL;
}

Queue *createQueue()
{
    Queue *temp = NULL;
    temp = (Queue *)malloc(sizeof(Queue));
    temp->array = (int *)malloc(sizeof(int) * max);
    temp->Front = temp->Rear = 0;
    return temp;
}

bool isFull(Queue *q)
{
    if ((q->Rear + 1) % q->Size == q->Front)
        return true;
    return false;
}
bool isEmpty(Queue *queue)
{
    if (queue->Rear == queue->Front)
        return true;
    return false;
}

void Enqueue(Queue *queue, int element)
{
    if (isFull(queue) != true)
    {
        queue->Rear = (queue->Rear + 1) % queue->Size;
        queue->array[queue->Rear] = element;
    }
    else
    {
        printf("QueueOverFlow\n");
    }
}

int Dequeue(Queue *queue)
{
    int x = -1;
    if (isEmpty(queue) != true)
    {
        queue->Front = (queue->Front + 1) % queue->Size;
        x = queue->array[queue->Front];
        return x;
    }
    else
    {
        printf("Queue Underflow!\n");
    }
    return x;
}

void freeQueue(Queue *queue)
{
    free(queue->array);
    free(queue);
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
    new_node = create_NODE(v);
    new_node->next = g->AdjList[u];
    g->AdjList[u] = new_node;
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

void print_topological_order(int A[], int n)
{
    printf("The Topological sorting is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
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

//V=6 E=10
//0 1 1 2 0 3 1 3 2 5 2 4 2 3 3 4 4 5 3 5



//V=7  E=8
//0 1 0 2 1 2 6 1 6 5 1 5 5 3 5 4