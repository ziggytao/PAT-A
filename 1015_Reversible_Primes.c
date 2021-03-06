#include <stdio.h>
#include <stdbool.h>

int transfer(int n,int radix);
bool isPrime(int n);
int main() {
    int n,radix;
    scanf("%d",&n);
    while(n >= 0){
        scanf("%d",&radix);
        if(isPrime(n) && isPrime(transfer(n,radix))){
            printf("Yes\n");
        } else{
            printf("No\n");
        }
        scanf("%d",&n);
    }
    return 0;
}
int transfer(int n,int radix){
    int ret = 0;
    while(n > 0){
        ret =  ret * radix + n % radix;
        n /= radix;
    }
    return ret;
}
/*
transfer函数完成了三件事
1.将十进制的n转换成radix进制
2.将数字逆序
3.转换回十进制
*/

bool isPrime(int n){
    bool isPrime = true;
    int i;
    if(n > 1){
        for(i = 2; i < n/2; i++){
            if(n % i == 0){
                isPrime = false;
                break;
            }
        }
    } else{
        isPrime = false;
    }
    return isPrime;
}
