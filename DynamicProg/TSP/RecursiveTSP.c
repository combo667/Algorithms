#include <stdio.h>
#include <limits.h>
#define max 10
#define V 4

int TSP(int, int, int[max][max]);

int visited_all_cities = (1 << V) - 1;

int main(int argc, char const *argv[])
{
    int graph[max][max] = {{0, 20, 42, 25},
                           {20, 0, 30, 34},
                           {42, 30, 0, 10},
                           {25, 34, 10, 0}};

    printf("The Min Weighted Hamiltonian Cycle is :%d.\n", TSP(1, 0, graph));
    

    return 0;
}

int TSP(int mask, int start, int graph[max][max])
{
    if (mask == visited_all_cities)
    {
        return graph[start][0];
    }

    int ans = INT_MAX;

    for (int i = 0; i < V; i++)
    {
        if ((mask & (1 << i)) == 0)
        {
            int newDistance = graph[start][i] + TSP((mask | (1 << i)), i, graph);
            ans = ans < newDistance ? ans : newDistance;
            }
    }

    return ans;
}
