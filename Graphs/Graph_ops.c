#include <stdio.h>
#include <stdlib.h>
int adj[10][10];
int v;
void createGraph()
{
    int e;
    printf("Enter the number of vertices:\n");
    scanf("%d",&v);
    e = v*(v-1);
    int origin,dest;
    for(int i=0;i<e;i++)
    {
        printf("Enter edge %d (-1,-1) to exit\n",i);
        scanf("%d %d",&origin,&dest);
        if(origin == -1 && dest == -1)
        {
            break;
        }
        else if(origin < 0 || dest < 0 || origin >= v || dest >= v)
        {
            printf("Invalid Input\n");
            i--;
        }
        else
        {
        adj[origin][dest] = 1;
        }
    }
}
void insertEdge(int origin, int dest)
{
    if(origin < 0 || origin > v)
    {
        printf("Origin vertex does not exist\n");
    }
    else if(dest < 0 || dest > v)
    {
        printf("Destination vertex does not exist\n");
    }
    else
    {
        adj[origin][dest] = 1;
    }
}
void deleteEdge(int origin, int dest)
{
    if(origin < 0 || origin > v)
    {
        printf("Origin vertex does not exist\n");
    }
    else if(dest < 0 || dest > v)
    {
        printf("Destination vertex does not exist\n");
    }
    else
    {
        adj[origin][dest] = 0;
    }
}
void display()
{
    // printf("%d",v);
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            printf("%4d ",adj[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int ch,t=0;
    createGraph();
    printf("Press 1 for inserting an edge\nPress 2 for deleting an edgee\nPress 3 to display\nPress 4 to exit\n");
    
    while(t!=1)
    {
        int origin,dest;
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                printf("Enter edge to be inserted\n");
                scanf("%d %d",&origin,&dest);
                insertEdge(origin,dest);
                break;
            case 2:
                printf("Enter edge to be deleted\n");
                scanf("%d %d",&origin,&dest);
                deleteEdge(origin,dest);
                break;
            case 3:
                display();
                break;
            case 4: 
                t=1;
                break;
            default:
                printf("Invalid Input\n");
                break;
        }
        // printf("PRESS 1 to EXIT\n");
        // scanf("%d",&t);
    }
    return 0;
}
