#include <stdio.h>
void bet(int b){
    switch(b){
        case 0:
            printf("W ");
            break;
        case 1:
            printf("T ");
            break;
        case 2:
            printf("L ");
            break;
    }
}
int main() {
    double game1[3],game2[3],game3[3];
    double profit,max1 = 0,max2 = 0,max3 = 0;
    int b1,b2,b3;
    int i;
    for (i = 0; i < 3; ++i) {
        scanf("%lf",&game1[i]);
        if(game1[i] > max1){
            max1 = game1[i];
            b1 = i;
        }
    }
    for (i = 0; i < 3; ++i) {
        scanf("%lf",&game2[i]);
        if(game2[i] > max2){
            max2 = game2[i];
            b2 = i;
        }
    }
    for (i = 0; i < 3; ++i) {
        scanf("%lf",&game3[i]);
        if(game3[i] > max3){
            max3 = game3[i];
            b3 = i;
        }
    }
    bet(b1);
    bet(b2);
    bet(b3);

    profit = (max1 * max2 * max3 * 0.65 - 1) * 2;
    printf("%.2f\n",profit);
    return 0;
}
