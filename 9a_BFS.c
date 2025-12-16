#include <stdio.h>

void bfs(int graph[20][20], int vertices, int start)
{
    int visited[20] = {0};
    int queue[20];
    int front = 0, rear = 0;
    int i, current;

    queue[rear++] = start;
    visited[start] = 1;

    printf("\nBFS Traversal: ");

    while (front < rear)
    {
        current = queue[front++];
        printf("%d ", current);

        for (i = 0; i < vertices; i++)
        {
            if (graph[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;  
            }
        }
    }

    printf("\n\nReachability:\n");
    for (i = 0; i < vertices; i++)
    {
        if (visited[i])
            printf("Vertex %d is reachable\n", i);
        else
            printf("Vertex %d is NOT reachable\n", i);
    }
}

int main()
{
    int graph[20][20];
    int vertices, start;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < vertices; i++)
        for (j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(graph, vertices, start);

    return 0;
}
