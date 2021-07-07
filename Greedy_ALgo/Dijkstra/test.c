#include <stdio.h>
#include <limits.h>
#define max 15

void dijkstra(int[max][max], int);
int min_vertice(int[max], int[max], int);

int main(int argc, char const *argv[])
{
    int graph[max][max] = {{0, 2, 2, 1, 0, 0},
                           {0, 0, 0, 2, 0, 0},
                           {0, 0, 0, 3, 1, 0},
                           {0, 0, 0, 0, 2, 0},
                           {0, 0, 0, 0, 0, 0},
                           {1, 5, 0, 0, 0, 0}};
    int vertices = 6;

    /* printf("Input the dimensions of the graph!\n");
    printf("Input the number of vertices!\n");
    scanf("%d", &vertices);

    printf("Input the weights!Incase if edge doen't exist input 0!\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("Index [%d],[%d]\n", i, j);
            scanf("%d", &graph[i][j]);
        }
    } */

    dijkstra(graph, vertices);

    return 0;
}

void dijkstra(int graph[max][max], int vertices) //Actual Algorithm
{

    int i = 0, j = 0;
    int vertex = 0;
    int cost[max];
    int visited[max];
    int parent[max];

    for (i = 0; i < vertices; i++)
    {
        cost[i] = INT_MAX;
    }

    parent[5] = -1; //assuming start node has no parent
    cost[5] = 0;    //assuming starting vertex as 0

    for (i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }

    for (i = 0; i < (vertices - 1); i++)
    {

        vertex = min_vertice(cost, visited, vertices);

        visited[vertex] = visited[vertex] + 1;

        for (j = 0; j < vertices; j++)
        {
            if (graph[vertex][j] != 0 && visited[j] == 0 && cost[vertex] != INT_MAX && (cost[vertex] + graph[vertex][j]) < cost[j])
            {
                cost[j] = cost[vertex] + graph[vertex][j];
                parent[j] = vertex;
            }
        }
    }

    printf("P -> C              Weight\n");

    printf("BACKTRACK TO GET THE PATH WITH COST!\n");
    for (i = 1; i < vertices; i++)
    {
        printf("X -> Y:   %d -> %d   weight=%d\n", parent[i], i, graph[parent[i]][i]);
    }
}

int min_vertice(int cost[max], int visited[max], int vertex)
{
    int minimum = INT_MAX;
    int index = 0;
    for (int i = 0; i < vertex; i++)
    {
        if ((visited[i] == 0) && (cost[i] < minimum))
        {
            minimum = cost[i];
            index = i;
        }
    }
    return index;
}
