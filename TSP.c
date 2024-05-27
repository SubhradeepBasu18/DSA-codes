#include <stdio.h>
#include <limits.h>
#include <string.h>
#define V 4

int all_visited = (1<<V)-1;

int min(int a, int b){
    return a<b?a:b;
}

int tsp(int graph[][V], int mask, int pos,int dp[][1<<V]){
    
    if(mask == all_visited) return graph[pos][0];

    if(dp[pos][mask] != -1) return dp[pos][mask];

    int mini = INT_MAX;
    for(int city=0;city<V;city++){

        if((mask&(1<<city)) == 0){

            int ans = graph[pos][city] + tsp(graph,mask|(1<<city),city,dp);
            mini = min(mini,ans);
        }
    }
    return dp[pos][mask] = mini;
}

int main()
{
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
        };
    
    int dp[V][1<<V]; //pos mask
    // for(int i=0;i<V;i++){
    //     for(int j=0;j<(1<<V);j++){
    //         dp[i][j] = -1;
    //     }
    // }
    memset(dp,-1,sizeof(dp));
    printf("MIN COST: %d",tsp(graph,1,0,dp));
    return 0;
}
