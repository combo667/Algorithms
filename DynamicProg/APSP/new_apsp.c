#include <stdio.h>
#define V 5
#define INF 9999

void print_Solution(int[V][V]);
void APSP(int[V][V]);
void print_Path(int[V][V], int[V][V]);
void trace_path(int[V][V], int, int);
void print_all_nodes(int[V][V], int[V][V]);

int main(int argc, char const *argv[])
{
    int graph[V][V] = {{0, INF, 2, INF, INF},
                       {1, 0, INF, INF, 1},
                       {INF, INF, 0, 3, INF},
                       {INF, 4, INF, 0, -2},
                       {INF, INF, INF, INF, 0}};

    APSP(graph);

    return 0;
}

void APSP(int graph[V][V])
{
    int cost[V][V];
    int path[V][V];
    int i = 0, j = 0, k = 0;
    char choice;

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            cost[i][j] = graph[i][j];

            if (i == j)
                path[i][j] = 0;
            else if (graph[i][j] != INF)
                path[i][j] = i;
            else
                path[i][j] = -1;
        }
    }

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if ((cost[i][k] + cost[k][j]) < cost[i][j])
                {
                    cost[i][j] = cost[i][k] + cost[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }

    print_Solution(cost);

    printf("Select any of the followig option!\n");
    printf("INPUT 'A' TO PRINT THE PATHS FROM EACH NODE TO ALL THE OTHER NODES!\n");
    printf("INPUT 'B' TO FIND PATH FROM A PARTICULAR SOURCE TO A PARTICULAR DESTINATION!\n");
    scanf("%c", &choice);

    switch (choice)
    {
    case 'A':
        print_all_nodes(path, cost);

        break;
    case 'B':
        print_Path(path, cost);
        break;

    default:
        printf("\nWrong choice!\n");
        break;
    }
}

void print_Solution(int graph[V][V])
{
    int i = 0, j = 0;
    printf("Final distance matrix!\n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (graph[i][j] == INF)
                printf("INF\t\t");
            else
                printf("%d\t\t", graph[i][j]);
        }
        printf("\n");
    }
}

void print_Path(int path[V][V], int cost[V][V])
{
    int source;
    int destn;
    printf("Input the source vertex!\n");
    scanf("%d", &source);
    printf("Input the destination vertex!\n");
    scanf("%d", &destn);

    if (source != destn && path[source][destn] != -1)
    {

        printf("The shortest path from %d to %d is :\n", source, destn);
        printf("%d  ", source);
        trace_path(path, source, destn);
        printf("->  %d", destn);
        printf("\nThe total cost from %d to %d is: %d.\n", source, destn, cost[source][destn]);
    }
}

void trace_path(int path[V][V], int source, int destn)
{

    if (path[source][destn] == source)
        return;

    trace_path(path, source, path[source][destn]);
    printf("-> %d ", path[source][destn]);
}

void print_all_nodes(int path[V][V], int cost[V][V])
{
    int x, y;
    for (x = 0; x < V; x++)
    {
        for (y = 0; y < V; y++)
        {
            if (x != y && path[x][y] != -1)
            {
                printf("\nThe shortest path from %d to %d is :\n", x, y);
                printf("%d  ", x);
                trace_path(path, x, y);
                printf("->  %d", y);
                printf("\nThe total cost from %d to %d is: %d.\n", x, y, cost[x][y]);
            }
        }
        printf("\n");
    }
}