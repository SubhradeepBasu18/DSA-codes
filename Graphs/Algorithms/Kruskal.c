/*
INPUT:
0 1 4
0 2 4
1 2 2
2 3 3
2 4 2
2 5 4
3 5 3
4 5 3
*/
/*
OUTPUT: 
1 - 2 : 2
2 - 4 : 2
2 - 3 : 3
3 - 5 : 3
0 - 2 : 4
Minimum Spanning Tree Weight: 14
*/



#include <stdio.h>
#include <stdlib.h>

struct subset{
    int parent;
    int size;
};

struct Edge{
    int src,dest,weight;
};

int compare(const void *a, const void *b){
    struct Edge *a1 = (struct Edge *)a;
    struct Edge *b1 = (struct Edge *)b;

    return a1->weight - b1->weight;
}

int findPar(struct subset subsets[], int x){
    if(subsets[x].parent != x){
        subsets[x].parent = findPar(subsets,subsets[x].parent);
    }
    return subsets[x].parent;
}

void UnionBySize(struct subset subsets[], int u, int v){
    int pu = findPar(subsets,u);
    int pv = findPar(subsets,v);

    if(pu == pv) return;

    if(subsets[pu].size < subsets[pv].size){
        subsets[pu].parent = pv;
        subsets[pv].size += subsets[pu].size;
    }
    else{
        subsets[pv].parent = pu;
        subsets[pu].size += subsets[pv].size;
    }

}

void kruskal(struct Edge *edges, int V, int E){

    qsort(edges,E,sizeof(struct Edge),compare);

    struct subset *subsets = (struct subset *)malloc(V* sizeof(struct subset));
    for(int i=0;i<V;i++){
        subsets[i].parent = i;
        subsets[i].size = 1;
    }

    int e=0,i=0,mstWt = 0;
    struct Edge ans[V];

    while(e<V-1 && e<E){
        struct Edge next = edges[i++];
        int u = next.src;
        int v = next.dest;

        int px = findPar(subsets ,u);
        int py = findPar(subsets ,v);

        if(px!=py){
            UnionBySize(subsets,px,py);
            ans[e++] = next;
            mstWt+=next.weight;
        }
    }
    for(int i=0;i<e;i++){
        printf("%d - %d : %d\n",ans[i].src, ans[i].dest, ans[i].weight);
    }
    printf("Minimum Spanning Tree Weight: %d\n",mstWt);
    free(subsets);
}

int main()
{
    int V,E;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d",&V,&E);

    struct Edge *edges = (struct Edge *)malloc(E*sizeof(struct Edge));    
    printf("Enter the edges in the format: src dest weight\n");

    for(int i=0;i<E;i++){
        scanf("%d %d %d",&edges[i].src,&edges[i].dest,&edges[i].weight);
    }
    kruskal(edges,V,E);
    return 0;
}
