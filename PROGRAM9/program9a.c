#include <stdio.h>
void bsf(int);
int n, a[10][10], vis[10];
void main(){
    int i, j, src;
    printf("Enter number of nodes\n");
    scanf("%d", &n);
    printf("Enter adjacency matrix\n");
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            scanf("%d", &a[i][j]);
        }
        vis[i] = 0;
    }
    printf("Enter source node\n");
    scanf("%d", &src);
    printf("The nodes reachable from source node\n");
    bfs(src);
}
void bfs(int v){
    int q[10], f=1, r=1, u, i;
    q[r] = v;
    vis[v] = 1;
    while(f<=r){
        u = q[f];
        printf("%d ", u);
        for(i=1; i<=n; i++){
            if(a[u][i]==1 && vis[i]==0){
                vis[i] = 1;
                r = r+1;
                q[r] = i;
            }
        }
        f = f+1;
    }
}
