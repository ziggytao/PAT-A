#include <stdio.h>
#include <stdbool.h>

/*
 * 非叶结点的输入并不一定是按照从上到下的顺序的，所以读入输入时还不能得到层数，只能记录下每个结点的父结点
 * 需要再遍历一次，
 * 子结点的层数等于父结点层数加一
 * 注意只有一个根结点的情况
 */
typedef struct{
   // char ID[10];
    int parent;
    int level;
    bool hasChild;
}Node;
int main() {
    Node tree[200];
    for(int i = 0; i < 200; i++){
        tree[i].hasChild = false;
    }
    int n = 0,k;
    int pid,cid;
    scanf("%d %d",&n,&k);
    if(n > 0){
        if(k > 0){
            int childnum;
            tree[0].level = 0;
            for (int i = 0; i < k; ++i) {
                scanf("%d",&pid);
                pid--;
                tree[pid].hasChild = true;
                scanf("%d",&childnum);
                for (int j = 0; j < childnum; ++j) {
                    scanf("%d",&cid);
                    cid--;
                    tree[cid].parent = pid;
                }
            }
            int leaves[200] = {0},level = 0;
            int i;
            for(i = 1; i < n; i++){
                tree[i].level = tree[tree[i].parent].level + 1;
                if(!tree[i].hasChild){
                    leaves[tree[i].level]++;
                }
                if(level < tree[i].level){
                    level = tree[i].level;
                }
            }
            for(int i = 0; i <= level; i++){
                if(i > 0){
                    printf(" ");
                }
                printf("%d",leaves[i]);
            }
        } else{
            printf("1\n");
        }
    }
    return 0;
}