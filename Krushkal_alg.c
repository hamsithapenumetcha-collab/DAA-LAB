#include<stdio.h>
#define MAX_EDGES 100
#define MAX_VERTICES 50

int parent[MAX_VERTICES];

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int find(int i){
    while(parent[i]!=i){
    i=parent[i];
    }
    return i;
}

int unionset(int i,int j){
    int root_i=find(i);
    int root_j=find(j);
    if(root_i != root_j){
    parent[root_i]=root_j;
    return 1;
    }
    return 0;
}

int main(){
    int V,E;
    int edges[MAX_EDGES][3];
    
    printf("Enter the number of vertices: ");
    scanf("%d",&V);
    printf("Enter the number of edges: ");
    scanf("%d",&E);
    printf("Enter edge details (Source Destination Weight):\n");
    for(int i=0;i<E;i++){
        printf("Edge %d: ",i+1);
        scanf("%d %d %d",&edges[i][1],&edges[i][2],&edges[i][0]);
    }
    for(int i=0;i<E-1;i++){
        for(int j=0;j<E-i-1;j++){
            if(edges[j][0]>edges[j+1][0]){
                swap(&edges[j][0],&edges[j+1][0]);
                swap(&edges[j][1],&edges[j+1][1]);
                swap(&edges[j][2],&edges[j+1][2]);
            }
        }
    }
    for(int i=0;i<V;i++){
        parent[i]=i;
    }
    printf("\n---Minimum Spanning Tree---\n");
    printf("Edges included in MST:\n");
    int mst_weight=0;
    int edges_count=0;

    for(int i=0;i<E;i++){
        int weight=edges[i][0];
        int u= edges[i][1];
        int v= edges[i][2];

        if(unionset(u,v)){
            printf("%d--%d=%d\n",u,v,weight);
            mst_weight +=weight;
            edges_count++;

            if(edges_count==V-1){
                break;
            }
        }
    }
    printf("Total cost of MST: %d\n",mst_weight);
    return 0;
}