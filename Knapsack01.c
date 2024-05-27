/*
    0/1 Knapsack
Enter the number of items:4
Enter the profit and weights of each item: 
3 2
4 3
5 4
6 5
Enter the capacity: 5
The maximum profit: 7
*/


#include <stdio.h>
int max(int a,int b){
    return a>b?a:b;
}
int knapsack01(int n,int profit[],int weight[],int capacity){
    int dp[n+1][capacity+1];

    for(int i=0;i<=n;i++){
        for(int w=0;w<=capacity;w++){
            if(i==0 || w==0) dp[i][w]=0;
            else if(weight[i-1]<=w){
                dp[i][w] = max(profit[i-1]+dp[i][w-weight[i-1]],dp[i-1][w]);
            }
            else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][capacity];
}
int main()
{
    int n,capacity;
    printf("Enter the number of items:");
    scanf("%d",&n);
    int profit[n],weight[n];
    printf("Enter the profit and weights of each item: \n");
    for(int i=0;i<n;i++){
        scanf("%d %d",&profit[i],&weight[i]);
    }
    printf("Enter the capacity: ");
    scanf("%d",&capacity);
    printf("The maximum profit: %d",knapsack01(n,profit,weight,capacity));
    return 0;
}
