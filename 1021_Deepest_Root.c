#include <stdio.h>
int G[11000][11000] = {0};
int visit[11000] = {0};
int n;
int depth[11000] = {0};
void dfs(int p){
    visit[p] = 1;
    int q;
    for(q = 1; q <= n; q++){
        if(!visit[q] && G[p][q] == 1){
            dfs(q);
        }
    }
}
void level(int p){
    int last = p,new_last,l = 0;
    int que[11000];
    int front= 0,i = 0,q,s;
    que[i++] = p;
    while (front < i){
        q = que[front++];
        visit[q] = 1;
        for(s = 1; s <= n; s++){
            if(!visit[s] && G[q][s] == 1){
                que[i++] = s;
                new_last = s;
            }
        }
        if(q == last){
            last = new_last;
            l++;
        }
    }
    depth[p] = l;
}
int main() {
    int max[11000],maxcnt = 0,maxdepth = 0;
    int i,j,k;
    scanf("%d",&n);
    for(k = 0; k < n-1; k++){
        scanf("%d %d",&i,&j);
        G[i][j] = G[j][i] = 1;
    }
    int cnt = 0;
    for(i = 1; i <= n; i++){
        if(!visit[i]){
            cnt++;
            level(i);
        }
    }
    if(cnt == 1){
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                visit[j] = 0;
            }
            level(i);
            if(maxdepth < depth[i]){
                maxdepth = depth[i];
            }
        }
        for(i = 1; i <= n; i++){
            if(depth[i] == maxdepth){
                printf("%d\n",i);
            }
        }
    } else{
        printf("Error: %d components\n",cnt);
    }

    return 0;
}