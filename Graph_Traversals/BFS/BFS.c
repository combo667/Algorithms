//BFS TRAVERSAL

#include <stdio.h>
#include <stdlib.h>
#define max 25

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

typedef struct Queue
{
    int Size, Front, Rear;
    int *array;
} Queue;

int isEmpty(Queue *);
int isFull(Queue *);
void Enqueue(Queue *, int);
int Dequeue(Queue *);
Queue *createQueue();
void freeQueue(Queue *);
void BFS(graph *, Queue *, int);
graph *create_GRAPH(int);
node *create_NODE(int);
void add_EDGE(graph *, int, int);
void free_GRAPH(graph *);
void free_LIST(node *);
void print_GRAPH(graph *);

int main(int argc, char const *argv[])
{
    Queue *queue = NULL;
    graph *g = NULL;
    int vertices = 0, edges = 0, source = 0, destn = 0, start = 0;

    queue = createQueue();

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

    printf("Input the Start Node!\n");
    scanf("%d", &start);

    printf("BFS TRAVERSAL:\n");
    BFS(g, queue, start);

    free_GRAPH(g);
    g = NULL;
    freeQueue(queue);
    queue = NULL;

    return 0;
}

void BFS(graph *g, Queue *queue, int start)
{

    int Visit_Node;
    node *temp = NULL;
    printf("%d ", start);

    g->visited[start] = 1;
    Enqueue(queue, start);
    while (isEmpty(queue) != 1)
    {
        Visit_Node = Dequeue(queue);
        temp = g->AdjList[Visit_Node];

        while (temp != NULL)
        {
            if (g->visited[temp->vertex] == 0)
            {
                printf("%d  ", temp->vertex);
                g->visited[temp->vertex] = 1;
                Enqueue(queue, temp->vertex);
            }

            temp = temp->next;
        }

        g->visited[Visit_Node] = 2;
    }
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

Queue *createQueue()
{
    Queue *temp = NULL;
    temp = (Queue *)malloc(sizeof(Queue));
    temp->array = (int *)malloc(sizeof(int) * max);
    temp->Front = temp->Rear = 0;
    temp->Size = max;
    return temp;
}

int isFull(Queue *q)
{
    if ((q->Rear + 1) % q->Size == q->Front)
        return 1;
    return 0;
}
int isEmpty(Queue *queue)
{
    if (queue->Rear == queue->Front)
        return 1;
    return 0;
}

void Enqueue(Queue *queue, int element)
{
    if (isFull(queue) != 1)
    {
        queue->Rear = (queue->Rear + 1) % queue->Size;
        queue->array[queue->Rear] = element;
    }

}

int Dequeue(Queue *queue)
{
    int x = -1;
    if (isEmpty(queue) != 1)
    {
        queue->Front = (queue->Front + 1) % queue->Size;
        x = queue->array[queue->Front];
        return x;
    }
   
    return x;
}

void freeQueue(Queue *queue)
{
    free(queue->array);
    free(queue);
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

//Input :
//Vertices =7
//Edges=9

//GRaph Input
//  0 1 0 2 0 3 3 4 2 4 4 5 4 6 1 2 3 2
