Calculate a+b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas
(unless there are less than four digits).

Input Specification:
Each input file contains one test case. Each case contains a pair of integers a and b where 
−10^6≤a,b≤10^6. The numbers are separated by a space.

Output Specification:
For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input:
-1000000 9
   
Sample Output:
-999,991

    
    
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
