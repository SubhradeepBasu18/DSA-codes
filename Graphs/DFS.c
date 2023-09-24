#include <stdio.h>
#include <stdlib.h>

int adj[10][10];
int n;

void createGraph()
{
    int origin, dest, max_edge;
    printf("Enter number of vertices:\n");
    scanf("%d", &n);
    max_edge = n * (n - 1);
    for (int i = 0; i < max_edge; i++)
    {
        printf("Enter the edge %d (-1,-1) to quit\n", i);
        scanf("%d %d", &origin, &dest);
        if (origin == -1 || dest == -1)
        {
            break;
        }
        else if (origin < 0 || dest < 0 || origin >= n || dest >= n)
        {
            printf("Edge doesn't exist\n");
            i--;
        }
        else
        {
            adj[origin][dest] = 1;
        }
    }
}
void dfs(int i,int visited[])
{
    
    visited[i] = 1;
    printf("%d ",i);
    for(int j=0;j<n;j++)
    {
        if(adj[i][j] == 1 && !visited[j])
        {
            dfs(j,visited);
        }
    }
}
int main()
{
    createGraph();
    int visited[n];
    for(int k=0;k<n;k++)
    {
        visited[k] = 0;
    }
    dfs(0,visited);
    return 0;
}
