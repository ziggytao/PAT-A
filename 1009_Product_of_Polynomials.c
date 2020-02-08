#include <stdio.h>
//两个多项式的乘积
struct poly{
    int exp;
    double coef;
};
int main() {
    int n1,n2,exp;
    double coef;
    int i,j,cnt = 0;
    struct poly p1[11],p2[11];
    double p3[2200] = {0};
    scanf("%d",&n1);
    for(i = 0;i < n1; i++){
        scanf("%d %lf",&exp,&coef);
        p1[i].exp = exp;
        p1[i].coef = coef;
    }
    scanf("%d",&n2);
    for(i = 0;i < n2; i++){
        scanf("%d %lf",&exp,&coef);
        p2[i].exp = exp;
        p2[i].coef = coef;
    }
    for(i = 0; i < n1; i++){
        for(j = 0; j < n2; j++){
            exp = p1[i].exp + p2[j].exp;
            coef = p1[i].coef * p2[j].coef;
            if(p3[exp] == 0 && coef != 0){
                cnt++;
            }
            p3[exp] += coef;
            if(p3[exp] == 0){
                cnt--;
            }
        }
    }
    printf("%d",cnt);
    for(i = 2199; i >=0; i--){
        if(p3[i] != 0){
            printf(" ");
            printf("%d %.1f",i,p3[i]);
        }
    }
    printf("\n");
    return 0;
}
