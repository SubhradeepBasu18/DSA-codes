#include <stdio.h>
#include <stdlib.h>

// int n = 6;

void prims(int **adj, int *vis, int n){

    vis[0] = 1;
    int mstWt = 0;

    for(int cnt=0; cnt<n-1;cnt++){
        int min = 999, x=0,y=0;

        for(int i=0;i<n;i++){
            if(vis[i]){
                for(int j=0;j<n;j++){
                    if(!vis[j] && adj[i][j]){
                        if(min>adj[i][j]){
                            min = adj[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, adj[x][y]);
        vis[y] = 1;
        mstWt+=adj[x][y];
    }
    printf("\nThe weight of the minimum spanning tree is: %d\n",mstWt);
}

int main()
{
    int n;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    
    int *vis = (int *)malloc(n*sizeof(int));
    int **adj = (int **)malloc(n*sizeof(int *));

    for(int i=0;i<n;i++){ 
        vis[i] = 0;
        adj[i] = (int *)malloc(n*sizeof(int));
        }

    printf("Enter the adjacency matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }

    prims(adj,vis,n);
    return 0;
}



//EXAMPLE
/*
0 4 4 0 0 0
4 0 2 0 0 0
4 2 0 3 2 0
0 0 3 0 0 3
0 0 2 0 0 3
0 0 4 3 3 0
*/

/*
0 - 1 : 4
1 - 2 : 2
2 - 4 : 2
2 - 3 : 3
3 - 5 : 3

The weight of the minimum spanning tree is: 14
*/
