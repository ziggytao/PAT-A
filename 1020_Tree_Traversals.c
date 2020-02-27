#include <stdio.h>
int in[100],post[100],le[10000],pre[100],x = 0;
void to_level(int root,int l1,int r1, int l){
    if(l1 <= r1){
        int i = l1;
        int r = post[root];
        le[l] = post[root];
        while (in[i] != r && i < r1){
            i++;
        }
        to_level(root - r1 + i - 1,l1,i - 1,l * 2 +1);
        to_level(root-1,i + 1,r1,l * 2 + 2);
    }
}
void to_pre(int root,int l1,int r1){
    if(l1 <= r1){
        int i = l1;
        pre[x++] = post[root];
        while (in[i] != post[root] && i < r1){
            i++;
        }
        to_pre(root - r1 + i -1,l1,i - 1);
        to_pre(root-1,i + 1,r1);
    }
}
int main() {
    int n,i;
    for(i = 0; i < 10000; i++){
        le[i] = -1;
    }
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        scanf("%d",post + i);
    }
    for (i = 0; i < n; i++) {
        scanf("%d",in + i);
    }
    to_level(n-1,0,n-1,0);
    to_pre(n-1,0,n-1);
    int cnt = n;
    for(i = 0; i < 10000; i++){
        if(le[i] != -1){
            if(i > 0){
                printf(" ");
            }
            printf("%d",le[i]);
            n--;
        }
        if(n <= 0){
            break;
        }
    }
    printf("\n");
    for (i = 0; i < cnt; i++){
        printf("%d ",pre[i]);
    }
    return 0;
}