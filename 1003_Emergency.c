#include <stdio.h>
#define INFINITE 999999
/*
 * num[]用来记录最短路径的条数,dis[]记录最短路径的长度,weight[]表示每个点的权重（救援人员数量）,w[]记录最大救援人数,
 * visit[]记录是否访问过
 * 用Dijkstra算法，每次找一个离源点最近的点，然后更新所有邻接点
 * 当判定dis[u] + e[u][v] < dis[v]的时候，不仅仅要更新dis[v]，还要更新num[v] = num[u], w[v] = weight[v] + w[u];
 * 如果dis[u] + e[u][v] == dis[v]，还要更新num[v] += num[u]，而且判断一下是否权重w[v]更小，如果更小了就更新w[v] = weight[v] + w[u]; 
 */
int visit[510] = {0};
int num[510] = {0},weight[510],w[510],dis[510],G[510][510];
int main() {
    int n,v,p1,p2,we,a,b,d;
    scanf("%d%d%d%d",&n,&v,&p1,&p2);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&we);
        weight[i] = we;
    }
    for (int k = 0; k < 510; ++k) {
        dis[k] = INFINITE;
        for (int i = 0; i < 510; ++i) {
            G[k][i] = INFINITE;
        }
    }
    for (int j = 0; j < v; ++j) {
        scanf("%d %d %d",&a,&b,&d);
        G[a][b] = G[b][a] = d;
    }
    dis[p1] = 0;
    w[p1] = weight[p1];
    num[p1] = 1;

    for(int i = 0; i < n; i++){
        int min = INFINITE,u = -1,v,j;
        for(j = 0; j < n; j++){
            if((dis[j] < min) && !visit[j]){
                min = dis[j];
                u = j;
            }
        }
        if(u == -1){
            //非连通的情况
            break;
        }
        visit[u] = 1;//第一次的u是p1
        for(v = 0; v < n; v++){
            if(dis[u] + G[u][v] < dis[v]){
                num[v] = num[u];
                w[v] = w[u] + weight[v];
                dis[v] = dis[u] + G[u][v];
            } else if(dis[u] + G[u][v] == dis[v]){
                num[v] += num[u];
                if(w[v] < w[u] + weight[v]){
                    w[v] = w[u] + weight[v];
                }
            }
        }
    }
    printf("%d %d\n",num[p2],w[p2]);
    return 0;
}