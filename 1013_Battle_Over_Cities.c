#include <stdio.h>

#define MAXNODE 1000
//实际上是求去掉一个点之后剩下的连通分量的个数
//用BFS会超时
//删除一座城市就是令该城市已被访问
int visited[1000] = {0};
void DFS(int g[][MAXNODE],int p,int n);
void BFS(int g[][MAXNODE],int p,int n);
int main() {
    int G[MAXNODE][MAXNODE];
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int i,n1,n2;
    for(i = 0; i < m; i++){
        scanf("%d %d",&n1,&n2);
        G[n1][n2] = 1;
        G[n2][n1] = 1;
    }
    int city;
    for(i = 0; i < k; i++){
        scanf("%d",&city);
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            visited[j] = 0;
        }
        visited[city] = 1;
        for (int j = 1; j <= n; ++j) {
            if(!visited[j])
            {
                DFS(G,j,n);
//                BFS(G,j,n);
                cnt++;
            }
        }

        printf("%d\n",cnt-1);
    }
    return 0;
}
void DFS(int g[][MAXNODE],int p,int n){
    visited[p] = 1;
    for (int i = 1; i <= n; ++i) {
        if(!visited[i] && g[p][i] == 1){
            DFS(g,i,n);
        }
    }
}
void BFS(int g[][MAXNODE],int p,int n){
    int q[n];
    int f = 0,r = 0;
    int t;
    q[r++] = p;
    while(r > f){
        t = q[f++];
        visited[t] = 1;
        for(p = 1; p <= n; p++){
            if(!visited[p] && g[t][p] == 1){
                q[r++] = p;
            }
        }
    }
}
