#include <stdio.h>

int main() {
    int n,base;
    int i = 0,ret = 1;
    int l[200];
    scanf("%d %d",&n,&base);
    while (n > 0) {
        l[i++] = n % base;
        n /= base;
    }
    int cnt = i;
    for (i = 0; i < cnt/2; i++) {
        if(l[i] != l[cnt-i-1]){
            ret = 0;
            break;
        }
    }
    if (ret) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    for (i = cnt -1; i >= 0; i--) {
        printf("%d",l[i]);
        if(i > 0){
            printf(" ");
        }
    }
    return 0;
}