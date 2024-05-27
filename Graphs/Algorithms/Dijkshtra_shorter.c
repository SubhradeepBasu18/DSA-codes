#include <stdio.h>
#include <string.h>
#define infinity 999

void dijkshtra(int V,int adj[][V]){

    int cost[V][V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(adj[i][j] == 0) cost[i][j] = infinity;
            else cost[i][j] = adj[i][j];
        }
    }
    int dist[V];
    for(int i=0;i<V;i++) dist[i] = infinity;

    dist[0]=0;

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if((cost[i][j]!=infinity)&&((dist[i]+cost[i][j])<dist[j])){
                dist[j] = dist[i]+cost[i][j];
            }
        }
    }
    for(int i=0;i<V;i++){
        printf("%d ",dist[i]);
    }
}

int main()
{
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d",&V);
    int adj[V][V];

    printf("Enter the adjacency matrix: ");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    dijkshtra(V,adj);
    return 0;
}
