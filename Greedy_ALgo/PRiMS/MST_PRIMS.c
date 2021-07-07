#include <stdio.h>
#define inf 9999
#define max 10

void MST_PRIM(int[max][max], int);
int extractMIN(int[max], int[max], int);
void PRINT_PARENT(int[max][max], int[max], int);

int main(int argc, char const *argv[])
{

    int vertices = 0, i = 0, j = 0;
    int graph[max][max];
    printf("Input the number of vertices in the graph!\n");
    scanf("%d", &vertices);

    printf("Input the edge weights one by one input 9999 incase no edge is present!\n");
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            printf("%d to %d\n", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    MST_PRIM(graph, vertices);

    return 0;
}

void MST_PRIM(int graph[max][max], int vertices)
{
    int parent[max], processed[max], weight[max], u = 0;

    for (int i = 0; i < vertices; i++)
    {
        weight[i] = inf;
        processed[i] = 0;
    }

    parent[0] = -1;
    weight[0] = 0;

    for (int i = 0; i < (vertices - 1); i++)
    {
        u = extractMIN(weight, processed, vertices); 
        processed[u] = 1;

        for (int j = 0; j < vertices; j++)
        {
            if ((graph[u][j] != 9999) && (processed[j] == 0) && (graph[u][j] < weight[j]))
            {
                weight[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }

    PRINT_PARENT(graph, parent, vertices);
}

int extractMIN(int weight[max], int processed[max], int vertices)
{
    int minimum = inf;
    int vertex;
    for (int i = 0; i < vertices; i++)
    {
        if ((processed[i] == 0) && (weight[i] < minimum))
        {
            vertex = i;
            minimum = weight[i];
        }
    }

    return vertex;
}

void PRINT_PARENT(int graph[max][max], int parent[max], int vertices)
{
    int min_cost = 0;
    printf("\nThe MST is :\n");
    for (int i = 1; i < vertices; i++)
    {
        printf("U -> V\t %d -> %d\t\tweight= %d\n", parent[i], i, graph[parent[i]][i]);
        min_cost = min_cost + graph[parent[i]][i];
    }

    printf("\nThe Total cost of Spanning Tree is : %d\n", min_cost);
}

//9999 4 6 9999 9999 9999 4 9999 6 3 4 9999 6 6 9999 1 8 9999 9999 3 1 9999 2 3 9999 4 8 2 9999 7 9999 9999 9999 3 7 9999

