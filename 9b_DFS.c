#include <stdio.h>

int visited[20];
int n;
int graph[20][20];

void dfs(int v)
{
    visited[v] = 1;
    printf("%d ", v);   // Print traversal order

    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}
void main()
{


    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
        visited[i] = 0;
    }

    printf("\nDFS Traversal Order: ");
    dfs(0);   // Start DFS from vertex 0

    // Check if all vertices are visited
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            printf("\nGraph is NOT connected\n");
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        printf("\nGraph is CONNECTED\n");


}
