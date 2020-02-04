#include <stdio.h>
#include <math.h>
int main() {
    int num,tmp;
    int a,b;
    int format[30];
    scanf("%d %d",&a,&b);
    num = a + b;
    tmp = num;
    if(num != 0){
        int i = 0,n = 0;
        while(num != 0) {
            format[i++] = (int)fabs(num % 10);
            num /= 10;
            n++;
        }
        if(tmp < 0){
            printf("-");
        }
        for(i = n-1; i >= 0; i--){
            printf("%d",format[i]);
            if(i % 3 == 0  && i != 0){
                printf(",");
            }
        }
        printf("\n");
    } else{
        printf("0\n");
    }

    return 0;
}
