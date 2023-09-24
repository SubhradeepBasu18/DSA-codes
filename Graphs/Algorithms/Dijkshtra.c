#include <stdio.h>
#define infinity 9999
#define MAX 10

void dijkshtra(int adj[MAX][MAX], int startNode, int n)
{
    int cost[MAX][MAX],distance[MAX],pred[MAX],visited[MAX],c=0,min,nextNode,j;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(adj[i][j] == 0)
            {
                cost[i][j] = infinity;
            }
            else
            {
                cost[i][j] = adj[i][j];
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        distance[i] = cost[startNode][i];
        pred[i] = startNode;
        visited[i] = 0;
    }

    distance[startNode] = 0;
    visited[startNode] = 1;
    c=1;

    while(c<n-1)
    {
        min = infinity;
        for(int i=0;i<n;i++)
        {
            if(distance[i]<min && !visited[i])
            {
                min = distance[i];
                nextNode = i;
            }
        }
            visited[nextNode] = 1;
            for(int i=0;i<n;i++)
            {
                if(!visited[i])
                {
                    if(min+cost[nextNode][i]<distance[i])
                    {
                        distance[i] = min+cost[nextNode][i];
                        pred[i] = nextNode;
                    }
                }
            }
        c++;
    }
    for(int i=0;i<n;i++)
    {
		if(i!=startNode)
		{
			printf("\nDistance of node%d=%d",i,distance[i]);
			printf("\nPath=%d",i);
			
			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=startNode);
	    }
    }
}
int main()
{
    int adj[MAX][MAX];
    int u,n;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    printf("Enter the starting node: ");
    scanf("%d",&u);
    dijkshtra(adj,u,n);
    return 0;
}
